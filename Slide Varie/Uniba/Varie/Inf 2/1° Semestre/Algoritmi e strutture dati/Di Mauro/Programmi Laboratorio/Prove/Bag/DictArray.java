package Bag;

import java.util.Iterator;

public class DictArray<K, V> implements Dictionary<K, V> {

	Object[] S = new Object[1];
	int n = 0;

	@Override
	public Iterator<K> iterator() {
		return new DictArrayIterator(this);
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

				for (j = i; j < n - 1; j++)
					S[j] = S[j + 1];
				n--;
				if (n > 1 && n < S.length / 4) {
					Object[] temp = new Object[S.length / 2];
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
			if (((Coppia) S[i]).key.equals(key))
				return (V) ((Coppia) S[i]).value;
		}
		return null;
	}
	
	
}
