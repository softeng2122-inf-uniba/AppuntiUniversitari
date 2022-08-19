package Fattura;

import java.util.Iterator;

import Fattura.Interfaces.Pila;

public abstract class Fattura {

	Pila<Bene> beni;
	protected String alfanum;
	protected int data;
	protected Persona venditore;
	protected Persona compratore;

	public Fattura(String alfanum, int data, Persona venditore,
			Persona compratore) {
		this.alfanum = alfanum;
		this.data = data;
		this.venditore = venditore;
		this.compratore = compratore;

	}

	public void aggiungiBene(String str, int q, int i) {

		beni.push(new Bene(str, q, i));

	}

	public Bene ultimo() {
		return beni.top();
	}

	public int quantitàUltimoBene() {
		return beni.top().quantita;
	}

	public int importoUltimoBene() {
		return beni.top().importo;
	}

	public void rimuoviUltimoBene() {
		beni.pop();
	}

	public int totaleImporto() {

		int tot = 0;

		for (Bene b : beni) {

			tot += b.importo * b.quantita;

		}
		return tot;
	}

	public int numBeniFatturati() {
		int n = 0;
		for (Bene b : beni)
			n++;
		return n;
	}

	public boolean uguali(Fattura f) {

		boolean uguali = false;
		if (this.data == f.data && this.venditore.nome.equals(f.venditore.nome)
				&& this.compratore.nome.equals(f.compratore.nome)) {

			if (this.numBeniFatturati() == f.numBeniFatturati()) {

				Iterator itPrimaFattura = this.beni.iterator();
				Iterator itSecondaFattura = f.beni.iterator();

				if (this.numBeniFatturati() > 0) {

					while (itPrimaFattura.hasNext()) {
						if (((Bene) itPrimaFattura.next()).nome
								.equals(((Bene) itSecondaFattura.next()).nome))
							uguali = true;
						else
							uguali = false;
					}
				} else
					uguali = true;

			}

		}
		return uguali;

	}

}
