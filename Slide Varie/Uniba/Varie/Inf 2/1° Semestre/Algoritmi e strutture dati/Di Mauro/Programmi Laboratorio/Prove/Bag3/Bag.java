package Bag3;

import java.util.Iterator;

public class Bag implements Iterable<String> {

	protected Dictionary<Integer> freqParole;

	public Bag() {
		freqParole = new ArrayDict<Integer>();
	}

	public void addItem(String s) {

		if (freqParole.search(s) != null) {
			int n = this.occurrences(s);
			freqParole.delete(s);
			freqParole.insert(n + 1, s);

		} else
			freqParole.insert(1, s);

	}

	public void delItem(String s) {
		if (freqParole.search(s) != null) {
			if (this.occurrences(s) > 1) {
				int n = this.occurrences(s);
				freqParole.delete(s);
				freqParole.insert(n - 1, s);
			} else
				freqParole.delete(s);
		}
	}

	public int occurrences(String s) {
		if (freqParole.search(s) != null)
			return freqParole.search(s);
		else
			return 0;
	}

	@Override
	public Iterator<String> iterator() {
		Iterator it=freqParole.iterator();
		return it;
	}

	
}
