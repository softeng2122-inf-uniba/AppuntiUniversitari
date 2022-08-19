package Bag3;

import java.util.Iterator;

public class ArrayDict<T> implements Dictionary<T> {

	private Object[] S = new Object[1];
	private int n = 0;

	private class ArrayDictIterator implements Iterator<Comparable> {

		private ArrayDict<T> diz;
		private int n;

		public ArrayDictIterator(ArrayDict<T> arrayDict) {
			diz = arrayDict;
			n = 0;
		}

		@Override
		public boolean hasNext() {
			if (n < diz.n)
				return diz.S[n] != null;
			return false;
		}

		@Override
		public Comparable next() {

			int p = n;
			n++;
			return (Comparable) ((Coppia) diz.S[p]).key;

		}
	}

	private class Coppia {

		private T elem;
		private Comparable key;

		public Coppia(T e, Comparable k) {
			elem = e;
			key = k;
		}

	}

	@Override
	public Iterator<Comparable> iterator() {
		return new ArrayDictIterator(this);
	}

	@Override
	public void insert(T e, Comparable k) {

		S[n] = new Coppia(e, k);
		n++;

		if (n == S.length) {
			Object[] temp = new Object[S.length * 2];
			for (int i = 0; i < n; i++)
				temp[i] = S[i];
			S = temp;
		}

	}

	@Override
	public void delete(Comparable k) {
		int j;
		for (int i = 0; i < n; i++) {
			if (((Coppia) S[i]).key.equals(k)) {
				for (j = i; j < n - 1; j++)
					S[j] = S[j + 1];
				n--;
				if (n > 1 && n < S.length / 4) {
					Object[] temp = new Object[S.length / 2];
					for (int m = 0; m < n; m++)
						temp[m] = S[m];
					S = temp;
				}

			}
		}

	}

	@Override
	public T search(Comparable k) {
		for (int i = 0; i < n; i++) {

			if (((Coppia) S[i]).key.equals(k))
				return ((Coppia) S[i]).elem;

		}

		return null;
	}

	public static void main(String[] args) {

		ArrayDict<String> arr = new ArrayDict<String>();
		arr.insert("ciao", 1);
		arr.insert("auee", 2);
		arr.insert("auee", 3);

		arr.insert("auee", 7);

		arr.insert("auee", 10);

		Iterator<Comparable> it = arr.iterator();
		while (it.hasNext())
			System.out.println(it.next());

	}

}
