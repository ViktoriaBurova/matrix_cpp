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
        throw std::invalid_argument("Неправильная размерность матрицы!");
    }
}

S21Matrix::S21Matrix(const S21Matrix& other) : S21Matrix(other.rows_, other.cols_) {
        rows_ = other.rows_;
        cols_ = other.cols_;
        memcpy(matrix_, other.matrix_, other.rows_ * other.cols_ * sizeof(double));
}

S21Matrix::S21Matrix(S21Matrix&& other) : S21Matrix(other) {
    // if (other.rows_ > 0 && other.cols_ > 0) {
    //     rows_ = other.rows_;
    //     cols_ = other.cols_;
    //     matrix_ = move(other.matrix_);
    // }

    // for (int i = 0; i < other.rows_; i++) {
    //     delete[] other.matrix_[i];
    // }
    // delete[] other.matrix_;
    // other.cols_ = 0;
    // other.rows_ = 0;

    // rows_ = other.rows_;
    // cols_ = other.cols_;
    // matrix_ = other.matrix_;
    // other.rows_ = other.cols_ = 0;
    // other.matrix_ = nullptr;
}

S21Matrix::~S21Matrix() {
    for (int i = 0; i < rows_; i++) {
        delete[] matrix_[i];
    }
    delete[] matrix_;
    cols_ = 0;
    rows_ = 0;
}

int S21Matrix::get_rows_() const {
    return rows_;
}

int S21Matrix::get_cols_() const {
    return cols_;
}

void S21Matrix::set_rows_(int rows) {
    rows_ = std::move(rows);
}

void S21Matrix::set_cols_(int cols) {
    cols_ = std::move(cols);
}

bool S21Matrix::EqMatrix(const S21Matrix& other) {

}

void S21Matrix::SumMatrix(const S21Matrix& other) {
    if (rows_ == other.get_rows_() || cols_ == other.get_cols_()) {
        for (int i = 0; i < rows_; i++) {
            for (int j = 0; j < cols_; j++) {
                matrix_[i][j] += other(i, j);
            }
        }
    } else {
        throw std::invalid_argument("Разный размер матриц!");
    }
}

void S21Matrix::SubMatrix(const S21Matrix& other) {
    if (rows_ == other.get_rows_() || cols_ == other.get_cols_()) {
        for (int i = 0; i < rows_; i++) {
            for (int j = 0; j < cols_; j++) {
                matrix_[i][j] -= other(i, j);
            }
        }
    } else {
        throw std::invalid_argument("Разный размер матриц!");
    }
}

void S21Matrix::MulNumber(const double num) {

}

void S21Matrix::MulMatrix(const S21Matrix& other) {

}

S21Matrix S21Matrix::Transpose() {

}

S21Matrix S21Matrix::CalcComplements() {

}

double S21Matrix::Determinant() {

}

S21Matrix S21Matrix::InverseMatrix() {

}
