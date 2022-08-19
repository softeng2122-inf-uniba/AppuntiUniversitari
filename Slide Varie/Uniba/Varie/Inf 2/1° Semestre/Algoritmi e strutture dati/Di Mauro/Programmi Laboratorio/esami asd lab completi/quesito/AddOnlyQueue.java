package quesito;

public interface AddOnlyQueue <T>{

	public void add(T dato);
	public T getElem(int i);
	public int numberElements();
}
