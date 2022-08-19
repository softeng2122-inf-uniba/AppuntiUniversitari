package Dizionario;

public interface Dizionario<T> {
	
	
	public void insert(T elem,Comparable key);
	public void delete(Comparable key);
	public T search(Comparable key);
	

}
