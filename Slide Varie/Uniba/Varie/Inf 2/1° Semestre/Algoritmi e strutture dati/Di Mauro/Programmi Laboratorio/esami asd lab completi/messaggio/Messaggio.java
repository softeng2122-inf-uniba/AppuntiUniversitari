package messaggio;

import listaIndicizzata.*;

public class Messaggio {
	private ListaIndicizzata<Datagramma> messaggio= new ListaIndicizzataRD<Datagramma>();
	private int ultimo=-1;
	private int ultimoValoreValido=-1;
	
	public void addDatagramma(Datagramma d) {
		
		try {
			
			messaggio.addElement(d, d.getIdentificativo());
			if (d.getUltimo()) {
				ultimo=d.getIdentificativo();
				ultimoValoreValido=ultimo;
			} else {
				if (d.getIdentificativo()>ultimoValoreValido) {
					ultimoValoreValido=d.getIdentificativo();
				}
			}
			
		} catch (EccezionePosizioneNonValida e){
			throw new EccezioneIdDatagrammaNonValido("id datagramma non valido");
		} catch (undefinedElement e){
			throw new EccezioneDatagrammaNullo("datagramma nullo");
		}	
	}
	
	public boolean completo(){
		
		if (ultimo==-1) return false; 
		int datagrammiAggiunti=messaggio.numberElements();
		if (datagrammiAggiunti==(ultimo+1)) return true;
		else return false;

	}
	
	public boolean esistedatagramma(int i){
		if (ultimo!=-1) {
			if (i<0 || i>ultimo ) throw new EccezionePosizioneNonValida("indice non valido");
			return messaggio.isEmpty(i);
		} else {
			if (i<0) throw new EccezionePosizioneNonValida("indice non valido");
			return messaggio.isEmpty(i);
		}
	}
	
	
	public String toString(){
		String s = "";
		
		for (int i=0; i<=ultimoValoreValido; i++) {
			if (messaggio.isEmpty(i)) {
				s=s+null;
			} else {
				Datagramma d=messaggio.getElement(i);
				s=s+ d.getdati();
			}
		}
		
		return s;
	}
}
