#include "Matrix.h"

Matrix::Matrix(MatrixSize mtx)
{
	this->_elements = MatrixContainer(mtx);
	this->_gaussian = MatrixContainer(mtx);
	this->_determinant = Number(NAN);
	this->_hasExtension = false;
}

Matrix::Matrix(Mtx_Mtx mtx)
{
	this->_elements = MatrixContainer(mtx);
	this->_gaussian = MatrixContainer(this->_elements.getSize());
	this->_determinant = Number(NAN);
	this->_hasExtension = false;
}

Matrix::Matrix(MatrixContainer mtx)
{
	this->_elements = MatrixContainer(mtx);
	this->_gaussian = MatrixContainer(mtx.getSize());
	this->_determinant = Number(NAN);
	this->_hasExtension = false;
}

Matrix::~Matrix()
{
}

Number& Matrix::operator()(size_t i, size_t j)
{
	return this->_elements(i,j);
}

MatrixSize Matrix::getSize()
{
	return this->_elements.getSize();
}

bool Matrix::_computeEquation()
{
	if(this->determinant() == 0) {
		return false;
	}
	size_t k = this->getSize().getISize()-1, j;
	Number tmp;
	MatrixContainer result(MatrixSize(this->getSize().getISize(),1));
	result(this->getSize().getISize()-1,0) = this->_extension(this->getSize().getISize()-1,0)/this->_gaussian(this->getSize().getISize()-1,this->getSize().getJSize()-1);
	do {
		tmp = 0;
		for(j = k+1; j<this->getSize().getISize(); j++) {
			tmp += this->_gaussian(k,j)*result(j,0);
		}
		result(k,0) = (this->_extension(k,0)-tmp)/this->_gaussian(k,k);
	} while(k-- != 0);
	this->_eqationAnswers = MatrixContainer(result);
	return true;
}

void Matrix::_computeGaussian()
{
	if(this->getSize().getISize() != this->getSize().getJSize()) {
		return;
	}
	size_t i=0, j=0, k;
	this->_gaussian = MatrixContainer(this->_elements);
	Number tmp;
	
	for(i=0; i<this->getSize().getISize(); i++) {
		if(this->_gaussian(i,i) == 0) {
			bool error = true;
			for(j=0; j<this->getSize().getJSize(); j++) {
				if(this->_gaussian(j,i) !=0) {
					error = false;
					this->_gaussian.swapRows(i,j);
					if(this->_hasExtension) {
						this->_extension.swapRows(i,j);
					}
					break;
				}
			}
			if(error) {
				this->_determinant = 0;
				this->_gaussian = MatrixContainer();
				return;
			}
		}
	}
	
	for(i=0;i<this->getSize().getISize()-1;i++){
        for(j=i+1;j<this->getSize().getISize();j++){
			tmp = this->_gaussian(j,i)/this->_gaussian(i,i);
			if(this->_hasExtension) {
				for(k=0; k<this->_extension.getSize().getJSize(); k++) {
					this->_extension(j,k) -= this->_extension(i,k)*tmp;
				}
			}
            for(k=i;k<this->getSize().getISize();k++){
				this->_gaussian(j,k) -= tmp*this->_gaussian(i,k);
            }
        }
    }
	
	Number det=1;
	for(i=0; i<this->getSize().getISize(); i++) {
		det *= this->_gaussian(i,i);
	}
	this->_determinant = det;
}

void Matrix::addMatrix(Matrix mtx)
{
	if(this->getSize() != mtx.getSize()) {
		throw new MatrixException(MatrixException::Container, "Error: Matrixes must be same size(Matrix::addMatrix)");
		return;
	}
	else {
		for(size_t i=0; i<this->_elements.getSize().getISize(); i++) {
			for(size_t j=0; j<this->_elements.getSize().getJSize(); j++) {
				this->operator()(i,j) += mtx(i,j);
			}
		}
	}
}

Matrix Matrix::addMatrixChain(Matrix mtx0, Matrix mtx1)
{
	if(mtx0.getSize() != mtx1.getSize()) {
		throw new MatrixException(MatrixException::Container, "Error: Matrixes must be same size(Matrix::addMatrixChain)");
	}
	else {
		Matrix result(mtx0.getSize());
		for(size_t i=0; i<mtx0.getSize().getISize(); i++) {
			for(size_t j=0; j<mtx0.getSize().getJSize(); j++) {
				result(i,j) = (mtx0(i,j)+mtx1(i,j));
			}
		}
		return result;
	}
}

void Matrix::addNumber(Number num)
{
	this->addMatrix(Matrix::diagonal(num, this->getSize()));
}

