#include "matrix_norm.hpp"
#include <cmath>
#include <stdexcept>
#include <algorithm>

double matrixNorm(const std::vector<double> & matrix, int rows, int columns, int numNorm)
{
  if (matrix.empty())
  {
    return 0;
  }
  else if (rows >=0 && columns >=0 && matrix.size() == rows * columns)
  {
    switch (numNorm)
    {
    case 1:
    {
      std::vector<double> sumOfIStr(rows);
      for (size_t i = 0; i < rows; ++i)
      {
        sumOfIStr[i] = 0;
        for (size_t j = 0; j < columns; ++j)
        {
          sumOfIStr[i] += fabs(matrix[i * columns + j]);
        }
      }
      return *std::max_element(sumOfIStr.begin(), sumOfIStr.end());
    }
    break;

    case 2:
    {
      std::vector<double> sumOfIStr(columns);
      for (size_t i = 0; i < columns; ++i)
      {
        sumOfIStr[i] = 0;
        for (size_t j = 0; j < rows; ++j)
        {
          sumOfIStr[i] += fabs(matrix[j * columns + i]);
        }
      }
      return *std::max_element(sumOfIStr.begin(), sumOfIStr.end());
    }
    break;

    case 3:
    {
      double norm = 0;
      for (double i: matrix)
      {
        norm += i * i;
      }
      return sqrt(norm);
    }
    break;

    default:
    {
      throw std::invalid_argument("Number of the norm can be only 1, 2 or 3!\n");
    }
    }
  }
  else
  {
    throw std::invalid_argument("Given rows and columns does not match the given matrix!\n");
  }
}