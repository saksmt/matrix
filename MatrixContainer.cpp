#include "MatrixContainer.h"

MatrixContainer::MatrixContainer(MatrixSize size)
{
	//this->_elements = Mtx_Mtx(size.getISize(), Mtx_Array(size.getJSize()));
	this->_elements.resize(size.getISize());
	for(size_t i=0; i<size.getISize(); i++) {
		this->_elements[i].resize(size.getJSize());
	}
    this->_size = size;
}

MatrixSize MatrixContainer::getSize()
{
    return _size;
}

MatrixContainer::MatrixContainer(Mtx_Mtx elements)
{
    this->_elements = elements;
	this->_size = MatrixSize(elements.size(), elements[0].size());
}

Number& MatrixContainer::operator()(size_t i, size_t j)
{
    if(i < _size.getISize() && j < _size.getJSize()) {
        return _elements[i][j];
    }
    else {
        throw "Index out of range(from Matrix::operator())";
    }
}

MatrixContainer::~MatrixContainer()
{
}

MatrixContainer::MatrixContainer(const MatrixContainer& elements)
{
	this->_elements = Mtx_Mtx(elements._elements);
	this->_size = elements._size;
}

MatrixContainer::MatrixContainer()
{
	this->_elements = Mtx_Mtx();
}

void MatrixContainer::swapRows(size_t from, size_t to)
{
	Mtx_Array tmp;
	tmp = this->_elements[from];
	this->_elements[from] = this->_elements[to];
	this->_elements[to] = tmp;
}
