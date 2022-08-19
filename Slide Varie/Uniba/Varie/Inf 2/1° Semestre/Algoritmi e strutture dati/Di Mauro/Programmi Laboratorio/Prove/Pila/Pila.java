package Pila;

public interface Pila <T>{
	
	
	public void push(T elem);
	public void pop();
	public boolean isEmpty();
	public Object top() throws EccezionePilaVuota;
	
	
	

}
