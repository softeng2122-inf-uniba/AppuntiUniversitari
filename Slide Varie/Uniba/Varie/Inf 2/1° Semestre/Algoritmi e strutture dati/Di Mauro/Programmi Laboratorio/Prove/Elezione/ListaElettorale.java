package Elezione;

import java.util.LinkedList;

public class ListaElettorale implements Comparable {
	String nome;
	LinkedList<String> lista;

	public ListaElettorale(String nome, LinkedList<String> lista) {
		this.nome = nome;
		this.lista = lista;
	}

	@Override
	public int compareTo(Object o) {

		return (this.nome.compareTo(((ListaElettorale) o).nome));
	}
	
	public void stampaLista(){
		System.out.println(this.nome);
	}
	
}
