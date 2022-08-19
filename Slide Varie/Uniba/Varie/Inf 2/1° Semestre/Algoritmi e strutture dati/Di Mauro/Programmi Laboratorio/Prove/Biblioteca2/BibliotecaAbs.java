package Biblioteca2;

import java.util.Iterator;

public abstract class BibliotecaAbs {

	protected Dictionary<String, Record> volumi;
	protected int n=0;

	public boolean bibliotecaVuota() {
		return n==0;
		
	}

	public void addVol(String posizione, Record volume) {

		volumi.insert(posizione, volume);
		n++;

	}

	public Record volume(String posizione) {
		return volumi.search(posizione);
	}

	public void prestito(String posizione) {
		if (this.volume(posizione) != null) {
			if (this.volume(posizione).prestato == false) {
				Record volume = this.volume(posizione);
				volume.prestato = true;
				System.out.println("Il volume nella posizione indicata è stato prestato");

			}
		}
	}

	public void restituzione(String posizione) {

		Record volume = this.volume(posizione);
		volume.prestato = false;

	}

	public boolean prestato(String posizione) {
		return this.volume(posizione).prestato==true;
	}

	public String posizione(Record volume) {
		Iterator it= volumi.iterator();
		while(it.hasNext()){
			
			String pos= (String) it.next();
			if(this.volume(pos).v.isEqual(volume.v))
				return pos;
			
		}
		return null;
			
	}

}
