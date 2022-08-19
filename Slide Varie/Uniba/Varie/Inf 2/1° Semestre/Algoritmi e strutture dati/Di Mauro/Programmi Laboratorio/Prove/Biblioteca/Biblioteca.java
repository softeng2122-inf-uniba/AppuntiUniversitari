package Biblioteca;

import java.util.Iterator;

public class Biblioteca extends BibliotecaAbs {

	public Biblioteca(ArrayDict<String, Record> diz) {
		this.volumi = diz;
	}

	@Override
	public boolean isEmpty() {
		return volumi.n == 0;
	}

	@Override
	public void addVol(String posizione, Record volume) {
		volumi.insert(posizione, volume);

	}

	@Override
	public Object volume(String posizione) {
		return volumi.search(posizione).volume;
	}

	@Override
	public void prestito(String posizione) {
		volumi.search(posizione).prestato = true;
		System.out.println("Il volume in posizione " + posizione
				+ " è stato prestato");

	}

	@Override
	public void restituzione(String posizione) {
		volumi.search(posizione).prestato = false;
	}

	@Override
	public boolean prestato(String posizione) {
		return volumi.search(posizione).prestato == true;

	}

	@Override
	public String posizione(Record vol) {
		String titolo = vol.volume.getTitolo();
		for (String pos : this.volumi) {
			Record rec = volumi.search(pos);
			if ( rec.volume.getTitolo().equals(titolo))
				return pos;

		}
		return null;

	}

	public static void main(String[] args) {

		Biblioteca bib = new Biblioteca(new ArrayDict<String, Record>());

		DoubleLinkedList<String> autori = new DoubleLinkedList<String>();
		autori.add("bertossi");
		autori.add("malerba");
		Record r1 = new Record(new Volume("ahaha", "aueee", 1992, autori));

		DoubleLinkedList<String> autori2 = new DoubleLinkedList<String>();
		autori2.add("ciao");
		autori2.add("stronzo");
		Record r2 = new Record(new Volume("ahawwha", "aueee", 1992, autori2));

		DoubleLinkedList<String> autori3 = new DoubleLinkedList<String>();
		autori3.add("mario");
		autori3.add("maccio");
		Record r3 = new Record(new Volume("aha wwha", "aueee", 1992, autori3));

		bib.addVol("scaffale1", r1);
		bib.addVol("scaffale2", r2);
		bib.addVol("scaffale3", r3);
		/*System.out.println(bib.posizione(r1));*/

		Iterator<String> it = bib.volumi.iterator();
		while (it.hasNext())
			System.out.println(it.next());

	}
}
