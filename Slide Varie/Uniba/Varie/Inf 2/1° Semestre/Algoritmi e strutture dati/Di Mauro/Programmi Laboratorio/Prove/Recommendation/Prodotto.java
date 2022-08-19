package Recommendation;

public class Prodotto {

	String nome;
	int prezzo;

	public String getNome() {
		return nome;
	}

	public int getPrezzo() {
		return prezzo;
	}

	public Prodotto(String n, int p) {
		this.nome = n;
		this.prezzo = p;
	}
	
	public String toString(){
		String res = null;
		
		res=this.nome+" "+this.prezzo;
		return res;
		
	}

}
