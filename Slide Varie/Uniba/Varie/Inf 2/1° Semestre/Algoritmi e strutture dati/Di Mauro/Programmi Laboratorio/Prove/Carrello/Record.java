package Carrello;

public class Record<T> {

	Comparable key;
	T elem;
	Record next, prev;

	public Record(Comparable key, T elem) {
		this.key = key;
		this.elem = elem;
		next = prev = null;
	}

}
