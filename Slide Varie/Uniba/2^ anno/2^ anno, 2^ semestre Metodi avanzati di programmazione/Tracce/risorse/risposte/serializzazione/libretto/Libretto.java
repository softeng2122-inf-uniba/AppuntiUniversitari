
import java.util.Map;
import java.util.HashMap;

import java.io.File;
import java.io.Serializable;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;

class Libretto implements Serializable {
	private Map<Esame, Voto> dati = new HashMap<Esame, Voto>();

	void verbalizza(Esame e, Voto v) {
		dati.put(e, v);
	}

	Voto leggiVoto(Esame e) {
		return dati.get(e);
	}

	@Override
	public String toString() {
		return dati.toString();
	}

	@Override
	public boolean equals(Object o) {
		Libretto l = (Libretto) o;
		return dati.equals(l.dati);
	}

	void save(String filename) throws IOException, ClassNotFoundException {
		ObjectOutputStream out = new ObjectOutputStream(
			new FileOutputStream(filename)
		);
		out.writeObject(dati);
	}

	void load(String filename) throws IOException, ClassNotFoundException {
		ObjectInputStream in = new ObjectInputStream(
			new FileInputStream(filename)
		);
		dati = (Map<Esame, Voto>) in.readObject();
	} 

	public static void main(String[] args) {
		Libretto lib = new Libretto();
		lib.verbalizza(new Esame("map"), new Voto(30));
		lib.verbalizza(new Esame("asd"), new Voto(18));
		lib.verbalizza(new Esame("asd"), new Voto(29));
		lib.verbalizza(new Esame("dis"), new Voto(25));
		System.out.println(lib);

		try {
			lib.save("test.dmp");
		} catch (IOException e) {
			System.err.println(e.getMessage());
		} catch (ClassNotFoundException e) {
			System.err.println(e.getMessage());
		}

		try {
			Libretto newLib = new Libretto();
			newLib.load("test.dmp");
			System.out.println(newLib);
		} catch (IOException e) {
			System.err.println(e.getMessage());
		} catch (ClassNotFoundException e) {
			System.err.println(e.getMessage());
		}
	}
}
