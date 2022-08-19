package Bussola2.Struttura;

import java.util.Iterator;

import Bussola2.Exceptions.ListaCircVuotaException;
import Bussola2.Interface.CircList;

public class ListaCircDC<T> implements CircList<T> {

	private Record inizio, fine = null;
	private int n = 0;

	private class ListaCircDCIterator<T> implements Iterator<T> {

		ListaCircDC<T> list;
		ListaCircDC<T>.Record inizio;

		public ListaCircDCIterator(ListaCircDC<T> listaCircDC) {
			this.list = listaCircDC;
			this.inizio = null;
		}

		@Override
		public boolean hasNext() {
			if (inizio == null)
				return true;
			else
				return inizio.next != null;
		}

		@Override
		public T next() {
			if (inizio == null) {
				inizio = list.inizio;
				return (T) inizio.elem;
			}

			else {
				ListaCircDC<T>.Record p = inizio;
				inizio = inizio.next;
				return p.next.elem;
			}
		}
	}

	private class Record {

		T elem;
		Record next;
		Record prev;

		public Record(T elem) {
			this.elem = elem;
			next = prev = null;
		}

	}

	@Override
	public Iterator<T> iterator() {
		return new ListaCircDCIterator<T>(this);
	}

	@Override
	public void addCircList(T elem) {

		Record p = new Record(elem);
		if (inizio == null) {
			inizio = fine = p;
		} else {
			fine.next = p;
			fine.next.prev = fine;
			fine = fine.next;
		}
		n++;

	}

	@Override
	public void delCircList() {

		if (inizio == fine) {
			inizio = fine = null;
		} else {
			inizio.next.prev = null;
			inizio = inizio.next;
		}
		n--;

	}

	@Override
	public T value() {
		if (isEmpty())
			throw new ListaCircVuotaException("La Lista è vuota");
		else
			return inizio.elem;
	}

	@Override
	public boolean isEmpty() {
		return inizio == null;
	}

	@Override
	public void ruotaAvanti() {
		if (inizio != fine) {
			this.addCircList(this.value());
			this.delCircList();
		}
	}

	@Override
	public void ruotaIndietro() {
		if (inizio != fine) {
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

		list.addCircList("nord");
		list.addCircList("nord-est");
		list.addCircList("est");
		list.addCircList("sud-est");
		list.addCircList("sud");
		list.addCircList("sud-ovest");
		list.addCircList("ovest");
		list.addCircList("nord-ovest");

		Iterator<String> it = list.iterator();

		while (it.hasNext())
			System.out.println(it.next());

		list.ruotaAvanti();
		list.ruotaAvanti();
		list.delCircList();

		System.out.println("\n \n");

		Iterator<String> it2 = list.iterator();

		while (it2.hasNext())
			System.out.println(it2.next());

	}

}
