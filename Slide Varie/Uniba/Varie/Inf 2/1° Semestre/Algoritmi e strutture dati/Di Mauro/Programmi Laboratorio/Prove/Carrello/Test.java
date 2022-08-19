package Carrello;

public class Test {

	public static void main(String[] args) {

		// array con gli articoli del negozio
		Articolo[] articoli = { new Articolo("frollini", "2kg"),
				new Articolo("ciao", "2lt"), new Articolo("prezzemolo", "1kg") };
		Market mercato = new Market(articoli, 10);
		mercato.stampa();
		mercato.istogramma();

	}
}
