package Bussola;

public class Bussola {

	private CircList<Cardinale> ago = new ListaCircDC<Cardinale>();
	private Cardinale direz; //contiene il primo elemento della listacircolare
	
	
	public Bussola(){
		ago.addCircList(Cardinale.nord);
		ago.addCircList(Cardinale.nordest);
		ago.addCircList(Cardinale.est);
		ago.addCircList(Cardinale.sudest);
		ago.addCircList(Cardinale.sud);
		ago.addCircList(Cardinale.sudovest);
		ago.addCircList(Cardinale.ovest);
		ago.addCircList(Cardinale.nordovest);
		this.direz=ago.value();
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
