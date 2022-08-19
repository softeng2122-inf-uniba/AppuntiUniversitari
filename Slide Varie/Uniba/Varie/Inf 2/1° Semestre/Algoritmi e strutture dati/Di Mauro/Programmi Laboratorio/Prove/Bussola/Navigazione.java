package Bussola;

import java.util.LinkedList;

public class Navigazione {

	private LinkedList<Record> list = new LinkedList<Record>();
	private Bussola buss = new Bussola();

	private void ruota(int i) {

		// genera un intero da 0 a 1 per ruotare la bussola o in avanti o
		// indietro
		int piuomeno = (int) Math.round((Math.random() * 2));
		switch (piuomeno) {
		case 0: {
			buss.ruotaA();
			list.add(new Record(i, buss.direzione()));
			break;
		}
		case 1: {
			buss.ruotaI();
			list.add(new Record(i, buss.direzione()));
			break;
		}
		default:
			break;
		}

	}

	public String toString() {
		String res = "";
		for (Record rec : list) {
			res += "\n" + rec.getN() + " " + rec.getDirezione().toString();
		}
		return res;

	}

	public void naviga(int n) {

		for (int i = 0; i < n; i++) {
			// genera un intero da 0 a 2 per "estrarre" la probabilità di
			// ruotare la bussola
			int m = (int) Math.round((Math.random() * 3));
			switch (m) {
			case 0:
				ruota(i);
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

	public static void main(String[] args) {

		Navigazione nave = new Navigazione();
		nave.naviga(30);

		System.out.println(nave.toString());

	}
}
