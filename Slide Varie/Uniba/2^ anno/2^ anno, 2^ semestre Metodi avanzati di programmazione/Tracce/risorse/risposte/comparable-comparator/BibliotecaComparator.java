
import java.util.Comparator;

class Libro {
	private static int codiceProgressivo = 0;
	private int codice = codiceProgressivo++;
	private String titolo;
	private String autore;
	private double prezzo;

	Libro(String titolo, String autore, double prezzo) {
		this.titolo = titolo;
		this.autore = autore;
		this.prezzo = prezzo;
	}

	String getTitolo() {
		return titolo;
	}

	String getAutore() {
		return autore;
	}

	double getPrezzo() {
		return prezzo;
	}

	public String toString() {
		String str = "";
		str += codice + ") " + titolo + " " + autore + " " + prezzo;
		return str;
	}
}

class PrezzoComparator implements Comparator<Libro> {
	public int compare(Libro l, Libro m) {
		if (l.getPrezzo() > m.getPrezzo()) {
			return 1;
		} else if (l.getPrezzo() < m.getPrezzo()) {
			return -1;
		} else {
			return 0;
		}
	}
}

class AutoreComparator implements Comparator<Libro> {
	public int compare(Libro l, Libro m) {
		return l.getAutore().compareTo(m.getAutore()); 
	}
}

class BibliotecaComparator {
	private Libro[] libri;

	BibliotecaComparator(int n) {
		libri = new Libro[n];
	}

	void addLibro(Libro l, int p) {
		libri[p] = l;
	}

	Libro maximum(Comparator<Libro> cmp) {
		Libro max = null;
		for (Libro l : libri) {
			if (l == null) {
				continue;
			}

			if (max == null) {
				max = l;
				continue;
			}

			if (cmp.compare(l, max) == 1) {
				max = l;
			}
		}
		return max;
	}

	public static void main(String[] args) {
		BibliotecaComparator b = new BibliotecaComparator(10);

		b.addLibro(new Libro("A", "a", 30.0), 0);
		b.addLibro(new Libro("B", "b", 20.0), 1);
		b.addLibro(new Libro("C", "c", 10.0), 2);

		System.out.println(b.maximum(new PrezzoComparator()));
		System.out.println(b.maximum(new AutoreComparator()));
	}
}
