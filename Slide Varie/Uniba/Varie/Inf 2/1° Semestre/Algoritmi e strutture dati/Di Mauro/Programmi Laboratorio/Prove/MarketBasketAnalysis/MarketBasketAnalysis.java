package MarketBasketAnalysis;

import java.util.HashMap;
import java.util.Map.Entry;
import java.util.Set;

import MarketBasketAnalysis.Articoli.Articolo;
import MarketBasketAnalysis.Articoli.Alimenti.Burro;
import MarketBasketAnalysis.Articoli.Alimenti.Cereali;
import MarketBasketAnalysis.Articoli.Alimenti.Pane;
import MarketBasketAnalysis.Articoli.Alimenti.Spaghetti;
import MarketBasketAnalysis.Articoli.Casalinghi.Piatti;
import MarketBasketAnalysis.Articoli.Casalinghi.Tovagliolini;
import MarketBasketAnalysis.Articoli.Igiene.Dentifricio;
import MarketBasketAnalysis.Articoli.Igiene.Sapone;

public class MarketBasketAnalysis {

	HashMap<Class, Integer> qTotArticolo = new HashMap<Class, Integer>();

	String toString(Item i) {

		return i.articolo.getClass().getSimpleName() + " " + i.quantita;

	}

	public void add(Carrello<Item> trolley) {

		for (Item item : trolley) {
			System.out.println(this.toString(item));

			if (item.articolo instanceof Burro) {

				if (qTotArticolo.containsKey(item.articolo.getClass())) {
					qTotArticolo.put(item.articolo.getClass(),
							qTotArticolo.get(item.articolo.getClass())
									+ item.quantita);
				} else
					qTotArticolo.put(item.articolo.getClass(), item.quantita);
			}
			if (item.articolo instanceof Cereali) {
				if (qTotArticolo.containsKey(item.articolo.getClass())) {
					qTotArticolo.put(item.articolo.getClass(),
							qTotArticolo.get(item.articolo.getClass())
									+ item.quantita);
				} else
					qTotArticolo.put(item.articolo.getClass(), item.quantita);
			}
			if (item.articolo instanceof Dentifricio) {
				if (qTotArticolo.containsKey(item.articolo.getClass())) {
					qTotArticolo.put(item.articolo.getClass(),
							qTotArticolo.get(item.articolo.getClass())
									+ item.quantita);
				} else
					qTotArticolo.put(item.articolo.getClass(), item.quantita);
			}
			if (item.articolo instanceof Pane) {
				if (qTotArticolo.containsKey(item.articolo.getClass())) {
					qTotArticolo.put(item.articolo.getClass(),
							qTotArticolo.get(item.articolo.getClass())
									+ item.quantita);
				} else
					qTotArticolo.put(item.articolo.getClass(), item.quantita);
			}
			if (item.articolo instanceof Piatti) {
				if (qTotArticolo.containsKey(item.articolo.getClass())) {
					qTotArticolo.put(item.articolo.getClass(),
							qTotArticolo.get(item.articolo.getClass())
									+ item.quantita);
				} else
					qTotArticolo.put(item.articolo.getClass(), item.quantita);
			}
			if (item.articolo instanceof Sapone) {
				if (qTotArticolo.containsKey(item.articolo.getClass())) {
					qTotArticolo.put(item.articolo.getClass(),
							qTotArticolo.get(item.articolo.getClass())
									+ item.quantita);
				} else
					qTotArticolo.put(item.articolo.getClass(), item.quantita);
			}
			if (item.articolo instanceof Spaghetti) {
				if (qTotArticolo.containsKey(item.articolo.getClass())) {
					qTotArticolo.put(item.articolo.getClass(),
							qTotArticolo.get(item.articolo.getClass())
									+ item.quantita);
				} else
					qTotArticolo.put(item.articolo.getClass(), item.quantita);
			}
			if (item.articolo instanceof Tovagliolini) {
				if (qTotArticolo.containsKey(item.articolo.getClass())) {
					qTotArticolo.put(item.articolo.getClass(),
							qTotArticolo.get(item.articolo.getClass())
									+ item.quantita);
				} else
					qTotArticolo.put(item.articolo.getClass(), item.quantita);
			}

		}

	}

}
