package Bussola3;

import java.util.LinkedList;

public class Navigazione {

	private Bussola bussola = new Bussola();
	private LinkedList<Record> navigazione = new LinkedList<Navigazione.Record>();

	private class Record {
		private int istante;
		private Cardinale direzione;

		public Record(int istante, Cardinale direzione) {
			this.istante = istante;
			this.direzione = direzione;
		}
	}

	public void naviga(int n) {

		for (int i = 0; i < n; i++) {

			int dado = (int) (Math.random() * 3);
			switch (dado) {
			case 0:
				int dado2 = (int) (Math.random() * 2);
				if (dado2 == 0)
					bussola.ruotaA();
				if (dado2 == 1)
					bussola.ruotaI();
				navigazione.add(new Record(i, bussola.direzione()));
				break;
			case 1:
				break;
			case 2:
				break;
			default:
				break;

			}

		}

	}

	public String toString() {

		String res = "";

		for (Record rec : navigazione)
			res += " " + (rec.istante + 1) + " " + rec.direzione.toString();

		return res;

	}

	public static void main(String[] args) {
		
		Navigazione nave = new Navigazione();
		nave.naviga(30);
		System.out.println(nave);
	}

}
