#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <iomanip>
#include "MatrixContainer.h"

class Matrix
{
public:
	~Matrix();
	
	Matrix(Mtx_Mtx mtx);
	MatrixSize getSize();
	Matrix(MatrixSize mtx);
	Matrix(MatrixContainer mtx);
	Matrix(const Matrix& mtx);
	
	Number& operator() (size_t i, size_t j);
	
	void addNumber(Number num);
	void subNumber(Number num);
	void addMatrix(Matrix mtx);
	void subMatrix(Matrix mtx);
	void divideByNumber(Number num);
	void multiplyByNumber(Number num);
	void multiplyByMatrix(Matrix mtx);
	
	Matrix addNumberChain(Matrix mtx, Number num);
	Matrix subNumberChain(Matrix mtx, Number num);
	Matrix addMatrixChain(Matrix mtx0, Matrix mtx1);
	Matrix subMatrixChain(Matrix mtx0, Matrix mtx1);
	Matrix divideByNumberChain(Matrix mtx, Number num);
	Matrix multiplyByNumberChain(Matrix mtx, Number num);
	Matrix multiplyByMatrixChain(Matrix mtx0, Matrix mtx1);
	
	Number determinant();
	Matrix getEquationAnswers();
	void appendExtensionalMatrix(Matrix mtx);
	Matrix getGaussian();
	
	void transpose();
	Matrix getTransposed();
	
	static Matrix identity(MatrixSize size);
	static Matrix diagonal(Number num, MatrixSize size);
	
	void print();
	friend std::istream& operator>>(std::istream & is, Matrix & mtx);
	friend std::ostream& operator<<(std::ostream & os, Matrix & mtx);
private:
	bool _computeEquation();
	void _computeGaussian();
	
    bool _hasExtension;
    Number _determinant;
    MatrixContainer _gaussian;
    MatrixContainer _elements;
    MatrixContainer _extension;
    MatrixContainer _eqationAnswers;
	
public:
	Matrix operator~();
	
	void operator*=(Matrix mtx);
	void operator+=(Matrix mtx);
	void operator-=(Matrix mtx);
	void operator/=(Number num);
	void operator*=(Number num);
	void operator+=(Number num);
	void operator-=(Number num);
	
	Matrix operator-(Number num);
	Matrix operator+(Number num);
	Matrix operator*(Number num);
	Matrix operator/(Number num);
	Matrix operator*(Matrix mtx);
	Matrix operator-(Matrix mtx);
	Matrix operator+(Matrix mtx);
};

#endif // MATRIX_H
