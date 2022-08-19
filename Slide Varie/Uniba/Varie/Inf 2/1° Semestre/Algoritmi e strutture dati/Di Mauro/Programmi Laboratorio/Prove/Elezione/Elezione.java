package Elezione;

import java.util.Arrays;
import java.util.LinkedList;

public class Elezione {

	int numVoti = 0;
	int nulle = 0;
	int bianche = 0;
	protected Dictionary<Integer> listeElettorali;

	public Elezione() {
		listeElettorali = new LinkedDict<Integer>();
	}

	public void aggiungiLista(ListaElettorale l) {
		listeElettorali.insert(0, l);

	}

	public void scrutinaVoto(Voto v) {
		if (v.voto() != null) {

			int n = numVoti(v.voto());
			listeElettorali.delete(v.voto());
			listeElettorali.insert(n + 1, v.voto());
		}

		else if (v.nullo())
			nulle++;
		else if (v.sbianca())
			bianche++;
		numVoti++;
	}

	public int numVoti(ListaElettorale l) {
		return listeElettorali.search(l);
	}

	public int nulle() {
		return nulle;
	}

	public int bianche() {
		return bianche;
	}

	public String elencoOrdinato() {
		String res = "";
		LinkedList<Integer> list = new LinkedList<Integer>();
		for (Integer i : listeElettorali) {
			list.add(i);
		}
		Object[] arrOrd = list.toArray();
		Arrays.sort(arrOrd);
		for (int i = 0; i < arrOrd.length; i++) {

			res += " " + arrOrd[i];
		}
		return res;
	}

	public static void main(String[] args) {

		Elezione e = new Elezione();
		ListaElettorale list = new ListaElettorale("w l'italia", null);
		ListaElettorale list2 = new ListaElettorale("in medio stat virtus",
				null);
		ListaElettorale list3 = new ListaElettorale("ecumenismo a sinistra",
				null);
		ListaElettorale list4 = new ListaElettorale("metamorfosi", null);

		e.aggiungiLista(list);
		e.aggiungiLista(list2);
		e.aggiungiLista(list3);
		e.aggiungiLista(list4);

		for (int i = 0; i < 30; i++) {

			int n = (int) (Math.random() * 4);
			switch (n) {
			case 0:
				e.scrutinaVoto(new Voto(list));
				break;
			case 1:
				e.scrutinaVoto(new Voto(list2));
				break;
			case 2:
				e.scrutinaVoto(new Voto(list3));
				break;
			case 3:
				e.scrutinaVoto(new Voto(list4));
				break;
			default:
				break;
			}

		}
		System.out.println(e.elencoOrdinato());

	}

}
