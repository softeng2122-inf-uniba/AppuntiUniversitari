package ListDoubling;

import java.util.Iterator;

public class ListIterator implements Iterator<Object> {

	ListDoubling list;
	Posizione p;

	public ListIterator(ListDoubling l) {
		list = l;
		p = l.firstList();
	}

	@Override
	public boolean hasNext() {
		return !list.endList(p);
	}

	@Override
	public Object next() {

		Posizione pos = p;
		p = list.succ(p);
		
		return list.readList(pos);

	}

	@Override
	public void remove() {
		// TODO Auto-generated method stub

	}

}
