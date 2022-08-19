package Bussola3;

public interface CircList<T> extends Iterable<T> {

	public void addLast(T elem);

	public void delFirst();

	public T value();

	public boolean isEmpty();

	public void ruotaAvanti();

	public void ruotaIndietro();

	public int numItem();

}
