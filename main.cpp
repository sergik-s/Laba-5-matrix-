#include <iostream>
#include <stdexcept>
#include "matrix_operations.h"

int main() {
    try {
        int32_t rows{};
        int32_t columns{};
        InputSizeMatrix(rows, columns);
        
        int32_t** matrix{nullptr};
        CreateMatrix(matrix, rows, columns);
        
        std::cout << "Enter matrix elements:" << std::endl;
        FillMatrix(matrix, rows, columns);
        
        char choice;
        std::cout << "Input variant of laboratory work: 1.1(1) or 1.2(2), 2.1(3) or 2.2(4)" << std::endl;
        std::cin >> choice;
        
        switch(choice) {
            case '1':
                FindMaxElementLowerRightTriangle(matrix, rows, columns);
                PrintMatrix(matrix, rows, columns);
                break;
            case '2':
                MaxElementZeroPosition(matrix, rows, columns);
                PrintMatrix(matrix, rows, columns);
                break;
            case '3':
                MaxLocalMaximum(matrix, rows, columns);
                PrintMatrix(matrix, rows, columns);
                break;
            case '4':
                SecondaryDiagonalProduct(matrix, rows, columns);
                PrintMatrix(matrix, rows, columns);
                break;
            default:
                std::cout << "Invalid choice\n";
                break;
        }
        
        DeleteMatrix(matrix, rows);
        return 0;
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    catch (const std::bad_alloc& e) {
        std::cerr << "Memory allocation error: " << e.what() << std::endl;
    }
    catch (...) {
        std::cerr << "Unknown error occurred" << std::endl;
    }
}
