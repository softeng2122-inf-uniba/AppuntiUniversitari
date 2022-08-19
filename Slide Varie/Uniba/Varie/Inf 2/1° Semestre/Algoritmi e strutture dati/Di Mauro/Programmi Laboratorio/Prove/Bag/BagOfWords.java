package Bag;

import java.util.Iterator;
import java.util.LinkedList;

public class BagOfWords {

	protected Bag<String> bow;
	protected int occurrences;

	public BagOfWords() {
		this.bow = new Bag<String>();
		this.occurrences = 0;
	}

	public void addText(String txt) {

		String[] stringhe = txt.split(" ");
		for (String stringa : stringhe) {
			bow.addItem(stringa);
			occurrences++;
		}

	}

	public float similarita(BagOfWords b) {
		float similarita = 0;

		Iterator it1 = this.bow.freqParole.iterator();
		Iterator it2 = b.bow.freqParole.iterator();
		LinkedList<String> list = new LinkedList<String>();
		while (it1.hasNext()) {

			String stringa = (String) it1.next();
			list.add(stringa);
		}
		while (it2.hasNext()) {
			String stringa = (String) it2.next();
			if (list.contains(stringa) == false)
				list.add(stringa);
		}

		for (String stringa : list) {

			similarita += ((this.bow.occurrences(stringa) + 1)
					/ this.occurrences + 2)
					* ((b.bow.occurrences(stringa) + 1) / b.occurrences + 2);

		}
		return similarita;
	}

	public static void main(String[] args) {

		BagOfWords b = new BagOfWords();
		b.addText("Those who cannot remember the past are condemned to repeat it");
		
		BagOfWords b2= new BagOfWords();
		b2.addText("Those who misquote Santayana are condemned to paraphrase it");
		
		BagOfWords b3=new BagOfWords();
		b3.addText("Sanity is a madness put to good uses");
		
		
		
		Iterator it = b.bow.freqParole.iterator();
		Iterator it2=b2.bow.freqParole.iterator();
		Iterator it3=b3.bow.freqParole.iterator();
	
		System.out.println("\n Prima stringa: \n");
		
		while (it.hasNext()) {

			String parola = (String) it.next();
			System.out.println(parola + " " + b.bow.occurrences(parola));
		}

		System.out.println("\n Seconda stringa: \n");
		while (it2.hasNext()) {

			String parola = (String) it2.next();
			System.out.println(parola + " " + b2.bow.occurrences(parola));
		}


		System.out.println("\n Terza stringa: \n");
		while (it3.hasNext()) {

			String parola = (String) it3.next();
			System.out.println(parola + " " + b3.bow.occurrences(parola));
		}

		System.out.println("\n Similarità tra la prima e la seconda frase: "+b.similarita(b2));
		System.out.println("\n Similarità tra la seconda e la terza frase: "+b2.similarita(b3));
		System.out.println("\n Similarità tra la prima e la terza frase: "+b.similarita(b3));

	}

}
