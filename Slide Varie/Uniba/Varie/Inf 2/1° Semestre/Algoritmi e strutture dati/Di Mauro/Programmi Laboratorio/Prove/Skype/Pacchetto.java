package Skype;

public class Pacchetto {

	Utente mittente;

	Utente destinatario;

	int identificativo;
	String dati;
	boolean ultimo;

	public Pacchetto(Utente mittente, Utente destinatario, int identificativo,
			String dati, boolean ultimo) {

		this.mittente = mittente;
		this.destinatario = destinatario;
		this.identificativo = identificativo;
		this.dati = dati;
		this.ultimo = ultimo;
	}

}
