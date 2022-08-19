package LL;

import java.util.Iterator;

public class LinkedList {

	Puntatore inizioLista, ultimoLista = null;

	public void addLast(Object e) {
		if (inizioLista == null)
			inizioLista = ultimoLista = new Puntatore(new Cella(e));
		else {
			Puntatore temp = ultimoLista;
			ultimoLista.cell.next = new Puntatore(new Cella(e));
			ultimoLista = ultimoLista.cell.next;
			ultimoLista.cell.prev = temp;
			temp.cell.next = ultimoLista;

		}
	}

	public void addFirst(Object e) {

		if (inizioLista == null)
			inizioLista = ultimoLista = new Puntatore(new Cella(e));
		else {

			Puntatore temp = inizioLista;
			inizioLista = new Puntatore(new Cella(e));
			inizioLista.cell.next = temp;
			temp.cell.prev = inizioLista;

		}

	}

	public void delLast() {
		if (inizioLista != ultimoLista) {
			ultimoLista = ultimoLista.cell.prev;
			ultimoLista.cell.next = null;
		} else
			inizioLista = ultimoLista = null;
	}

	public void delFirst() {

		if (inizioLista == ultimoLista)
			inizioLista = ultimoLista = null;
		else {
			inizioLista = inizioLista.cell.next;
			inizioLista.cell.prev = null;
		}

	}

	public void ruotaAvanti() {

		if (inizioLista != ultimoLista) {
			Puntatore temp = inizioLista;
			this.addLast(temp.cell.elem);
			this.delFirst();
		}

	}
	public Iterator iterator(){
		return new LinkedListIterator(this);
	}

	public static void main(String[] args) {

		LinkedList list = new LinkedList();
		list.addLast("minchia");
		
		Iterator it=list.iterator();
		
		while(it.hasNext())
			System.out.println(it.next());
		
		}

}