Matrix Matrix::addNumberChain(Matrix mtx, Number num)
{
	return this->addMatrixChain(mtx, Matrix::diagonal(num, mtx.getSize()));
}

void Matrix::appendExtensionalMatrix(Matrix mtx)
{
	if(mtx.getSize().getISize() != this->getSize().getISize()) {
		throw new MatrixException(MatrixException::Container, "Extensional matrix must have same \"height\" as main");
	}
	this->_extension = mtx._elements;
	this->_hasExtension = true;
}

Number Matrix::determinant()
{
	if(isnan(this->_determinant)) {
		this->_computeGaussian();
	}
	if(isnan(this->_determinant)) {
		throw new MatrixException(MatrixException::Logical, "Error computing determinant");
	}
	return this->_determinant;
}

Matrix Matrix::diagonal(Number num, MatrixSize size)
{
	Matrix newMtx(size);
	size_t s = ((size.getISize() <= size.getJSize())?size.getISize():size.getJSize());
	for(size_t i=0; i<s; i++) {
		newMtx(i,i) = num;
	}
	return newMtx;
}

void Matrix::divideByNumber(Number num)
{
	for(size_t i=0; i<this->getSize().getISize(); i++) {
		for(size_t j=0; j<this->getSize().getJSize(); j++) {
			this->_elements(i,j) /= num;
		}
	}
}

Matrix Matrix::divideByNumberChain(Matrix mtx, Number num)
{
	for(size_t i=0; i<mtx.getSize().getISize(); i++) {
		for(size_t j=0; j<mtx.getSize().getJSize(); j++) {
			mtx(i,j) /= num;
		}
	}
	return mtx;
}

Matrix Matrix::getEquationAnswers()
{
	if(this->_computeEquation()) {
		return this->_eqationAnswers;
	}
	throw new MatrixException(MatrixException::Logical, "Logical error while computing equation system");
}

Matrix Matrix::getTransposed()
{
	Matrix mtx(~this->getSize());
	for(size_t i=0; i<this->getSize().getISize(); i++) {
        for(size_t j=0; j<this->getSize().getJSize(); j++) {
			mtx(j,i) = this->_elements(i,j);
		}
	}
	return mtx;
}

Matrix Matrix::identity(MatrixSize size)
{
	return Matrix::diagonal(Number(1),size);
}

void Matrix::multiplyByMatrix(Matrix mtx)
{
	(*this) = (*this)*mtx;
}

Matrix Matrix::multiplyByMatrixChain(Matrix mtx0, Matrix mtx1)
{
	if(mtx0.getSize().getJSize() != mtx1.getSize().getISize()) {
		throw new MatrixException(MatrixException::Container, "Matrixies sizes are incompatible for multiplection");
	}
	Matrix result(MatrixSize(mtx0.getSize().getISize(), mtx1.getSize().getJSize()));
	for(size_t i=0; i<mtx0.getSize().getISize(); i++) {
		for(size_t j=0; j<mtx1.getSize().getJSize(); j++) {
			Number lineRes = 0;
			for(size_t iter=0; iter<mtx0.getSize().getJSize(); iter++) {
				lineRes += mtx0(i,iter)*mtx1(iter,j);
			}
			result(i,j) = lineRes;
		}
	}
	return result;
}

void Matrix::multiplyByNumber(Number num)
{
	for(size_t i=0; i<this->getSize().getISize(); i++) {
		for(size_t j=0; j<this->getSize().getJSize(); j++) {
			this->_elements(i,j) *= num;
		}
	}
}

Matrix Matrix::multiplyByNumberChain(Matrix mtx, Number num)
{
	for(size_t i=0; i<mtx.getSize().getISize(); i++) {
		for(size_t j=0; j<mtx.getSize().getJSize(); j++) {
			mtx(i,j) *= num;
		}
	}
}

void Matrix::subMatrix(Matrix mtx)
{
	if(this->getSize() != mtx.getSize()) {
		throw new MatrixException(MatrixException::Container, "Error matrixies must be the same size(Matrix::subMatrix)");
	}
	for(size_t i=0; i<mtx.getSize().getISize(); i++) {
		for(size_t j=0; j<mtx.getSize().getJSize(); j++) {
			this->_elements(i,j) -= mtx(i,j);
		}
	}
}

Matrix Matrix::subMatrixChain(Matrix mtx0, Matrix mtx1)
{
	if(mtx0.getSize() != mtx1.getSize()) {
		throw new MatrixException(MatrixException::Container, "Error matrixies must be the same size(Matrix::subMatrixChain)");
	}
	Matrix mtx(mtx0.getSize());
	for(size_t i=0; i<mtx0.getSize().getISize(); i++) {
		for(size_t j=0; j<mtx0.getSize().getJSize(); j++) {
			mtx(i,j) = mtx0(i,j)-mtx1(i,j);
		}
	}
}

