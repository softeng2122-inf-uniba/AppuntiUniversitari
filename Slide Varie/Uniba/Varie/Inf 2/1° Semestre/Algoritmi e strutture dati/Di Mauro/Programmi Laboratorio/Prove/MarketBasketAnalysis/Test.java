package MarketBasketAnalysis;

import java.util.Set;
import java.util.Map.Entry;

import MarketBasketAnalysis.Articoli.Articolo;
import MarketBasketAnalysis.Articoli.Alimenti.Burro;
import MarketBasketAnalysis.Articoli.Alimenti.Cereali;
import MarketBasketAnalysis.Articoli.Alimenti.Pane;
import MarketBasketAnalysis.Articoli.Alimenti.Spaghetti;
import MarketBasketAnalysis.Articoli.Casalinghi.Piatti;
import MarketBasketAnalysis.Articoli.Casalinghi.Tovagliolini;
import MarketBasketAnalysis.Articoli.Igiene.Dentifricio;
import MarketBasketAnalysis.Articoli.Igiene.Sapone;

public class Test {
	public static void main(String[] args) {

		MarketBasketAnalysis m = new MarketBasketAnalysis();

		Articolo[] art = { new Burro(), new Cereali(), new Dentifricio(),
				new Pane(), new Piatti(), new Sapone(), new Spaghetti(),
				new Tovagliolini() };

		for (int i = 0; i < 10; i++) {

			Carrello<Item> carr = new Carrello<Item>();
			for (int j = 0; j < Math.round(Math.random() * art.length) + 1; j++) {

				carr.add(new Item(art[j], (int) (5 * Math.random() + 1)));

			}
			System.out.println("\nCarrello " + (i + 1));
			m.add(carr);

		}
		Set<Entry<Class, Integer>> set=m.qTotArticolo.entrySet();
		
		System.out.println("\n");
		for(Entry entry:set){
			
			System.out.println(entry.toString().replaceAll("class MarketBasketAnalysis.Articoli.", ""));
			
		}

	}
}
