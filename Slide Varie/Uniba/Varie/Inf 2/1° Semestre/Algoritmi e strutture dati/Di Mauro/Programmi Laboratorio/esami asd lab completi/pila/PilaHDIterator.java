package pila;

import java.util.Iterator;

public class PilaHDIterator <T> implements Iterator<T>{

	private int i,n;
	private T[] S;
	
	public PilaHDIterator(T[] t, int dim) {
		this.n=dim;
		i=n-1;
		this.S=t;
	}
	
	@Override
	public boolean hasNext() {
		return (i>=0);
	}

	@Override
	public T next() {
		int y=i;
		i--;
		return S[y];
	}

	@Override
	public void remove() {
		// TODO Auto-generated method stub
		
	}

}
