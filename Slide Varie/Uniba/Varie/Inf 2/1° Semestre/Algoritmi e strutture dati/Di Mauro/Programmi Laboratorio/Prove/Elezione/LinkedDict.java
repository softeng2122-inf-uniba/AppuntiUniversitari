package Elezione;

import java.util.Iterator;

public class LinkedDict<S> implements Dictionary<S> {

	Record list = null;

	private class LinkedDictIterator implements Iterator<S> {

		LinkedDict<S> dict;
		Record p;

		public LinkedDictIterator(LinkedDict<S> linkedDict) {
			dict = linkedDict;
			p = null;
		}

		@Override
		public boolean hasNext() {
			if (p == null)
				return true;
			return p.next != list;
		}

		@Override
		public S next() {
			if (p == null) {
				p = dict.list;
				return p.elem;
			} else {
				Record f = p;
				p = p.next;
				return f.next.elem;
			}
		}
	}

	private class Record {
		S elem;
		Comparable key;
		Record next, prev;

		public Record(S e, Comparable k) {
			elem = e;
			key = k;
			next = prev = null;
		}
	}

	@Override
	public Iterator<S> iterator() {
		return new LinkedDictIterator(this);
	}

	@Override
	public void insert(S e, Comparable k) {
		Record p = new Record(e, k);

		if (list == null) {
			list = p.next = p.prev = p;
		} else {
			p.next = list.next;
			p.next.prev = p;
			p.prev = list;
			list.next = p;
		}

	}

	@Override
	public void delete(Comparable k) {
		for (Record p = list;; p = p.next) {

			if (p.key.compareTo(k)==0) {
				
				if(p==list && p.next==list){
					list=p=null;break;
				}
				 if (p == list) {
					list = list.next;
					list.prev = p.prev;
					p.prev.next = list;
					
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
	public S search(Comparable k) {
		if (list == null)
			return null;
		
			for (Record p = list;; p = p.next) {
				if (p.key.compareTo(k)==0)
					return p.elem;
				if (p == list.prev)
					return null;
			}
		}
	public Comparable kSearch(S e){
		
		if (list == null)
			return null;
		
			for (Record p = list;; p = p.next) {
				if (p.elem.equals(e))
					return p.key;
				if (p == list.prev)
					return null;
			}
		}
		
		
		
	
	
	public static void main(String[]args){
		LinkedDict<String>dict= new LinkedDict<String>();
		dict.insert("minchia", 1);
		dict.insert("alex", 2);
		System.out.println(dict.search(1));	
		dict.delete(1);
		System.out.println(dict.list.elem);	

	}

}
