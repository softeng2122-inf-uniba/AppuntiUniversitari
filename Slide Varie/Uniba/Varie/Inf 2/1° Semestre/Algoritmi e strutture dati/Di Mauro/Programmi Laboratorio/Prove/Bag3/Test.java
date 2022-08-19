package Bag3;

import java.util.Iterator;

public class Test {

	public static void main(String[] args) {
		BagOfWords b1 = new BagOfWords();
		BagOfWords b2 = new BagOfWords();
		BagOfWords b3 = new BagOfWords();

		b1.addText("Questo è un sistema innovativo per la scoperta automatica di plagi");
		b2.addText("Questo sistema innovativo permette la scoperta automatica di plagi");
		b3.addText("Questo sistema non fa proprio nulla di interessante");

		Iterator<String> it1 = b1.bagOfWords.iterator();
		Iterator<String> it2 = b2.bagOfWords.iterator();
		Iterator<String> it3 = b3.bagOfWords.iterator();

		while (it1.hasNext()) {

			String stringa = it1.next();
			System.out.println(stringa + " "
					+ b1.bagOfWords.occurrences(stringa));

		}
		System.out.println("\n \n");
		while (it2.hasNext()) {

			String stringa = it2.next();
			System.out.println(stringa + " "
					+ b2.bagOfWords.occurrences(stringa));

		}
		
		System.out.println("\n \n");

		while (it3.hasNext()) {

			String stringa = it3.next();
			System.out.println(stringa + " "
					+ b3.bagOfWords.occurrences(stringa));

		}
		System.out.println(b1.similarita(b2));
		System.out.println(b2.similarita(b3));
		System.out.println(b1.similarita(b3));
	


	}

}
