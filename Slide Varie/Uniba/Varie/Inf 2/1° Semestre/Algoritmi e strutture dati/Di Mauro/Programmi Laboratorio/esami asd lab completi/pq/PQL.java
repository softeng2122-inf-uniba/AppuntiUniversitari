package pq;

import java.util.LinkedList;
import java.util.List;

public abstract class PQL<ITEM> implements PQ<ITEM>{
	
	protected List<ITEM> coda;
	private List<Integer> priority= new LinkedList<Integer>();

	public boolean isNew(){
		return coda.isEmpty();
	}
	
	public void insert(ITEM e, int p){
		int i;
	
		for (i=0; i<coda.size(); i++) {
			if (p<priority.get(i)) {
				coda.add(i, e);
				priority.add(i,p);
				break;
			}
		}
			
		if (i==coda.size()){
			coda.add(e);
			priority.add(p);
		}
	}
	
	
	public ITEM first(){
		if (isNew()) throw new EccezioneStrutturaVuota("la coda è vuota");
		return coda.get(0);
	}
	
	
	public void delFirst() {
		if (isNew()) throw new EccezioneStrutturaVuota("la coda è vuota");
        coda.remove(0);
        priority.remove(0);
	}
	
	
	public void changePriority(ITEM e, int p) {
		
		int i;
		for (i=0; i<coda.size(); i++) {
			if (coda.get(i).equals(e)) {
				break;
			}
		}
		
		if (i==coda.size()) throw new EccezioneElementoNonValido("l'elemento " + e +" non è presente nella coda");
		coda.remove(i);
		priority.remove(i);
		this.insert(e,p);
	}
	
	public int getPriority(ITEM e){
		int i;
		for (i=0; i<coda.size(); i++) {
			if (coda.get(i).equals(e)) {
				break;
			}
		}
		
		if (i==coda.size()) throw new EccezioneElementoNonValido("l'elemento " + e +" non è presente nella coda");
	    return priority.get(i);
	}
	
	public int size(){
		return coda.size();
	}
}
