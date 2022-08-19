package SkypeCollegato;

import java.util.LinkedList;

public class SkypeTest {

	public static void popolaComunicazione(Skype sk1, int n) {
		LinkedList<Integer> list = new LinkedList<Integer>();

		int i = 0;
		while (i < n) {
			int indice = (int) (Math.random() * n);
			if (!list.contains(indice)) {
				list.add(indice);
				if (indice == (n - 1)) {
					Pacchetto p = new Pacchetto(new Utente("ciccio"),
							new Utente("franco"), indice,
							String.valueOf(Integer.hashCode(indice)), true);
					sk1.addPacchetto(p);
				} else {
					Pacchetto p = new Pacchetto(new Utente("ciccio"),
							new Utente("franco"), indice,
							String.valueOf(Integer.hashCode(indice)), false);
					sk1.addPacchetto(p);
				}
				i++;
			}

		}
	}

	public static void main(String[] args) {

		Skype sk1 = new Skype();
		Skype sk2 = new Skype();
		Skype sk3 = new Skype();
		
		popolaComunicazione(sk1, 7);
		System.out.println(sk1);
		
		popolaComunicazione(sk2, 9);
		System.out.println(sk2);
		
		popolaComunicazione(sk3, 13);
		System.out.println(sk3);
		
		System.out.println("\n\n");
		
		System.out.println(sk1.compareTo(sk2));
		System.out.println(sk2.compareTo(sk3));
		System.out.println(sk1.compareTo(sk3));
		
		System.out.println(sk3.compareTo(sk1));
		System.out.println(sk3.compareTo(sk3));


	}
}
