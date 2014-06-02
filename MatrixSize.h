#ifndef MATRIXSIZE_H
#define MATRIXSIZE_H

#include <stddef.h>

class MatrixSize
{
public:
    MatrixSize();
	size_t getJSize();
	size_t getISize();
	MatrixSize transpose();
	MatrixSize operator~();
	void setJSize(size_t size);
	void setISize(size_t size);
	MatrixSize(size_t i, size_t j);
    bool operator==(const MatrixSize& other);
	bool operator!=(const MatrixSize& other);
private:
    size_t _jSize;
    size_t _iSize;
};

#endif // MATRIXSIZE_H
