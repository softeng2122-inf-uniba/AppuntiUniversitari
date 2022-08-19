package pila;

import java.util.Iterator;

public class PilaHD <T> implements Pila<T>{

	private int n=0;
	private T[] S= (T[]) new Object[1];

	@Override
	public Iterator<T> iterator() {
		return new PilaHDIterator<T>(this.S,this.n);
	}

	@Override
	public boolean isEmpty() {
		return (n==0);
	}

	@Override
	public void push(T e) {
		
		if (n==S.length) {
			T[] tmp =(T[])new Object[S.length*2];
			for (int i=0; i<n; i++) {
				tmp[i]=S[i];
			}
			S=tmp;
		}
		S[n]=e;
		n++;
		
	}

	@Override
	public void pop() {
		
		if (isEmpty()) throw new EccezionePilaVuota("la pila è vuota");
		n --; 
		if (n>1 && n<(S.length/4)) {
			T[] tmp = (T[])new Object[S.length/2];
			for (int i=0; i<n; i++) {
				tmp[i]=S[i];
			}
			S=tmp;
		}
		
	}

	
	public T top() {
		if (isEmpty()) throw new EccezionePilaVuota("la pila è vuota");
		return S[n-1];
	}

}
