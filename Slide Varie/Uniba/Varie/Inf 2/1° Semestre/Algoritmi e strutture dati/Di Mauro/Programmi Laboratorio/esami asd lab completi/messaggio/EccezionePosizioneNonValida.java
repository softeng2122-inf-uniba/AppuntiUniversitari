package messaggio;

public class EccezionePosizioneNonValida extends RuntimeException{
	EccezionePosizioneNonValida(){
		
	}
	
	EccezionePosizioneNonValida(String messaggio){
		super (messaggio);
	}

}
