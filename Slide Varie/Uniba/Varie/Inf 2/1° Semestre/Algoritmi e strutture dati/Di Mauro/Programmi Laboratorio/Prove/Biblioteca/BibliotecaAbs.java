package Biblioteca;

public abstract class BibliotecaAbs {

	protected ArrayDict<String, Record> volumi;

	public abstract boolean isEmpty();

	public abstract void addVol(String posizione, Record volume);

	public abstract Object volume(String posizione);

	public abstract void prestito(String posizione);

	public abstract void restituzione(String posizione);

	public abstract boolean prestato(String posizione);

	public abstract String posizione(Record volume);

}
