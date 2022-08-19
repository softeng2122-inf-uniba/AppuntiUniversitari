package Carrello2;

public interface AddOnlyList<T> extends Iterable <T> {
	public void add(T e);
	public void backward();
	public void forward();

}
