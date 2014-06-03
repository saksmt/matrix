#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <iomanip>
#include "MatrixContainer.h"

class Matrix
{
  
  /**
   * @class Matrix Matrix.h
   * @author smt <kirillsaksin@yandex.ru>
   * @version 1.0-pre
   * @date 06.2014
   * @copyright The MIT License
   * @brief Matrix logic class
   * 
   * Matrix class, provides functions for basic operations
   * on matrixies, e.g. addition, subtraction, ...
   */
  
public:
	/**
	* Destructor does nothing
	*/
	~Matrix();
	
	/**
	 * Constructs matrix from 2 dimensional vector based array
	 * @param mtx Vector to be constructed from
	 * @exception MatrixException* @see MatrixContainer::MatrixContainer(Mtx_Mtx)
	 */
	Matrix(Mtx_Mtx mtx);
	
	/**
	 * Simply gets size of the matrix
	 * @brief Get size
	 * @return Size of the matrix in @link MatrixSize @endlink
	 */
	MatrixSize getSize();
	
	/**
	 * Constructs matrix from its size
	 * @param mtx Matrix size in @link MatrixSize @endlink
	 */
	Matrix(MatrixSize mtx);
	
	/**
	 * Constructs matrix from its elements in @link MatrixContainer @endlink
	 * @param mtx Matrix elements
	 */
	Matrix(MatrixContainer mtx);
	
	/**
	 * Copy constructor
	 * @param mtx another matrix object
	 */
	Matrix(const Matrix& mtx);
	
	/**
	 * Overload for providing simple acces to the elements at given coordinates
	 * @brief Accesses elements at given coordinates
	 * @param i Matrix row(counting from zero)
	 * @param j Matrix column(counting from zero)
	 * @return Reference to the element
	 * @exception MatrixException* Throws it if index is out of range
	 */
	Number& operator() (size_t i, size_t j);
	
	/**
	 * Alias to overloaded plus operator with integral argument
	 * @brief Addition
	 * @param num Integral value to summarize with
	 */
	void addNumber(Number num);
	
	/**
	 * Alias to overloaded minus operator with integral argument
	 * @brief Subtration
	 * @param num Integral value to subtract
	 */
	void subNumber(Number num);
	
	/**
	 * Alias to overloaded plus operator with another matrix
	 * @brief Addition
	 * @param mtx Matrix to summarize with
	 * @exception MatrixException* Throws it if matrix sizes aren't same
	 */
	void addMatrix(Matrix mtx);
	
	/**
	 * Alias to overloaded minus operator with another matrix
	 * @brief Subtration
	 * @param mtx Matrix to subtract
	 * @exception MatrixException* Throws it if matrix sizes aren't same
	 */
	void subMatrix(Matrix mtx);
	
	/**
	 * Alias to overloaded division operator with integral value
	 * @brief Division
	 * @param num Integral value to divide
	 */
	void divideByNumber(Number num);
	
	/**
	 * Alias to overloaded multiplection operator with integral value
	 * @brief Multiplection
	 * @param num Integral value to multiply
	 */
	void multiplyByNumber(Number num);
	
	/**
	 * Alias to overloaded multiplection operator with another matrix
	 * @brief Multiplection
	 * @param mtx Matrix to multiply
	 * @exception MatrixException* Throws it if matrix sizes aren't possible for multiplection
	 */
	void multiplyByMatrix(Matrix mtx);
	
	/**
	 * Addition
	 * @param mtx Matrix
	 * @param num Integral value
	 * @return Result of addition
	 */
	Matrix addNumberChain(Matrix mtx, Number num);
	
	/**
	 * Subtration
	 * @param mtx Matrix
	 * @param num Integral value
	 * @return Result of subtraction @a num from @a mtx
	 */
	Matrix subNumberChain(Matrix mtx, Number num);
	
	/**
	 * Addition
	 * @param mtx0 First matrix
	 * @param mtx1 Second matrix
	 * @return Result of addition
	 * @exception MatrixException* Throws it if matrix sizes aren't same
	 */
	Matrix addMatrixChain(Matrix mtx0, Matrix mtx1);
	
	/**
	 * Subtration
	 * @param mtx0 First matrix
	 * @param mtx1 Second matrix
	 * @return Result of subtraction @a mtx1 from @a mtx0
	 * @exception MatrixException* Throws it if matrix sizes aren't same
	 */
	Matrix subMatrixChain(Matrix mtx0, Matrix mtx1);
	
	/**
	 * Division
	 * @param mtx Matrix
	 * @param num Integral value
	 * @return Result of division
	 */
	Matrix divideByNumberChain(Matrix mtx, Number num);
	
	/**
	 * Multiplection
	 * @param mtx Matrix
	 * @param num Integral value
	 * @return Result of multiplection
	 */
	Matrix multiplyByNumberChain(Matrix mtx, Number num);
	
