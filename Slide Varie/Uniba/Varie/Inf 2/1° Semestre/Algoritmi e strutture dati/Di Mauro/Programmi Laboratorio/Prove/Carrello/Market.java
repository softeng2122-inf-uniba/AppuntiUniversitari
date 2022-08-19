package Carrello;

import java.util.Iterator;

public class Market {

	protected Articolo[] merce;
	protected Carrello[] acquisti;

	public Market(Articolo[] articoli, int n) {
		merce = articoli;

		acquisti = new Carrello[n];

		// per ogni carrello mette un numero casuale di articoli
		for (int i = 0; i < acquisti.length; i++) {

			acquisti[i] = new Carrello();
			for (int j = 0; j < Math.round((Math.random() * merce.length)); j++) {

				for (int p = 1; p < Math.round(Math.random() * 100); p++)
					// aggiunge una quantità random di articoli random
					acquisti[i].aggArticolo(merce[j]);

			}

		}

	}

	public void stampa() {

		for (int m = 0; m < acquisti.length; m++) {

			// se è vuoto...
			if (acquisti[m].isEmpty())
				System.out.println(m + 1 + "° carrello vuoto");
			else {

				// se non è vuoto,per ogni prodotto stampa il nome e la quantità
				Iterator it = acquisti[m].iterator();
				Iterator it2 = acquisti[m].carrello.iterator();
				System.out.println(m + 1 + "° carrello: ");

				while (it.hasNext())
					System.out.println(it.next() + " " + it2.next());

			}
		}

	}

	public void istogramma() {

		for (Articolo art : merce) { // per ogni articolo di merce stampa le
										// quantità acquistate da ogni carrello

			int quantitaAcq = 0;
			for (int i = 0; i < acquisti.length; i++) {
				if (acquisti[i].appartiene(art))
					quantitaAcq += acquisti[i].quantita(art);
			}
			System.out.println("Quantità acquistate di " + art.toString() + " "
					+ quantitaAcq);

		}

	}

}
