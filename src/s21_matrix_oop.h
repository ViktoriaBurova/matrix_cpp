#ifndef SRC_S21_MATRIX_OOP_H_
#define SRC_S21_MATRIX_OOP_H_

#include <iostream>
#include <algorithm>
#include <cmath>

class S21Matrix {
    private:
        int rows_, cols_;
        double **matrix_;
    public:
        S21Matrix();
        S21Matrix(int rows, int cols);
        S21Matrix(const S21Matrix& other);
        S21Matrix(S21Matrix&& other) noexcept;
        ~S21Matrix();

        bool EqMatrix(const S21Matrix& other) const;
        void SumMatrix(const S21Matrix& other);
        void SubMatrix(const S21Matrix& other);
        void MulNumber(const double num);
        void MulMatrix(const S21Matrix& other);
        S21Matrix Transpose();
        S21Matrix CalcComplements();
        double Determinant();
        S21Matrix InverseMatrix();

        int getRows() const;
        int getCols() const;
        void setRows(const int rows);
        void setCols(const int cols);

        S21Matrix operator+(const S21Matrix &other);
        S21Matrix operator-(const S21Matrix &other);
        S21Matrix operator*(const S21Matrix &other);
        S21Matrix operator*(const double num);
        S21Matrix operator=(const S21Matrix &other);
        bool operator==(const S21Matrix &other);
        S21Matrix operator+=(const S21Matrix &other);
        S21Matrix operator-=(const S21Matrix &other);
        S21Matrix operator*=(const S21Matrix &other);
        S21Matrix operator*=(const double num);
        double operator()(int rows, int cols) const ;
        double& operator()(int rows, int cols);
};

#endif  //  SRC_S21_MATRIX_OOP_H_
