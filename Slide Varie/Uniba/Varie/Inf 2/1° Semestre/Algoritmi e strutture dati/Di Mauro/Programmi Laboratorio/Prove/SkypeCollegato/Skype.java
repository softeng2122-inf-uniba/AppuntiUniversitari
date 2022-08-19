package SkypeCollegato;

public class Skype implements Comparable {
	private IndexedList<Pacchetto> comunicazione = new IndexedLL<Pacchetto>();

	public void addPacchetto(Pacchetto p) {
		comunicazione.addItem(p, p.getIdentificativo());
	}

	public boolean complete() {
		boolean complete = false;

		for (Pacchetto p : comunicazione) {
			if (p.isUltimo()) {
				for (int i = 0; i < comunicazione.numberItems(); i++) {
					if (comunicazione.isEmpty(i))
						return false;
					else
						complete = true;
				}
				break;
			}
		}

		return complete;
	}

	public String toString() {

		String res = "";

		for (int i = 0; i < comunicazione.numberItems(); i++) {
			if (!comunicazione.isEmpty(i))
				res += " " + comunicazione.getItem(i).getDati() + " ";
		}
		return res;
	}

	@Override
	public int compareTo(Object sk) {
		if (this.complete() && ((Skype) sk).complete()) {
			if (this.comunicazione.numberItems() == ((Skype) sk).comunicazione
					.numberItems())
				return 0;
			if (this.comunicazione.numberItems() < ((Skype) sk).comunicazione
					.numberItems())
				return -1;
			else
				return 1;
		}
		return -20;
	}

	public static void main(String[] args) {

		Skype sk = new Skype();
		Skype sk2 = new Skype();

		Pacchetto p1 = new Pacchetto(new Utente("ciccio"),
				new Utente("franco"), 5, "ciao", true);
		Pacchetto p2 = new Pacchetto(new Utente("ciccio"),
				new Utente("franco"), 4, "bello", true);
		Pacchetto p3 = new Pacchetto(new Utente("ciccio"),
				new Utente("franco"), 3, "sono", true);
		Pacchetto p4 = new Pacchetto(new Utente("ciccio"),
				new Utente("franco"), 2, "alessandro", true);
		Pacchetto p5 = new Pacchetto(new Utente("ciccio"),
				new Utente("franco"), 1, "come", true);
		Pacchetto p6 = new Pacchetto(new Utente("ciccio"),
				new Utente("franco"), 0, "stai?", true);

		Pacchetto p7 = new Pacchetto(new Utente("ciccio"),
				new Utente("franco"), 6, "stai?", true);
		sk.addPacchetto(p6);

		sk.addPacchetto(p3);

		sk.addPacchetto(p1);
		sk.addPacchetto(p2);

		sk.addPacchetto(p4);
		sk.addPacchetto(p5);

		sk2.addPacchetto(p6);
		sk2.addPacchetto(p1);
		sk2.addPacchetto(p2);
		sk2.addPacchetto(p4);
		sk2.addPacchetto(p5);
		sk2.addPacchetto(p3);

		System.out.println(sk.compareTo(sk2));

	}

}
