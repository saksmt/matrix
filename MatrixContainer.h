#ifndef MATRIXCONTAINER_H
#define MATRIXCONTAINER_H

#include <vector>
#include <cmath>
#include "MatrixSize.h"

typedef double Number;
typedef std::vector<Number> Mtx_Array;
typedef std::vector<Mtx_Array> Mtx_Mtx;

class MatrixContainer
{
public:
	MatrixSize getSize();
	MatrixContainer();
	MatrixContainer(MatrixSize size);
	MatrixContainer(Mtx_Mtx elements);
	MatrixContainer(const MatrixContainer& elements);
	Number& operator()(size_t i, size_t j);
	~MatrixContainer();
	void swapRows(size_t from, size_t to);
private:
    MatrixSize _size;
    Mtx_Mtx _elements;
};

#endif // MATRIXCONTAINER_H
