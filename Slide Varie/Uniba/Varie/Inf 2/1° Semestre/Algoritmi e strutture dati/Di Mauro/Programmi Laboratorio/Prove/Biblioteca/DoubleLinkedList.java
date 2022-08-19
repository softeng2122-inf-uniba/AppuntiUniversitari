package Biblioteca;

import java.util.Iterator;

public class DoubleLinkedList<S> implements AddOnlyList<S> {

	Puntatore inizioLista = null;

	@Override
	public Iterator<S> iterator() {
		return new DoubleLinkedListIterator<S>(this);
	}

	public String toString() {
		return null;

	}

	@Override
	public void add(S e) {

		if (inizioLista == null) {
			inizioLista = new Puntatore(new Cella<S>(e));
		} else {

			Puntatore temp = inizioLista;
			inizioLista = new Puntatore(new Cella<S>(e));
			inizioLista.cella.next = temp;
		}

	}

	

}
