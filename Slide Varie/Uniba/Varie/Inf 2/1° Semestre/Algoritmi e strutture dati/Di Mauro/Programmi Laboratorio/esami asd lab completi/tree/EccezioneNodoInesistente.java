package tree;

public class EccezioneNodoInesistente extends RuntimeException{
	
	EccezioneNodoInesistente() {
		
	}
	
	EccezioneNodoInesistente(String messaggio){
		super (messaggio);
	}

}
