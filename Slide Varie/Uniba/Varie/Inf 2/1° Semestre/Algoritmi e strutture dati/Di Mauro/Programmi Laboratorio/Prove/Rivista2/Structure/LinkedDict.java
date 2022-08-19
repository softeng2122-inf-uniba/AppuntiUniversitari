package Rivista2.Structure;

import java.util.Iterator;

import Rivista2.Interface.Dictionary;

public class LinkedDict<K, V> implements Dictionary<K, V> {

	private Record list = null;

	private class LinkedDictIterator implements Iterator<K> {

		private LinkedDict<K, V> diz;
		private Record pos;

		public LinkedDictIterator(LinkedDict<K, V> diz) {
			this.diz = diz;
			pos = null;
		}

		@Override
		public boolean hasNext() {
			if (pos == null)
				return true;
			else {
				return pos != diz.list.prev;
			}
		}

		@Override
		public K next() {
			if (pos == null) {
				pos = diz.list;
				return pos.key;
			} else {
				Record p = pos;
				pos = pos.next;

				return p.next.key;
			}
		}
	}

	private class Record {

		private K key;
		private V value;
		private Record next, prev;

		public Record(K key, V value) {
			this.key = key;
			this.value = value;
			next = prev = null;
		}
	}

	@Override
	public Iterator<K> iterator() {
		return new LinkedDictIterator(this);
	}

	@Override
	public void insert(K key, V value) {
		Record p = new Record(key, value);
		if (list == null)
			list = p.next = p.prev = p;
		else {
			p.next = list.next;
			p.next.prev = p;
			p.prev = list;
			list.next = p;
		}
	}

	@Override
	public void delete(K key) {

		for (Record p = list;; p = p.next) {

			if (p.key.equals(key)) {
				if (p == list && p.next == list) {
					list = p.next = p.prev = null;
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
	public V search(K key) {

		if (list == null)
			return null;
		for (Record p = list;; p = p.next) {

			if (p.key.equals(key))
				return p.value;
			if (p == list.prev)
				return null;
		}

	}

}
