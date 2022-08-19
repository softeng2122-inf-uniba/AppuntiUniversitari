package Rivista;

public interface Dictionary<K, V> extends Iterable {
	
	public void insert(K key, V value);

	public void delete(K key);

	public V search(K key);

}
