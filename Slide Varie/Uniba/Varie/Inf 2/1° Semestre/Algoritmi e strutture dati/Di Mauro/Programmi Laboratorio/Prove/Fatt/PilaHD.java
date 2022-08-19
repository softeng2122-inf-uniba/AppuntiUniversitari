package Fatt;

import java.util.Iterator;

public class PilaHD<T> implements Pila<T> {

	Object[] S = new Object[1];
	int n = 0;

	@Override
	public Iterator<T> iterator() {
		return new PilaHDIterator(this);
	}

	@Override
	public boolean isEmpty() {
		// TODO Auto-generated method stub
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
		if ((isEmpty()))
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
		if ((isEmpty()))
			throw new EccezionePilaVuota("La pila è vuota");

		return (T) S[n - 1];
	}

	public static void main(String[] args) {
		PilaHD<String> pila = new PilaHD<String>();
		pila.push("ciao");
		pila.push("mi ");
		pila.push("chiamoo");
		pila.push("alessandro");
		Iterator it = pila.iterator();
		while (it.hasNext())
			System.out.println(it.next());

	}

}
