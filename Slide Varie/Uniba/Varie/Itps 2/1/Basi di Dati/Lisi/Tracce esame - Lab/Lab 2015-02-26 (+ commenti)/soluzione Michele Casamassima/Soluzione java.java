package applicazione;

/*

 Prova di Laboratorio di PROGETTAZIONE DI BASI DI DATI
 C.d.S. in Informatica e Tecnologie per la Produzione del Software (3 anni)
 Docente: dott.ssa Francesca A. Lisi

 26 Febbraio 2015

 -------------------------------------
 Cognome e Nome	: Casamassima Michele
 Matricola	: 621831
 -------------------------------------

 */

import java.sql.*;

public class ProvaDB20150226 {

	public static void main(String[] args) {
		// sezione dichiarazione variabili locali

		String titolo;
		String nome;
		String cognome;
		int numero;

		Connection connessione = null;

		// es. 1: creazione stringa contenente comando SQL
		String stringa1 = "ALTER TABLE Libri "
				+ "ADD FOREIGN KEY (Codice_editore) "
				+ "REFERENCES Editori(Codice_editore) ";

		// es. 2: creazione stringa contenente comando SQL
		String stringa2 = "DELETE FROM Editori "
				+ "WHERE Nome_editore = 'Arcade Publishing' ";

		// es. 3: creazione stringa contenente comando SQL
		String stringa3 = "CREATE VIEW LibriPubblicati_MA(Titolo_libro, Nome_editore) AS "
				+ "SELECT Titolo_libro, Nome_editore "
				+ "FROM Libri NATURAL JOIN Editori "
				+ "WHERE Stato_editore = 'MA' ";

		// es. 4: creazione stringa contenente comando SQL
		String stringa4 = "SELECT * FROM LibriPubblicati_MA ";

		// es. 5: creazione stringa contenente comando SQL
		String stringa5 = "SELECT Nro_autore, Cognome_autore, Nome_autore "
				+ "FROM Autori NATURAL JOIN LibriAutori NATURAL JOIN Libri NATURAL JOIN LibriPubblicati_MA "
				+ "GROUP BY Nro_autore "
				+ "ORDER BY Cognome_autore, Nome_autore ";

		// es. 6: creazione stringa contenente comando SQL
		String stringa6 = " ";

		// es. 7: creazione stringa contenente comando SQL
		String stringa7 = "SELECT Nome_editore, Count(Codice_libro) AS Libri_pubblicati, Avg(Prezzo_libro) AS Prezzo_medio "
				+ "FROM Editori NATURAL JOIN Libri " 
				+ "GROUP BY Nome_editore ";

		try {
			// caricamento del driver
			new com.mysql.jdbc.Driver();
			/*
			 * creazione di una connessione al database HenrysBooksDB20150226
			 * con credenziali di accesso appropriate
			 */
			connessione = DriverManager.getConnection(
					"jdbc:mysql://localhost/henrysbooksdb20150226", "root", "");

			// es. 1: esecuzione comando SQL
			Statement istruzione1 = connessione.createStatement();
			int ok = istruzione1.executeUpdate(stringa1);

			System.out.println();

			// es. 2: esecuzione comando SQL
			Statement istruzione2 = connessione.createStatement();
			int num = istruzione2.executeUpdate(stringa2);

			System.out
					.println("\n Il numero di tuple eliminate dalla tabella Editori è: "
							+ num + " ");

			// es. 3: esecuzione comando SQL
			Statement istruzione3 = connessione.createStatement();
			istruzione3.execute(stringa3);

			System.out.println();

			// es. 4: esecuzione comando SQL
			Statement istruzione4 = connessione.createStatement();
			ResultSet risultato4 = istruzione4.executeQuery(stringa4);

			System.out
					.println("\n Il contenuto della vista LibriPubblicati_MA è:");
			while (risultato4.next()) {
				titolo = risultato4.getString("Titolo_libro");
				nome = risultato4.getString("Nome_editore");
				System.out.println("Titolo_ libro: " + titolo
						+ "\tNome_editore:" + nome);

			}

			// es. 5: esecuzione comando SQL
			Statement istruzione5 = connessione.createStatement();
			ResultSet risultato5 = istruzione5.executeQuery(stringa5);

			System.out
					.println("\n Gli autori di libri pubblicati da editori dello stato del Massachusetts sono:");
			while (risultato5.next()) {
				numero = risultato5.getInt("Nro_autore");
				cognome = risultato5.getString("Cognome_autore");
				nome = risultato5.getString("Nome_autore");
				System.out.println("Nro_autore: " + numero
						+ "\tCognome_autore: " + cognome + "\tNome_autore: "
						+ nome);

			}

			// es. 6: esecuzione comando SQL
		//	Statement istruzione6 = connessione.createStatement();
		//	ResultSet risultato6 = istruzione6.executeQuery(stringa6);

		//	System.out
		//			.println("\n I Gli autori in ordine alfabetico per cognome sono:");
		//	while (risultato6.next()) {

		//	}

			// es. 7: esecuzione comando SQL
			Statement istruzione7 = connessione.createStatement();
			ResultSet risultato7 = istruzione7.executeQuery(stringa7);

			System.out.println("\n Il numero ed il prezzo medio dei libri pubblicati da ciascun editore:");
			while (risultato7.next()) {
				nome = risultato7.getString("Nome_editore");
				numero = risultato7.getInt("Libri_pubblicati");
				double prezzo = risultato7.getDouble("Prezzo_medio");
				System.out.println("Nome_editore: " + nome + "\tLibri_pubblicati: " + numero + "\tPrezzo_medio: " + prezzo);

			}
		} catch (SQLException e) {
			e.printStackTrace();

		}

	}
}
