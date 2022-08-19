package Orologio2;

import java.util.Iterator;

public class Orologio<S> implements CircList<S> {

	Object[] S = new Object[1];
	int n = 0;

	@Override
	public Iterator<S> iterator() {
		return new OrologioIterator(this);
	}

	@Override
	public void add(S e) {

		for (int j = S.length - 1; j > 0; j--) {
			S[j] = S[j - 1];
		}

		S[0] = e;
		n++;
		if (n == S.length) {
			Object[] temp = new Object[S.length * 2];
			for (int i = 0; i < n; i++)
				temp[i] = S[i];
			S = temp;
		}

	}

	@Override
	public S value() {
		if (isEmpty())
			throw new RuntimeException("La struttura è vuota");
		else
			return (S) S[0];
	}

	@Override
	public boolean isEmpty() {
		return n == 0;
	}

	@Override
	public void rotateF() {
		Object temp = S[0];
		for (int i = 0; i < n - 1; i++)
			S[i] = S[i + 1];
		S[n-1] = temp;

	}

	@Override
	public int size() {
		return n;
	}

	@Override
	public boolean equals(CircList<S> s) {
		// TODO Auto-generated method stub
		return false;
	}

	public static void main(String[] args) {

		Orologio<Integer> or = new Orologio<Integer>();
		or.add(1);
		or.add(2);
		
	Iterator<Integer> it= or.iterator();
	while(it.hasNext())
		System.out.println(it.next());





	}

}
