package Fatt;

import java.util.Iterator;

public class FatturaHD extends Fattura {

	public FatturaHD(String alfanum, String data, Persona compratore,
			Persona venditore) {
		super(alfanum, data, compratore, venditore);
		beni = new PilaHD<Bene>();
	}

	public static void main(String[] args) {
		FatturaHD fatt1 = new FatturaHD("132", "2014", new Persona("Ciccio"),
				new Persona("Donato"));
		fatt1.aggiungiBene(new Bene("Meringa", 3, 10));
		fatt1.aggiungiBene(new Bene("Berimba", 5, 10));
		
		FatturaHD fatt2 = new FatturaHD("147", "2014", new Persona("Ciccio"), new Persona("Donato"));
		fatt2.aggiungiBene(new Bene("Meringa", 4, 10));
		fatt2.aggiungiBene(new Bene("Berimba", 5, 10));

		
		Iterator it1=fatt1.beni.iterator();
		while (it1.hasNext()){
			
			Bene b=(Bene) it1.next();
			System.out.println(b.nome+" "+b.quantita+" "+b.importo);
			
			
		}
		
		
		
		
		
		System.out.println(fatt1.uguali(fatt2));

	}

}
