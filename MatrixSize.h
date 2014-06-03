#ifndef MATRIXSIZE_H
#define MATRIXSIZE_H

#include <stddef.h>
#include "MatrixException.h"

class MatrixSize
{
	/**
	 * @class MatrixSize MatrixSize.h
	 * @author smt <kirillsaksin@yandex.ru>
	 * @version 1.0-pre
	 * @date 06.2014
	 * @copyright The MIT License
	 * @brief Matrix size container
	 * Contains matrix size
	 */
public:
	/**
	 * Default constructor, does nothing
	 */
    MatrixSize();
	
	/**
	 * Get columns count
	 * @return Columns count
	 */
	size_t getJSize();
	
	/**
	 * Get rows count
	 * @return Rows count
	 */
	size_t getISize();
	
	/**
	 * Swap rows count and columns count
	 * @brief Transpose size vector
	 * @return Transposed size
	 */
	MatrixSize transpose();
	
	/**
	 * @see MatrixSize::transpose
	 */
	MatrixSize operator~();
	
	/**
	 * Set columns count
	 * @param size New columns count
	 */
	void setJSize(size_t size);
	
	/**
	 * Set rows count
	 * @param size New rows count
	 */
	void setISize(size_t size);
	
	/**
	 * Constructor from rows and columns count
	 */
	MatrixSize(size_t i, size_t j);
	
	/**
	 * Compare sizes
	 * @param other Another size
	 * @return @a true if sizes are equal, @a false otherwise
	 */
    bool operator==(const MatrixSize& other);
	
	/**
	 * Compare sizes
	 * @param other Another size
	 * @return @a false if sizes are equal, @a true otherwise
	 */
	bool operator!=(const MatrixSize& other);
private:
    size_t _jSize;
    size_t _iSize;
};

#endif // MATRIXSIZE_H
