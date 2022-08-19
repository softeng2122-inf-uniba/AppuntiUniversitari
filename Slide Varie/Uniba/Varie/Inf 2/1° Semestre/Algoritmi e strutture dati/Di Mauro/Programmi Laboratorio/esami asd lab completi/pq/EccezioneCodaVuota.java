package pq;

public class EccezioneCodaVuota extends RuntimeException{
	
	EccezioneCodaVuota(){
		
	}

	EccezioneCodaVuota(String messaggio){
		super (messaggio);
	}
	


}
