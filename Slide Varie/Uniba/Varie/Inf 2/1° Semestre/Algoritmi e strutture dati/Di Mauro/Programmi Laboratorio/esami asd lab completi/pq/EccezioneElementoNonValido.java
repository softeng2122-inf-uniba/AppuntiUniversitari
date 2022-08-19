package pq;

public class EccezioneElementoNonValido extends RuntimeException{
	
	EccezioneElementoNonValido() {
		
	}
	
	EccezioneElementoNonValido(String messaggio){
		super(messaggio);
	}
}
