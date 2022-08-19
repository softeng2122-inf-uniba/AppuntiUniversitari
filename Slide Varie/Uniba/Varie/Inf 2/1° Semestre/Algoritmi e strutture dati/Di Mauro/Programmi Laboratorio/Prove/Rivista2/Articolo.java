package Rivista2;

import Rivista2.Interface.AddOnlyList;

public class Articolo {

	private AddOnlyList<String> autori;
	private int volume;

	public Articolo(AddOnlyList<String> autori, int volume) {
		this.autori = autori;
		this.volume = volume;
	}

	public AddOnlyList<String> getAutori() {
		return autori;
	}

	public int getVolume() {
		return volume;
	}

}
