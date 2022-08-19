package referendum;

public class EccezioneQuesitoNonValido extends RuntimeException{

	EccezioneQuesitoNonValido(){
		
	}

	EccezioneQuesitoNonValido(String messaggio){
		super(messaggio);
	}
}
