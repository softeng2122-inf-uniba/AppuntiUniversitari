package Carrello2;

import java.util.Iterator;

public class Carrello<T> implements AddOnlyList<T> {

	Record list = null;
	private boolean forward = true;

	private class Record {

		T elem;
		Record next, prev;

		public Record(T elem) {
			this.elem = elem;
			next = prev = null;
		}

	}

	private class CarrelloIterator<T> implements Iterator<T> {

		Carrello<T> carr;
		Carrello<T>.Record p;

		public CarrelloIterator(Carrello<T> carrello) {
			carr = carrello;

			p = null;
		}

		@Override
		public boolean hasNext() {
			if (carr.forward == true) {
				if (p == null)
					return true;

				else
					return p != list.next;

			} else {
				if (p == null)
					return true;
				else
					return p != list;

			}
		}

		@Override
		public T next() {

			if (carr.forward == true) {
				if (p == null) {
					p = carr.list;
					return p.elem;
				} else {
					Carrello<T>.Record q = p;
					p = p.prev;
					return q.prev.elem;
				}
			} else {
				if (p == null) {
					p = carr.list.next;
					return p.elem;
				} else {
					Carrello<T>.Record q = p;
					p = p.next;
					return q.next.elem;
				}
			}

		}
	}

	@Override
	public Iterator<T> iterator() {
		return new CarrelloIterator<T>(this);
	}

	@Override
	public void add(T e) {
		Record p = new Record(e);

		if (list == null) {
			list = p.prev = p.next = p;

		} else {
			p.next = list.next;
			p.next.prev = p;
			p.prev = list;
			list.next = p;
		}

	}

	@Override
	public void backward() {
		forward = false;

	}

	@Override
	public void forward() {
		// TODO Auto-generated method stub
		forward = true;
	}

	public static void main(String[] args) {

		Carrello<String> carr = new Carrello<String>();
		carr.add("carota");
		carr.add("cipolla");
		carr.add("melanzane");
		carr.add("minchia");
		carr.backward();
		Iterator<String> it = carr.iterator();
		while (it.hasNext())
			System.out.println(it.next());

	}

}
