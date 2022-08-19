package Bussola2.Interface;

public interface CircList<T> extends Iterable<T> {

	public void addCircList(T elem);

	public void delCircList();

	public T value();

	public boolean isEmpty();

	public void ruotaAvanti();

	public void ruotaIndietro();

	public int numItem();

}
