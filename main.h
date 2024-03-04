/* Name: Tony Le
 * Class: CS260 - 12720
 * Project: #4
 * Date: Mar 1041, 2024
 * Description: This is the header file for the main program.
 */

#ifndef MAIN_H
#define MAIN_H

#include "BST.h"
#include "myUtil.h"

const char* DATA_FILE = "websites.txt";

// Function prototypes

/**
 * This function prints a welcome message.
 *
 * @return void
 */
void welcome();

/**
 * This function prints a goodbye message.
 *
 * @return void
 */
void goodbye();

/**
 * This function displays the menu to the user.
 *
 * @return void
 */
void displayMenu();

/**
 * This function executes the option that the user chooses.
 *
 * @param option The option that the user chooses.
 * @param bst The instance of BST ADT.
 * @return void
 */
void exeOption(int option, BST& bst);

/**
 * Prompts for the website's information and adds a new website into the bst.
 *
 * @param bst The instance of table ADT.
 * @return void
 */
void insertWebsite(BST& bst);

/**
 * Prompts for the topic name and removes all websites based on that topic
 * name.
 *
 * @param bst The instance of table ADT.
 * @return void
 */
void removeWebsitesByTopic(BST& bst);

/**
 * Prompts for the keyword and removes the website based on that keyword.
 *
 * @param bst The instance of table ADT.
 * @return void
 */
void removeWebsiteByKeyword(BST& bst);

/**
 * Prompts for the keyword and retrieves websites based on that keyword.
 *
 * @param bst The instance of table ADT.
 * @return void
 */
void retrieveBasedOnKeyword(BST& bst);

/**
 * Displays all websites in the bst alphabetically.
 *
 * @param bst The instance of table ADT.
 * @return void
 */
void displayWebsitesAlphabetically(BST& bst);

/**
 * Displays the height of the bst.
 *
 * @param bst The instance of table ADT.
 * @return void
 */
void displayHeight(BST& bst);

/**
 * Prints the list of websites.
 *
 * @param total    The number of websites.
 * @param websites The array of websites.
 * @return void
 */
void printWebsites(const int total, const Website websites[]);

#endif
