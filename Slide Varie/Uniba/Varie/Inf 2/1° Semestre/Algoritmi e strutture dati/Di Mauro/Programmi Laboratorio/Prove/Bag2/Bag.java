package Bag2;

import java.util.Iterator;

public class Bag<T> implements Iterable<T> {

	protected Dictionary<T, Integer> freqParole;
	 int n = 0;

	public void addItem(T item) {

		if (this.ocurrences(item) > 0) {
			int m = this.ocurrences(item);
			freqParole.delete(item);
			freqParole.insert(item, m + 1);

		} else
			freqParole.insert(item, 1);
		n++;
	}

	public void delItem(T item) {

		if (this.ocurrences(item) == 1) {
			freqParole.delete(item);
			n--;
		}
		if (this.ocurrences(item) > 1) {
			int m = this.ocurrences(item);
			freqParole.delete(item);
			freqParole.insert(item, m - 1);
			n--;
		}

	}

	public int ocurrences(T item) {
		if (freqParole.search(item) != null)
			return freqParole.search(item);
		else
			return 0;
	}

	public boolean isEmpty() {
		return n == 0;
	}

	@Override
	public Iterator<T> iterator() {
		Iterator<T> it = freqParole.iterator();
		return it;
	}

	

}
