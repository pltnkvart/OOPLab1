#ifndef LAB1_FUNC_H
#define LAB1_FUNC_H

#include <iostream>

namespace myMatrix{

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
	
    int getInt();
    Matrix input();
    Matrix countElements(const Matrix &matrix);
    void push_back(Matrix &matrix, int value, int i, int j);
    void print(const Matrix &matrix);
    void erase(Matrix &matrix);
}

#endif //LAB1_FUNC_H
