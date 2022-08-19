package LL;

import java.util.Iterator;

public class LinkedListIterator implements Iterator {

	LinkedList list;
	Puntatore p;

	public LinkedListIterator(LinkedList list) {
		this.list = list;
		p = null;

	}

	@Override
	public boolean hasNext() {
		if (p == null) {

			return true;
		} else
			return p.cell.next != null;
	}

	@Override
	public Object next() {
		if (p == null) {
			p = list.inizioLista;
			return p.cell.elem;
		} else {
			Puntatore q = p;
			p = p.cell.next;
			return q.cell.next.cell.elem;
		}
	}

}
