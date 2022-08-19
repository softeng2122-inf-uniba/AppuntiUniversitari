package MarketBasketAnalysis;

public class Cella {

	Object elem;
	Puntatore next, prev;

	public Cella(Object e) {
		this.elem = e;
		this.next = this.prev = null;
	}

}
