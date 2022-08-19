package pila;

public interface Pila<T> {

	public boolean isEmpty();
	public void push(T e);
	public T top();
	public void pop();

}
