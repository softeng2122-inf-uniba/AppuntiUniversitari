package Skype;

import java.util.LinkedList;

public class SkypeTest {

	public static void main(String[] args) {

		Skype sk1 = new Skype();
		LinkedList<Integer> list = new LinkedList<Integer>();

		while (list.size()<7) {
			int i = (int) ((7) * Math.random());
			if (!list.contains(i)) {

				if (i == 6) {
					sk1.addPacchetto(new Pacchetto(new Utente("ciccio"),
							new Utente("cappuccio"), i, String.valueOf(i), true));
					list.add(i);
				}
				if (i < 6) {
					sk1.addPacchetto(new Pacchetto(new Utente("ciccio"),
							new Utente("cappuccio"), i, String.valueOf(i),
							false));
					list.add(i);
				}

				System.out.println(sk1);

			} else {
				System.out.println("contenuto");
			}

		}
	}

}
