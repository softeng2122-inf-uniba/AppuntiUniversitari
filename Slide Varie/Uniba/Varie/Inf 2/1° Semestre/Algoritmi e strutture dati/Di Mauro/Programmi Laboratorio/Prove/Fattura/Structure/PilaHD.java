package Fattura.Structure;

import java.util.Iterator;

import Fattura.Exceptions.EccezionePilaVuota;
import Fattura.Interfaces.Pila;

public class PilaHD<T> implements Pila<T> {

	Object[] S = new Object[1];
	private int n = 0;

	@Override
	public Iterator<T> iterator() {
		return new PilaHDIterator(this);
	}

	@Override
	public boolean isEmpty() {
		return n == 0;
	}

	@Override
	public void push(T e) {

		S[n] = e;
		n++;
		if (n == S.length) {
			Object[] temp = new Object[S.length * 2];
			for (int i = 0; i < n; i++)
				temp[i] = S[i];
			S = temp;
		}
	}

	@Override
	public void pop() {
		if(isEmpty())
			throw new EccezionePilaVuota("La pila è vuota");
		n--;
		if (n > 1 && n < S.length / 4) {
			Object[] temp = new Object[S.length / 2];
			for (int i = 0; i < n; i++)
				temp[i] = S[i];
			S = temp;
		}

	}

	@Override
	public T top() {
		if(isEmpty())
			throw new EccezionePilaVuota("La pila è vuota");
		return (T) S[n-1];
	}
	
	

}
