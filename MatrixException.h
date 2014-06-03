#ifndef MATRIXEXCEPTION_H
#define MATRIXEXCEPTION_H

class MatrixException
{
	/**
	 * @class MatrixException MatrixException.h
	 * @author smt <kirillsaksin@yandex.ru>
	 * @version 1.0-pre
	 * @date 06.2014
	 * @copyright The MIT License
	 * @brief Exception class
	 * Exception class for @link Matrix @endlink, @link MatrixContainer @endlink, @link MatrixSize @endlink
	 */
public:
	/**
	 * Default destructor
	 */
    ~MatrixException();
	
	/**
	 * Constructor
	 * @param type Error type @see MatrixExceptionType
	 * @param message Error description
	 */
	MatrixException(MatrixExceptionType type, const char * message);
	
	/**
	 * Get exception type
	 * @return Type
	 * @see MatrixExceptionType
	 */
	MatrixExceptionType getType();
	
	/**
	 * Get error description
	 * @return Message
	 */
	const char * getMessage();
	
	/**
	 * Enumeration with error codes for @link MatrixException @endlink
	 * @brief Error codes
	 */
	enum MatrixExceptionType {
		/**
		 * Logical error, like zeroes on main diagonal, when computing equation
		 * @brief Logical error
		 */
		Logical,
		/**
		 * Out of range error, appears only when you try to access element which doesn't exist
		 * @brief Out of range error
		 */
		OutOfRange,
		/**
		 * Container error, appears when you try to construct matrix from vector with differnt row sizes
		 * or when you try to compute arithmetic operation on matrixies with different sizes
		 * @brief Container error
		 */
		Container
	};
	
private:
    MatrixExceptionType _type;
	const char * _errorMessage;
};

#endif // MATRIXEXCEPTION_H
