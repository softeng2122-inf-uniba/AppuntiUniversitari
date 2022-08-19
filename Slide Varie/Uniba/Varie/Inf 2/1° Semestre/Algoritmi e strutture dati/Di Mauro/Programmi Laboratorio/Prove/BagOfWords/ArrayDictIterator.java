package BagOfWords;

import java.util.Iterator;

public class ArrayDictIterator implements Iterator<Comparable> {
	
	private ArrayDict diz;
	private int n;
	

	public ArrayDictIterator(ArrayDict arrayDict) {
		diz=arrayDict;
		n=0;
	}

	@Override
	public boolean hasNext() {
		return diz.S[n]!=null;
	}

	@Override
	public Comparable next() {
		int p=n;
		n++;
		return diz.S[p].key;
	}

	@Override
	public void remove() {
		// TODO Auto-generated method stub

	}

}
