package Datagramma;

import java.util.Iterator;

public class IndexedListIterator<T> implements Iterator<T> {

	private IndexedList list;
	private int n;
	
	public IndexedListIterator(IndexedList list){
		this.list=list;
		n=0;
	}
	
	
	@Override
	public boolean hasNext() {
		return n<list.n;
	}

	@Override
	public T next() {
		int p=n;
		n++;
		return (T) list.getElement(p);
	}

}
