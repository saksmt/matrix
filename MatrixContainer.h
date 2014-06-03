#ifndef MATRIXCONTAINER_H
#define MATRIXCONTAINER_H

#include <vector>
#include <cmath>
#include "MatrixSize.h"

/**
 * You can change this line if you want to use another base type
 */
typedef double Number;

/**
 * Needed to write less
 */
typedef std::vector<Number> Mtx_Array;

/**
 * Same thing, I don't want to write "std::vector< std::vector< Number > >"
 * it is to long, even using IDE
 */
typedef std::vector<Mtx_Array> Mtx_Mtx;

class MatrixContainer
{
	/**
	 * @class MatrixContainer MatrixContainer.h
	 * @author smt <kirillsaksin@yandex.ru>
	 * @version 1.0-pre
     * @date 06.2014
     * @copyright The MIT License
	 * @brief Container class for matrixies
	 * Contains double vector and @link MatrixSize @endlink
	 */
public:
	/**
	 * Default constructor
	 */
	MatrixContainer();
	
	/**
	 * Default destructructor, does nothing
	 */
	~MatrixContainer();
	
	/**
	 * Get matrix size in @link MatrixSize @endlink
	 * @brief Matrix size
	 * @return Matrix size
	 */
	MatrixSize getSize();
	
	/**
	 * Constructs matrix from its size
	 * @param size Matrix size in @link MatrixSize @endlink
	 */
	MatrixContainer(MatrixSize size);
	
	/**
	 * Constructs matrix from its elements in @link MatrixContainer @endlink
	 * @brief Matrix from elements
	 * @param elements Matrix elements
	 */
	MatrixContainer(Mtx_Mtx elements);
	
	/**
	 * Swap row with index @a from with row with index @a to
	 * @brief Swap rows
	 * @param from First index
	 * @param to Second index
	 */
	void swapRows(size_t from, size_t to);
	
	/**
	 * Overload for providing simple acces to the elements at given coordinates
	 * @brief Accesses elements at given coordinates
	 * @param i Matrix row(counting from zero)
	 * @param j Matrix column(counting from zero)
	 * @return Reference to the element
	 * @exception MatrixException* Throws it if index is out of range
	 */
	Number& operator()(size_t i, size_t j);
	
	/**
	 * Copy constructor
	 * @param elements Another object
	 */
	MatrixContainer(const MatrixContainer& elements);
private:
    MatrixSize _size;
    Mtx_Mtx _elements;
};

#endif // MATRIXCONTAINER_H
