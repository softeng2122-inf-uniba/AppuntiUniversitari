package Rivista;

import java.util.Iterator;

public class VectorListIterator<S> implements Iterator<S> {

	private VectorList list;
	private int n;

	public VectorListIterator(VectorList l) {

		list = l;
		n = 0;

	}

	@Override
	public boolean hasNext() {
		return list.S[n] != null;
	}

	@Override
	public S next() {

		int p = n;
		n++;

		return (S) list.S[p];
	}

	@Override
	public void remove() {

	}

}
