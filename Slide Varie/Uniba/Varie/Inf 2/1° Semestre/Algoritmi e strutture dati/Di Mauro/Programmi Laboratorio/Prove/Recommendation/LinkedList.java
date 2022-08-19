package Recommendation;

import java.util.Iterator;

public class LinkedList<T> implements AddOnlyList<T> {

	Puntatore inizioLista = null;
	Puntatore last = null;

	@Override
	public Iterator<T> iterator() {
		return new LinkedListIterator(this);
	}

	@Override
	public void add(T e) {

		if (inizioLista == null)
			inizioLista = last = new Puntatore(new Cella(e));
		else {
			last.cell.next = new Puntatore(new Cella(e));
			last = last.cell.next;
		}

	}

	public static void main(String[] args) {
		LinkedList<String> list = new LinkedList<String>();
		list.add("ciao");
		list.add("auee");
		list.add("oii");
		list.add("alessandro");
		Iterator it=list.iterator();
		
		
		while(it.hasNext())
			System.out.println(it.next());
		
		

	}

}
