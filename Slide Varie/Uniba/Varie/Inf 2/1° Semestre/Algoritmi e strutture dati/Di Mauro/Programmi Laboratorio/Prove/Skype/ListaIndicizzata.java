package Skype;

import java.util.Iterator;

public class ListaIndicizzata<T> implements IndexedList<T> {

	private Object[] S = new Object[1];
	private int n = 0;

	private class ListaIndicizzataIterator<T> implements Iterator<T> {

		private ListaIndicizzata<T> list;
		private int n;

		public ListaIndicizzataIterator(ListaIndicizzata<T> listaIndicizzata) {
			list = listaIndicizzata;
			n = 0;
		}

		@Override
		public boolean hasNext() {
			return n < list.S.length;
		}

		@Override
		public T next() {
			int p = n;
			n++;
			return list.getItem(p);
		}

	}

	@Override
	public Iterator<T> iterator() {
		return new ListaIndicizzataIterator<T>(this);
	}

	@Override
	public boolean isEmpty(int i) {
		return S[i] == null;
	}

	@Override
	public void addItem(T e, int i) {

		if (i >= S.length) {
			Object[] temp = new Object[i + 1];
			for (int k = 0; k < n; k++)
				temp[k] = S[k];
			S = temp;
		}
		if (isEmpty(i)) {
			S[i] = e;
			n++;
		} else {
			throw new ItemAlreadyPresentException("Posizione già occupata");
		}
		if (n == S.length) {
			Object[] temp = new Object[S.length * 2];
			for (int j = 0; j < S.length; j++)
				temp[j] = S[j];
			S = temp;
		}

	}

	@Override
	public void delItem(int i) {
		if (!isEmpty(i)) {

			S[i] = null;
			n--;

		} else
			throw new ItemNotPresentException("Posizione non occupata");

	}

	@Override
	public T getItem(int i) {
		return (T) S[i];
	}

	@Override
	public int numberItems() {
		return n;
	}

	public static void main(String[] args) {

		ListaIndicizzata<Integer> list = new ListaIndicizzata<Integer>();
		

		Iterator<Integer> it = list.iterator();
		while (it.hasNext())
			System.out.println(it.next());

	}

}
