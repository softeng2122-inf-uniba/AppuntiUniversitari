package Bussola2;

import java.util.LinkedList;

public class Navigazione {

	private Bussola buss = new Bussola();
	private LinkedList<Registrazione> list = new LinkedList<Registrazione>();

	private class Registrazione {
		private Cardinale direzione;
		private int istante;

		public Registrazione(Cardinale dir, int ist) {
			direzione = dir;
			istante = ist;
		}

		public Cardinale getDirezione() {
			return direzione;
		}

		public int getIstante() {
			return istante;
		}
	}

	public void naviga(int n) {

		for (int i = 0; i < n; i++) {
			int caso = (int) (Math.random() * 3);
			switch (caso) {

			case 0:
				int avantioindietro = (int) (Math.random() * 2);
				if (avantioindietro == 0) {

					buss.ruotaA();
					list.add(new Registrazione(buss.direzione(), i));
				}

				if (avantioindietro == 1) {
					buss.ruotaI();
					list.add(new Registrazione(buss.direzione(), i));
				}
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
		for (Registrazione reg : this.list)
			res += " |" + (reg.getIstante() + 1) + " " + reg.getDirezione();

		return res;

	}

	public static void main(String[] args) {
		Navigazione n = new Navigazione();

		n.naviga(30);
		System.out.println(n);

	}

}
