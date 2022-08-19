package Skype;

import java.util.Iterator;

public class Skype implements Comparable {
	 IndexedList<Pacchetto> comunicazione = new IndexedLL<Pacchetto>();

	public void addPacchetto(Pacchetto p) {

		comunicazione.addItem(p, p.identificativo);

	}

	public boolean complete() {

		boolean complete = false;
		if (comunicazione.numberItems() > 0) {
			for (Pacchetto p : comunicazione)
				if (p.ultimo == true) {
					for (int i = 0; i < p.identificativo + 1; i++) {
						if (comunicazione.isEmpty(i))
							return false;
					}
					return true;
				}
		}
		return complete;

	}

	@Override
	public int compareTo(Object p) {
		int res;
		if (this.complete() && ((Skype) p).complete()) {

			if (this.comunicazione.numberItems() == ((Skype) p).comunicazione
					.numberItems())

				res = 0;
			else if (this.comunicazione.numberItems() < ((Skype) p).comunicazione
					.numberItems())
				res = -1;
			else
				res = 1;

		} else
			throw new ComunicazioneIncompletaException(
					"Una delle due comunicazioni non è completa");

		return res;
	}

	public String toString() {

		String res = "";

		for (Pacchetto p : this.comunicazione)
			res += " " + p.dati;

		return res;

	}

	public static void main(String[] args) {

		Skype sk = new Skype();
		Skype sk2 = new Skype();

		sk.addPacchetto(new Pacchetto(new Utente("ciccio"),
				new Utente("franco"), 0, "ahah", false));

		sk.addPacchetto(new Pacchetto(new Utente("uccio"), new Utente(
				"de santis"), 4, "olee", true));
		sk.addPacchetto(new Pacchetto(new Utente("uccio"), new Utente(
				"de santis"), 1, "olee", false));
		sk.addPacchetto(new Pacchetto(new Utente("uccio"), new Utente(
				"de santis"), 2, "olee", false));
		
		sk.addPacchetto(new Pacchetto(new Utente("uccio"), new Utente(
				"de santis"), 3, "olee", false));
	

		System.out.println(sk.complete());
	}

}
