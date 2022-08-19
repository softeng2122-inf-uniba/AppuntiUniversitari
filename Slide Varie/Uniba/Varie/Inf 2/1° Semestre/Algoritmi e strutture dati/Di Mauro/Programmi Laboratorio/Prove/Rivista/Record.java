package Rivista;

public class Record<K, V> {

	K key;
	V elem;
	Record next, prev;

	public Record(K k, V e) {

		key = k;
		elem = e;
		next = prev = null;
	}

}
