/* This is the header file for a utility file, which contains common
 * functions, constants, and libraries.
 */

#ifndef _MYUTIL_
#define _MYUTIL_

#include <cfloat>
#include <climits>
#include <cstring>
#include <fstream>
#include <iostream>

using namespace std;

/**
 * Error code
 */
const int ERROR = -1;

/**
 * The length of a string.
 */
const int STR_SIZE = 101;

/**
 * Initial capacity of an array.
 */
const int INIT_CAP = 5;

enum TRAVERSAL_ORDER { PREORDER, INORDER, POSTORDER };

/**
 * This function copy a dynamic array to a new array.
 *
 * @param srcArr The source array.
 * @param destArr The destination array.
 * @return void
 */
void setCharArr(const char*& srcArr, char*& destArr);

#include "myUtil.inl"

#endif
