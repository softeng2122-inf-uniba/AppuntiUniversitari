package Bag3;

import java.util.Iterator;
import java.util.LinkedList;

public class BagOfWords {

	protected Bag bagOfWords;
	protected int occurrences;

	public BagOfWords() {
		bagOfWords = new Bag();
		occurrences = 0;
	}

	void addText(String txt) {

		String[] stringhe = txt.split(" ");
		for (String s : stringhe) {
			bagOfWords.addItem(s);
			occurrences++;
		}

	}

	float similarita(BagOfWords b) {

		float similarita = 0;
		LinkedList<String> list = new LinkedList<String>();
		for (String s : this.bagOfWords) {
			list.add(s);
		}
		for (String s2 : b.bagOfWords) {
			if (!list.contains(s2))
				list.add(s2);
		}
		
		for(String s:list){
			
			
			similarita+=((float)(this.bagOfWords.occurrences(s)+1)/(this.occurrences+2))*((float)(b.bagOfWords.occurrences(s)+1)/(b.occurrences+2));
			
		}

		return similarita;

	}



}
