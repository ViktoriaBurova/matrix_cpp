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