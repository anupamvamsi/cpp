// Function pointers
#include <iostream>
// #include <utility> // Is this include needed? (for std::swap)

bool asc(int x, int y) { return x > y; }

bool desc(int x, int y) { return x < y; }

using CompareFunc = bool (*)(int, int);  // Type aliasing

void SelectionSort(int* array, int size, CompareFunc cmp_fn = asc) {
  for (int start_idx{0}; start_idx < size; start_idx++) {
    int best_idx{start_idx};

    for (int curr_idx{start_idx + 1}; curr_idx < size; curr_idx++) {
      if (cmp_fn(array[best_idx], array[curr_idx])) {
        best_idx = curr_idx;
      }
    }

    std::swap(array[start_idx], array[best_idx]);
  }
}

void PrintArray(int* array, int size) {
  for (int i{0}; i < size; i++) {
    std::cout << array[i] << " ";
  }
  std::cout << std::endl;
}

int main() {
  int num_elements;
  std::cout << "Enter number of elements: ";
  std::cin >> num_elements;

  int* arr = new int[num_elements]{0};

  // Space/Enter separated input
  for (int i{0}; i < num_elements; i++) {
    std::cin >> arr[i];
  }

  SelectionSort(arr, num_elements);
  PrintArray(arr, num_elements);

  SelectionSort(arr, num_elements, desc);
  PrintArray(arr, num_elements);

  delete[] arr;

  std::cin.ignore();
  std::cin.get();
}