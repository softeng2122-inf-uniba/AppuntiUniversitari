package Biblioteca2;

import java.util.Iterator;

public class DoubleLinkedListIterator<T> implements Iterator<T> {

	DoubleLinkedList list;
	Puntatore inizio;

	public DoubleLinkedListIterator(DoubleLinkedList<T> doubleLinkedList) {

		this.list = doubleLinkedList;
		this.inizio = null;

	}

	@Override
	public boolean hasNext() {

		if (inizio == null)
			return true;
		else

			return inizio.c.next != null;
	}

	@Override
	public T next() {
		if (inizio == null) {
			inizio = list.inizio;
			return (T) list.inizio.c.elem;
		} else {

			Puntatore p = inizio;
			inizio = inizio.c.next;

			return (T) p.c.next.c.elem;
		}
	}

}
