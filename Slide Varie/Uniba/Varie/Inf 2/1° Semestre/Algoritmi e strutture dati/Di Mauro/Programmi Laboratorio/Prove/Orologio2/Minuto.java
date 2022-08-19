package Orologio2;

public class Minuto {

	private String nome;
	private Event e;

	public Minuto(String nome, Event e) {
		this.nome = nome;
		this.e = e;

	}

	public Event getEvent() {
		return e;
	}

	public void setEvent(Event e) {
		this.e = e;
	}

	public String getName() {
		return nome;
	}

	
	
	
}
