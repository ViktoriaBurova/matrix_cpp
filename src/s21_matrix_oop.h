#ifndef SRC_S21_MATRIX_OOP_H_
#define SRC_S21_MATRIX_OOP_H_

#include <iostream>
#include <cstring>

class S21Matrix {
    private:
        int rows_, cols_;
        
    public:
        double **matrix_;
        S21Matrix();
        S21Matrix(int rows, int cols);
        S21Matrix(const S21Matrix& other);
        S21Matrix(S21Matrix&& other);
        ~S21Matrix();

        bool EqMatrix(const S21Matrix& other);
        void SumMatrix(const S21Matrix& other);
        void SubMatrix(const S21Matrix& other);
        void MulNumber(const double num);
        void MulMatrix(const S21Matrix& other);
        S21Matrix Transpose();
        S21Matrix CalcComplements();
        double Determinant();
        S21Matrix InverseMatrix();

        int get_rows_() const;
        int get_cols_() const;
        void set_rows_(const int rows);
        void set_cols_(const int cols);

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

};

#endif  //  SRC_S21_MATRIX_OOP_H_
