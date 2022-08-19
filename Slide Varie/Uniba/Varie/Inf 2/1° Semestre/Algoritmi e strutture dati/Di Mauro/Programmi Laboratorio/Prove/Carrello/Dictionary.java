package Carrello;

public interface Dictionary<T> extends Iterable<Comparable> {
	
	public void insert(Comparable key, T value);

	public void delete(Comparable key);

	public T search(Comparable key);
}