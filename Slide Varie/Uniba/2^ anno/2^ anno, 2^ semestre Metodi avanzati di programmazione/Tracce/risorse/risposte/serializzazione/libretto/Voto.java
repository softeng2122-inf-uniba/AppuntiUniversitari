
import java.io.Serializable;

class Voto implements Serializable {
	private int punteggio;

	Voto(int punteggio) {
		this.punteggio = punteggio;
	}

	int getPunteggio() {
		return punteggio;
	}

	@Override
	public boolean equals(Object o) {
		return punteggio == ((Voto) o).punteggio;
	}

	@Override
	public String toString() {
		return new Integer(punteggio).toString();
	}
}
