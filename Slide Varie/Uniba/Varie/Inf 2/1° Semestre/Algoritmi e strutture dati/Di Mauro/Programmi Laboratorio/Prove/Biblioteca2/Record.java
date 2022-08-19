package Biblioteca2;

public class Record {

	Volume v;
	boolean prestato = false;

	public Record(Volume volume) {

		this.v = volume;

	}

	public String toString() {

		String res = "";

		return res += " Titolo: " + v.titolo + " Casa editrice: " + v.casa
				+ " Anno: " + v.anno + "  Autori: " + v.autori.toString();

	}
}
