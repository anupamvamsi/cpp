#include <iostream>
#include <vector>

void printMatrix(std::vector<std::vector<int>>& matrix) {
  for (auto& r : matrix) {
    for (auto& e : r) {
      std::cout << e << " ";
    }
    std::cout << "\n";
  }
}

void printVector(std::vector<std::size_t>& vec) {
  for (auto& e : vec) {
    std::cout << e << " ";
  }
  std::cout << "\n";
}

void rewriteMatrix(std::vector<std::vector<int>>& matrix) {
  if (matrix.empty()) {
    std::cout << "No matrix was given.\n";
  }

  // get coordinates of the zeroes
  std::vector<std::size_t> row{}, col{};

  for (std::size_t i{}; i < matrix.size(); ++i) {
    for (std::size_t j{}; j < matrix[0].size(); ++j) {
      if (matrix[i][j] == 0) {
        row.push_back(i);
        col.push_back(j);
      }
    }
  }

  if (!row.empty()) {
    std::cout << "\nPosition(s) of the zero(es) in the given matrix of "
              << matrix.size() << " x " << matrix[0].size() << " is/are:\n";
    for (std::size_t i{}; i < row.size(); ++i) {
      std::cout << "(" << row[i] << ", " << col[i] << ")  ";
    }
    std::cout << "\n";

    // rewrite the matrix
    for (std::size_t i{}; i < row.size(); ++i) {
      // std::fill(matrix[row[i]].begin(), matrix[row[i]].end(), 0);

      std::size_t r{row[i]}, c{col[i]};

      for (std::size_t j{}; j < matrix[r].size(); ++j) {
        matrix[r][j] = 0;
      }

      for (std::size_t k{}; k < matrix.size(); ++k) {
        matrix[k][c] = 0;
      }
    }
    std::cout << "\nRewritten Matrix:\n";
    printMatrix(matrix);
  }

  else {
    std::cout << "\nNo zeroes in the given matrix. No rewriting of matrix has "
                 "happened.\n";
  }
}

int main() {
  std::size_t m{}, n{};

  std::cin >> m >> n;

  std::vector<std::vector<int>> matrix(m, std::vector<int>(n, 0));

  for (auto& r : matrix) {
    for (auto& e : r) {
      std::cin >> e;
    }
  }

  std::cout << "\nThe given matrix is of size (" << matrix.size() << " x "
            << matrix[0].size() << "):\n";
  printMatrix(matrix);

  rewriteMatrix(matrix);

  return 0;
}

/*
SAMPLE INPUTS:
5 12
1 2 3 4 5 6 7 8 9 7 1 1
2 3 4 5 6 7 8 9 1 1 2 3
4 5 6 7 8 9 1 2 3 4 5 6
7 8 9 1 2 3 4 5 6 7 8 9
1 1 2 3 4 5 6 7 8 9 1 2

5 12
1 2 3 4 5 6 7 8 9 7 0 1
2 3 4 5 6 7 8 9 1 1 2 3
4 5 6 7 8 9 1 2 3 4 5 6
7 8 9 1 2 3 4 5 6 7 8 9
1 1 2 3 4 5 6 7 8 9 1 2

5 12
1 2 3 4 5 6 7 8 9 7 0 1
2 3 4 5 6 7 8 9 0 1 2 3
4 5 6 7 8 9 1 2 3 4 5 6
7 8 9 1 2 3 4 5 6 7 8 9
0 1 2 3 4 5 6 7 8 9 1 2
*/