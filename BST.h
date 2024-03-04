#ifndef Table_H
#define Table_H

#include "Website.h"
#include "myUtil.h"

/**
 * The Node of the table.
 */
struct Node {
    Node(const Website& data) {
      this->data = new Website(data);
      this->left = this->right = nullptr;
    }

    ~Node() {
      if (this->data) {
        delete this->data;
        this->data = nullptr;
      }
    }

    Website* data;
    Node *left, *right;
};

/**
 * This class represents a binary search tree containing information about
 * websites
 */
class BST {
  private:
    /**
     * The size of the BST.
     */
    int size;

    /**
     * The root of the BST.
     */
    Node* root;

  public:
    /**
     * Default constructor.
     */
    BST();

    /**
     * Destructor.
     */
    ~BST();

    /**
     * Insert a new website by topic.
     *
     * @param website The website to add.
     * @return        void
     */
    void insert(const Website& website);

    /**
     * Removes all websites based on a topic.
     *
     * @param topic         The topic to remove.
     * @param results       The removed websites.
     * @param totalResults  The total number of removed websites.
     * @return              void
     */
    void removeWebsitesByTopic(const char* topic, Website*& results,
                               int& totalResults);

    /**
     * Removes a website based on a keyword.
     *
     * @param keyword       The keyword to remove.
     * @param website       The removed websites.
     * @return              void
     */
    bool removeWebsiteByKeyword(const char* keyword, Website& website);

    /**
     * Retrieves all websites based on a topic keyword.
     *
     * @param topicKeyword  The topic keyword to search for.
     * @param results       The retrieved websites.
     * @param totalResults  The total number of retrieved websites.
     * @return              void
     */
    void retrieveBasedOnKeyword(const char* keyword, Website*& results,
                                int& totalResults);

    /**
     * Displays all websites in the bst alphabetically.
     *
     * @param topicKeyword  The topic keyword to search for.
     */
    void displayWebsitesAlphabetically(ostream& out) const;

    /**
     * Calculates the height of the bst.
     *
     * @return int  The height of the bst.
     */
    int calculateHeight();

    /**
     * Loads data from a file into the table.
     *
     * @param fileName  The name of the file to load data from.
     * @return          The number of records loaded, returns ERROR in case
     *                  the data can not be loaded.
     */
    int loadData(const char* fileName);

    /**
     * Writes data from the table to a file.
     *
     * @param fileName  The name of the file to write data to.
     * @return          Whether the data is written successfully.
     */
    bool writeData(const char* fileName) const;

  private:
    /**
     * Destroys the table.
     *
     * @return void
     */
    void destroy(Node*& curRoot);

    /**
     * Recursive function to insert a new website by topic.
     *
     * @param currRoot The current root of the BST.
     * @param website  The website to add.
     * @return         void
     */
    void insert(Node*& currRoot, const Website& website);

    /**
     * Recursive function to remove all websites based on a topic keyword.
     *
     * @param curRoot       The current root of the BST.
     * @param topic         The topic to remove.
     * @param results       The removed websites.
     * @param totalResults  The total number of removed websites.
     * @return              void
     */
    void removeWebsitesByTopic(Node*& curRoot, const char* topic,
                               Website*& results, int& totalResults);

    /**
     * Delete the target node.
     *
     * @param target The target node to delete.
     * @return       void
     */
    void deleteTarget(Node*& target);

    /**
     * Recursive function to remove a website based on a keyword.
     *
     * @param curRoot       The current root of the BST.
     * @param keyword       The keyword to remove.
     * @param website       The removed websites.
     * @return              void
     */
    bool removeWebsiteByKeyword(Node*& curRoot, const char* keyword,
                                Website& website);

    /**
     * Recursive function to retrieve all websites based on a keyword.
     *
     * @param keyword       The keyword to search for.
     * @param results       The retrieved websites.
     * @param totalResults  The total number of retrieved websites.
     * @return              void
     */
    void retrieveBasedOnKeyword(Node*& curRoot, const char* keyword,
                                Website*& website, int& totalResults) const;

    /**
     * Recursive function to calculate the height of the bst.
     *
     * @param root  The current root of the BST.
     * @return int  The height of the bst.
     */
    int calculateHeight(Node* root);

    /**
     * Recursive function to write data to a file.
     *
     * @param curRoot The current root of the BST.
     * @param outFile The file to write data to.
     * @param index   The index of the current node.
     * @return        void
     */
    void writeData(Node* curRoot, ostream& outFile, int& index,
                   TRAVERSAL_ORDER traversalOrder) const;

    /**
     * Initializes the table's data.
     */
    void init();
};

#endif