void Matrix::subNumber(Number num)
{
	this->subMatrix(Matrix::diagonal(num, this->getSize()));
}

Matrix Matrix::subNumberChain(Matrix mtx, Number num)
{
	return this->subMatrixChain(mtx, Matrix::diagonal(num, mtx.getSize()));
}

void Matrix::transpose()
{
	(*this) = this->getTransposed();
}

Matrix::Matrix(const Matrix& mtx)
{
	this->_elements = MatrixContainer(mtx._elements);
	this->_determinant = Number(NAN);
	this->_gaussian = MatrixContainer(this->getSize());
	this->_hasExtension = false;
}

std::ostream& operator<<(std::ostream & os, Matrix & mtx)
{
	for(size_t i=0; i<mtx.getSize().getISize(); i++) {
		for(size_t j=0; j<mtx.getSize().getJSize(); j++) {
			os << mtx(i,j);
			if(mtx.getSize().getJSize()-1 != j) {
				os << ' ';
			}
		}
		os << ';';
	}
	return os;
}

std::istream& operator>>(std::istream & is, Matrix & mtx)
{
	Mtx_Mtx m(1, Mtx_Array(0));
	Number tmp;
	while(!is.eof())
    {
        is >> tmp;
        m.back().push_back(tmp);
        if(is.peek() == ';')
        {
            m.push_back(Mtx_Array());
            is.ignore(1);
        }
    }
    m.erase(m.end());
	mtx = Matrix(m);
	return is;
}

void Matrix::print()
{
	char * border = "||";
	char * ltborder = "||";
	char * rtborder = "||";
	char * lbborder = "||";
	char * rbborder = "||";
#ifdef __unix
	border = "│";
	ltborder = "╭";
	rtborder = "╮";
	lbborder = "╰";
	rbborder = "╯";
#endif
	for(size_t i=0; i<this->getSize().getISize(); i++) {
		std::cout << std::setw(2);
		if(i == 0) {
			std::cout << ltborder;
		}
		else if(i == this->getSize().getISize()-1){
			std::cout << lbborder;
		}
		else {
			std::cout<< border;
		}
		for(size_t j=0; j<this->getSize().getJSize(); j++) {
			std::cout << std::setw(5) << std::setprecision(4) << std::left << this->_elements(i,j);
		}
		std::cout << std::setw(2);
		if(i == 0) {
			std::cout << rtborder;
		}
		else if(i == this->getSize().getISize()-1){
			std::cout << rbborder;
		}
		else {
			std::cout<< border;
		}
		std::cout<<std::endl;
	}
}

Matrix Matrix::operator*(Number num)
{
	return this->multiplyByNumberChain(*this, num);
}

Matrix Matrix::operator*(Matrix mtx)
{
	return this->multiplyByMatrixChain(*this, mtx);
}

void Matrix::operator*=(Matrix mtx)
{
	this->multiplyByMatrix(mtx);
}

void Matrix::operator*=(Number num)
{
	this->multiplyByNumber(num);
}

Matrix Matrix::operator+(Matrix mtx)
{
	return this->addMatrixChain(*this, mtx);
}

Matrix Matrix::operator+(Number num)
{
	return this->addNumberChain(*this, num);
}

void Matrix::operator+=(Number num)
{
	this->addNumber(num);
}

void Matrix::operator+=(Matrix mtx)
{
	this->addMatrix(mtx);
}

Matrix Matrix::operator-(Matrix mtx)
{
	this->subMatrixChain(*this, mtx);
}

Matrix Matrix::operator-(Number num)
{
	this->subNumberChain(*this, num);
}

void Matrix::operator-=(Number num)
{
	this->subNumber(num);
}

void Matrix::operator-=(Matrix mtx)
{
	this->subMatrix(mtx);
}

Matrix Matrix::operator/(Number num)
{
	this->divideByNumberChain(*this, num);
}

void Matrix::operator/=(Number num)
{
	this->divideByNumber(num);
}

Matrix Matrix::operator~()
{
	return this->getTransposed();
}

Matrix Matrix::getGaussian()
{
 	if(this->_gaussian.getSize().getISize() == 0) {
		this->_computeGaussian();
 	}
 	if(this->_gaussian.getSize().getISize() == 0) {
		throw new MatrixException(MatrixException::Container, "Matrix is null");
	}
	return Matrix(this->_gaussian);
}
