package Datagramma;

import java.util.Iterator;

public class IndexedList<T> implements ListaIndicizzata<T> {

	Object[] S = new Object[1];
	int n = 0;

	@Override
	public Iterator<T> iterator() {
		return new IndexedListIterator<T>(this);
	}

	@Override
	public boolean isEmpty(int i) {
		if (i < n)
			return S[i] == null;
		else
			return true;
	}

	@Override
	public void addElement(T e, int i) {
		if (isEmpty(i)) {
			if (i >= S.length) {
				Object[] temp = new Object[i + 1];
				for (int k = 0; k < S.length; k++)
					temp[k] = S[k];
				S = temp;
				S[i] = e;
				n++;

			} else {
				S[i] = e;
				n++;
			}
		}

	}

	@Override
	public T getElement(int i) {
		if (i < S.length)
			return (T) S[i];
		throw new UndefinedElementException("Elemento non definito");
	}

	@Override
	public int numberElements() {
		return n;
	}

}
