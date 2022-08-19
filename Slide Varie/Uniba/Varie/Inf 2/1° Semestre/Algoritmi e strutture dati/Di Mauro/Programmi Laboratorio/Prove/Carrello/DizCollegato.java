package Carrello;

import java.util.Iterator;

public class DizCollegato<T> implements Dictionary<T> {

	Record list = null;

	@Override
	public Iterator<Comparable> iterator() { // itera e restituisce le chiavi (i
												// nomi dei prodotti)
		return new DizIterator(this);
	}

	@Override
	public void insert(Comparable key, T value) {
		Record p = new Record(key, value);
		if (list == null)
			list = p.next = p.prev = p;
		else {
			p.next = list.next;
			p.next.prev = p;
			p.prev = list;
			list.next = p;
		}

	}

	@Override
	public void delete(Comparable key) {

		for (Record p = list;; p = p.next) {

			if (p.key.equals(key)) {

				if (p.next == p && p.prev == p) {
					p.elem = list = p.next = p.prev = p = null;
					break;
				} else if (p == list) {
					list.next.prev = list.prev;
					list.prev.next = list.next;
					list = list.next;
					break;
				} else {
					p.next.prev = p.prev;
					p.prev.next = p.next;
					break;
				}

			}
			if (p == list.prev)
				break;
		}

	}

	@Override
	public T search(Comparable key) {
		if (list == null)
			return null;
		else {
			for (Record p = list;; p = p.next) {
				if (p.key.compareTo(key) == 0)

					return (T) p.elem;
				if (p == list.prev)
					return null;

			}
		}
	}

}
