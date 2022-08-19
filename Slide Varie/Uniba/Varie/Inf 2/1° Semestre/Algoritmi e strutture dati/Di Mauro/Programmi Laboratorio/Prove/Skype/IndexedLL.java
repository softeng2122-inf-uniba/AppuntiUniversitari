package Skype;

import java.util.Iterator;

public class IndexedLL<T> implements IndexedList<T> {

	Record inizio, fine = null;
	private int n = 0;
	
	private class IndexedLLIterator<T> implements Iterator<T>{
		
		IndexedLL list;
		Record inizio;
		
		

		public IndexedLLIterator(IndexedLL<T> indexedLL) {
			list=indexedLL;
			inizio=null;
		}

		@Override
		public boolean hasNext() {
			if(inizio==null)
				return true;
			else return inizio.next!=null;
		}

		@Override
		public T next() {
			if(inizio==null){
				inizio=list.inizio;
				return (T) inizio.elem;
			}
			else{
			Record p=inizio;
			inizio=inizio.next;
			return (T) p.next.elem;
		}}
		
		
		
	}

	private class Record {

		T elem;
		int i;
		Record next, prev;

		public Record(T e) {
			elem = e;
			next = prev = null;
		}

	}

	@Override
	public Iterator<T> iterator() {
		return new IndexedLLIterator(this);
	}

	@Override
	public boolean isEmpty(int i) {

		for (Record p = inizio;; p = p.next) {
			if (p == null)
				return true;
			if (p.i == i)
				return false;

		}
	}

	@Override
	public void addItem(T e, int i) {
		if (isEmpty(i)) {

			Record p = new Record(e);
			p.i = i;

			for (Record r = inizio;; r = r.next) {
				if (inizio == null) {
					inizio = fine = p;
					n++;
					break;
				}
				if (r == null) {
					fine.next = p;
					fine.next.prev = fine;
					fine = fine.next;
					n++;
					break;
				}
				if (p.i < r.i) {

					p.prev = r.prev;
					if (r.prev != null)
						r.prev.next = p;
					r.prev = p;
					p.next = r;
					n++;
					break;

				}

			}
		} else
			throw new ItemAlreadyPresentException("Posizione già occupata");

	}

	@Override
	public void delItem(int i) {

		if (!isEmpty(i)) {
			for (Record p = inizio;; p = p.next) {

				if (p.i == i) {
					if (inizio == fine) {
						inizio = fine = null;
						n--;
						break;
					}
					if (p == inizio) {

						inizio.next.prev = null;
						inizio = inizio.next;
						n--;
						break;

					}
					if (p == fine) {
						fine.prev.next = null;
						fine = fine.prev;
						n--;
						break;
					} else {
						p.next.prev = p.prev;
						p.prev.next = p.next;
						n--;
						break;
					}
				}
			}

		} else
			throw new ItemNotPresentException("Posizione non occupata");

	}

	@Override
	public T getItem(int i) {

		if (isEmpty(i))
			throw new ItemNotPresentException("Posizione non occupata");
		for (Record p = inizio;; p = p.next) {

			if (p.i == i)
				return p.elem;

		}
	}

	@Override
	public int numberItems() {
		return n;
	}

	public static void main(String[] args) {

		IndexedLL<String> list = new IndexedLL<String>();
		list.addItem("ciao", 0);

		list.addItem("olaaa", 2);
		list.addItem("aaaaaaaa", 1);
		Iterator it=list.iterator();
		while(it.hasNext())
			System.out.println(it.next());
	}

}
