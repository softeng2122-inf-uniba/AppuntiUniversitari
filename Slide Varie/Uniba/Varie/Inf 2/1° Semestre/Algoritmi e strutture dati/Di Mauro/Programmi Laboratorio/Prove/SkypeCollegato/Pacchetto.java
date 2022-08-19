package SkypeCollegato;

public class Pacchetto {

	private Utente mittente;

	private Utente destinatario;

	private int identificativo;

	private String dati;

	private boolean ultimo;

	public Pacchetto(Utente mittente, Utente destinatario, int identificativo,
			String dati, boolean ultimo) {

		this.mittente = mittente;
		this.destinatario = destinatario;
		this.identificativo = identificativo;
		this.dati = dati;
		this.ultimo = ultimo;
	}

	public Utente getMittente() {
		return mittente;
	}

	public Utente getDestinatario() {
		return destinatario;
	}

	public int getIdentificativo() {
		return identificativo;
	}

	public String getDati() {
		return dati;
	}

	public boolean isUltimo() {
		return ultimo;
	}

}
