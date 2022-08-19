package Biblioteca2;

import java.util.Iterator;

public class ArrayDict<K, V> implements Dictionary<K, V> {

	Object[] S = new Object[1];
	int n = 0;

	private class ArrayDictIterator<K> implements Iterator<K> {

		ArrayDict diz;
		int n;
		int max;

		public ArrayDictIterator(ArrayDict<K, V> arrayDict) {
			diz = arrayDict;
			n = 0;
			max = arrayDict.n;
		}

		@Override
		public boolean hasNext() {

			if (n == max)
				return false;
			return S[n] != null;

		}

		@Override
		public K next() {

			int p = n;
			n++;

			return (K) ((Coppia) S[p]).key;
		}

	}

	private class Coppia {

		K key;
		V value;

		public Coppia(K key, V value) {
			this.key = key;
			this.value = value;
		}

	}

	@Override
	public void insert(K key, V value) {
		S[n] = new Coppia(key, value);
		n++;
		if (n == S.length) {
			Object[] temp = new Object[S.length * 2];
			for (int i = 0; i < n; i++)
				temp[i] = S[i];
			S = temp;
		}

	}

	@Override
	public void delete(K key) {

		int j;
		for (int i = 0; i < n; i++) {

			if (((Coppia) S[i]).key.equals(key)) {

				for (j = i; j < n - 1; j++) {
					S[j] = S[j + 1];

				}
				n--;
				if (n > 1 && n < S.length / 4) {
					Object[] temp = new Object[S.length / 2];
					for (int k = 0; k < n; k++)
						temp[k] = S[k];
					S = temp;
				}
				break;

			}

		}

	}

	@Override
	public V search(K key) {
		for (int i = 0; i < n; i++) {

			if (((Coppia) S[i]).key.equals(key))

				return ((Coppia) S[i]).value;

		}
		return null;
	}

	@Override
	public Iterator<K> iterator() {
		return new ArrayDictIterator(this);
	}

	public static void main(String[] args) {

		ArrayDict<String, String> diz = new ArrayDict<String, String>();

		diz.insert("ciao", "bello");
		diz.insert("minchia", "oh");
		diz.insert("barba", "papa");

		diz.insert("papa", "nero");


		Iterator it = diz.iterator();
		while (it.hasNext())
			System.out.println(it.next());

	}

}
