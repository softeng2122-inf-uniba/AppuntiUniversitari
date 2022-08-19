package pq;

import java.util.LinkedList;

public class CodaLL<ITEM> extends PQL<ITEM> {
	
	public CodaLL() {
		super.coda=new LinkedList<ITEM> ();
	}

	public static void main(String[] args) {
		PQL<String> lista= new CodaLL<String>();
		
		lista.insert("malerba", 10);
		lista.insert("visaggio", 2);
		lista.insert("fanizzi", 8);
		lista.insert("ardimento", 4);
		lista.insert("lisi", 20);
		lista.insert("pisani", 10);
		lista.insert("lanza", 14);
		

		System.out.println("elemento con maggior priorità: " +lista.first());
		lista.delFirst();
		System.out.println("elemento con maggior priorità: " +lista.first());
	    lista.changePriority("malerba",1);
	    System.out.println("elemento con maggior priorità: " +lista.first());
	    System.out.println("dimensione della coda: " + lista.size());
	    System.out.println(lista.isNew());
	    try {
	    	lista.changePriority("boffoli",2);
	    } catch (EccezioneElementoNonValido e){
	    	System.out.println(e.getMessage());
	    }
	    
	}

}
