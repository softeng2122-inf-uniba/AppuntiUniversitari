package Rivista;

import java.util.Iterator;

public class LinkedDictIterator<K,V> implements Iterator {

	LinkedDict diz;
	Record rec;

	public LinkedDictIterator(LinkedDict d) {
		diz = d;
		rec = null;
	}

	@Override
	public boolean hasNext() {
		if (rec == null)
			return true;
		return rec.next != diz.list;
	}

	@Override
	public V next() {
		if (rec == null) {
			rec = diz.list;
			return (V) diz.list.elem;
		}

		Record p = rec;
		rec = rec.next;

		return (V) p.next.elem;
	}

	@Override
	public void remove() {
		// TODO Auto-generated method stub

	}

}
