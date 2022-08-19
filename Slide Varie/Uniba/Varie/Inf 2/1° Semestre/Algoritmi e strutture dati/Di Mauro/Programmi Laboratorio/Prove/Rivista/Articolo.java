package Rivista;

public class Articolo {

	private AddOnlyList<String> autori;
	int volume;

	public AddOnlyList getAutori() {
		return this.autori;
	}

	public Articolo(AddOnlyList<String> aut, int n) {
		autori = aut;
		volume = n;
	}

}
