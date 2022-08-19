package sequenzeBiologiche;

import java.util.HashMap;

public class Nucleotide extends Monomero{

	static final char adenimaSymbol='A';
	static final char citosinaSymbol='C';
	static final char guanimaSymbol='G';
	static final char timinaSymbol='T';
	
	private static final HashMap<Character,String> nucleotidi= new HashMap<Character,String>();
	static {
		nucleotidi.put(adenimaSymbol, "adenima");
		nucleotidi.put(citosinaSymbol, "citosina");
		nucleotidi.put(guanimaSymbol, "guanima");
		nucleotidi.put(timinaSymbol, "timina");
	}
	
	public Nucleotide (char s){
		if (s==adenimaSymbol || s==citosinaSymbol || s==guanimaSymbol || s==timinaSymbol) {
			simbolo=s;
			nome=nucleotidi.get(s);
		} else {
			throw new IllegalNucleotide("nucleotide non volido");
		}
	}
}
