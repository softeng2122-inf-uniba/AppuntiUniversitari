package Bussola;

public class Cella<T> {

	 T elem;
	Puntatore next;
	Puntatore prev;

	public Cella(T e) {
		elem = e;
		next = prev = null;
	}

}
