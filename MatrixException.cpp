#include "MatrixException.h"

MatrixException::~MatrixException()
{
	delete [] this->_errorMessage;
}

const char* MatrixException::getMessage()
{
	return this->_errorMessage;
}

MatrixException::MatrixExceptionType MatrixException::getType()
{
	return this->_type;
}

MatrixException::MatrixException(MatrixException::MatrixExceptionType type, const char* message)
{
	this->_type = type;
	this->_errorMessage = message;
}
