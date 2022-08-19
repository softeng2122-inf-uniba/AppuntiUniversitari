package Fattura;

import Fattura.Structure.PilaHD;

public class FatturaHD extends Fattura {

	public FatturaHD(String alfanum, int data, Persona venditore,
			Persona compratore) {
		super(alfanum, data, venditore, compratore);
		beni = new PilaHD<Bene>();
	}

}
