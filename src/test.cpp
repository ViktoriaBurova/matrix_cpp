#include "s21_matrix_oop.h"

void printMatrix(S21Matrix &m) {
    for (int i = 0; i < m.get_rows_(); i++) {
        for (int j = 0; j < m.get_cols_(); j++) {
            std::cout << m.matrix_[i][j] << " ";
        }
        std::cout << std::endl;
    }
} 

int main() {
    S21Matrix a(4, 4);
    printMatrix(a);
    S21Matrix b(std::move(a));
    printMatrix(b);
    printMatrix(a);
}