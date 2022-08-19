package Biblioteca2;

import java.util.Iterator;

public class Test {
	public static void main(String[] args) {

		Biblioteca bib = new Biblioteca();

		DoubleLinkedList<String> autori1 = new DoubleLinkedList<String>();
		autori1.add("Camil Demetrescu");
		autori1.add("Umberto Ferraro Petrillo");
		autori1.add("Irene Finocchi");
		autori1.add("Giuseppe F.Italiano");
		Volume vol1 = new Volume(
				"Progetto di algoritmi e strutture dati in Java",
				"Mc Graw Hill", 2007, autori1);
		Record rec1 = new Record(vol1);
		Record rec2 = new Record(vol1);

		bib.addVol("scaffale 1", rec1);
		bib.addVol("scaffale 2", rec2);

		DoubleLinkedList<String> autori2 = new DoubleLinkedList<String>();
		autori2.add("Alan Bertossi");
		Volume vol2 = new Volume("Algoritmi e strutture dati",
				"CittaStudiEdizioni", 2009, autori2);
		Record rec3 = new Record(vol2);
		bib.addVol("scaffale 3", rec3);

		DoubleLinkedList<String> autori3 = new DoubleLinkedList<String>();
		autori3.add("Deitel & Deitel");
		Volume vol3 = new Volume("Programmazione Java:fondamenti",
				"Pearson-Prentice Hall", 2008, autori3);
		Record rec4 = new Record(vol3);
		Record rec5 = new Record(vol3);
		Record rec6 = new Record(vol3);
		bib.addVol("scaffale 4", rec4);
		bib.addVol("scaffale 5", rec5);
		bib.addVol("scaffale 6", rec6);

		DoubleLinkedList<String> autori4 = new DoubleLinkedList<String>();
		autori4.add("John Lewis");
		autori4.add("Joseph Chase");
		Volume vol4 = new Volume("Java Software Structures",
				"Pearson Education", 2010, autori4);
		Record rec7 = new Record(vol4);
		Record rec8 = new Record(vol4);

		bib.addVol("scaffale 7", rec7);
		bib.addVol("scaffale 8", rec8);

		System.out.println(bib.posizione(rec7));
		bib.prestito(bib.posizione(rec7));

		System.out.println(bib.posizione(rec3));
		bib.prestito(bib.posizione(rec3));

		Iterator it = bib.volumi.iterator();
		while (it.hasNext()) {
			Record rec = bib.volume((String) it.next());
			if (bib.prestato(bib.posizione(rec)) == false)
				System.out.println(rec);
		}

	}

}
