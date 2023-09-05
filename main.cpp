#include <iostream>

struct Element {
    int value;
    int i;
    int j;
    Element *next;
};

struct Matrix {
    int lines;
    int columns;
    Element *head;
    Element *tail;
};

int getInt() {
    int a;
    std::cin >> a;
    if (!std::cin.good()) {
        throw std::runtime_error("Failed to read number");
    }
    return a;
}

void push_back(Matrix &matrix, int value, int i, int j) {
    Element *newElem = new Element;
    newElem->i = i;
    newElem->j = j;
    newElem->value = value;
    if (matrix.head == nullptr) {
        matrix.head = newElem;
    }
    if (matrix.tail != nullptr) {
        matrix.tail->next = newElem;
    }
    matrix.tail = newElem;
}

Matrix countElements(const Matrix &matrix) {
    Matrix newMatrix;
    newMatrix.columns = matrix.columns;
    newMatrix.lines = matrix.lines;
    int count = 0;
    Element *p = matrix.head;
    while (p) {
        Element *curr = matrix.head;
        int data = p->value;
        while (curr != nullptr) {
            if (curr->i == p->i && curr->value == data) {
                count++;
            }
            curr = curr->next;
        }
        if (count >= 2) {
            push_back(newMatrix, p->value, p->i, p->j);
        }
        std::cout << std::endl;
        p = p->next;
        count = 0;
    }
    return newMatrix;
}

void print(const Matrix &matrix) {
    for (int i = 0; i < matrix.lines; ++i) {
        for (int j = 0; j < matrix.columns; ++j) {
            Element *p = matrix.head;
            while (p) {
                if (p->i == i && p->j == j) {
                    std::cout << p->value << " ";
                    break;
                }
                p = p->next;
            }
            if (!p) {
                std::cout << "0 ";
            }
        }
        std::cout << std::endl;
    }
}


Matrix input() {
    Matrix matrix;
    matrix.head = nullptr;
    matrix.tail = nullptr;
    try {
        std::cout << "Enter number of lines: --> ";
        matrix.lines = getInt();
        std::cout << "Enter number of columns: --> ";
        matrix.columns = getInt();
        for (int i = 0; i < matrix.lines; i++) {
            for (int j = 0; j < matrix.columns; j++) {
                std::cout << "Enter value for " << i << " " << j << " position: --> ";
                int value = getInt();
                if (value != 0) push_back(matrix, value, i, j);
            }
        }
    } catch (...) {
        std::cerr << "Error" << std::endl;
        throw;
    }
    return matrix;
}

int main() {
    Matrix matrix;
    matrix = input();
    print(matrix);
    Matrix newMatrix = countElements(matrix);
    print(newMatrix);
    return 0;
}
