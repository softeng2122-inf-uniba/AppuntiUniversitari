package Fattura.Structure;

import java.util.Iterator;

public class PilaHDIterator<T> implements Iterator<T> {

	PilaHD pila;
	int n;

	public PilaHDIterator(PilaHD p) {
		pila = p;
		n = 0;

	}

	@Override
	public boolean hasNext() {

		return pila.S[n] != null;
	}

	@Override
	public T next() {
		int p = n;
		n++;
		return (T) pila.S[p];
	}

	@Override
	public void remove() {
		throw new UnsupportedOperationException("Operazione non supportata");
	}

}
