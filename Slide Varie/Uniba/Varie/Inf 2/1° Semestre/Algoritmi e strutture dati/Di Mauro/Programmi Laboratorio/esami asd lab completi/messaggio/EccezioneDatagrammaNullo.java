package messaggio;

public class EccezioneDatagrammaNullo extends RuntimeException {
	
	EccezioneDatagrammaNullo(){
		
	}
	
	EccezioneDatagrammaNullo(String messaggio){
		super (messaggio);
	}

}
