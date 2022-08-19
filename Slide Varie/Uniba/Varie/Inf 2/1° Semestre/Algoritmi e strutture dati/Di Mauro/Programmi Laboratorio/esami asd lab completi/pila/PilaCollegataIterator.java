package pila;

import java.util.Iterator;

public class PilaCollegataIterator<T> implements Iterator<T> {
	
	private Record<T> current;
	
	
	public PilaCollegataIterator(Record<T> first){
		current=first;
	}
	@Override
	public boolean hasNext() {
		return (current!=null);
	}

	@Override
	public T next() {
		T elemRes=current.elem;
		current=current.next;
		return elemRes;
	}

	@Override
	public void remove() {
		// TODO Auto-generated method stub
		
	}



}
