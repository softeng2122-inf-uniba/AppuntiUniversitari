package BagOfWords;

import java.util.Iterator;

public class BagIterator implements Iterator<String> {

	Bag bag;
	int n;

	public BagIterator(Bag b) {
		this.bag = b;
		this.n = 0;
	}

	@Override
	public boolean hasNext() {

		return ((ArrayDict) bag.freqParole).S[n] != null;
	}

	@Override
	public String next() {

		int p = n;
		n++;

		return  ((ArrayDict) bag.freqParole).S[p].elem.toString();
	}

	@Override
	public void remove() {
		// TODO Auto-generated method stub

	}

}
