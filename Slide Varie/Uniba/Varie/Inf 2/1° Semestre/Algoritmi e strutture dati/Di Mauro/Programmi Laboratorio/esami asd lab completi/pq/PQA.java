package pq;

import java.util.Iterator;

public class PQA<Item> implements PQ<Item> {

	private int n=0; // contiene il numero effettivo di elementi nella coda
	private Record [] coda= new PQA.Record[1]; // coda con priorità
 
	//classe interna record
	private class Record{
		public Item elem;
		public int priority;
		
		public Record (Item e, int p){
			elem=e;
			priority=p;
		}
		
	}
	
	//classe interna iteratore
	public class CodaArrayIterator<Item> implements Iterator<Item>{

		int i=0;
			
		public boolean hasNext() {
			return i<n;
		}

		
		public Item next() {
			int y=i;
			i++;
			return (Item) coda[y].elem; 
		}

		
		public void remove() {
			// TODO Auto-generated method stub
			
		}
		
	}
	
	
	// metodo main di test per la classe
	public static void main(String[] args) {
		PQ<String> codaP=new PQA<String>();
		
		codaP.insert("a", 2);
		codaP.insert("b", 7);
		codaP.insert("c", 9);
		codaP.insert("e", 4);
		codaP.insert("d", 1);
		codaP.insert("f", 20);
		codaP.insert("g", 10);
		codaP.insert("h", 6);
		codaP.insert("i", 14);
		codaP.insert("l", 20);
		codaP.insert("m", 6);
		codaP.insert("n", 30);
		codaP.insert("o", 26);
			
		for (String s: codaP){
			System.out.println(s + " " + codaP.getPriority(s));
		}
		for (int i=0; i<5; i++) {
			codaP.delFirst();
		}
		
		System.out.println("--");
		for (String s: codaP){
			System.out.println(s + " " + codaP.getPriority(s));
		}
		System.out.println("--");
		codaP.changePriority("i", 36);
		codaP.changePriority("o", 1);
		codaP.changePriority("l", 5);
		for (String s: codaP){
			System.out.println(s + " " + codaP.getPriority(s));
		}
	}

	
	public Iterator<Item> iterator() {
		return new CodaArrayIterator<Item>();
	}

	
	public boolean isNew() {
		return (n==0);
	}

	@Override
	public void insert(Item i, int p) {
		
		//assumo che se un 
		//elemento è già presente nella coda non può essre
		//inserito nuovamente
		int j;
		
		//verifico se l'elemento è già presente nella coda
		for (j=0; j<n; j++) {
			if (coda[j].elem.equals(i)) break;
		}
		if (j!=n) throw new EccezioneElementoGiàPresente("elemento già presente nella coda");

		
		//verifico se serve raddoppiare la dimensione dell'array
		if (n==coda.length) {
			Record[] tmp= new PQA.Record[coda.length*2];
			for (j=0; j<n; j++) {
				tmp[j]=coda[j];
			}
			coda=tmp;
		}
		//inserisco momentaneamente l'elemento in ultima posizione
		coda[n]=new Record(i,p);
		n++;
		

		//trovo la poszione corretta per l'elemento appena inserito
		for (j=n-2; j>=0; j--) {
			if (coda[n-1].priority>=coda[j].priority) break;
		}
		//inserisco l'elemento in posizione trovata +1
		Record tmp= coda[n-1];
		for(int k=n-1; k>j+1; k--) {
			coda[k]=coda[k-1];
		}
		coda[j+1]=tmp;
		
	}

	@Override
	public Item first() {
		if (n==0) throw new EccezioneCodaVuota("la coda è vuota");
		return coda[0].elem;
	}

	@Override
	public void delFirst() {
		if (n==0) throw new EccezioneCodaVuota("la coda è vuota");
		
		for (int i=0; i<n-1; i++) {
			coda[i]=coda[i+1];
		}
		n--;
		
		if (n>1 && n<coda.length/4){
			Record[] tmp= new PQA.Record[coda.length/2];
			for (int i=0; i<n; i++) {
				tmp[i]=coda[i];
			}
			coda=tmp;
		}
	}

	@Override
	public void changePriority(Item i, int p) {
		int j;
		//verifico se l'elemento da modificare la priorità è effettivamente presente nella coda
		for (j=0; j<n; j++) {
			if (coda[j].elem.equals(i)) break;
		}
		if (j==n) throw new EccezioneElementoNonPresente("elemento non presente");
		
		//elimino momentaneamente l'elemento dalla coda
		for (int k=j; k<n-1; k++) {
			coda[k]=coda[k+1];
		}
		n--;
		if (n>1 && n<coda.length/4){
			Record[] tmp= new PQA.Record[coda.length/2];
			for (int k=0; k<n; k++) {
				tmp[k]=coda[k];
			}
			coda=tmp;
		}
		
		//inserisco l'elemento nella coda con la nuova priorità
		this.insert(i,p);
	}

	@Override
	public int getPriority(Item i) {
		int j;
		for (j=0; j<n; j++) {
			if (coda[j].elem.equals(i)) break;
		}
		
		if (j==n) throw new EccezioneElementoNonPresente("elemento non presente");
		return coda[j].priority;
	}

	@Override
	public int size() {
		return n;
	}

}
