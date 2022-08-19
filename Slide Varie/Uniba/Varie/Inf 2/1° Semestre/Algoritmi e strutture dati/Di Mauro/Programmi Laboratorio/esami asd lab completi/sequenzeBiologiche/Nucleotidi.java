package sequenzeBiologiche;

import java.util.HashMap;

public class Nucleotidi {

	public static HashMap<Character,Nucleotide> nucleotidi= new HashMap<Character,Nucleotide>();
	
	static{
		nucleotidi.put(Nucleotide.adenimaSymbol, new Nucleotide(Nucleotide.adenimaSymbol));
		nucleotidi.put(Nucleotide.citosinaSymbol, new Nucleotide(Nucleotide.citosinaSymbol));
		nucleotidi.put(Nucleotide.guanimaSymbol, new Nucleotide(Nucleotide.guanimaSymbol));
		nucleotidi.put(Nucleotide.timinaSymbol, new Nucleotide(Nucleotide.timinaSymbol));
	}
	
	
}
