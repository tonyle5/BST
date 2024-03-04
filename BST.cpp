#include "BST.h"

// Default constructor.
BST::BST() {
  this->init();
}

// Destructor.
BST::~BST() {
  this->destroy(this->root);
}

// Inserts a new website by topic.
void BST::insert(const Website& website) {
  this->insert(this->root, website);
}

// Recursive function to insert a new website by topic.
void BST::insert(Node*& currRoot, const Website& website) {
  if (!currRoot) {
    currRoot = new Node(website);
    this->size++;
  } else if (strcmp(website.getKeyword(), currRoot->data->getKeyword()) < 0) {
    this->insert(currRoot->left, website);
  } else {
    this->insert(currRoot->right, website);
  }
}

// Removes all websites based on a topic keyword.
void BST::removeWebsitesByTopic(const char* topic, Website*& results,
                                int& totalResults) {
  results = new Website[this->size];
  totalResults = 0;

  this->removeWebsitesByTopic(this->root, topic, results, totalResults);
}

// Recursive function to remove all websites based on a topic keyword.
void BST::removeWebsitesByTopic(Node*& curRoot, const char* topic,
                                Website*& results, int& totalResults) {
  if (!curRoot) {
    return;
  }

  int temp;
  do {
    temp = strcmp(topic, curRoot->data->getTopic());

    if (temp == 0) {
      results[totalResults] = *(curRoot->data);
      this->deleteTarget(curRoot);
      size--;
      totalResults++;
    }
  } while (temp == 0);

  if (temp < 0) {
    this->removeWebsitesByTopic(curRoot->left, topic, results, totalResults);
  } else {
    this->removeWebsitesByTopic(curRoot->right, topic, results, totalResults);
  }
}

// Delete the target node.
void BST::deleteTarget(Node*& target) {
  if (!target->left && !target->right) {
    delete target;
    target = nullptr;
  } else if (!target->left) {
    Node* temp = target;
    target = target->right;
    delete temp;
  } else if (!target->right) {
    Node* temp = target;
    target = target->left;
    delete temp;
  } else {
    // two children
    Node* prev = nullptr;
    Node* curr = target->right;
    if (!curr->left) {
      target->right = curr->right;
    } else {
      while (curr->left) {
        prev = curr;
        curr = curr->left;
      }
      prev->left = curr->right;
    }

    delete target->data;
    target->data = curr->data;
    curr->data = nullptr;
    delete curr;
  }
}

// Remove a website by keyword.
bool BST::removeWebsiteByKeyword(const char* keyword, Website& website) {
  return this->removeWebsiteByKeyword(this->root, keyword, website);
}

// Recursive function to remove a website based on a keyword.
bool BST::removeWebsiteByKeyword(Node*& curRoot, const char* keyword,
                                 Website& website) {
  if (!curRoot) {
    return false;
  }

  int temp = strcmp(keyword, curRoot->data->getKeyword());

  if (temp == 0) {
    website = *(curRoot->data);
    deleteTarget(curRoot);
    size--;
    return true;
  }

  if (temp < 0) {
    return this->removeWebsiteByKeyword(curRoot->left, keyword, website);
  } else {
    return this->removeWebsiteByKeyword(curRoot->right, keyword, website);
  }
}

// Retries all websites based on keyword.
void BST::retrieveBasedOnKeyword(const char* keyword, Website*& results,
                                 int& totalResults) {
  results = new Website[this->size];
  totalResults = 0;

  this->retrieveBasedOnKeyword(this->root, keyword, results, totalResults);
}

// Recursive function to retrieve all websites based on a keyword.
void BST::retrieveBasedOnKeyword(Node*& curRoot, const char* keyword,
                                 Website*& results, int& totalResults) const {
  if (curRoot) {
    this->retrieveBasedOnKeyword(curRoot->left, keyword, results,
                                 totalResults);

    if (strstr(curRoot->data->getKeyword(), keyword)) {
      results[totalResults] = *(curRoot->data);
      totalResults++;
    }

    this->retrieveBasedOnKeyword(curRoot->right, keyword, results,
                                 totalResults);
  }
}

