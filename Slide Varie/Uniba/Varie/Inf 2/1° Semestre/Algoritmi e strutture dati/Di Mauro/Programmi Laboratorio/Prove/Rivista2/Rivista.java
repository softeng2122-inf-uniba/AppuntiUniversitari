package Rivista2;

import Rivista2.Exceptions.ArticleNotFoundException;
import Rivista2.Exceptions.VolumeNotFoundException;
import Rivista2.Interface.Dictionary;
import Rivista2.Structure.LinkedDict;
import Rivista2.Structure.VectorList;

public class Rivista {

	protected Dictionary<String, Articolo> articoli;
	protected Dictionary<Integer, Boolean> volumi;
	private int n;

	public Rivista() {
		articoli = new LinkedDict<String, Articolo>();
		volumi = new LinkedDict<Integer, Boolean>();
		n = 0;
	}

	public boolean rivistaNuova() {
		return n == 0;
	}

	public void addArt(String titolo, int volume) {
		VectorList<String> autori = new VectorList<String>();
		Articolo art = new Articolo(autori, volume);
		articoli.insert(titolo, art);
		if (volumi.search(volume) == null)
			volumi.insert(volume, false);
	}

	public void addAut(String titolo, String autore) {

		if (articoli.search(titolo) != null) {
			articoli.search(titolo).getAutori().add(autore);
		} else
			throw new ArticleNotFoundException("Articolo non registrato");

	}

	public void pubblicaVol(int volume) {
		if (volumi.search(volume) != null) {
			volumi.delete(volume);
			volumi.insert(volume, true);
			n++;

		} else
			throw new VolumeNotFoundException("Volume non registrato");
	}

	public boolean pubblicato(int volume) {

		if (volumi.search(volume) != null)
			return volumi.search(volume) == true;
		else
			throw new VolumeNotFoundException("Volume non registrato");

	}

}