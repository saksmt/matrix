#include "MatrixSize.h"

MatrixSize::MatrixSize()
{

}

bool MatrixSize::operator==(const MatrixSize& other)
{
	return (this->_iSize == other._iSize && this->_jSize == other._jSize);
}

size_t MatrixSize::getISize()
{
	return this->_iSize;
}

size_t MatrixSize::getJSize()
{
	return this->_jSize;
}

MatrixSize::MatrixSize(size_t i, size_t j)
{
	this->_iSize = i;
	this->_jSize = j;
}

void MatrixSize::setISize(size_t size)
{
	this->_iSize = size;
}

void MatrixSize::setJSize(size_t size)
{
	this->_jSize = size;
}

bool MatrixSize::operator!=(const MatrixSize& other)
{
	return !this->operator==(other);
}

MatrixSize MatrixSize::operator~()
{
	return this->transpose();
}

MatrixSize MatrixSize::transpose()
{
	return MatrixSize(this->_jSize, this->_iSize);
}

