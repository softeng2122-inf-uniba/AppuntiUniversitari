
import java.io.Serializable;

class Esame implements Serializable {
	private String nome;
	
	Esame(String nome) {
		this.nome = nome;
	}

	String getNome() {
		return nome;
	}

	@Override
	public boolean equals(Object o) {
		return ((Esame) o).nome.equals(nome);
	}

	@Override
	public String toString() {
		return nome;
	}

	@Override
	public int hashCode() {
		return nome.hashCode();
	}
}

