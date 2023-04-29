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

S21Matrix::S21Matrix(const S21Matrix& other)
    : S21Matrix(other.rows_, other.cols_) {
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
  other.cols_ = 0;
  other.rows_ = 0;
  other.matrix_ = nullptr;
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

int S21Matrix::getRows() const { return rows_; }

int S21Matrix::getCols() const { return cols_; }

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
        if (fabs(matrix_[i][j] - other.matrix_[i][j]) <= 1e-7) {
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
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] *= num;
    }
  }
}

void S21Matrix::MulMatrix(const S21Matrix& other) {
  if (cols_ == other.getRows()) {
    S21Matrix result(rows_, other.getCols());
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < other.getCols(); j++) {
        int sum = 0;
        for (int m = 0; m < other.getRows(); m++) {
          sum += matrix_[i][m] * other.matrix_[m][j];
        }
        result.matrix_[i][j] = sum;
      }
    }
    *this = result;
  } else {
    throw std::invalid_argument("Разный размер матриц!");
  }
}

S21Matrix S21Matrix::Transpose() const {
  S21Matrix result(cols_, rows_);
  for (int i = 0; i < result.rows_; i++) {
    for (int j = 0; j < result.cols_; j++) {
      result.matrix_[i][j] = matrix_[j][i];
    }
  }
  return result;
}

double S21Matrix::Determinant() const {
  double result = 0;
  if (cols_ == rows_) {
    if (cols_ == 2) {
      result = matrix_[0][0] * matrix_[1][1] - matrix_[0][1] * matrix_[1][0];
    }
    if (cols_ == 1) {
      result = matrix_[0][0];
    }
    if (cols_ > 2) {
      S21Matrix minor(rows_ - 1, cols_ - 1);
      double determinant = 0;
      for (int j = 0; j < rows_; j++) {
        for (int n = 0; n < rows_ - 1; n++) {
          for (int m = 0; m < rows_ - 1; m++) {
            if (m >= j) {
              minor.matrix_[n][m] = matrix_[n + 1][m + 1];
            } else {
              minor.matrix_[n][m] = matrix_[n + 1][m];
            }
          }
        }
        result = minor.Determinant();
        determinant += matrix_[0][j] * result * pow(-1, j);
      }
      result = determinant;
    }
  } else {
    throw std::invalid_argument("Неправильная размерность матрицы!");
  }
  return result;
}

S21Matrix S21Matrix::CalcComplements() const {
  S21Matrix result(rows_, cols_);
  if (cols_ == rows_) {
    S21Matrix minor(rows_ - 1, cols_ - 1);
    double determinant = 0;
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < rows_; j++) {
        for (int n = 0; n < rows_ - 1; n++) {
          for (int m = 0; m < rows_ - 1; m++) {
            if (n < i && m < j) {
              minor.matrix_[n][m] = matrix_[n][m];
            } else if (n < i && m >= j) {
              minor.matrix_[n][m] = matrix_[n][m + 1];
            } else if (n >= i && m < j) {
              minor.matrix_[n][m] = matrix_[n + 1][m];
            } else if (n >= i && m >= j) {
              minor.matrix_[n][m] = matrix_[n + 1][m + 1];
            }
          }
        }
        determinant = minor.Determinant();
        result.matrix_[i][j] = determinant * pow(-1, j + i);
      }
    }
  } else {
    throw std::invalid_argument("Неправильная размерность матрицы!");
  }
  return result;
}

S21Matrix S21Matrix::InverseMatrix() const {
  if (cols_ == rows_) {
    double determinant = Determinant();
    if (fabs(determinant) > 1e-7) {
      S21Matrix calc_complements(CalcComplements());
      S21Matrix transpose(calc_complements.Transpose());
      return transpose * (1. / determinant);
    } else {
      throw std::invalid_argument("Определитель матрицы равен 0!");
    }
  } else {
    throw std::invalid_argument("Неправильная размерность матрицы!");
  }
}
