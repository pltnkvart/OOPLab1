#include <iostream>
#include "func.h"

using namespace myMatrix;

int main() {
    Matrix matrix = input();
    std::cout << "Sourced matrix:" << std::endl;
    print(matrix);
    Matrix newMatrix = countElements(matrix);
    std::cout << "New matrix:" << std::endl;
    print(newMatrix);
    erase(matrix);
    erase(newMatrix);
    return 0;
}