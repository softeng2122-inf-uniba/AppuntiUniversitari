package Recommendation;

import java.util.Iterator;

public class ItemRecommender {

	Sessioni sessioni;
	Prodotto[] prodotti = { new Prodotto("lacca", 2), new Prodotto("cibo", 4),
			new Prodotto("coca", 3), new Prodotto("latte", 3),
			new Prodotto("moka", 30), new Prodotto("borsa", 40),
			new Prodotto("ciao", 2010), new Prodotto("latticini", 5) };

	public ItemRecommender(int n) {
		sessioni = new Sessioni();

		for (int i = 0; i < n; i++) {

			SessioneLL sessione = new SessioneLL();

			// da 2 a 10...?
			for (int j = (int) ((5 - 2 + 1) * Math.random()) + 2; j < 7; j++) {
				sessione.prodotti.add(prodotti[(int) Math.round(Math.random()
						* prodotti.length)
						% prodotti.length]);

			}
			((LinkedList) sessioni.sessioni).add(sessione);

		}

	}

	int acquistiAssociati(Prodotto a, Prodotto b) {

		int coo = 0;

		for (SessioneLL sess : sessioni.sessioni) {
			Iterator it = sess.prodotti.iterator();
			while (it.hasNext()) {
				Prodotto p = (Prodotto) it.next();
				if (p.nome.contains(a.nome)) {
					while (it.hasNext()) {
						if (((Prodotto) it.next()).nome.contains(b.nome))
							coo++;
						break;
					}

				}
				if (p.nome.contains(b.nome)) {
					while (it.hasNext()) {
						if (((Prodotto) it.next()).nome.contains(a.nome))
							coo++;
						break;
					}
				}
			}
		}

		return coo;

	}
/*
	public static void main(String[] args) {

		ItemRecommender ir = new ItemRecommender(5);
		LinkedList lista = (LinkedList) (ir.sessioni.sessioni);

		Iterator it = lista.iterator(); // stampa le cinque sessioni.
		int n = 0;
		while (it.hasNext()) {

			SessioneLL sessione = (SessioneLL) it.next();
			n++;

			Iterator it2 = sessione.prodotti.iterator();
			System.out.println(n + "a sessione: ");

			while (it2.hasNext()) {
				System.out.println(it2.next().toString());
			}
		}

		System.out.println(ir.acquistiAssociati(new Prodotto("coca", 5),
				new Prodotto("ciao", 2010)));
	}
*/
}
