package Orologio;

public class Test {

	public static void main(String[] args) {

		OrologioDaPolso a = new OrologioDaPolso();
		OrologioDaPolso b = new OrologioDaPolso();

		// stampa true perchè sono uguali
		System.out.println(a.equals(b));

		// ferma il primo alle 2 e 5
		a.stopAt(new Ora("2"), new Minuto("5"));

		// stampa false perchè ora non segnano la stessa ora
		System.out.println(a.equals(b));

		// il primo completa la giornata
		a.stopAt(new Ora("24"), new Minuto("59"));

		// anche il secondo completa la giornata
		b.stopAt(new Ora("24"), new Minuto("59"));

		// ora sono uguali infatti stampa true
		System.out.println(a.equals(b));

	}

}
