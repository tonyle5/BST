/**
 * This function reads an input from the user and validates if the number is
 * a number of type T and within a range.
 *
 * @param      prompt The prompt to display to the user.
 * @param      errorMsg The error message to display to the user.
 * @param      from The lower bound of the range.
 * @param      to The upper bound of the range.
 * @param[out] num The number to store the user input.
 */
template <typename T>
void getNumber(const char prompt[], const char errorMsg[], const T from,
               const T to, T& num) {
  cout << prompt;

  cin >> num;

  while (!cin || num < from || num > to) {
    cout << errorMsg << endl;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << prompt;
    cin >> num;
  }

  cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

/**
 * This function frees the memory allocated for a dynamic array.
 *
 * @param[in, out] arr The dynamic array to free.
 * @return void
 */
template <typename T>
void freeDynamicArray(T*& arr) {
  if (arr) {
    delete[] arr;
    arr = nullptr;
  }
}
