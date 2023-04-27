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
    S21Matrix a(4, 4);
    //std::cout << "a" << std::endl;
    //printMatrix(a);

    fillMatrix(a);
    printMatrix(a);
    S21Matrix b;
    b = a;
    printMatrix(b);

    b.SubMatrix(a);
    printMatrix(b);


    //printMatrix(a);
    // S21Matrix b(std::move(a));
    // std::cout << "b" << std::endl;
    // printMatrix(b);
    // std::cout << "a" << std::endl;
    // printMatrix(a);
}