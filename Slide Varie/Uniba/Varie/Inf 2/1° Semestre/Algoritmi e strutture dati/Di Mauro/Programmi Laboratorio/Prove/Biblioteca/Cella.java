package Biblioteca;

public class Cella<S> {

	S elem;
	Puntatore next;

	public Cella(S elem) {

		this.elem = elem;
		next = null;

	}

}
