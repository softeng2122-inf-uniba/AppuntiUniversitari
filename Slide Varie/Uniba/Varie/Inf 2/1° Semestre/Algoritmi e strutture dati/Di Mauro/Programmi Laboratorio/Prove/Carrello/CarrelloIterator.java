package Carrello;

import java.util.Iterator;

//ITERA SUGLI ARTICOLI

public class CarrelloIterator implements Iterator<Articolo> {

	Carrello carr;
	Record rec;

	public CarrelloIterator(Carrello carrello) {
		this.carr = carrello;
		rec = null;
	}

	@Override
	public boolean hasNext() {
		if (rec == null)
			return true;
		return rec != ((DizCollegato) carr.carrello).list.prev;

	}

	@Override
	public Articolo next() {
		if (rec == null) {
			rec = ((DizCollegato) carr.carrello).list;
			return (Articolo) ((DizCollegato) carr.carrello).list.key;
		}
		Record p = rec;
		rec = rec.next;
		return (Articolo) p.next.key;
	}

	@Override
	public void remove() {
		throw new UnsupportedOperationException("Operazione non supportata");
	}

}
