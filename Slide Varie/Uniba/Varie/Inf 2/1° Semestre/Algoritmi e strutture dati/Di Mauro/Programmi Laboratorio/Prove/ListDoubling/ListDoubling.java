package ListDoubling;

import java.util.Iterator;

public class ListDoubling implements Lista {

	private Object[] S = new Object[1];
	private int n = 0;

	@Override
	public boolean isEmpty() {
		return n == 0;
	}

	@Override
	public Object readList(Posizione p) {

		if (checkPosition(p) == true)

			return S[((Indice) p).indice];
		else
			throw new IndexOutOfBoundsException("Posizione non valida");
	}

	private boolean checkPosition(Posizione p) {
		if (((Indice) p).indice < 0 || ((Indice) p).indice > n)
			return false;
		else
			return true;
	}

	@Override
	public void writeList(Object e, Posizione p) {
		if (checkPosition(p) == true)

			S[((Indice) p).indice] = e;
		else
			throw new IndexOutOfBoundsException("Posizione non valida");

	}

	@Override
	public Posizione firstList() {
		return new Indice();
	}

	@Override
	public boolean endList(Posizione p) {
		return ((Indice) p).indice == n;
	}

	@Override
	public Posizione succ(Posizione p) {

		if (endList(p))
			throw new IndexOutOfBoundsException("Fine della lista!");
		else {

			Indice pos = new Indice();
			pos.indice = ((Indice) p).indice + 1;

			return pos;
		}
	}

	@Override
	public Posizione pred(Posizione p) {

		if (((Indice) p).indice == ((Indice) firstList()).indice)
			throw new IndexOutOfBoundsException("La posizione è la prima");

		Indice pos = new Indice();
		((Indice) pos).indice = pos.indice - 1;

		return pos;
	}

	@Override
	public void insert(Object e, Posizione p) {

		for (int i = n; i > ((Indice) p).indice; i--) {

			S[i] = S[i - 1];

		}
		S[((Indice) p).indice] = e;
		n++;

		if (n == S.length) {

			Object[] temp = new Object[S.length * 2];
			for (Posizione pos = firstList(); ((Indice) pos).indice < n; pos = succ(pos))
				temp[((Indice) pos).indice] = S[((Indice) pos).indice];
			S = temp;

		}

	}

	@Override
	public void remove(Posizione p) {

		for (int i = ((Indice) p).indice; i < n; i++)
			S[i] = S[i + 1];
		n--;
		if (n > 1 && n < S.length / 4) {

			Object[] temp = new Object[S.length / 2];

			for (Posizione pos = firstList(); ((Indice) pos).indice < n; pos = succ(pos))
				temp[((Indice) pos).indice] = S[((Indice) pos).indice];
			S = temp;

		}

	}

	@Override
	public Iterator<Object> iterator() {

		return new ListIterator(this);
	}

	public static void main(String[] args) {

		ListDoubling lista = new ListDoubling();
		lista.insert("ciao", lista.firstList());
		lista.insert("alessandro", lista.succ(lista.firstList()));
		lista.insert("sono", lista.succ(lista.succ(lista.firstList())));
		lista.insert("io",
				lista.succ(lista.succ(lista.succ(lista.firstList()))));

		lista.writeList("auee", lista.firstList());

		Iterator<Object> iterator = lista.iterator();
		while (iterator.hasNext())
			System.out.println(iterator.next());

	}
}
