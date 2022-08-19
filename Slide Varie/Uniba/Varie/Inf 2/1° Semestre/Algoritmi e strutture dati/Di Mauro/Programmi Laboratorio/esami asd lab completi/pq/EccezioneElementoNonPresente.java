package pq;

public class EccezioneElementoNonPresente extends RuntimeException{
	
	EccezioneElementoNonPresente(){
		
	}
	
	EccezioneElementoNonPresente(String messaggio){
		super(messaggio);
	}



}
