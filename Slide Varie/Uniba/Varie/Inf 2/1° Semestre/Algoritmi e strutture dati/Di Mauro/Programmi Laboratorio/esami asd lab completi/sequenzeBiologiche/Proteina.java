package sequenzeBiologiche;
import listaSemplice.*;
public class Proteina extends Polimero{
	
	public Proteina (String proteinaString){
		char [] proteina=proteinaString.toCharArray();
		sequenza= new AList();
		for (int i=0; i<proteina.length; i++) {
			Aminoacido a= Aminoacidi.aminoacidi.get(proteina[i] );
			if (a==null) throw new IllegalAminoacido("proteina: " + proteinaString + " non valida");
			sequenza.add(a);
		}
	}

}
