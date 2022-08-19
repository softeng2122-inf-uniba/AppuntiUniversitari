package quesito;

public class EccezioneQuesitoVuoto extends RuntimeException{
	
	EccezioneQuesitoVuoto(){
		
	}

	EccezioneQuesitoVuoto(String messaggio){
		super(messaggio);
	}

}
