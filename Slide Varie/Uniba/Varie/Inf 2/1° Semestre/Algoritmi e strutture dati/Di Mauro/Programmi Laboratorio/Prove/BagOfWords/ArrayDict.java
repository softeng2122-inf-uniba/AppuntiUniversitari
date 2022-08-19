package BagOfWords;

import java.util.Iterator;

public class ArrayDict<T> implements Dictionary<T> {

	Coppia[] S = new Coppia[1];
	int n = 0;

	@Override
	public Iterator<Comparable> iterator() {
		return new ArrayDictIterator(this);
	}

	@Override
	public void insert(T e, Comparable k) {
		S[n] = new Coppia<T>(k, e);
		n++;
		if (n == S.length) {
			Coppia[] temp = new Coppia[S.length * 2];
			for (int i = 0; i < n; i++)
				temp[i] = S[i];
			S = temp;
		}

	}

	@Override
	public void delete(Comparable k) {
		int i;
		for (i = 0; i < n; i++) {
			if (S[i].key.equals(k))
				for (int j = i; j < n - 1; j++)
					S[j] = S[j + 1];
			n--;
			break;
		}
		if (n > 1 && n < S.length / 4) {
			Coppia[] temp = new Coppia[S.length / 2];
			for (int m = 0; m < n; m++)
				temp[m] = S[m];
			S = temp;
		}

	}

	@Override
	public T search(Comparable k) {
		for (int i = 0; i < n; i++) {
			if (S[i].key.equals(k))
				return (T) S[i].elem;
		}
		return null;
	}

	public static void main(String[] args) {

		ArrayDict<String> diz = new ArrayDict<String>();
		diz.insert("ciao", 1);
		diz.insert("auee", 2);
		diz.insert("maciao", 4);

		Iterator it = diz.iterator();

		while (it.hasNext())
			System.out.println(it.next());

	}

}
