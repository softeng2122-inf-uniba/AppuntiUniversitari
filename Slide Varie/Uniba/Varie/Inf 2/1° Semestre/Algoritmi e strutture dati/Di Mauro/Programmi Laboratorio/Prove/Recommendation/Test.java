package Recommendation;

import java.util.Iterator;

public class Test {
	
	public static void main(String[] args) {

		ItemRecommender ir = new ItemRecommender(20);
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

}
