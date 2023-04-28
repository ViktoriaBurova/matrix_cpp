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
    for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < cols_; j++) {
            matrix_[i][j] = other.matrix_[i][j];
        }
    }
}

S21Matrix::S21Matrix(S21Matrix&& other) noexcept {
    std::swap(rows_, other.rows_);
    std::swap(cols_, other.cols_);
    std::swap(matrix_, other.matrix_);
}

S21Matrix::~S21Matrix() {
    for (int i = 0; i < rows_; i++) {
        delete[] matrix_[i];
        matrix_[i] = nullptr;
    }
    delete[] matrix_;
    matrix_ = nullptr;
    cols_ = 0;
    rows_ = 0;
}

int S21Matrix::getRows() const {
    return rows_;
}

int S21Matrix::getCols() const {
    return cols_;
}

void S21Matrix::setRows(const int rows) {
    if (rows >= 1) {
        S21Matrix other(rows, cols_);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols_; j++) {
                if (i < rows_) {
                    other.matrix_[i][j] = matrix_[i][j];
                }
            }
        }
        *this = other;
    } else {
        throw std::invalid_argument("Строка меньше единицы!");
    }
}

void S21Matrix::setCols(const int cols) {
    if (cols >= 1) {
        S21Matrix other(rows_, cols);
        for (int i = 0; i < rows_; i++) {
            for (int j = 0; j < cols; j++) {
                if (j < cols_) {
                    other.matrix_[i][j] = matrix_[i][j];
                }
            }
        }
        *this = other;
    } else {
        throw std::invalid_argument("Столбец меньше единицы!");
    }
}

bool S21Matrix::EqMatrix(const S21Matrix& other) const {
    int res = false;
    int count = 0;
    if (rows_ == other.getRows() && cols_ == other.getCols()) {
        for (int i = 0; i < rows_; i++) {
            for (int j = 0; j < cols_; j++) {
                if (fabs(matrix_[i][j] - other.matrix_[i][j]) <= 1e-6) {
                    count++;
                }
            }
        }
        if (count == (cols_ * rows_)) {
            res = true;
        }
    }
    return res;
}

void S21Matrix::SumMatrix(const S21Matrix& other) {
    if (rows_ == other.getRows() && cols_ == other.getCols()) {
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
    if (rows_ == other.getRows() && cols_ == other.getCols()) {
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
    if (cols_ == other.getRows()) {
        for (int i = 0; i < rows_; i++) {
            for (int j = 0; j < other.getCols(); j++) {
                int sum = 0;
                for (int m = 0; m < other.getRows(); m++) {
                    sum = sum + matrix_[i][m] * other.matrix_[m][j];
                }
                matrix_[i][j] = sum;
            }
        }
    }
}

S21Matrix S21Matrix::Transpose() {

}

S21Matrix S21Matrix::CalcComplements() {

}

double S21Matrix::Determinant() {

}

S21Matrix S21Matrix::InverseMatrix() {

}
