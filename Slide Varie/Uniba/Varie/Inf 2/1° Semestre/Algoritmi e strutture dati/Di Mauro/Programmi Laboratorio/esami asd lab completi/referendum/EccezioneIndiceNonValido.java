package referendum;

public class EccezioneIndiceNonValido extends RuntimeException{
	
	EccezioneIndiceNonValido(){
		
	}

	EccezioneIndiceNonValido(String messaggio){
		super(messaggio);
	}


}
