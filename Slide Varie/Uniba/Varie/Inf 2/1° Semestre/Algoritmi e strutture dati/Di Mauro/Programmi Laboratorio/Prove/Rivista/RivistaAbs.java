package Rivista;


public abstract class RivistaAbs {

	protected Dictionary<String, Articolo> articoli = new LinkedDict<String, Articolo>();
	protected Dictionary<Integer, Boolean> volumi = new LinkedDict<Integer, Boolean>();

	public abstract boolean rivistaNuova();

	public abstract void addArt(String titolo, int volume);

	public abstract void addAut(String titolo, String autore);

	public abstract void pubblicaVol(int volume);

	public abstract boolean pubblicato(int volume);

}
