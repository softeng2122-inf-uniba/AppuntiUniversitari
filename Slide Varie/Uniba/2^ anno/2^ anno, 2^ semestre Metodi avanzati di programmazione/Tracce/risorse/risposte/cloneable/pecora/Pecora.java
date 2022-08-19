
enum Colore {
	Bianco,
	Nero
}

class PeloDiPecora implements Cloneable {
	private double lunghezza;
	private Colore colore;

	PeloDiPecora(double lunghezza, Colore colore) {
		this.lunghezza = lunghezza;
		this.colore = colore;
	}

	@Override
	public Object clone() {
		Object o = null;
		try {
			o = super.clone();
		} catch (CloneNotSupportedException e) {
			System.err.println(e.getMessage());
		}
		return o;
	}

	@Override
	public String toString() {
		return lunghezza + " " + colore;
	}
}

public class Pecora implements Cloneable {
	private String nome;
	private PeloDiPecora pelo;
	private int peso;

	Pecora(String nome, PeloDiPecora pelo, int peso) {
		this.nome = nome;
		this.pelo = pelo;
		this.peso = peso;
	}

	void setNome(String nome) {
		this.nome = nome;
	}

	void setPelo(PeloDiPecora pelo) {
		this.pelo = pelo;
	}

	void setPeso(int peso) {
		this.peso = peso;
	}

	@Override
	public Object clone() {
		Object o = null;
		try {
			o = super.clone();
			((Pecora) o).nome = new String(nome);
			((Pecora) o).pelo = (PeloDiPecora) pelo.clone();
		} catch (CloneNotSupportedException e) {
			System.err.println(e.getMessage());
		}
		return o;
	}

	@Override
	public String toString() {
		return nome + " " + pelo + " " + peso;
	}

	public static void main(String[] args) {
		Pecora pecora = new Pecora("dolly",
			new PeloDiPecora(2.0, Colore.Bianco), 100);

		Pecora nuovaPecora = (Pecora) pecora.clone();

		nuovaPecora.setNome("satana");
		nuovaPecora.setPelo(new PeloDiPecora(3.0, Colore.Nero));
		nuovaPecora.setPeso(200);

		System.out.println(pecora);
		System.out.println(nuovaPecora);
	}
}
