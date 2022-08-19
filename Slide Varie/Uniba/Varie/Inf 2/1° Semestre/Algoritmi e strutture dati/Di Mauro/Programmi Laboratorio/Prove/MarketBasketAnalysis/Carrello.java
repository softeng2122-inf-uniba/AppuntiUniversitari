package MarketBasketAnalysis;

import java.util.Iterator;

import MarketBasketAnalysis.Interface.AddOnlyList;

public class Carrello<S> implements AddOnlyList<S> {

	Puntatore inizioLista = null;

	boolean isForward = true;

	@Override
	public void add(S e) {
		if (inizioLista == null) {
			inizioLista = new Puntatore(new Cella(e));
			inizioLista.cella.next = inizioLista.cella.prev = inizioLista;
		} else {

			Puntatore p = new Puntatore(new Cella(e));
			p.cella.next = inizioLista.cella.next;
			p.cella.next.cella.prev = p;
			p.cella.prev = inizioLista;
			inizioLista.cella.next = p;
		}
	}

	@Override
	public void forward() {
		isForward = true;

	}

	@Override
	public void backward() {
		isForward = false;

	}


	@Override
	public Iterator<S> iterator() {
		return new CarrelloIterator(this);
	}

}
