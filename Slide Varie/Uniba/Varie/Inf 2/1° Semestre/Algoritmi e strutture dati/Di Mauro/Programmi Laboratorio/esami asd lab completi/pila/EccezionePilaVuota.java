package pila;

public class EccezionePilaVuota extends RuntimeException {
	
	EccezionePilaVuota(){
		
	}
	
	EccezionePilaVuota(String messaggio){
		super (messaggio);
	}

}
