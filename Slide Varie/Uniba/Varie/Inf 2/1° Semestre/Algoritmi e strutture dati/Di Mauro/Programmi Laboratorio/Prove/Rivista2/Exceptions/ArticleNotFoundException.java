package Rivista2.Exceptions;

public class ArticleNotFoundException extends RuntimeException {

	public ArticleNotFoundException(String msg) {
		super(msg);
	}

}
