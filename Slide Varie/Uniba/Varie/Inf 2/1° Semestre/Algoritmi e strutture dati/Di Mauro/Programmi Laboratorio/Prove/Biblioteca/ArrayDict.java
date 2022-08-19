package Biblioteca;

import java.util.Iterator;

public class ArrayDict<K, V> implements Dictionary<K, V> {

	int n = 0;
	Coppia<K, V>[] S = new Coppia[1];

	private class ArrayDictIterator implements Iterator {

		private ArrayDict diz;
		private int m;

		public ArrayDictIterator(ArrayDict diz) {
			this.diz = diz;
			this.m = 0;
		}

		@Override
		public boolean hasNext() {
			return diz.S[this.m] != null;
		}

		@Override
		public String next() {
			int i = m;
			m++;

			return (S[i].key.toString() + ' ' + S[i].elem.toString());
		}

		@Override
		public void remove() {

			throw new UnsupportedOperationException("Operazione non supportata");

		}

	}

	private class Coppia<K, V> {

		private K key;
		private V elem;

		public Coppia(K key, V elem) {
			this.key = key;
			this.elem = elem;
		}

	}

	@Override
	public Iterator<K> iterator() {
		return new ArrayDictIterator(this);
	}

	@Override
	public void insert(K key, V value) {

		S[n] = new Coppia(key, value);
		n++;
		
		//doubling

		if (n == S.length) {

			Coppia[] temp = new Coppia[S.length * 2];
			for (int i = 0; i < n; i++)
				temp[i] = S[i];
			S = temp;

		}

	}

	@Override
	public void delete(K key) {

		int i;
		for (i = 0; i < n; i++) {

			if (S[i].key.equals(key)) {

				for (int j = i; j < n - 1; j++)
					S[j] = S[j + 1];
				n--;
				
				//halving
				if (n > 1 && n < S.length / 4) {

					Coppia[] temp = new Coppia[S.length / 2];
					for (int m = 0; m < n; m++)
						temp[m] = S[m];
					S = temp;

				}
				break;

			}

		}

	}

	@Override
	public V search(K key) {
		for (int i = 0; i < n; i++) {
			if (S[i].key.equals(key))
				return S[i].elem;
		}
		return null;
	}

}
