#include "matrix_multiply.hpp"
#include <stdexcept>

std::vector<double> matrixMultiply(const std::vector<double> & lhsMatrix, const std::vector<double> & rhsMatrix,
                                   int lhsRows, int lhsColumns, int rhsRows, int rhsColumns)
{
  if (lhsMatrix.empty() || rhsMatrix.empty())
  {
    if (lhsMatrix.size() == rhsMatrix.size())
    {
      return lhsMatrix; // return of empty matrix as both of them are empty
    }
    else
    {
      throw std::invalid_argument("Cannot multiply! One of the given matrixes is empty.\n");
    }
  }
  if ((lhsColumns == rhsRows) && (lhsRows >= 0) && (lhsColumns >= 0) && (rhsRows >= 0) && (rhsColumns >= 0) &&
      (lhsMatrix.size() == lhsRows * lhsColumns) && (rhsMatrix.size() == rhsRows * rhsColumns))
  {
    std::vector<double> multiplied(lhsRows * rhsColumns);

    for (size_t i = 0; i < lhsRows; ++i)
    {
      for (size_t j = 0; j < rhsColumns; ++j)
      {
        multiplied[i * rhsColumns + j] = 0;
        for (size_t k = 0; k < lhsColumns; ++k)
        {
          multiplied[i * rhsColumns + j] += lhsMatrix[i * lhsColumns + k] * rhsMatrix[k * rhsColumns + j];
        }
      }
    }

    return std::move(multiplied);
  }
  else
  {
    throw std::invalid_argument("Cannot multiply! Either given args are not valid or"
                                "given matrixes do not match given parameters.\n");
  }
}