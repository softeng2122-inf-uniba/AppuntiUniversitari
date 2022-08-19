package referendum;

import quesito.*;
import dizionario.*;


public class Referendum {

	protected Dictionary<Quesito> referendum;
	private int aventiDirittoAlVoto;
	
	public Referendum(int n){
		referendum= new ArrayOrdinato<Quesito>();
		aventiDirittoAlVoto= n;
	}
	
	
	public void aggiungiQuesito(String q){
		Quesito<Voto> nQuesito= new Quesito<Voto>(q);
		try {
			referendum.insert(nQuesito, nQuesito.quesito);
		} catch (EccezioneChiaveGi‡Presente e){
			throw new EccezioneQuesitoGi‡Presente("il quesito " + q + " Ë gi‡ presente nel referendum");
		}
	}
	
	public void scrutinaVoto(String q, Voto v){
		
		Quesito<Voto> quesitoS= referendum.search(q); //cerco nel referendum il quesito da scrutinare		
		if (quesitoS==null) throw new EccezioneQuesitoNonValido("il qesito da scrutinare non esiste");
		referendum.search(q).add(v);
	}
	
	public int numVoti(String q){
		Quesito<Voto> quesito= referendum.search(q); //cerco nel referendum il quesito 	
		if (quesito==null) throw new EccezioneQuesitoNonValido("il qesito non esiste");
		return referendum.search(q).numberElements();
	}
	
	public Voto voto(String q, int i){
		Quesito<Voto> quesito= referendum.search(q); //cerco nel referendum il quesito 	
		if (quesito==null) throw new EccezioneQuesitoNonValido("il qesito non esiste");
		
		try {
			return (Voto) referendum.search(q).getElem(i);
		} catch (EccezioneIndiceNonValido e){
			throw new EccezioneIndiceNonValido("l'indice passato non Ë corretto");
		} catch (EccezioneQuesitoVuoto qv){
			throw new EccezioneIndiceNonValido("il quesito non ha voti scrutinati");
		}
		
	}
	
	public boolean quorum (String q){
		Quesito<Voto> quesito= referendum.search(q); //cerco nel referendum il quesito 		
		if (quesito==null) throw new EccezioneQuesitoNonValido("il qesito non esiste");
		int votiScrutinati=referendum.search(q).numberElements();
		
		if (votiScrutinati >= ((aventiDirittoAlVoto/2)+1)) return true;
		else return false;
	
	}
	
}
