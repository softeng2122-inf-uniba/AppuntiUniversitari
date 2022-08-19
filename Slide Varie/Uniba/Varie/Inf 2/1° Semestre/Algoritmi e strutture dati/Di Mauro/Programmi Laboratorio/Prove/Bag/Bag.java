package Bag;

import java.util.Iterator;


public class Bag<T> implements Iterable<T> {

	protected Dictionary<T, Integer> freqParole;

	public Bag() {
		freqParole = new DictArray<T, Integer>();
	}

	public void addItem(T e) {

		if (this.occurrences(e) > 0) {
			int n = this.occurrences(e);
			freqParole.delete(e);
			freqParole.insert(e, n + 1);
		} else
			freqParole.insert(e, 1);

	}

	public void delItem(T e) {
		if(this.isEmpty())
			throw new EccezioneStrutturaVuota("Insieme vuoto");
		else{

		if (this.occurrences(e) > 1) {
			int n = this.occurrences(e);
			freqParole.delete(e);
			freqParole.insert(e, n - 1);
		} else {
			freqParole.delete(e);

		}
		}
	}

	public int occurrences(T e) {
		if (freqParole.search(e) != null)
			return freqParole.search(e);
		return 0;
	}

	public boolean isEmpty() {
		return ((DictArray) freqParole).n == 0;
	}

	@Override
	public Iterator<T> iterator() {
		// TODO Auto-generated method stub
		return null;
	}

	

}
