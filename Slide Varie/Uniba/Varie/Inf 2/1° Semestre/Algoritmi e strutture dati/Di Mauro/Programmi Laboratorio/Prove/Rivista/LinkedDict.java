package Rivista;

import java.util.Iterator;


public class LinkedDict<K, V> implements Dictionary<K, V> {

	Record list = null;

	@Override
	public void insert(K key, V value) {
		Record p = new Record(key, value);

		if (list == null)
			list = p.next = p.prev = p;
		else {

			p.next = list.next;
			p.next.prev = p;
			list.next = p;
			p.prev = list;

		}

	}

	@Override
	public void delete(K key) {

		for (Record p = list;; p = p.next) {

			if (p.key.equals(key)) {

				if (p.next == p.prev) {
					list = p.next = p.prev = p = null;
					break;
				} else if (p == list) {

					list.next.prev = list.prev;
					list.prev.next = list.next;
					list = list.next;
					break;

				} else {

					p.next.prev = p.prev;
					p.prev.next = p.next;
					break;

				}
			}
			if (p == list.prev)
				break;
		}

	}

	@Override
	public V search(K k) {
		if (list==null)
			return null;
		for (Record p = list;; p = p.next) {

			if (p.key.equals(k))
				return (V) p.elem;

			if (p == list.prev)
				return null;
		}
	}

	public static void main(String[] args) {
		LinkedDict<Integer, String> diz = new LinkedDict<Integer, String>();
		diz.insert(1, "malerba");
		diz.insert(2, "alerba");
		diz.insert(3, "lerba");
		diz.insert(4, "erba");

		Iterator it = diz.iterator();
		while (it.hasNext())
			System.out.println(it.next());

	}

	@Override
	public Iterator iterator() {
		return new LinkedDictIterator(this);
	}
}
