/*****************************************************************************
# Author:           Tony Le
# Project:          Project 4
# Date:             Mar 04, 2024
# Description:      This program will help you save favorite websites using
#                   a binary search tree.
# Sources:          Project 4 specifications
#****************************************************************************/

#include "main.h"

int main() {
  BST bst;
  int option = -1;

  int loadResult = bst.loadData(DATA_FILE);

  welcome();

  if (loadResult != ERROR) {
    cout << loadResult << " websites were loaded." << endl;

    do {
      displayMenu();

      getNumber("", "Please choose the option from 1 to 7!", 1, 7, option);

      exeOption(option, bst);
    } while (option != 7);

    goodbye();
  }
}

// This function prints a welcome message.
void welcome() {
  cout << "Welcome to Favorite Websites program!" << endl;
  cout
    << "This program will help you keeping track of your favorite websites.";
  cout << endl << endl;
}

// This function prints a goodbye message.
void goodbye() {
  cout << endl;
  cout << "Thank you for using the program!!";
}

// This function displays the menu to the user.
void displayMenu() {
  cout << "Pick an option from below: " << endl << endl;
  cout << "1. Insert a new website" << endl;
  cout << "2. Remove all matches to a topic name" << endl;
  cout << "3. Remove a particular website based on keyword" << endl;
  cout << "4. Retrieve the information about a particular website based on "
       << "its keyword" << endl;
  cout << "5. Display all websites" << endl;
  cout << "6. Display tree's height" << endl;
  cout << "7. Quit" << endl;
  cout << endl;
}

// This function executes the option that the user chooses.
void exeOption(int option, BST& bst) {
  switch (option) {
    case 1:
      insertWebsite(bst);
      break;
    case 2:
      removeWebsitesByTopic(bst);
      break;
    case 3:
      removeWebsiteByKeyword(bst);
      break;
    case 4:
      retrieveBasedOnKeyword(bst);
      break;
    case 5:
      bst.displayWebsitesAlphabetically(cout);
      break;
    case 6:
      displayHeight(bst);
    case 7:
      bst.writeData(DATA_FILE);
      break;
    default:
      cout << "Invalid option!! Please try again!!!" << endl << endl;
  }
}

// Prompts for the website's information and adds a new website into the hash
// table.
void insertWebsite(BST& bst) {
  char topic[STR_SIZE];
  char keyword[STR_SIZE];
  char address[STR_SIZE];
  char summary[STR_SIZE];
  char review[STR_SIZE];
  unsigned short int rating;

  cout << "Enter the topic: ";
  cin.getline(topic, STR_SIZE);

  cout << "Enter the keyword: ";
  cin.getline(keyword, STR_SIZE);

  cout << "Enter the address: ";
  cin.getline(address, STR_SIZE);

  cout << "Enter the summary: ";
  cin.getline(summary, STR_SIZE);

  cout << "Enter the review: ";
  cin.getline(review, STR_SIZE);

  getNumber<unsigned short int>(
    "Enter the rating (1-5 stars – 1 being not very useful, 5 being very "
    "useful): ",
    "Please enter a valid rating!", 1, 5, rating);
  cout << endl;

  bst.insert(Website(topic, keyword, address, summary, review, rating));

  cout << endl;
}

// Prompts for the topic name and removes all websites based on that topic.
void removeWebsitesByTopic(BST& bst) {
  char topic[STR_SIZE];
  Website* results = nullptr;
  int totalResults;

  cout << "Enter the topic: ";
  cin.getline(topic, STR_SIZE);
  cout << endl;

  bst.removeWebsitesByTopic(topic, results, totalResults);

  cout << "The removed websites are: " << endl;
  printWebsites(totalResults, results);
  cout << endl;

  delete[] results;
}

// Prompts for the keyword and removes the website based on that keyword.
void removeWebsiteByKeyword(BST& bst) {
  char keyword[STR_SIZE];
  Website website;

  cout << "Enter the keyword: ";
  cin.getline(keyword, STR_SIZE);

  bst.removeWebsiteByKeyword(keyword, website);

  cout << endl;
}

// Prompts for the keyword and retrieves websites based on that keyword.
void retrieveBasedOnKeyword(BST& bst) {
  char keyword[STR_SIZE];
  Website* results = nullptr;
  int totalResults;

  cout << "Enter the keyword: ";
  cin.getline(keyword, STR_SIZE);

  bst.retrieveBasedOnKeyword(keyword, results, totalResults);

  cout << "The websites with that keyword are: " << endl;
  printWebsites(totalResults, results);
  cout << endl;

  if (results) {
    delete[] results;
  }
}

// Prints the list of websites.
void printWebsites(const int total, const Website websites[]) {
  for (int i = 0; i < total; i++) {
    websites[i].printInformation(cout);
    cout << endl;
  }
}

// Displays the height of the bst.
void displayHeight(BST& bst) {
  cout << "The height of the tree is: " << bst.calculateHeight() << endl;
  cout << endl;
}
