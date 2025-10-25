#ifndef MATRIX_TEMPLATE_CLASS_MATRIX_H
#define MATRIX_TEMPLATE_CLASS_MATRIX_H
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <random>
#include "Point.h"

constexpr int MIN_RAND = -50;
constexpr int MAX_RAND = 120;

template <class ValuesType = int>
class Matrix {
    ValuesType** arr = nullptr;
    int rows = 0, cols = 0;
    int GenerateNum() const { return rand() % (MAX_RAND - MIN_RAND + 1) + MIN_RAND; }

    double GenerateDecimal() const;
public:
    Matrix(int rows, int cols);
    Matrix(int rows, int cols) requires std::same_as<ValuesType, Point>;
    Matrix<ValuesType>& operator+=(int value);
    Matrix<ValuesType>& operator-=(int value);
    Matrix<ValuesType>& operator*=(int value);
    Matrix<ValuesType>& operator/=(int value);
    void Print() const;
    ~Matrix();
};
#endif


template<class ValuesType>
double Matrix<ValuesType>::GenerateDecimal() const{
    std::random_device rd;
    std::default_random_engine generator(rd());
    std::uniform_real_distribution<double> distribution(MIN_RAND,MAX_RAND);

    return round(distribution(generator) * 10.0) / 10.0;
}

template<class ValuesType>
Matrix<ValuesType>::Matrix(int rows, int cols) {
    arr = new ValuesType*[rows];
    this->rows = rows;
    this->cols = cols;
    for (int i = 0; i < rows; ++i)
        arr[i] = new ValuesType[cols];

    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j) {
            if constexpr (std::is_same_v<ValuesType, int>) arr[i][j] = GenerateNum();
            else arr[i][j] = GenerateDecimal();

        }
}

template<class ValuesType>
Matrix<ValuesType>::Matrix(int rows, int cols) requires std::same_as<ValuesType, Point> {
    arr = new ValuesType*[rows];
    this->rows = rows;
    this->cols = cols;

    for (int i = 0; i < rows; ++i) {
        arr[i] = new ValuesType[cols];
        for (int j = 0; j < cols; ++j) {
            arr[i][j] = Point(GenerateNum(), GenerateNum());
        }
    }


}

template<class ValuesType>
Matrix<ValuesType>& Matrix<ValuesType>::operator+=(const int value) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j)
            arr[i][j] += value;
    }
    return *this;

}

template<class ValuesType>
Matrix<ValuesType>& Matrix<ValuesType>::operator-=(const int value) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j)
            arr[i][j] -= value;
    }
    return *this;

}

template<class ValuesType>
Matrix<ValuesType>& Matrix<ValuesType>::operator*=(const int value) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j)
            arr[i][j] *= value;
    }
    return *this;

}

template<class ValuesType>
Matrix<ValuesType>& Matrix<ValuesType>::operator/=(const int value) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j)
            arr[i][j] /= value;
    }
    return *this;

}

template<class ValuesType>
void Matrix<ValuesType>::Print() const {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j)
            std::cout << std::setw(3) << arr[i][j] << " | ";
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

template<class ValuesType>
Matrix<ValuesType>::~Matrix() {
    for (int i = 0; i < rows; ++i) delete[] arr[i];
    delete[] arr;
}
