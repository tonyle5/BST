#include "myUtil.h"

// This function copy a dynamic array to a new array.
void setCharArr(const char*& srcArr, char*& destArr) {
  if (srcArr) {
    freeDynamicArray<char>(destArr);

    int size = strlen(srcArr);
    destArr = new char[size + 1];

    strcpy(destArr, srcArr);
  }
}
