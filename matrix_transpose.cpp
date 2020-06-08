#include <stdexcept>
#include <iostream>
#include "matrix_transpose.hpp"

std::vector<double> matrixTranspose(const std::vector<double> & matrix, int rows, int columns)
{
  if (matrix.empty())
  {
    return matrix;
  }
  if (rows >=0 && columns >=0 && matrix.size() == rows * columns)
  {
    std::vector<double> transposed(rows * columns);

    for (size_t i = 0; i < rows; ++i)
    {
      for (size_t j = 0; j < columns; ++j)
      {
        transposed[j * rows + i] = matrix[i * columns + j];
      }
    }

    return std::move(transposed);
  }
  else
  {
    throw std::invalid_argument("Given rows and columns does not match the given matrix!\n");
  }
}