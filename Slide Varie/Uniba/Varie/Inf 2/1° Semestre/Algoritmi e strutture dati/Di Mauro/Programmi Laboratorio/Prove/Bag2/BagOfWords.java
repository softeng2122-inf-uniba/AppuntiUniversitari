package Bag2;

import java.util.Iterator;
import java.util.LinkedList;

public class BagOfWords {
	protected Bag<String> bow;
	protected int occurrences;

	public BagOfWords() {
		bow = new Bag();
		bow.freqParole = new ArrayDict<String, Integer>();
		occurrences = 0;
	}

	void addText(String txt) {

		String[] stringhe = txt.split(" ");
		for (String stringa : stringhe) {
			bow.addItem(stringa);
			occurrences++;
		}

	}

	float similarita(BagOfWords b) {

		float similarita = 0;

		LinkedList<String> list = new LinkedList<String>();

		for (String stringa : this.bow.freqParole)
			list.add(stringa);
		for (String stringa : b.bow.freqParole) {
			if (!list.contains(stringa))
				list.add(stringa);
		}

		for (String stringa : list) {

			similarita += ((this.bow.ocurrences(stringa)+1)/this.occurrences+2)*((b.bow.ocurrences(stringa)+1)/b.occurrences+2);
			
		}

		return similarita;

	}

	public static void main(String[] args) {

		BagOfWords bag = new BagOfWords();
		BagOfWords bag2 = new BagOfWords();
		BagOfWords bag3 = new BagOfWords();

		bag.addText("those who cannot remember the past are condemned to repeat it");
		bag2.addText("those who misquote sanatyana are condemned to paraphrase him");
		bag3.addText("sanity is a madness put to good uses");

		Iterator<String> it = bag.bow.iterator();
		Iterator <String> it2=bag2.bow.iterator();
		Iterator <String> it3=bag3.bow.iterator();
		
		while(it.hasNext()){
			String next=it.next();
			System.out.println(next+" "+ bag.bow.ocurrences(next));
		}
		while(it2.hasNext()){
			String next2=it2.next();
			System.out.println(next2+" "+ bag2.bow.ocurrences(next2));
		}
		
		while(it3.hasNext()){
			String next3=it3.next();
			System.out.println(next3+" "+ bag3.bow.ocurrences(next3));
		}
		
	
System.out.println(bag.similarita(bag2));
System.out.println(bag2.similarita(bag3));
System.out.println(bag.similarita(bag3));

	}
}
