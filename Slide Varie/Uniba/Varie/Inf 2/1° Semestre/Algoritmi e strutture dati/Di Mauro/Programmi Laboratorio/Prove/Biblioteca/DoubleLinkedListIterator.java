package Biblioteca;

import java.util.Iterator;

public class DoubleLinkedListIterator<S> implements Iterator<S> {

	private DoubleLinkedList list;
	private Puntatore pos;

	public DoubleLinkedListIterator(DoubleLinkedList<S> doubleLinkedList) {

		this.list = doubleLinkedList;
		this.pos = null;

	}

	@Override
	public boolean hasNext() {

		if (pos == null)
			return true;
		else

			return pos.cella.next != null;

	}

	@Override
	public S next() {

		if (pos == null) {
			pos = list.inizioLista;

			return (S) list.inizioLista.cella.elem;
		} else {
			Puntatore q = pos;
			pos = pos.cella.next;
			return (S) q.cella.next.cella.elem;
		}

	}

	@Override
	public void remove() {
		// TODO Auto-generated method stub

	}

}
