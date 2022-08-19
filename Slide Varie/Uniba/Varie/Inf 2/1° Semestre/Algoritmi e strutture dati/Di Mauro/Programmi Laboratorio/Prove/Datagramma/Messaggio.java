package Datagramma;

import java.util.Iterator;

public class Messaggio {
	private ListaIndicizzata<Datagramma> messaggio = new IndexedList<Datagramma>();
	private int ultimo = -1;

	public void addDatagramma(Datagramma d) {

		messaggio.addElement(d, d.getIdentificativo());

	}

	public boolean completo() {
		boolean completo = false;

		for (Datagramma d : messaggio) {
			if (d == null)
				break;
			else if (d.getUltimo() == true) {
				for (int i = 0; i < messaggio.numberElements(); i++) {
					if (!(messaggio.isEmpty(i)))
						completo = true;
					else
						return false;

				}
			}
		}

		return completo;

	}

	public String toString() {

		String res = "";

		for (Datagramma d : messaggio)
			if (d != null)
				res += " " + d.getDati();

		return res;

	}

	public boolean confronta(Messaggio m) {

		boolean uguali = false;

		if (this.messaggio.numberElements() == m.messaggio.numberElements()) {

			if (this.completo() && m.completo()) {

				Iterator it = m.messaggio.iterator();
				for (Datagramma d : this.messaggio)
					if (d.getDati().equals(((Datagramma) it.next()).getDati()))
						uguali = true;
					else {
						uguali = false;
						break;
					}

			}

		}

		return uguali;

	}

	public static void main(String[] args) {

		Messaggio m = new Messaggio();
		Datagramma d1 = new Datagramma(null, null, 0, "ciao", false);
		Datagramma d2 = new Datagramma(null, null, 1, "alessandro", false);
		Datagramma d3 = new Datagramma(null, null, 2, "sono", false);
		Datagramma d4 = new Datagramma(null, null, 3, "tuo", false);
		Datagramma d5 = new Datagramma(null, null, 4, "fratello", false);
		Datagramma d6 = new Datagramma(null, null, 5, "e", false);
		Datagramma d7 = new Datagramma(null, null, 6, "vado", false);
		Datagramma d8 = new Datagramma(null, null, 7, "a", false);
		Datagramma d9 = new Datagramma(null, null, 8, "scuola", false);
		Datagramma d10 = new Datagramma(null, null, 9, "arrivederci", true);

		m.addDatagramma(d1);
		m.addDatagramma(d3);
		m.addDatagramma(d10);
		m.addDatagramma(d4);
		m.addDatagramma(d6);
		m.addDatagramma(d5);
		m.addDatagramma(d7);
		m.addDatagramma(d8);
		m.addDatagramma(d9);
		m.addDatagramma(d2);

		System.out.println(m);
	}

}
