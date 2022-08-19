package Carrello;

import java.util.Iterator;

public class Carrello implements Iterable<Articolo> {

	protected Dictionary<Integer> carrello = new DizCollegato<Integer>();
	private int m = 0;// articoli distinti

	public void aggArticolo(Articolo art) {
		if (appartiene(art)) {
			int n = quantita(art);
			carrello.delete(art);
			carrello.insert(art, n + 1);

		} else {
			carrello.insert(art, 1);
			m++;
		}
	}

	public void togliArticolo(Articolo art) {

		if (appartiene(art)) {
			int n = quantita(art);
			if (n == 1) {
				carrello.delete(art);
				m--;
			} else {
				carrello.delete(art);
				carrello.insert(art, n - 1);
			}

		} else {
			throw new ArticoloNonPresenteException("L'articolo "
					+ art.toString() + " non è presente nel carrello");

		}

	}

	public int quantita(Articolo art) {
		if (this.appartiene(art))
			return this.carrello.search(art);
		else
			return 0;
	}

	public boolean isEmpty() {
		return ((DizCollegato) carrello).list == null;
	}

	public boolean appartiene(Articolo art) {
		if (carrello.search(art) != null)
			return true;
		else
			return false;
	}

	public int numArtDistinti() {
		return m;
	}

	@Override
	public Iterator<Articolo> iterator() {
		return new CarrelloIterator(this);
	}

	public static void main(String[] args) {

		Carrello carr = new Carrello();
		Articolo art2 = new Articolo("frollini", "2chili");
		Articolo art = new Articolo("frullato", "2litri");

		carr.aggArticolo(art2);
		carr.aggArticolo(art2);
		carr.aggArticolo(art2);
		carr.aggArticolo(art);

		carr.togliArticolo(art2);
		carr.togliArticolo(art2);
		carr.togliArticolo(art2);

	}

}
