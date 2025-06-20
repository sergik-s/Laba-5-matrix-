#include "matrix_operations.h"
#include <iostream>
#include <stdexcept>
#include <iomanip>
#include <cstdlib>


void InputSizeMatrix(int32_t& rows, int32_t& columns) {
    std::cout << "Input rows of matrix: ";
    std::cin >> rows;
        
    std::cout << "Input columns of matrix: ";
    std::cin >> columns;
       
    if (rows < 1 || columns < 1) {
        throw std::invalid_argument("Rows and columns must be positive");
    }
}

void CreateMatrix(int32_t**& matrix, int32_t rows, int32_t columns) {
    matrix = new int32_t*[rows];
    for (int32_t i = 0; i < rows; ++i) {
        matrix[i] = new int32_t[columns];
    }
}

void FillMatrix(int32_t** matrix, int32_t rows, int32_t columns) {
    for (int32_t i = 0; i < rows; ++i) {
        for (int32_t j = 0; j < columns; ++j) {
            std::cout << "Element [" << i << "][" << j << "]: ";
            std::cin >> matrix[i][j];
        }
    }
}

void PrintMatrix(int32_t** matrix, int32_t rows, int32_t columns) {
    for (int32_t i = 0; i < rows; ++i) {
        for (int32_t j = 0; j < columns; ++j) {
            std::cout << std::setw(4) << matrix[i][j];
        }
        std::cout << std::endl;
    }
}

void DeleteMatrix(int32_t** matrix, int32_t rows) {
    for (int32_t i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void FindMaxElementLowerRightTriangle(int32_t** matrix, int32_t rows, int32_t cols) {
    if (matrix == nullptr || rows <= 0 || cols <= 0) {
        throw std::invalid_argument("Invalid matrix dimensions");
    }

    int32_t triangle_size = std::min(rows, cols);
    int32_t max_element{}; 
    int32_t max_row = -1;
    int32_t max_col = -1; 

    for (int32_t i = rows - triangle_size; i < rows; ++i) {
        int32_t start_col = cols - (rows - i);
        
        for (int32_t j = start_col; j < cols; ++j) {
            if (matrix[i][j] > max_element) {
                max_element = matrix[i][j];
                max_row = i;
                max_col = j;
            }
        }
    }

    if (max_row != -1) { 
        std::cout << "Max element in lower right triangle: " << max_element 
                  << " at position [" << max_row << "][" << max_col << "]" << std::endl;
    } else {
        std::cout << "No elements in lower right triangle" << std::endl;
    }
}

void MaxElementZeroPosition(int32_t** matrix, int32_t rows, int32_t columns) {
    int32_t matrix_max_element{};
    int32_t max_row = -1;
    int32_t max_col = -1; 
    
    for(int32_t i{}; i < rows; ++i) {
        for(int32_t j{}; j < columns; ++j) {
            if (matrix[i][j] > matrix_max_element) {
                matrix_max_element = matrix[i][j];
                max_row = i;
                max_col = j;
            }
        }
    }
    
    if (max_row == 0 && max_col == 0) {
        std::cout << "Max element is already in the right position!" << std::endl;
    } else {
        for(int32_t j{}; j < columns; ++j) {
            std::swap(matrix[0][j], matrix[max_row][j]);
        }
        for(int32_t i{}; i < rows; ++i) {
            std::swap(matrix[i][0], matrix[i][max_col]);
        }
    }
}

void MaxLocalMaximum(int32_t** matrix, int32_t rows, int32_t columns) {
    int32_t max_val{}; 
    int32_t max_i = -1, max_j = -1;

    for (int32_t i = 0; i < rows; ++i) {
        for (int32_t j = 0; j < columns; ++j) {
            bool is_local_max = true;
            int32_t current = matrix[i][j];

            for (int32_t di = -1; di <= 1; ++di) {
                for (int32_t dj = -1; dj <= 1; ++dj) {
                    if (di == 0 && dj == 0) continue;  
                    int32_t ni = i + di;
                    int32_t nj = j + dj;

                    if (ni >= 0 && ni < rows && nj >= 0 && nj < columns) {
                        if (matrix[ni][nj] >= current) {
                            is_local_max = false;
                            break;
                        }
                    }
                }
                if (!is_local_max) {
                    break;
                }
            }

            if (is_local_max) {
                std::cout << "Local maximum: " << current 
                          << " at position (" << i << ", " << j << ")\n";
                
                if (current > max_val) {
                    max_val = current;
                    max_i = i;
                    max_j = j;
                }
            }
        }
    }

    if (max_i != -1) {
        std::cout << "Maximum local maximum: " << max_val 
                  << " at position (" << max_i << ", " << max_j << ")\n";
    } else {
        std::cout << "No local maxima found.\n";
    }
}

void SecondaryDiagonalProduct(int32_t** matrix, int32_t rows, int32_t columns) {
    int64_t product = 1; 
    for (int32_t i = 0; i < rows; ++i) {
        for (int32_t j = 0; j < columns; ++j) { 
            if (i + j > rows - 1) {
                product *= matrix[i][j];
            }
        }
    }
    std::cout << "Product of elements below secondary diagonal: " << product << std::endl;
}
