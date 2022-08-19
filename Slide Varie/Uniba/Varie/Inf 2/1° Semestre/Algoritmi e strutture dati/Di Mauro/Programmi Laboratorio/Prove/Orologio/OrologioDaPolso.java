package Orologio;

import java.util.Iterator;

public class OrologioDaPolso {

	Orologio<Ora> ore = new Orologio<Ora>();
	Orologio<Minuto> minuti = new Orologio<Minuto>();

	public OrologioDaPolso() {

		// inserisce le ore
		for (int i = 1; i < 25; i++) {
			ore.orologio.add(new Ora(Integer.toString(i)));
		}

		// inserisce i minuti
		for (int i = 0; i < 60; i++) {
			minuti.orologio.add(new Minuto(Integer.toString(i)));
		}

		// stampa tutte le ore e i minuti
		for (Ora or : ore.orologio) {
			for (Minuto min : minuti.orologio)
				System.out.println(or.nome + ":" + (min.nome));
		}
	}

	/*
	 * fa ruotare le lancette (value) di ore e minuti fintanto che il nome
	 * dell'ora e del minuto segnati dalla lancetta non sono uguali a quelli
	 * passati come parametro
	 */
	void stopAt(Ora o, Minuto m) {

		while (!(this.ore.orologio.value().nome.equals(o.nome))) {
			this.ore.orologio.rotateF();
		}
		while (!(this.minuti.orologio.value().nome.equals(m.nome))) {
			this.minuti.orologio.rotateF();
		}

		System.out.println(this.ore.orologio.value().nome + ":"
				+ this.minuti.orologio.value().nome);

	}

	boolean equals(OrologioDaPolso b) {

		boolean equal = false;

		// controllo sulle frazioni
		if (this.ore.orologio.size() == b.ore.orologio.size()) {
			if (this.minuti.orologio.size() == b.minuti.orologio.size()) {

				for (Ora or : this.ore.orologio) {
					if (or.nome.equals(b.ore.orologio.value().nome)) {
						equal = true;
						b.ore.orologio.rotateF();
					} else
						return equal = false;

				}
				for (Minuto min : this.minuti.orologio) {
					if (min.nome.equals(b.minuti.orologio.value().nome)) {
						equal = true;
						b.minuti.orologio.rotateF();
					} else
						return equal = false;
				}

				// controllo sulle lancette
				if (this.ore.orologio.value().nome.equals(b.ore.orologio
						.value().nome)) {
					if (this.minuti.orologio.value().nome
							.equals(b.minuti.orologio.value().nome))
						equal = true;
				} else
					return equal = false;
			}
		}
		return equal;

	}

}
