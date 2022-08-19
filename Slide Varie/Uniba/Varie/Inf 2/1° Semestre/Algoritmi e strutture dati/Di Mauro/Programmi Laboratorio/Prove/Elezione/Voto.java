package Elezione;

public class Voto {

	ListaElettorale s;

	public Voto(ListaElettorale s) {
		this.s = s;
	}

	public Voto() {
		s = new ListaElettorale("Scheda bianca", null);
	}

	public boolean nullo() {

		return this.s == null;

	}

	public boolean sbianca() {
		return this.s.nome.equalsIgnoreCase("Scheda bianca");
	}

	public ListaElettorale voto() {
		if (!(this.nullo() || this.sbianca()))
			return this.s;

		return null;
	}

	public static void main(String[] args) {
		ListaElettorale l = new ListaElettorale("forza", null);
		Voto v = new Voto(null);

	}

}
