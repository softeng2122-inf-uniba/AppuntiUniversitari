package Bag3;

public interface Dictionary<T> extends Iterable<Comparable> {
	
	
	public void insert(T e,Comparable k);
	public void delete(Comparable k);
	public T search(Comparable k);

}
