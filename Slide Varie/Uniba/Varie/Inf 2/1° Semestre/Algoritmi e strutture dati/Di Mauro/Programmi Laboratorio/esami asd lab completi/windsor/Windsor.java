package windsor;

import java.util.Date;

public class Windsor {
		
	private String nome;
	private String titolo;
	private String genere;
	private Date dNascita;

	public Windsor (String n, String t,String g, Date d) {
		this.nome=n;
		this.titolo=t;
		this.dNascita=d;
		this.genere=g;
		
	}
	
	public String getNome(){
		return this.nome;
	}
	
	public String getTitolo(){
		return this.titolo;
	}
	
	public String getGenere(){
		return this.genere;
	}
	
	public Date getDataNascita(){
		return this.dNascita;
	}
	
	public String toString(){
		String s=this.nome + " - " + this.titolo + " - " + this.genere + " - " + this.dNascita;
		return s;
	}
}
