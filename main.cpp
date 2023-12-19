#include <iostream>
#include "func.h"

using namespace myMatrix;

int main() {
	Matrix matrix;
	Matrix newMatrix;
    try {
        matrix = input();
        std::cout << "Sourced matrix:" << std::endl;
        print(matrix);
        newMatrix = countElements(matrix);
        std::cout << "New matrix:" << std::endl;
        print(newMatrix);
        erase(matrix);
        erase(newMatrix);
    } catch(...) {
        std::cout << "Error" << std::endl;
        return 1;
    }
    return 0;
}
