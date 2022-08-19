package Coda;

public class CodaCollegata implements Coda {

	Record inizio, fine = null;

	private class Record {

		Object elem;
		Record next;

		public Record(Object e) {
			elem = e;
			next = null;
		}

	}

	@Override
	public boolean isEmpty() {
		return inizio == null;
	}

	@Override
	public void enqueue(Object elem) {

		Record p = new Record(elem);

		if (inizio == null)
			inizio = fine = p;
		else {
			fine.next = p;
			fine = fine.next;

		}

	}

	@Override
	public void dequeue() {
		if (isEmpty())
			throw new EccezioneCodaVuota("La coda è vuota!");
		else
			inizio = inizio.next;

	}

	@Override
	public Object first() {
		if (isEmpty())
			throw new EccezioneCodaVuota("La coda è vuota!");
		else
			return inizio.elem;
	}
	
	
	public static void main(String[]args){
		
		
		

		
		
	}

}
