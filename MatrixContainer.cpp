#include "MatrixContainer.h"

MatrixContainer::MatrixContainer(MatrixSize size)
{
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
	for(size_t i=0; i<elements.size(); i++) {
		if(i+1 < elements.size() && elements[i].size() != elements[i+1].size()) {
			throw new MatrixException(MatrixException::Container, "Error constructing matrix, vector isn't balanced");
		}
	}
    this->_elements = elements;
	this->_size = MatrixSize(elements.size(), elements[0].size());
}

Number& MatrixContainer::operator()(size_t i, size_t j)
{
    if(i < _size.getISize() && j < _size.getJSize()) {
        return _elements[i][j];
    }
    else {
        throw new MatrixException(MatrixException::OutOfRange, "Index out of range");
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
	this->_size = MatrixSize(0,0);
}

void MatrixContainer::swapRows(size_t from, size_t to)
{
	if(from >= this->_elements.size() || to >= this->_elements.size()) {
		throw new MatrixException(MatrixException::OutOfRange, "Error swapping rows");
	}
	Mtx_Array tmp;
	tmp = this->_elements[from];
	this->_elements[from] = this->_elements[to];
	this->_elements[to] = tmp;
}
