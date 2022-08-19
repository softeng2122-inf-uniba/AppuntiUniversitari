package Orologio2;

public class Secondo {
	private String nome;
	private Event e;

	public Secondo(String nome, Event e) {
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
