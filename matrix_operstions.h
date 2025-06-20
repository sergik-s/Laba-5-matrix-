#ifndef MATRIX_OPERATIONS_H
#define MATRIX_OPERATIONS_H

#include <cstdint>

void InputSizeMatrix(int32_t& rows, int32_t& columns);
void CreateMatrix(int32_t**& matrix, int32_t rows, int32_t columns);
void FindMaxElementLowerRightTriangle(int32_t** matrix, int32_t rows, int32_t cols);
void MaxElementZeroPosition(int32_t** matrix, int32_t rows, int32_t columns);
void MaxLocalMaximum(int32_t** matrix, int32_t rows, int32_t columns);
void SecondaryDiagonalProduct(int32_t** matrix, int32_t rows, int32_t columns);
void DeleteMatrix(int32_t** matrix, int32_t rows);
void FillMatrix(int32_t** matrix, int32_t rows, int32_t columns);
void PrintMatrix(int32_t** matrix, int32_t rows, int32_t columns);

#endif 
