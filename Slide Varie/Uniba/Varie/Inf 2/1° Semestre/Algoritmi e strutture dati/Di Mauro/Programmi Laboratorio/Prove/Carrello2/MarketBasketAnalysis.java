package Carrello2;

import java.util.HashMap;
import java.util.Map.Entry;
import java.util.Set;

public class MarketBasketAnalysis {

	HashMap<Class, Integer> qTotArticolo = new HashMap<Class, Integer>();

	void add(Carrello<Item> trolley) {

		for (Item item : trolley) {
			System.out.println(item.articolo.getClass().getSimpleName() + " "
					+ item.quantita);

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

		}

	}

	public String toString() {
		String res = "";
		Set<Entry<Class, Integer>> set = this.qTotArticolo.entrySet();
		for (Entry<Class, Integer> entry : set)
			res += "\n " + entry.toString().replaceAll("class Carrello2.", "");
		return res;
	}

	public static void main(String[] args) {

		Articolo[] articoli = { new Spaghetti(), new Burro(), new Cereali(),
				new Sapone(), new Dentifricio() };
		MarketBasketAnalysis m = new MarketBasketAnalysis();
		for (int i = 0; i < 10; i++) {

			Carrello<Item> carr = new Carrello<Item>();
			for (int j = 0; j < (int) ((articoli.length * (Math.random())) + 1); j++) {
				carr.add(new Item(articoli[j], (int) (Math.random() * 5) + 1));
			}
			System.out.println("\n******Carrello numero " + (i + 1) + "\n");
			m.add(carr);
		}
		System.out.println(m.toString());
	}
}
