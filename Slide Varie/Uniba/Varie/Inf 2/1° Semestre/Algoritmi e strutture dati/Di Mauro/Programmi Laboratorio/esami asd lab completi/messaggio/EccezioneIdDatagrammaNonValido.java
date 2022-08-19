package messaggio;

public class EccezioneIdDatagrammaNonValido extends RuntimeException{
	
	EccezioneIdDatagrammaNonValido(){
		
	}
	
	EccezioneIdDatagrammaNonValido(String messaggio){
		super (messaggio);
	}
	
}
