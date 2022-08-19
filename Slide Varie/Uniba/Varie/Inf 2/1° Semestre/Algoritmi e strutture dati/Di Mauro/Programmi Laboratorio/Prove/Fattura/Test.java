package Fattura;

import java.util.Iterator;

public class Test {
	
	public static void main(String[] args) {

		FatturaHD fatt1 = new FatturaHD("123", 11, new Persona("dino"),
				new Persona("sauro"));
		fatt1.aggiungiBene("burro", 2, 5);
		fatt1.aggiungiBene("coca", 5, 7);
		fatt1.aggiungiBene("pc", 1, 400);

		// itera sui beni della prima fattura
		Iterator<Bene> it1 = fatt1.beni.iterator();
		System.out.println("\n Prima Fattura: \n");

		while (it1.hasNext()) {
			Bene b = it1.next();
			System.out.println("Bene: " + b.nome + " Quantità: " + b.quantita
					+ " Importo: " + b.importo);
		}

		FatturaHD fatt2 = new FatturaHD("123", 11, new Persona("dino"),
				new Persona("sauro"));

		fatt2.aggiungiBene("burro", 2, 5);
		fatt2.aggiungiBene("coca", 5, 7);
		fatt2.aggiungiBene("pc", 1, 400);

		// itera sui beni della seconda fattura
		Iterator<Bene> it2 = fatt2.beni.iterator();
		System.out.println("\n Seconda Fattura: \n");

		while (it2.hasNext()) {
			Bene b = it2.next();
			System.out.println("Bene: " + b.nome + " Quantità: " + b.quantita
					+ " Importo: " + b.importo);
		}

		FatturaHD fatt3 = new FatturaHD("256", 18, new Persona("Donato"),
				new Persona("Michelangelo"));

		fatt3.aggiungiBene("fanta", 3, 52);
		fatt3.aggiungiBene("sprite", 6, 76);
		fatt3.aggiungiBene("finestra", 4, 4500);

		// itera sui beni della terza fattura
		Iterator<Bene> it3 = fatt3.beni.iterator();
		System.out.println("\nTerza Fattura: \n");

		while (it3.hasNext()) {
			Bene b = it3.next();
			System.out.println("Bene: " + b.nome + " Quantità: " + b.quantita
					+ " Importo: " + b.importo);
		}

		System.out.println("\nLa prima e la seconda fattura sono uguali??  "
				+ fatt1.uguali(fatt2));
		System.out.println("\nLa seconda e la terza fattura sono uguali??  "
				+ fatt2.uguali(fatt3));

	}
}
