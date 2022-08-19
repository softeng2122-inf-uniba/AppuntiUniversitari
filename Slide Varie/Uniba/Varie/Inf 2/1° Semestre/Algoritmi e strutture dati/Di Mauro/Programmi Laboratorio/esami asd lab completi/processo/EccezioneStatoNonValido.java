package processo;

public class EccezioneStatoNonValido extends RuntimeException{
	
	EccezioneStatoNonValido(){
		
	}
	
	EccezioneStatoNonValido(String messaggio) {
		super(messaggio);
	}


}
