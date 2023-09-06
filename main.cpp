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
    newElem->next = nullptr;
    if (matrix.head == nullptr) {
        matrix.head = newElem;
        matrix.tail = newElem;
    } else {
        matrix.tail->next = newElem;
        matrix.tail = newElem;
    }
}


Matrix countElements(const Matrix &matrix) {
    Matrix newMatrix;
    newMatrix.columns = matrix.columns;
    newMatrix.lines = matrix.lines;
    newMatrix.head = nullptr;
    newMatrix.tail = nullptr;
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
        p = p->next;
        count = 0;
    }
    return newMatrix;
}


void print(const Matrix &matrix) {
    for (int i = 0; i < matrix.lines; ++i) {
        for (int j = 0; j < matrix.columns; ++j) {
            bool printed = false;
            Element *p = matrix.head;
            while (p != nullptr) {
                if (p->i == i && p->j == j) {
                    std::cout << p->value << " ";
                    printed = true;
                    break;
                }
                p = p->next;
            }
            if (!printed) {
                std::cout << "0 ";
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void erase(Matrix &matrix) {
    Element *current = matrix.head;
    while (current) {
        Element *temp = current;
        current = current->next;
        delete temp;
    }
    matrix.head = nullptr;
    matrix.tail = nullptr;
    matrix.lines = 0;
    matrix.columns = 0;
}

Matrix input() {
    Matrix matrix;
    matrix.head = nullptr;
    matrix.tail = nullptr;
    matrix.lines = 0;
    matrix.columns = 0;
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
        erase(matrix);
        throw;
    }
    return matrix;
}

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