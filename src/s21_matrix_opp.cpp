#include "s21_matrix_oop.h"

S21Matrix::S21Matrix() {
    rows_ = 3;
    cols_ = 3;
    matrix_ = new double*[rows_]();
    for (int i = 0; i < rows_; i++) {
        matrix_[i] = new double[cols_]();
    }
}

S21Matrix::S21Matrix(int rows, int cols) {
    if (rows > 0 && cols > 0) {
        rows_ = rows;
        cols_ = cols;
        matrix_ = new double*[rows_]();
        for (int i = 0; i < rows_; i++) {
            matrix_[i] = new double[cols_]();
        }
    } else {
        throw invalid_argument("Неправильная размерность матрицы!");
    }
}

S21Matrix::S21Matrix(const S21Matrix& other) : S21Matrix(other.rows_, other.cols_) {
    if (other.rows_ > 0 && other.cols_ > 0) {
        rows_ = other.rows_;
        cols_ = other.cols_;
        memcpy(matrix_, other.matrix_, other.rows_ * other.cols_ * sizeof(double));
    }
}

S21Matrix::S21Matrix(S21Matrix&& other) {
    move();
}

S21Matrix::~S21Matrix() {

}