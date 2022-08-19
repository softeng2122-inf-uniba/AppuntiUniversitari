package sequenzeBiologiche;

public class IllegalNucleotide extends RuntimeException{

	IllegalNucleotide(){
		
	}
	
	IllegalNucleotide(String messaggio){
		super (messaggio);
	}
}
