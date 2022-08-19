package persona;

public class Persona implements Comparable{

	private String nome;
	
	public Persona (String n){
		this.nome=n;
	}
	
	
	public String getNome(){
		return this.nome;
	}


	public int compareTo(Object o) {
		Persona p= (Persona) o;
		if (this.nome.equals(p.getNome())) return 0;
		else return -1;
	}
	
	public String toString(){
		return this.getNome();
	}
}
