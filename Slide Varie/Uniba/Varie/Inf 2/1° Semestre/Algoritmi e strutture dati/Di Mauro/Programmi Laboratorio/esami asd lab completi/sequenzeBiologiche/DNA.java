package sequenzeBiologiche;
import listaSemplice.*;
public class DNA extends Polimero{

	public DNA (String stringDNA){
		
		char [] dna= stringDNA.toCharArray();
		sequenza= new AList();
		for (int i=0; i<dna.length; i++) {
			Nucleotide n= Nucleotidi.nucleotidi.get(dna[i]);
			if (n==null) throw new IllegalNucleotide("dna: " + stringDNA + " non valido");
			sequenza.add(n);
		}
	}
	
}
