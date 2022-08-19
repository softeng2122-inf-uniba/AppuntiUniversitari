package Orologio;

import java.util.Iterator;

import Orologio.Exceptions.CodaVuotaException;
import Orologio.Interface.CircQueue;

public class OrologioQueue<S> implements CircQueue<S> {

	Object[] frazioni = new Object[1];
	private int n = 0;
	private boolean stop = false;

	@Override
	public Iterator<S> iterator() {
		return new OrologioQueueIterator(this);
	}

	@Override
	public void add(S e) {

		frazioni[n] = e;
		n++;

		if (n == frazioni.length) {
			Object[] temp = new Object[frazioni.length * 2];
			for (int i = 0; i < n; i++)
				temp[i] = frazioni[i];
			frazioni = temp;
		}

	}

	@Override
	public S value() {
		if (isEmpty())
			throw new CodaVuotaException("L'orologio è vuoto!");
		else
			return (S) frazioni[0];

	}

	@Override
	public boolean isEmpty() {
		return n == 0;
	}

	@Override
	public void rotateF() {
		if (stop == false) {

			if (n > 1) {

				Object temp = frazioni[0];
				for (int i = 0; i < n - 1; i++)
					frazioni[i] = frazioni[i + 1];
				frazioni[n - 1] = temp;

			}

		}
	}

	@Override
	public int size() {
		return n;
	}

	@Override
	public boolean equals(CircQueue<S> s) {
		boolean equal = false;

		if (this.n == ((OrologioQueue) s).n) {
			for (int i = 0; i < this.n; i++) {
				if (this.frazioni[i].equals(((OrologioQueue) s).frazioni[i]))
					equal = true;
				else
					equal = false;
			}
		}
		return equal;
	}

	@Override
	public void stop() {
		stop = true;
	}

	@Override
	public void restart() {
		stop = false;
	}

}
