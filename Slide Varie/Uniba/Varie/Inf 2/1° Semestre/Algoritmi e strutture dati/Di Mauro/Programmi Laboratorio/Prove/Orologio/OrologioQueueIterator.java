package Orologio;

import java.util.Iterator;

public class OrologioQueueIterator<S> implements Iterator<S> {

	OrologioQueue orologio;
	int n;

	public OrologioQueueIterator(OrologioQueue<S> or) {
		this.orologio = or;
		n = 0;
	}

	@Override
	public boolean hasNext() {

		return orologio.frazioni[n] != null;
	}

	@Override
	public S next() {

		int p = n;
		n++;

		return (S) orologio.frazioni[p];
	}

	@Override
	public void remove() {
		// TODO Auto-generated method stub

	}

}
