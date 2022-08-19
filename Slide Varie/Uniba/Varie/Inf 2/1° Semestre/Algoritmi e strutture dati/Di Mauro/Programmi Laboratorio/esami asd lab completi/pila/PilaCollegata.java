package pila;

import java.util.Iterator;

public class PilaCollegata <T> implements Pila<T>{

	private Record <T> first=null;
	
	@Override
	public Iterator<T> iterator() {
		return new PilaCollegataIterator<T>(first);
	}

	@Override
	public boolean isEmpty() {
		return (first==null);
	}

	@Override
	public void push(T e) {
		if (isEmpty()) {
			first= new Record<T>(e);
		} else {
			Record <T> tmp= new Record<T>(e);
			tmp.next=first;
			first=tmp;
		}	
	}

	@Override
	public T top() {
		if (isEmpty()) throw new EccezionePilaVuota("la pila è vuota");
		return first.elem;
	}

	@Override
	public void pop() {
		if (isEmpty()) throw new EccezionePilaVuota("la pila è vuota");
		first=first.next;
	}



}
