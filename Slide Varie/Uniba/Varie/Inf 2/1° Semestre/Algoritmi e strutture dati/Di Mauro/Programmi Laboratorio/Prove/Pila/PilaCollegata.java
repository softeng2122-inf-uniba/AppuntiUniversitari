package Pila;

public class PilaCollegata<T> implements Pila<T> {

	private Record<T> inizio, fine = null;

	private class Record<T> {

		T elem;
		Record<T> next, prev;

		public Record(T elem) {
			this.elem = elem;

		}

	}

	@Override
	public void push(T elem) {

		Record<T> p = new Record<T>(elem);
		if (inizio == null)
			inizio = fine = p;
		else {
			fine.next = p;
			fine.next.prev=fine;
			fine = fine.next;
		}

	}

	@Override
	public void pop() {
		if(isEmpty())
			throw new EccezionePilaVuota("La pila è vuota");
		fine = fine.prev;

	}

	@Override
	public boolean isEmpty() {
		return inizio == null;
	}

	@Override
	public Object top() throws EccezionePilaVuota {
		return fine.elem;
	}

	public static void main(String[] args) {

		PilaCollegata<String> pila = new PilaCollegata<String>();
		pila.push("ciao");
		System.out.println(pila.top());
		pila.push("aueee");
		System.out.println(pila.top());
		
	

	}
}
