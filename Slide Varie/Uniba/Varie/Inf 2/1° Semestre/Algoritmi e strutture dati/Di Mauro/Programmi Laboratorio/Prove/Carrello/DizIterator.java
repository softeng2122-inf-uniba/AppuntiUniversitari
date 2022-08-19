package Carrello;

import java.util.Iterator;

//itera sugli elementi (le quantità dei prodotti)

public class DizIterator implements Iterator<Comparable> {

	DizCollegato diz;
	Record rec;

	public DizIterator(DizCollegato d) {
		diz = d;
		rec = null;

	}

	@Override
	public boolean hasNext() {
		if (rec == null)
			return true;
		return rec != diz.list.prev;
	}

	@Override
	public Comparable next() {
		if (rec == null) {
			rec = diz.list;
			return (Comparable) diz.list.elem;
		}
		Record p = rec;
		rec = rec.next;
		return (Comparable) p.next.elem;
	}

	@Override
	public void remove() {
		throw new UnsupportedOperationException("Operazione non supportata");
	}

}
