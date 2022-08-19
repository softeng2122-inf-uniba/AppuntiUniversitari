package Biblioteca2;

import java.util.Iterator;

public class Volume {

	String titolo;
	String casa;
	int anno;
	AddOnlyList<String> autori;

	public Volume(String titolo, String casa, int anno,
			AddOnlyList<String> autori) {
		this.titolo = titolo;
		this.casa = casa;
		this.anno = anno;
		this.autori = autori;
	}

	public boolean isEqual(Volume vol) {

		boolean isEqual = false;

		if (this.titolo.equals(vol.titolo) && this.casa.equals(vol.casa)
				&& this.anno == vol.anno) {

			if (((DoubleLinkedList) this.autori).n == ((DoubleLinkedList) (vol.autori)).n) {

				Iterator it1 = this.autori.iterator();
				Iterator it2 = vol.autori.iterator();

				while (it1.hasNext()) {

					String autore = (String) it2.next();
					if (it1.next().equals(autore))
						isEqual = true;
					else {
						isEqual = false;
						break;
					}

				}

			}

		}
		return isEqual;

	}
	
	

}
