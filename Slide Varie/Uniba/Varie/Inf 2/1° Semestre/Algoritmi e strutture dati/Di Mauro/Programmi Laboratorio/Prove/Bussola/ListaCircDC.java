package Bussola;

import java.util.Iterator;

public class ListaCircDC<T> implements CircList<T> {

	Puntatore inizioLista;
	Puntatore ultimo;
	private int n = 0; //conta gli elementi della lista(utile per numItem)

	@Override
	public Iterator<T> iterator() {
		return new ListaCircDCIterator(this);
	}

	@Override
	public void addCircList(T item) {
		if (isEmpty()) {
			inizioLista = new Puntatore(new Cella(item));
			ultimo = inizioLista;
			inizioLista.cell.next = inizioLista.cell.prev = inizioLista;
		} else {
			Puntatore p = new Puntatore(new Cella(item));
			Puntatore temp = ultimo;
			ultimo.cell.next = p;
			ultimo = ultimo.cell.next;
			ultimo.cell.prev = temp;
		}
		n++;
	}

	@Override
	public void delCircList() {
		if (isEmpty())
			throw new IndexOutOfBoundsException("La struttura è vuota!");
		else if (inizioLista == ultimo) // se c'è un solo elemento
			inizioLista = null;
		else {
			inizioLista.cell.prev.cell.next = inizioLista.cell.next;
			inizioLista.cell.next.cell.prev = inizioLista.cell.prev;
			inizioLista = inizioLista.cell.next;

		}
		n--;

	}

	@Override
	public T value() {

		return (T) inizioLista.cell.elem;
	}

	@Override
	public boolean isEmpty() {
		return inizioLista == null;
	}

	@Override
	public void ruotaAvanti() { //equivale ad aggiungere per ultimo il primo elemento e a cancellarlo dalla testa
		this.addCircList(this.value());
		this.delCircList();

	}

	@Override
	public void ruotaIndietro() {

		Puntatore temp = inizioLista;
		inizioLista = ultimo;
		ultimo = ultimo.cell.prev;
		ultimo.cell.next = null;
		inizioLista.cell.next = temp;
		temp.cell.prev = inizioLista;

	}

	@Override
	public int numItem() {
		return n;
	}

	public static void main(String[] args) {
		ListaCircDC<String> list = new ListaCircDC<String>();
		list.addCircList("nord");
		list.addCircList("nord-est");
		list.addCircList("est");
		list.addCircList("sud-est");
		list.addCircList("sud");
		list.addCircList("sud-ovest");
		list.addCircList("ovest");
		list.addCircList("nord-ovest");
		
		Iterator it1 = list.iterator();

		
		//stampa le varie bussole,ruotate e senza l'elemento di testa,come da richiesta di Malerba
		System.out.println("La bussola: ");
		while (it1.hasNext())
			System.out.println(it1.next());
		
		list.ruotaAvanti();
		list.ruotaAvanti();
		
		
		Iterator it2 = list.iterator();
		System.out.println("La bussola ruotata in avanti di due posizioni: ");
		while (it2.hasNext())
			System.out.println(it2.next());
		
		list.delCircList();

		Iterator it3 = list.iterator();
		System.out.println("La bussola ruotata in avanti di due posizioni e senza l'elemento di testa: ");
		while (it3.hasNext())
			System.out.println(it3.next());

	}

}
