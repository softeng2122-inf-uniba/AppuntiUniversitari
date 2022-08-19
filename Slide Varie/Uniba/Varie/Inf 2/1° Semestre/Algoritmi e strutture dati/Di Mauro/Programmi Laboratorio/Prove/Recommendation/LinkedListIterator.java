package Recommendation;

import java.util.Iterator;

public class LinkedListIterator<T> implements Iterator<T> {

	private LinkedList list;
	private Puntatore link;

	public LinkedListIterator(LinkedList l) {
		this.list = l;
		this.link = null;
	}

	@Override
	public boolean hasNext() {

		if (link == null){
			return true;
		}
		return link.cell.next != null;
	}

	@Override
	public T next() {
		if (link == null) {
			link = list.inizioLista;
			return (T) link.cell.elem;
		} else {
			Puntatore pos=link;
			link=link.cell.next;
			return (T) pos.cell.next.cell.elem;
		}
	}

	@Override
	public void remove() {
		// TODO Auto-generated method stub

	}

}
