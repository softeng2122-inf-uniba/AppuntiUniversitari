package sequenzeBiologiche;

import java.util.HashMap;

public class Aminoacidi {
	public static HashMap<Character,Aminoacido> aminoacidi= new HashMap<Character,Aminoacido>();
	static{
		aminoacidi.put(Aminoacido.alanimaS, new Aminoacido(Aminoacido.alanimaS));
		aminoacidi.put(Aminoacido.cisteinaS, new Aminoacido(Aminoacido.cisteinaS));
		aminoacidi.put(Aminoacido.acidoAsparticoS, new Aminoacido(Aminoacido.acidoAsparticoS));
		aminoacidi.put(Aminoacido.acidoGluatammicoS, new Aminoacido(Aminoacido.acidoGluatammicoS));
		aminoacidi.put(Aminoacido.fenilalaninaS, new Aminoacido(Aminoacido.fenilalaninaS));
		aminoacidi.put(Aminoacido.glicinaS, new Aminoacido(Aminoacido.glicinaS));
		aminoacidi.put(Aminoacido.istidinaS, new Aminoacido(Aminoacido.istidinaS));
		aminoacidi.put(Aminoacido.isoleucinaS, new Aminoacido(Aminoacido.isoleucinaS));
		aminoacidi.put(Aminoacido.lisinaS, new Aminoacido(Aminoacido.lisinaS));
		aminoacidi.put(Aminoacido.leucinaS, new Aminoacido(Aminoacido.leucinaS));
		aminoacidi.put(Aminoacido.metionimaS, new Aminoacido(Aminoacido.metionimaS));
		aminoacidi.put(Aminoacido.asparaginaS, new Aminoacido(Aminoacido.asparaginaS));
		aminoacidi.put(Aminoacido.prolinaS, new Aminoacido(Aminoacido.prolinaS));
		aminoacidi.put(Aminoacido.glutamminaS, new Aminoacido(Aminoacido.glutamminaS));
		aminoacidi.put(Aminoacido.arginaS, new Aminoacido(Aminoacido.arginaS));
		aminoacidi.put(Aminoacido.serinaS, new Aminoacido(Aminoacido.serinaS));
		aminoacidi.put(Aminoacido.treoninaS, new Aminoacido(Aminoacido.treoninaS));
		aminoacidi.put(Aminoacido.valinaS, new Aminoacido(Aminoacido.valinaS));
		aminoacidi.put(Aminoacido.triptofanoS, new Aminoacido(Aminoacido.triptofanoS));
		aminoacidi.put(Aminoacido.tirosinaS, new Aminoacido(Aminoacido.tirosinaS));	
	}

}
