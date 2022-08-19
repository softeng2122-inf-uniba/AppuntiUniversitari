package Rivista;

import java.util.Iterator;

public class Rivista extends RivistaAbs {

	@Override
	public boolean rivistaNuova() {
		Iterator it = volumi.iterator();
		boolean pubb = false;
		while (it.hasNext())
			if (it.next().equals(true))
				pubb = true;
		return pubb;

	}

	@Override
	public void addArt(String titolo, int volume) {

		VectorList<String> autori = new VectorList<String>();
		articoli.insert(titolo, new Articolo(autori, volume));
		if (volumi.search(Integer.valueOf(volume)) == null) {
			volumi.insert(Integer.valueOf(volume), false);
		}

	}

	@Override
	public void addAut(String titolo, String autore) {

		this.articoli.search(titolo).getAutori().add(autore);

	}

	@Override
	public void pubblicaVol(int volume) {
		
		

		volumi.delete(Integer.valueOf(volume));
		volumi.insert(Integer.valueOf(volume), true);
		
	}

	@Override
	public boolean pubblicato(int volume) {

		boolean b = volumi.search(Integer.valueOf(volume)).booleanValue();
		return b == true;

	}
	private String getTitle(Articolo art){
		
		for(Record p=((LinkedDict)articoli).list;;p=p.next)
			if(p.elem.equals(art))
				return (String) p.key;
		
	}
	
	public static void main(String[] args) {

		Rivista focus = new Rivista();
		focus.addArt("a relational", 1);
		focus.addAut("a relational", "Donato Malerba");
		focus.addAut("a relational", "ciao");

		focus.addArt("Multi label", 1);
		focus.addAut("Multi label", "Patricia");

		focus.addArt("Multi label", 2);
		focus.addAut("Multi label", "Patricia");
		
		System.out.println(focus.pubblicato(1));
		System.out.println(focus.pubblicato(2));

		focus.pubblicaVol(2);
		System.out.println(focus.pubblicato(2));
		
		focus.pubblicaVol(1);
		System.out.println(focus.pubblicato(1));

		
		
		Iterator artIt = focus.articoli.iterator();

		while (artIt.hasNext()) {
			Articolo art = (Articolo) artIt.next();

			System.out.println("Autori: " + art.getAutori().toString() + "\n "
					+ "titolo: " + "valore" + "\n" + " Volume: " + art.volume
					+ " ");
		}

	}

}
