#include <iostream>
#include <iterator>  // std::size()

void swap(int& num1, int& num2) {
  int temp = num1;
  num1 = num2;
  num2 = temp;
}

void printArray(int array[], int size) {
  for (int i{0}; i < size; i++) {
    std::cout << array[i] << " ";
  }
  std::cout << "\n";
}

void recursiveSelSort(int* array, int size, int count = 0) {
  int idx{count};

  for (int i{count}; i < size; i++) {
    if (array[idx] > array[i]) {  // find smallest number
      idx = i;
    }
  }

  swap(array[idx], array[count]);
  printArray(array, size);

  ++count;
  if (count == size) {
    return;
  }

  recursiveSelSort(array, size, count);
}

void bubbleSort(int array[], int size, int count = 0) {
  bool swapped = false;

  for (int i{0}; i < size - 1; i++) {
    // "size - 1" is for maintaining bound of array

    if (array[i] > array[i + 1]) {
      swap(array[i], array[i + 1]);
      swapped = true;

      printArray(array, size);
    }
  }

  std::cout << "\n";

  if (!swapped) {
    return;
  }

  ++count;
  if (count == size) {
    return;
  }

  bubbleSort(array, size, count);
}

int main() {
  int array[]{12, 24, -34, 32, 1, -9083, -239, -4212};
  int sizeArray = std::size(array);

  std::cout << "Original array: ";
  printArray(array, sizeof(array) / sizeof(array[0]));

  std::cout << "Bubble sort on array:\n";
  bubbleSort(array, sizeArray);

  int array2[]{12, 24, -34, 32, 1, -9083, -239, -4212};

  std::cout << "Selection sort on array:\n";
  recursiveSelSort(array2, sizeArray);

  // arrays
  int arr[]{1, 4, 5};

  // arr[2] == *(arr + 2) == *(&arr[2])
  if (arr[2] == *(arr + 2) && arr[2] == *(&arr[2]) && arr[2] == 2 [arr] &&
      arr[2] == *(2 + arr)) {
    std::cout
        << "\narr[2] == *(arr + 2) == *(&arr[2]) == 2[arr] == *(2 + arr) == "
        << arr[2] << '\n';
  }

  char name[]{"Jason"};  // C-style string (also an array)
  std::cout << name << " " << *name << '\n';

  std::cout << arr << " " << &arr << "\n";
  std::cout << *(arr) << " " << typeid(&arr).name() << "\n";

  return 0;
}