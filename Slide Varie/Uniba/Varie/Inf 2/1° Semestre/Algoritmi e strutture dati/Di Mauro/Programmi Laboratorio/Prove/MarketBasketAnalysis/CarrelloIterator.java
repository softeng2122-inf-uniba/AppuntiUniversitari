package MarketBasketAnalysis;

import java.util.Iterator;

public class CarrelloIterator<S> implements Iterator<S> {

	Carrello carr;
	Puntatore inizio;

	public CarrelloIterator(Carrello c) {
		this.carr = c;
		this.inizio = null;
	}

	@Override
	public boolean hasNext() {
		if (inizio == null)

			return true;
		else {
			if (carr.isForward == true) {

				return this.inizio != carr.inizioLista.cella.prev;
			} else {
				return this.inizio != carr.inizioLista.cella.next;
			}
		}
	}

	@Override
	public S next() {
		if (inizio == null) {

			inizio = carr.inizioLista;
			return (S) inizio.cella.elem;
		} else {
			if (carr.isForward == true) {
				Puntatore pos = inizio;
				inizio = inizio.cella.next;

				return (S) pos.cella.next.cella.elem;
			} else {
				Puntatore pos = inizio;
				inizio = inizio.cella.prev;

				return (S) pos.cella.prev.cella.elem;
			}
		}
	}

	@Override
	public void remove() {
		throw new UnsupportedOperationException("Operazione non supportata");
	}

}
