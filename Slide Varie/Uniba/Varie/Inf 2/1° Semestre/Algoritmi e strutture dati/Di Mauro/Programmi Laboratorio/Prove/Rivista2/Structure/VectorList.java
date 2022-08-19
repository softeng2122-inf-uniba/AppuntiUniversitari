package Rivista2.Structure;

import java.util.Iterator;

import Rivista2.Interface.AddOnlyList;

public class VectorList<S> implements AddOnlyList<S> {

	private Object[] S = new Object[1];
	private int n = 0;

	private class VectorListIterator implements Iterator<S> {

		private VectorList<S> list;
		private int n;

		public VectorListIterator(VectorList<S> vectorList) {
			list = vectorList;
			n = 0;
		}

		@Override
		public boolean hasNext() {
			return n < list.n;
		}

		@Override
		public S next() {
			int p = n;
			n++;
			return (S) list.S[p];
		}
	}

	@Override
	public Iterator<S> iterator() {
		return new VectorListIterator(this);
	}

	@Override
	public void add(S e) {
		S[n] = e;
		n++;
		if (n == S.length) {
			Object[] temp = new Object[S.length * 2];
			for (int i = 0; i < n; i++)
				temp[i] = S[i];
			S = temp;
		}
	}

	public String toString() {

		String res = "";

		for (Object elem : S) {
			res += " " + elem.toString();
		}

		return res;

	}

}
