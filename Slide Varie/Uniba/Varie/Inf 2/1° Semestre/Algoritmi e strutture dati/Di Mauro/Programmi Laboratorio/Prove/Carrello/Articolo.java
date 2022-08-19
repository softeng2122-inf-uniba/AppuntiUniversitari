package Carrello;

public class Articolo implements Comparable {

	String nome;
	String misura;

	public Articolo(String nome, String misura) {

		this.nome = nome;
		this.misura = misura;

	}

	public String toString() {

		String res = this.nome + " " + this.misura;
		return res;

	}

	@Override
	public int compareTo(Object o) {
		if (this.nome.equals(((Articolo) o).nome))
			return 0;
		return -1;

	}

	public static void main(String[] args) {

		Articolo follini = new Articolo("frollini", "1");
		Articolo follini2 = new Articolo("frollini", "1");

		System.out.println(follini.compareTo(follini2));

	}

}
