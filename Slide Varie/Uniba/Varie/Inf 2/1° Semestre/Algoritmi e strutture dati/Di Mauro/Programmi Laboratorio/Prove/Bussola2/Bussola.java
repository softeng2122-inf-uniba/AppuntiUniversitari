package Bussola2;

import Bussola2.Interface.CircList;
import Bussola2.Struttura.ListaCircDC;

public class Bussola {

	private CircList<Cardinale> ago;

	public void ruotaA() {
		ago.ruotaAvanti();
	}

	public void ruotaI() {
		ago.ruotaIndietro();
	}

	public Cardinale direzione() {
		return ago.value();
	}

	public Bussola() {

		ago = new ListaCircDC<Cardinale>();
		ago.addCircList(Cardinale.nord);
		ago.addCircList(Cardinale.nordest);
		ago.addCircList(Cardinale.est);
		ago.addCircList(Cardinale.sudest);
		ago.addCircList(Cardinale.sud);
		ago.addCircList(Cardinale.sudovest);
		ago.addCircList(Cardinale.ovest);
		ago.addCircList(Cardinale.nordovest);

	}

}
