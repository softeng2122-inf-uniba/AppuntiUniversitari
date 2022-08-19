package Bussola;

public interface CircList<T> extends Iterable<T> {

	public void addCircList(T item);

	public void delCircList();

	public T value();

	public boolean isEmpty();

	public void ruotaAvanti();

	public void ruotaIndietro();

	public int numItem();
}
