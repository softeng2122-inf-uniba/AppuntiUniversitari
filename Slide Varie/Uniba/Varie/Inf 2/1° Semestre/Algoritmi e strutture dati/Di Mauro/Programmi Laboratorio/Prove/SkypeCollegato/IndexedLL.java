package SkypeCollegato;

import java.util.Iterator;

import Skype.ItemAlreadyPresentException;
import Skype.ItemNotPresentException;

public class IndexedLL<T> implements IndexedList<T> {

	private Record inizio, fine = null;
	private int n = 0;

	private class IndexedLLIterator implements Iterator<T> {
		private IndexedLL<T> list;
		private Record pos;

		public IndexedLLIterator(IndexedLL<T> list) {
			this.list = list;
			pos = null;
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
				Record p = pos;
				pos = pos.next;
				return p.next.elem;
			}
		}

	}

	private class Record {
		T elem;
		int index;
		Record next, prev;

		public Record(T elem, int index) {
			this.elem = elem;
			this.index = index;
			next = prev = null;
		}
	}

	@Override
	public Iterator<T> iterator() {
		return new IndexedLLIterator(this);
	}

	@Override
	public boolean isEmpty(int i) {
		if (n == 0)
			return true;
		else {
			for (Record p = inizio;; p = p.next) {
				if (p.index == i)
					return false;

				if (p == fine)
					break;
			}
		}

		return true;
	}

	@Override
	public void addItem(T e, int i) {
		if (isEmpty(i)) {
			Record p = new Record(e, i);
			if (inizio == null)
				inizio = fine = p;
			else {
				fine.next = p;
				fine.next.prev = fine;
				fine = fine.next;
			}
			n++;
		} else
			throw new ItemAlreadyPresentException("Posizione già occupata");

	}

	@Override
	public void delItem(int i) {
		if (isEmpty(i))
			throw new ItemNotPresentException("Posizione non occupata");
		else {
			for (Record p = inizio;; p = p.next) {
				if (p.index == i) {

					if (p == inizio && inizio == fine) {
						inizio = fine = null;
						n--;
						break;
					} else if (p == inizio) {
						inizio = inizio.next;
						inizio.prev = null;
						n--;
						break;
					} else if (p == fine) {
						fine = fine.prev;
						fine.next = null;
						n--;
						break;
					} else {
						p.next.prev = p.prev;
						p.prev.next = p.next;
						n--;
						break;
					}

				}
				if (p == fine)
					break;
			}
		}

	}

	@Override
	public T getItem(int i) {
		if (isEmpty(i))
			throw new ItemNotPresentException("posizione non occupata");
		else
			for (Record p = inizio;; p = p.next) {
				if (p.index == i)
					return p.elem;
			}
	}

	@Override
	public int numberItems() {
		return n;
	}

	public static void main(String[] args) {
		IndexedLL<String> list = new IndexedLL<String>();

		System.out.println(list.isEmpty(8));
		list.addItem("ciao", 8);
		list.addItem("alessandro", 9);

		System.out.println(list.isEmpty(8));

		Iterator<String> it = list.iterator();
		while (it.hasNext())
			System.out.println(it.next());

	}

}
