package Bussola;

import java.util.Iterator;

public class ListaCircDCIterator<T> implements Iterator<T> {

	ListaCircDC list;
	Puntatore pos;

	public ListaCircDCIterator(ListaCircDC list) {
		this.list = list;
		this.pos = null;

	}

	@Override
	public boolean hasNext() {
		if (pos == null)
			return true;
		return pos.cell.next != null;
	}

	@Override
	public T next() {

		if (pos == null) {
			pos = list.inizioLista;

			return (T) list.inizioLista.cell.elem;
		}
		Puntatore p = pos;
		pos = pos.cell.next;
		return (T) p.cell.next.cell.elem;
	}

	@Override
	public void remove() {
		throw new UnsupportedOperationException("operazione non supportata");
	}

}
