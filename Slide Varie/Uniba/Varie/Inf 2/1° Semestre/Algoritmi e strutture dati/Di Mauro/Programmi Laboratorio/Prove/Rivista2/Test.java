package Rivista2;

import java.util.Iterator;

public class Test {

	public static void main(String[] args) {
		Rivista playboy = new Rivista();
		playboy.addArt("a relational perspective on spatial data mining", 1);
		playboy.addAut("a relational perspective on spatial data mining",
				"Donato Malerba");

		playboy.addArt("Multi-label large margin hierarchical perceptron", 1);
		playboy.addAut("Multi-label large margin hierarchical perceptron",
				"Clay Woolam");
		playboy.addAut("Multi-label large margin hierarchical perceptron",
				"Latifur Khan");

		playboy.addArt("Privacy preserving record linkage approaches", 2);
		playboy.addAut("Privacy preserving record linkage approaches",
				"Vassilios S. Verykios");
		playboy.addAut("Privacy preserving record linkage approaches",
				"Alexandros Karakasidis");
		playboy.addAut("Privacy preserving record linkage approaches",
				"Vassilios K. Mitrogiannis");

		playboy.addArt(
				"On the selection of k efficient paths by clustering techniques",
				3);
		playboy.addAut(
				"On the selection of k efficient paths by clustering techniques",
				"Massimiliano Caramia");
		playboy.addAut(
				"On the selection of k efficient paths by clustering techniques",
				"Stefano Giordani");

		playboy.pubblicaVol(1);
		playboy.pubblicaVol(2);
		playboy.pubblicaVol(3);

		Iterator<String> it = playboy.articoli.iterator();
		while (it.hasNext()) {
			String titoloArt = it.next();
			Articolo art = playboy.articoli.search(titoloArt);

			System.out.print("\nAutori: ");
			Iterator<String> it2 = playboy.articoli.search(titoloArt)
					.getAutori().iterator();
			while (it2.hasNext())
				System.out.print(it2.next() + " ");

			System.out.println("\nTitolo: " + titoloArt + "\nVolume: "
					+ art.getVolume() + " ");

		}

	}

}
