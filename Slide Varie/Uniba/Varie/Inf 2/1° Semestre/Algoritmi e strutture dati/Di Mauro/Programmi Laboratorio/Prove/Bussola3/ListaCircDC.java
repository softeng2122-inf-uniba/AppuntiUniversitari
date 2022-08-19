package Bussola3;

import java.util.Iterator;

public class ListaCircDC<T> implements CircList<T> {

	private Record inizio, fine = null;
	private int n = 0;

	private class ListaCircDCIterator implements Iterator<T> {

	private	ListaCircDC<T> list;
	private	Record pos;

		public ListaCircDCIterator(ListaCircDC<T> l) {
			this.list = l;
			this.pos = null;
		}

		@Override
		public boolean hasNext() {
			if (pos == null)
				return true;
			else
				return pos.next != null;
		}

		@Override
		public T next() {
			if (pos == null) {
				pos = list.inizio;
				return pos.elem;
			} else {
				Record p=pos;
				pos=pos.next;
				return p.next.elem;
			}
		}
	}

	private class Record {
		private T elem;
		private Record next, prev;

		public Record(T elem) {
			this.elem = elem;
			next = prev = null;
		}
	}

	@Override
	public Iterator<T> iterator() {
		return new ListaCircDCIterator(this);
	}

	@Override
	public void addLast(T elem) {
		Record p = new Record(elem);
		if (isEmpty())
			inizio = fine = p;
		else {
			fine.next = p;
			fine.next.prev = fine;
			fine = fine.next;
		}
		n++;

	}

	@Override
	public void delFirst() {
		if (isEmpty())
			throw new EccezioneListaCircVuota("La lista circolare è vuota!");
		else if (inizio == fine)
			inizio = fine = null;
		else {
			inizio = inizio.next;
			inizio.prev = null;
		}
		n--;

	}

	@Override
	public T value() {
		if (isEmpty())
			throw new EccezioneListaCircVuota("La lista circolare è vuota!");
		else
			return inizio.elem;
	}

	@Override
	public boolean isEmpty() {
		return inizio == null;
	}

	@Override
	public void ruotaAvanti() {
		if (isEmpty())
			throw new EccezioneListaCircVuota("La lista circolare è vuota!");
		else if (inizio != fine) {
			fine.next = new Record(this.value());
			fine.next.prev = fine;
			fine = fine.next;
			inizio = inizio.next;
			inizio.prev = null;
		}

	}

	@Override
	public void ruotaIndietro() {
		if (isEmpty())
			throw new EccezioneListaCircVuota("La lista circolare è vuota!");
		else if (inizio != fine) {
			inizio.prev = new Record(fine.elem);
			inizio.prev.next = inizio;
			inizio = inizio.prev;
			fine = fine.prev;
			fine.next = null;
		}

	}

	@Override
	public int numItem() {
		return n;
	}

	public static void main(String[] args) {

		ListaCircDC<String> list = new ListaCircDC<String>();

		list.addLast("nord");
		list.addLast("nord-est");
		list.addLast("est");
		list.addLast("sud-est");
		list.addLast("sud");
		list.addLast("sud-ovest");
		list.addLast("ovest");
		list.addLast("nord-ovest");
		
	

		
		Iterator<String>it= list.iterator();
		while(it.hasNext())
			System.out.println(it.next());
		
		list.ruotaAvanti();
		list.ruotaAvanti();
		list.delFirst();
		
		System.out.println("\n\n");
		
		Iterator<String>it2= list.iterator();
		while(it2.hasNext())
			System.out.println(it2.next());

	}

}
