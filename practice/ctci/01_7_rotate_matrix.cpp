#include <cmath>
#include <iostream>
#include <vector>

void printMatrix1D(std::vector<int>& matrix) {
  if (matrix.empty()) {
    std::cout << "(Empty matrix)\n";
    return;
  }

  for (auto& e : matrix) {
    std::cout << e << " ";
  }
  std::cout << "\n\n";
}

void clockwiseRotateMatrix1D(std::vector<int>& matrix) {
  std::size_t N{static_cast<std::size_t>(sqrt(matrix.size()))};

  std::vector<int> rotatedMatrix(matrix.size(), 0);

  for (std::size_t i{}, r{}, c{1}; i < matrix.size(); ++i, ++c) {
    if (i % N == 0) {
      ++r;
      c = 1;
    }
    // std::cout << (N * (N - c)) + r - 1 << ", i: " << i << "\n";
    rotatedMatrix[i] = matrix[(N * (N - c)) + r - 1];
  }
  std::cout << "Rotating a 1-D Matrix:\n";
  printMatrix1D(rotatedMatrix);
}

void convert2DTo1DAndRotate(std::vector<std::vector<int>>& matrix2D) {
  if (matrix2D.empty()) {
    std::cout << "Cannot convert an empty matrix.\n";
    return;
  }

  std::vector<int> matrix(matrix2D.size() * matrix2D[0].size(), 0);

  for (std::size_t i{}; i < matrix2D.size(); ++i) {
    for (std::size_t j{}; j < matrix2D[0].size(); ++j) {
      // idx = (rIdx * nCols) + cIdx
      std::size_t idx = (i * matrix2D[0].size()) + j;
      matrix[idx] = matrix2D[i][j];
    }
  }

  printMatrix1D(matrix);
  clockwiseRotateMatrix1D(matrix);
}

void printMatrix2D(std::vector<std::vector<int>>& matrix2D) {
  if (matrix2D.empty()) {
    std::cout << "(Empty matrix)\n";
    return;
  }

  for (auto& r : matrix2D) {
    for (auto& e : r) {
      std::cout << e << " ";
    }
    std::cout << "\n";
  }
  std::cout << "\n";
}

void clockwiseRotateMatrix2D(std::vector<std::vector<int>>& matrix) {
  if (matrix.empty()) {
    std::cout << "CW: No rotations possible on empty matrices!\n";
    return;
  }

  std::size_t N{matrix.size()};

  std::vector<std::vector<int>> rotatedMatrix(N, std::vector<int>(N, 0));

  // i, j for rotatedMatrix
  // l = [0, (N-1)]
  // k = [(N-1), 0]
  for (std::size_t i{}, l{}; i < N; ++i, ++l) {
    for (std::size_t j{}, k{N - 1}; j < N; ++j, --k) {
      rotatedMatrix[i][j] = matrix[k][l];
    }
  }

  std::cout << "Clockwise rotation (90^):\n";
  printMatrix2D(rotatedMatrix);
}

void counterClockwiseRotateMatrix2D(std::vector<std::vector<int>>& matrix) {
  if (matrix.empty()) {
    std::cout << "CCW: No rotations possible on empty matrices!\n";
    return;
  }

  std::size_t N{matrix.size()};

  std::vector<std::vector<int>> rotatedMatrix(N, std::vector<int>(N, 0));

  // i, j for rotatedMatrix
  // l = [(N-1), 0]
  // k = [0, (N-1)]
  for (std::size_t i{}, l{N - 1}; i < N; ++i, --l) {
    for (std::size_t j{}, k{}; j < N; ++j, ++k) {
      rotatedMatrix[i][j] = matrix[k][l];
    }
  }

  std::cout << "Counter clockwise rotation (90^):\n";
  printMatrix2D(rotatedMatrix);
}

int main() {
  std::vector<std::vector<int>> matrix1{
      {0, 1, 2, 3}, {4, 5, 6, 7}, {8, 9, 10, 11}, {12, 13, 14, 15}};

  printMatrix2D(matrix1);
  clockwiseRotateMatrix2D(matrix1);
  counterClockwiseRotateMatrix2D(matrix1);
  convert2DTo1DAndRotate(matrix1);

  std::vector<std::vector<int>> matrix2{{0, 1, 2}, {3, 4, 5}, {6, 7, 8}};

  printMatrix2D(matrix2);
  clockwiseRotateMatrix2D(matrix2);
  counterClockwiseRotateMatrix2D(matrix2);
  convert2DTo1DAndRotate(matrix2);

  std::vector<std::vector<int>> matrix3{{0, 1}, {2, 3}};

  printMatrix2D(matrix3);
  clockwiseRotateMatrix2D(matrix3);
  counterClockwiseRotateMatrix2D(matrix3);
  convert2DTo1DAndRotate(matrix3);

  std::vector<std::vector<int>> matrix4{{0}};

  printMatrix2D(matrix4);
  clockwiseRotateMatrix2D(matrix4);
  counterClockwiseRotateMatrix2D(matrix4);
  convert2DTo1DAndRotate(matrix4);

  std::vector<std::vector<int>> matrix5{};

  printMatrix2D(matrix5);
  clockwiseRotateMatrix2D(matrix5);
  counterClockwiseRotateMatrix2D(matrix5);
  convert2DTo1DAndRotate(matrix5);

  return 0;
}