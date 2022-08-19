package Dizionario;

public class ArrayOrdinato<T> implements Dizionario<T> {

	private Coppia<T>[] S = new Coppia[0];

	public void insert(T elem, Comparable key) {

		Coppia<T>[] temp = new Coppia[S.length + 1];
		int i;

		for (int m = 0; m < S.length; m++)
			temp[m] = S[m];
		S = temp;

		for (i = 0; i < S.length - 1; i++) {

			if (key.compareTo(S[i].k) <= 0)
				
				break;

		}
		for (int j = S.length - 1; j > i; j--)
			S[j] = S[j - 1];
		
		S[i] = new Coppia<T>(elem, key);

	}

	public void delete(Comparable key) {

		Coppia<T>[] temp;

		for (int i = 0; i < S.length; i++) {
			if (S[i].k.equals(key)) {

				for (int j = i; j < S.length - 1; j++)
					S[j] = S[j + 1];

				temp = new Coppia[S.length - 1];
				for (int m = 0; m < S.length - 1; m++)
					temp[m] = S[m];
				S = temp;

				break;
			}

		}

	}

	public T search(Comparable key) {
		int i = 0;
		int j = S.length;

		while (i < j) {

			int m = (i + j) / 2;

			if (S[m].k.equals(key))
				return S[m].e;
			else if (key.compareTo(S[m].k) < 0)
				j = m;
			else
				i = m + 1;

		}
		return null;
	}

	private class Coppia<T> {

		T e;
		Comparable k;

		public Coppia(T elem, Comparable key) {
			e = elem;
			k = key;

		}

	}

	public static void main(String[] args) {

		ArrayOrdinato<String> diz = new ArrayOrdinato<String>();

		diz.insert("ahah", 2);
		diz.insert("ciao", 1);
		diz.insert("aaaaao", 3);
		diz.insert("adaada", 5);
		System.out.println(diz.search(2));
		System.out.println(diz.search(1));

		diz.delete(2);
		System.out.println(diz.search(2));
		diz.delete(1);
		System.out.println(diz.search(1));
		System.out.println(diz.search(5));



	}

}
