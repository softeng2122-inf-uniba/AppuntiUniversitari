package Dizionario;

public class StrCollegata implements Dizionario {

	private Record list = null;

	private class Record {

		Object elem;
		Comparable key;
		Record prev, next;

		public Record(Object elem, Comparable key) {

			this.elem = elem;
			this.key = key;
			prev = next = null;

		}

	}

	@Override
	public void insert(Object elem, Comparable key) {

		Record p = new Record(elem, key);

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
	public void delete(Comparable key) {

		for (Record p = list;; p = p.next) {

			if (p.key.equals(key)) {

				if (p.next == p.prev) {
					list = p.next = p.prev = null;
					break;
				} else if (p == list) {
					list = list.next;
					list.prev = p.prev;
					p.prev.next = list;
					break;
				}

				else {

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
	public Object search(Comparable key) {
		for (Record p = list;; p = p.next) {
			if (p.key.equals(key))
				return p.elem;
			if (p == list.prev)
				return null;
		}
	}
	public static void main(String[]args)
	{
		
		
		StrCollegata diz=new StrCollegata();
		diz.insert("ahah", 0);
		diz.insert("ciaoo", 1);
		diz.insert("aleeeeee", 2);
		
		System.out.println(diz.search(0));
		System.out.println(diz.search(1));

		System.out.println(diz.search(2));
		System.out.println(diz.search(3));
		
		diz.delete(0);
		System.out.println(diz.search(0));



		
		
		
		
		
		
		
		
		
	}

}
