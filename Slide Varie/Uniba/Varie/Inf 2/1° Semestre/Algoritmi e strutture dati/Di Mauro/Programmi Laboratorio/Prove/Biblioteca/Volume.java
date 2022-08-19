package Biblioteca;

import java.util.Iterator;

public class Volume {

	private String titolo;
	private String casa;
	private int anno;
	private AddOnlyList<String> autori;
	private int disponibilità=0;

	 String getTitolo() {
		return titolo;
	}

	 String getCasa() {
		return casa;
	}

	 int getAnno() {
		return anno;
	}

	String getAutori() {
		String res="";
		for(String aut:autori){
			res+=" "+aut;
		}
		return res;
	}

	 Volume(String titolo, String casa, int anno,
			AddOnlyList<String> autori) {
		this.titolo = titolo;
		this.casa = casa;
		this.anno = anno;
		this.autori = autori;
		this.disponibilità++;
	}

	private static boolean areEqual(Volume vol1, Volume vol2) {
		boolean equals = false;
		if (vol1.titolo.equals(vol2.titolo) && vol1.casa.equals(vol2.casa)
				&& vol1.anno == vol2.anno) {
			Iterator autIterator1 = vol1.autori.iterator();
			Iterator autIterator2 = vol2.autori.iterator();

			while (autIterator1.hasNext() && autIterator2.hasNext()) {
				if (autIterator1.next().equals(autIterator2.next()))
					equals = true;
				else
					equals = false;
			}

		}
		return equals;

	}

}
