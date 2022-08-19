package DoppiaCoda;

import Coda.EccezioneCodaVuota;

public class DoubleQueue<T> implements DQueue<T> {

	private Record<T> inizio, fine = null;

	private class Record<T> {

		T elem;
		Record next;
		Record prev;

		public Record(T elem) {

			this.elem = elem;
			next = prev = null;

		}

	}

	@Override
	public void push(T elem) {

		Record p = new Record(elem);
		if (inizio == null) {

			inizio = fine = p;
			fine.prev = p;
			inizio.next = p;
		} else {
			fine.next = p;
			fine.next.prev = fine;
			fine = fine.next;
		}

	}

	@Override
	public void pop() {

		if (isEmpty())
			throw new EccezioneCodaVuota("La doppiacoda è vuota!");

		fine = fine.prev;

	}

	@Override
	public boolean isEmpty() {
		return inizio == null;
	}

	@Override
	public T top() {
		return fine.elem;
	}

	@Override
	public void dequeue() {
		if (isEmpty())
			throw new EccezioneCodaVuota("La doppiacoda è vuota!");
		inizio = inizio.next;

	}

	@Override
	public T first() {
		return inizio.elem;
	}

	public static void main(String[] args) {
		
		
		
		
		

	}

}
