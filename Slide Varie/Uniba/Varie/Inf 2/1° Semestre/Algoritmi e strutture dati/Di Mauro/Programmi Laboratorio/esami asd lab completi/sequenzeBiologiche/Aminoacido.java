package sequenzeBiologiche;

import java.util.HashMap;

public class Aminoacido extends Monomero{
	
	static final char alanimaS='A';
	static final char cisteinaS='C';
	static final char acidoAsparticoS='D';
	static final char acidoGluatammicoS='E';
	static final char fenilalaninaS='F';
	static final char glicinaS='G';
	static final char istidinaS='H';
	static final char isoleucinaS='I';
	static final char lisinaS='K';
	static final char leucinaS= 'L';
	static final char metionimaS='M';
	static final char asparaginaS='N';
	static final char prolinaS = 'P';
	static final char glutamminaS= 'Q';
	static final char arginaS='R';
	static final char serinaS= 'S';
	static final char treoninaS='T';
	static final char valinaS = 'V';
	static final char triptofanoS='W';
	static final char tirosinaS='Y';
	
	private static final HashMap<Character,String> aminoacidi=new HashMap<Character,String>();
	
	static {
		aminoacidi.put(alanimaS, "alanima");
		aminoacidi.put(cisteinaS, "cisteina");
		aminoacidi.put(acidoAsparticoS, "acido aspartico");
		aminoacidi.put(acidoGluatammicoS, "acido gluatammico");
		aminoacidi.put(fenilalaninaS, "fenilalanina");
		aminoacidi.put(glicinaS, "glicina");
		aminoacidi.put(istidinaS, "istidina");
		aminoacidi.put(isoleucinaS, "isoleucina");
		aminoacidi.put(lisinaS, "lisina");
		aminoacidi.put(leucinaS, "leucina");
		aminoacidi.put(metionimaS, "metionima");
		aminoacidi.put(asparaginaS, "asparagina");
		aminoacidi.put(prolinaS, "prolina");
		aminoacidi.put(glutamminaS, "glutammina");
		aminoacidi.put(arginaS, "argina");
		aminoacidi.put(serinaS, "serina");
		aminoacidi.put(treoninaS, "treonina");
		aminoacidi.put(valinaS, "valina");
		aminoacidi.put(triptofanoS, "triptofano");
		aminoacidi.put(tirosinaS, "tirosina");	
	}
	
	public Aminoacido(char am){
		for (char a: aminoacidi.keySet()){
			if (a==am) {
				simbolo=am;
				nome=aminoacidi.get(am);
				return ;
			}
		}
		
		throw new IllegalAminoacido("aminoacido non valido");
	}
	
}
