package Fatt;

import java.util.Iterator;

public class PilaHDIterator<T> implements Iterator<T> {

	PilaHD pila;
	int n;

	public PilaHDIterator(PilaHD pila) {
		this.pila = pila;
		this.n = (pila.n)-1;
	}

	@Override
	public boolean hasNext() {
		if(n==-1)
			return false;
		return true;
	}

	@Override
	public T next() {
		int p = n;
		n--;
		return (T) pila.S[p];
	}

	@Override
	public void remove() {
		// TODO Auto-generated method stub

	}

}
