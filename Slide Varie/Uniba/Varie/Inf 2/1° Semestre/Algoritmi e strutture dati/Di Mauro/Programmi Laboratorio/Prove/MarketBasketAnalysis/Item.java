package MarketBasketAnalysis;

import MarketBasketAnalysis.Articoli.Articolo;

public class Item {
	
	Articolo articolo;
	int quantita;
	Item next,prev=null;
	
	public Item(Articolo a,int q){
		this.articolo=a;
		this.quantita=q;
	}

	public Articolo getArticolo() {
		return articolo;
	}

	public int getQuantita() {
		return quantita;
	}

}
