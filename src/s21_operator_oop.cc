#include "s21_matrix_oop.h"

S21Matrix S21Matrix::operator+(const S21Matrix &other) {
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
  }
  for (int i = 0; i < rows_; i++) {
    delete[] matrix_[i];
    matrix_[i] = nullptr;
  }
  delete[] matrix_;
  matrix_ = nullptr;
  rows_ = other.getRows();
  cols_ = other.getCols();
  matrix_ = new double *[rows_]();
  for (int i = 0; i < rows_; i++) {
    matrix_[i] = new double[cols_]();
  }
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = other.matrix_[i][j];
    }
  }
  return *this;
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

double S21Matrix::operator()(int i, int j) const {
  if (i >= 0 && i < rows_ && j >= 0 && j < cols_) {
    return matrix_[i][j];
  } else {
    throw std::invalid_argument("Выход за пределы матрицы!");
  }
}

double &S21Matrix::operator()(int i, int j) {
  if (i >= 0 && i < rows_ && j >= 0 && j < cols_) {
    return matrix_[i][j];
  } else {
    throw std::invalid_argument("Выход за пределы матрицы!");
  }
}