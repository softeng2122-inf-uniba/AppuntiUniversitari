package Fatt;

import java.util.Iterator;

public abstract class Fattura {

	Pila<Bene> beni;
	String alfanum;
	String data;
	Persona compratore;
	Persona venditore;
	int numBeni;

	public Fattura(String alfanum, String data, Persona compratore,
			Persona venditore) {

		this.alfanum = alfanum;
		this.data = data;
		this.compratore = compratore;
		this.venditore = venditore;
		numBeni = 0;

	}

	public void aggiungiBene(Bene b) {

		beni.push(b);
		numBeni++;

	}

	public String ultimoBene() {
		return beni.top().nome;
	}

	public int quantitaUltimoBene() {
		return beni.top().quantita;
	}

	public int importoUltimoBene() {
		return beni.top().importo;
	}

	public void rimuoviUltimoBene() {
		beni.pop();
		numBeni--;
	}

	public int totaleImporto() {

		int tot = 0;

		for (Bene b : beni) {
			tot += b.importo * b.quantita;
		}

		return tot;
	}

	public int numeroBeniFatturati() {
		return numBeni;
	}

	public boolean uguali(Fattura f) {

		boolean equal = false;

		if (this.data.equals(f.data)
				&& this.venditore.nome.equals(f.venditore.nome)
				&& this.compratore.nome.equals(f.compratore.nome)
				&& this.numBeni == f.numBeni) {
			Iterator it1 = this.beni.iterator();
			Iterator it2 = f.beni.iterator();
			while (it1.hasNext()) {
				if (((Bene) it1.next()).nome.equals(((Bene) it2.next()).nome)) {
					equal = true;

				} else
					return false;
			}

		}

		return equal;
	}
}
