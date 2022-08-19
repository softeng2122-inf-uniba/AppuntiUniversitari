package pq;

public class EccezioneStrutturaVuota extends RuntimeException {
	
	EccezioneStrutturaVuota() {
		
	}
	
	EccezioneStrutturaVuota(String messaggio){
		super(messaggio);
	}

}
