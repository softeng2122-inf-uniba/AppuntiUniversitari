package Bag2;

import java.util.Iterator;

public class ArrayDict<K, V> implements Dictionary<K, V> {

	Coppia<K, V>[] S = new Coppia[1];
	int n = 0;

	private class ArrayDictIterator implements Iterator<K> {

		ArrayDict<K, V> diz;
		int n;

		public ArrayDictIterator(ArrayDict<K, V> arrayDict) {
			diz = arrayDict;
			n = 0;
		}

		@Override
		public boolean hasNext() {
			return S[n] != null;
		}

		@Override
		public K next() {
			int p = n;
			n++;
			return S[p].key;
		}
	}

	private class Coppia<K, V> {

		K key;
		V value;

		public Coppia(K key, V value) {
			this.key = key;
			this.value = value;
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

		if (n == S.length) {
			Coppia[] temp = new Coppia[S.length * 2];
			for (int i = 0; i < n; i++)
				temp[i] = S[i];
			S = temp;
		}

	}

	@Override
	public void delete(K key) {
		int j;
		for (int i = 0; i < n; i++) {
			if (S[i].key.equals(key)) {
				for (j = i; j < n - 1; j++)
					S[j] = S[j + 1];
				n--;
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
				return S[i].value;
		}

		return null;
	}

	public static void main(String[] args) {

	}

}
