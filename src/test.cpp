#include "s21_matrix_oop.h"

void printMatrix(S21Matrix &m) {
    for (int i = 0; i < m.getRows(); i++) {
        for (int j = 0; j < m.getCols(); j++) {
            std::cout << m(i, j) << " ";
        }
        std::cout << std::endl;
    }
}

void fillMatrix(S21Matrix &m) {
    int k = 0;
    for (int i = 0; i < m.getRows(); i++) {
        for (int j = 0; j < m.getCols(); j++) {
            m(i, j) = k;
            k++;
        }
    }
} 

int main() {
    S21Matrix a(2, 3);
    S21Matrix b(3, 2);
    //std::cout << "a" << std::endl;
    //printMatrix(a);
    a(0, 0) = 2;
    a(0, 1) = -3;
    a(0, 2) = 1;
    a(1, 0) = 5;
    a(1, 1) = 4;
    a(1, 2) = -2;

    b(0, 0) = -7;
    b(0, 1) = 5;
    b(1, 0) = 2;
    b(1, 1) = -1;
    b(2, 0) = 4;
    b(2, 1) = 3;

    //fillMatrix(a);
    printMatrix(a);
    std::cout << std::endl;

    //fillMatrix(b);
    printMatrix(b);
    std::cout << std::endl;

    a.MulMatrix(b);
    printMatrix(a);
    std::cout << std::endl;
    // S21Matrix b;
    // b = a;
    // printMatrix(b);
    // std::cout << std::endl;

    // bool c;
    // c = b.EqMatrix(a);
    // std::cout << c << std::endl;

    // b.SubMatrix(a);
    // printMatrix(b);


    // printMatrix(a);
    // S21Matrix b(std::move(a));
    // std::cout << "b" << std::endl;
    // printMatrix(b);
    // std::cout << "a" << std::endl;
    // printMatrix(a);
}