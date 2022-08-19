package Biblioteca;

public class Record {

	Volume volume;
	boolean prestato = false;

	public Record(Volume vol) {
		volume = vol;
	}

	public String toString() {

		return volume.getTitolo() + " " + volume.getCasa() + " "
				+ volume.getAnno() + " "+volume.getAutori();

	}

}
