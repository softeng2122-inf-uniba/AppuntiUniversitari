package Bussola3;

public class Bussola {

	private CircList<Cardinale> ago;

	public Bussola() {
		ago = new ListaCircDC<Cardinale>();
		ago.addLast(Cardinale.nord);
		ago.addLast(Cardinale.nordest);
		ago.addLast(Cardinale.est);
		ago.addLast(Cardinale.sudest);
		ago.addLast(Cardinale.sud);
		ago.addLast(Cardinale.sudovest);
		ago.addLast(Cardinale.ovest);
		ago.addLast(Cardinale.nordovest);
	}

	public void ruotaA() {
		ago.ruotaAvanti();
	}

	public void ruotaI() {
		ago.ruotaIndietro();
	}

	public Cardinale direzione() {
		return ago.value();
	}

}
