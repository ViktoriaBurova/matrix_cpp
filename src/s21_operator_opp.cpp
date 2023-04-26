#include "s21_matrix_oop.h"

S21Matrix S21Matrix::operator+(const S21Matrix &other){
    S21Matrix matrix(*this);
    matrix.SumMatrix(other);
    return matrix;
}

S21Matrix S21Matrix::operator-(const S21Matrix &other) {
    S21Matrix matrix(*this);
    matrix.SubMatrix(other);
    return matrix;
}

S21Matrix S21Matrix::operator*(const S21Matrix &other) {
    S21Matrix matrix(*this);
    matrix.MulMatrix(other);
    return matrix;
}

S21Matrix S21Matrix::operator*(const double num) {
    S21Matrix matrix(*this);
    matrix.MulNumber(num);
    return matrix;
}

S21Matrix S21Matrix::operator=(const S21Matrix &other) {
    if (*this == other) {
        return *this;
    } else {
        
    }
    // Remove();
    // rows_ = other.getRows(), cols_ = other.getCols();
    // Create();
    // Copy(other);
    // return *this;
}

bool S21Matrix::operator==(const S21Matrix &other) {
    return this->EqMatrix(other);
}

S21Matrix S21Matrix::operator+=(const S21Matrix &other) {
    this->SumMatrix(other);
    return *this;
}

S21Matrix S21Matrix::operator-=(const S21Matrix &other) {
    this->SubMatrix(other);
    return *this;
}

S21Matrix S21Matrix::operator*=(const S21Matrix &other) {
    this->MulMatrix(other);
    return *this;
}

S21Matrix S21Matrix::operator*=(const double num) {
    this->MulNumber(num);
    return *this;
}

double S21Matrix::operator()(int rows, int cols) const {
    // предусмотреть выход за границы матрицы
    return matrix_[rows][cols];
}

double& S21Matrix::operator()(int rows, int cols) {
    // предусмотреть выход за границы матрицы
    return matrix_[rows][cols];
}        