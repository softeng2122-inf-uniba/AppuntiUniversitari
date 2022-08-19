package exceptions;


/**
 * This class represent the exception thrown when a number is too big.
 * It extends the class Exception.
 *
 */
public class NumberTooBigException extends Exception {

	public NumberTooBigException() {
		// TODO Auto-generated constructor stub
	}

	public NumberTooBigException(String message) {
		super(message);
		// TODO Auto-generated constructor stub
	}

	public NumberTooBigException(Throwable cause) {
		super(cause);
		// TODO Auto-generated constructor stub
	}

	public NumberTooBigException(String message, Throwable cause) {
		super(message, cause);
		// TODO Auto-generated constructor stub
	}

}