	/**
	 * Multiplection
	 * @param mtx0 First matrix
	 * @param mtx1 Second matrix
	 * @return Result of multiplection @a mtx0 by @a mtx1
	 * @exception MatrixException* Throws it if matrix sizes aren't possible for multiplection
	 */
	Matrix multiplyByMatrixChain(Matrix mtx0, Matrix mtx1);
	
	/**
	 * Compute determinant of a matrix if it is possible
	 * @brief Determinant of matrix
	 * @return Integral value representing determinant
	 * @exception MatrixException* Throws it if matrix isn't square
	 */
	Number determinant();
	
	/**
	 * Computes and returns equation answers
	 * @brief Equation answers
	 * @return Equation answers
	 * @exception MatrixException* Throws it if extensional matrix wasn't set or some error occured while computing answers
	 */
	Matrix getEquationAnswers();
	
	/**
	 * Appends extensional matrix need for computing equations
	 * or doing same operations on another matrix while computing gaussian(triangular) matrix
	 * @brief Append extension for matrix
	 * @param mtx Extensional matrix
	 */
	void appendExtensionalMatrix(Matrix mtx);
	
	/**
	 * Computes gaussian(triangular) matrix doing same operations on
	 * extensional matrix if it was setted
	 * @brief Get gaussian(triangular) matrix
	 * @return Gaussian(triangular) matrix
	 */
	Matrix getGaussian();
	
	/**
	 * Transforms current matrix to get transposed one
	 * @brief Trasposes matrix
	 */
	void transpose();
	
	/**
	 * Transforms copy of current matrix to get transposed one
	 * without modification of source
	 * @brief Get transposed matrix
	 * @return Transposed matrix
	 */
	Matrix getTransposed();
	
	/**
	 * Get identity matrix with specified size
	 * @brief Identity matrix
	 * @param size Size of matrix in @link MatrixSize @endlink
	 * @return Identity matrix
	 */
	static Matrix identity(MatrixSize size);
	
	/**
	 * Get diagonal matrix with specified integral value at main diagonal
	 * of specified size in @link MatrixSize @endlink
	 * @brief Diagonal matrix
	 * @param num Integral value to set at main diagonal
	 * @param size Matrix size
	 * @return Diagonal matrix
	 */
	static Matrix diagonal(Number num, MatrixSize size);
	
	/**
	 * Prints matrix in human readable format to standart output
	 * @brief Print matrix
	 */
	void print();
	
	/**
	 * Reads matrix from stream
	 * Format: @example ./example.mtx
	 * @brief Read matrix
	 * @param is Input stram to read from
	 * @param mtx Matrix to write in
	 * @return Input stream
	 */
	friend std::istream& operator>>(std::istream & is, Matrix & mtx);
	
	/**
	 * Save specified matrix to output stream
	 * Format: @example ./example.mtx
	 * @brief Save matrix
	 * @param os Output stream to save to
	 * @param mtx Matrix to save
	 * @return Output stream
	 */
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
	/**
	 * Get transposed matrix @see Matrix::getTransposed
	 */
	Matrix operator~();
	
	/**
	 * Overloaded operator
	 * @see Matrix::multiplyByMatrix
	 */
	void operator*=(Matrix mtx);
	
	/**
	 * Overloaded operator
	 * @see Matrix::addMatrix
	 */
	void operator+=(Matrix mtx);
	
	/**
	 * Overloaded operator
	 * @see Matrix::subMatrix
	 */
	void operator-=(Matrix mtx);
	
	/**
	 * Overloaded operator
	 * @see Matrix::divideByNumber
	 */
	void operator/=(Number num);
	
	/**
	 * Overloaded operator
	 * @see Matrix::multiplyByNumber
	 */
	void operator*=(Number num);
	
	/**
	 * Overloaded operator
	 * @see Matrix::addNumber
	 */
	void operator+=(Number num);
	
	/**
	 * Overloaded operator
	 * @see Matrix::subNumber
	 */
	void operator-=(Number num);
	
	/**
	 * Overloaded operator
	 * @see Matrix::subNumberChain
	 */
	Matrix operator-(Number num);
	
	/**
	 * Overloaded operator
	 * @see Matrix::addNumberChain
	 */
	Matrix operator+(Number num);
	
	/**
	 * Overloaded operator
	 * @see Matrix::multiplyByNumberChain
	 */
	Matrix operator*(Number num);
	
	/**
	 * Overloaded operator
	 * @see Matrix::divideByNumberChain
	 */
	Matrix operator/(Number num);
	
	/**
	 * Overloaded operator
	 * @see Matrix::multiplyByMatrixChain
	 */
	Matrix operator*(Matrix mtx);
	
	/**
	 * Overloaded operator
	 * @see Matrix::subMatrixChain
	 */
	Matrix operator-(Matrix mtx);
	
	/**
	 * Overloaded operator
	 * @see Matrix::addMatrixChain
	 */
	Matrix operator+(Matrix mtx);
};

#endif // MATRIX_H
