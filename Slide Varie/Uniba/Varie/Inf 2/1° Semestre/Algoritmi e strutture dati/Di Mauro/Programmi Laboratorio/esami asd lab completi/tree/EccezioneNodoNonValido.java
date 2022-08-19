package tree;

public class EccezioneNodoNonValido extends RuntimeException{
	EccezioneNodoNonValido(){
		
	}
	
	EccezioneNodoNonValido(String messaggio){
		super (messaggio);
	}
}