// Displays all websites in the bst alphabetically by keyword.
void BST::displayWebsitesAlphabetically(ostream& out) const {
  int index = 0;
  this->writeData(this->root, out, index, TRAVERSAL_ORDER::INORDER);
  cout << endl;
}

// Loads data from a file into the table.
int BST::loadData(const char* fileName) {
  ifstream inFile;
  inFile.open(fileName);

  if (!inFile) {
    return ERROR;
  }

  char topic[STR_SIZE];
  char keyword[STR_SIZE];
  char address[STR_SIZE];
  char summary[STR_SIZE];
  char review[STR_SIZE];
  unsigned short int rating;

  inFile.ignore(numeric_limits<streamsize>::max(), '\n');
  inFile.getline(topic, STR_SIZE, ';');

  while (!inFile.eof()) {
    inFile.getline(keyword, STR_SIZE, ';');
    inFile.getline(address, STR_SIZE, ';');
    inFile.getline(summary, STR_SIZE, ';');
    inFile.getline(review, STR_SIZE, ';');

    inFile >> rating;
    inFile.ignore(numeric_limits<streamsize>::max(), '\n');

    this->insert(Website(topic, keyword, address, summary, review, rating));

    inFile.getline(topic, STR_SIZE, ';');
  }

  inFile.close();

  return this->size;
}

// Calculates the height of the bst.
int BST::calculateHeight() {
  return this->calculateHeight(this->root);
}

// Recursive function to calculate the height of the bst.
int BST::calculateHeight(Node* root) {
  if (!root) {
    return 0;
  }

  // Calculate the height of the left and right subtrees
  int leftHeight = calculateHeight(root->left);
  int rightHeight = calculateHeight(root->right);

  // Return the maximum of left and right subtree heights, plus 1 for the
  // current level
  return max(leftHeight, rightHeight) + 1;
}

// Writes data from the table to a file.
bool BST::writeData(const char* fileName) const {
  ofstream outFile;
  int curIndex = 0;
  outFile.open(fileName);

  if (!outFile) {
    return false;
  }

  outFile << "Topic name; Keyword; Website address; Summary; Review; Rating"
          << endl;

  this->writeData(this->root, outFile, curIndex, TRAVERSAL_ORDER::PREORDER);

  outFile.close();

  return true;
}

// Recursive function to write data to a file.
void BST::writeData(Node* curRoot, ostream& outFile, int& index,
                    TRAVERSAL_ORDER traversalOrder) const {
  if (curRoot) {
    switch (traversalOrder) {
      case TRAVERSAL_ORDER::PREORDER:
        curRoot->data->printInformation(outFile);
        outFile << endl;
        this->writeData(curRoot->left, outFile, index, traversalOrder);
        this->writeData(curRoot->right, outFile, index, traversalOrder);
        break;

      case TRAVERSAL_ORDER::INORDER:
        this->writeData(curRoot->left, outFile, index, traversalOrder);
        curRoot->data->printInformation(outFile);
        outFile << endl;
        this->writeData(curRoot->right, outFile, index, traversalOrder);
        break;

      case TRAVERSAL_ORDER::POSTORDER:
        this->writeData(curRoot->left, outFile, index, traversalOrder);
        this->writeData(curRoot->right, outFile, index, traversalOrder);
        curRoot->data->printInformation(outFile);
        outFile << endl;
        break;

      default:
        break;  // Do nothing
    }
  }
}

// Destroys the table.
void BST::destroy(Node*& curRoot) {
  if (curRoot) {
    this->destroy(curRoot->left);
    this->destroy(curRoot->right);
    delete curRoot;
    curRoot = nullptr;
  }
}

// Initialize the table's data.
void BST::init() {
  this->size = 0;
  this->root = nullptr;
}
