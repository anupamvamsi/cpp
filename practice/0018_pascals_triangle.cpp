/*

Enter number of rows for Pascal's triangle: 7
1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
1 5 10 10 5 1
1 6 15 20 15 6 1

*/

#include <iostream>
#include <vector>

int main() {
  int num_rows, r_count = 0;
  std::cout << "Enter number of rows for Pascal's triangle: ";
  std::cin >> num_rows;

  // 2-D vector/array - p_t == pascal_triangle; r_count == row_count
  std::vector<std::vector<int>> p_t(num_rows, std::vector<int>(num_rows, 1));

  for (int row = num_rows; row > 0; row--) {
    for (int col = 0; col <= r_count; col++) {
      if (col == 0 || col == r_count) {
        p_t[r_count][col] = 1;
        std::cout << p_t[r_count][col] << " ";
      } else if (col > 0 && col < r_count) {
        p_t[r_count][col] = p_t[r_count - 1][col - 1] + p_t[r_count - 1][col];
        std::cout << p_t[r_count][col] << " ";
      }
    }
    r_count++;
    std::cout << "\n";
  }
}

/* BOUNDS CHECKING WITH THE ".at()" METHOD

  // std::vector<int> array = {1, 2, 3, 4};
  // std::cout << array[3] << " " << array[7];
  // array[9] = 21;
  // std::cout << " " << array.size() << " " << array[9] << " b " <<
  array.at(9);

*/