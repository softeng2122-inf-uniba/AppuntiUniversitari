package BagOfWords;

import java.util.Iterator;

public class Bag implements Iterable<String> {

	protected Dictionary<Integer> freqParole = new ArrayDict<Integer>();

	public void addItem(String item) {

		if (freqParole.search(item.toLowerCase()) != null) {
			int n = this.occurences(item);
			this.delItem(item);
			freqParole.insert(n + 1, item.toLowerCase());
		} else {

			freqParole.insert(1, item);
		}
	}

	public void delItem(String item) {

		freqParole.delete(item);

	}

	public int occurences(String item) {
		if (freqParole.search(item.toLowerCase()) != null)

			return freqParole.search(item);
		else
			return 0;
	}

	public boolean isEmpty() {
		return ((ArrayDict) freqParole).n == 0;
	}

	@Override
	public Iterator<String> iterator() {
		return new BagIterator(this);
	}
	
	public static void main(String[]args){
		Bag bag= new Bag();
		bag.addItem("ciao");
		bag.addItem("ciao");

		System.out.println(bag.occurences("ciao"));
	}

}
