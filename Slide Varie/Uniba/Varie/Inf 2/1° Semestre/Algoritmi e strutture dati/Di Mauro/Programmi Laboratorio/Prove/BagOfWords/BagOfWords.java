package BagOfWords;

import java.util.Iterator;
import java.util.LinkedList;

public class BagOfWords {
	protected Bag bagOfWords = new Bag();
	protected int occurrences;

	public void addText(String txt) {

		String[] strArr = txt.split(" ");
		for (int i = 0; i < strArr.length; i++)

			bagOfWords.addItem(strArr[i].toLowerCase());

	}

	public float similarità(BagOfWords bow) {

		float similarity = 0;
		Iterator it = this.bagOfWords.freqParole.iterator();

		// lista con le parole di entrambe le bags
		LinkedList<String> list = new LinkedList<String>();
		String next;
		while (it.hasNext()) {
			next = (String) it.next();
			list.add(next);

		}

		Iterator it2 = bow.bagOfWords.freqParole.iterator();
		String next2;
		while (it2.hasNext()) { // inserisce le stringhe della seconda bag,non
								// ripetendole.
			next2 = (String) it2.next();
			if (!list.contains(next2))

				list.add(next2);

		}
		System.out.println(list.toString());

		for (String s : list) {

			similarity += ((this.bagOfWords.occurences(s) + 1) / (this.occurrences + 1))
					* ((bow.bagOfWords.occurences(s) + 1) / (bow.occurrences + 1));

		}

		return similarity;

	}

}
