package Dizionario;

public class ArrayDoubling<T> implements Dizionario<T> {

	private Coppia[] S = new Coppia[1];
	private int n = 0;

	private class Coppia<T> {

		T elem;
		Comparable key;

		public Coppia(T e, Comparable k) {
			elem = e;
			key = k;

		}

	}

	@Override
	public void insert(T elem, Comparable key) {

		S[n] = new Coppia(elem, key);
		n++;
		if (n == S.length) {

			Coppia[] temp = new Coppia[S.length * 2];
			for (int i = 0; i < n; i++)
				temp[i] = S[i];
			S = temp;

		}

	}

	@Override
	public void delete(Comparable key) {

		for (int i = 0; i < n; i++) {
			if (S[i].key.equals(key)) {

				for (int j = i; j < n; j++)
					S[j] = S[j + 1];
				n--;

				if (n < S.length / 4) {

					Coppia[] temp = new Coppia[S.length / 2];
					for (int m = 0; m < n; m++)
						temp[m] = S[m];
					S = temp;
					break;

				}

			}
		}

	}

	@Override
	public T search(Comparable key) {
		for(int i=0;i<n;i++){
			if(S[i].key.equals(key))
				return (T) S[i].elem;
		}
		return null;
	}

	public static void main(String[] args) {
		
		
		ArrayDoubling<String> diz=new ArrayDoubling<String>();
		diz.insert("ciao", 0);
		diz.insert("sono", 1);
		diz.insert("alessandro", 10);
		
		
		System.out.println(diz.search(0));
		System.out.println(diz.search(1));
		System.out.println(diz.search(10));
		System.out.println(diz.search(2));
		
		diz.delete(0);
		System.out.println(diz.search(0));

		diz.delete(1);
		diz.delete(10);

		
		

	}
}
