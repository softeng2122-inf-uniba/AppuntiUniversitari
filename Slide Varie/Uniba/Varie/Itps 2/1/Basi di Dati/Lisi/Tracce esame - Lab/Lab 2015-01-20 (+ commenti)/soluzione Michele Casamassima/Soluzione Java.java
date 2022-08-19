package applicazione;
/*

Prova di Laboratorio di PROGETTAZIONE DI BASI DI DATI
C.d.S. in Informatica e Tecnologie per la Produzione del Software (3 anni)
Docente: dott.ssa Francesca A. Lisi

20 Gennaio 2015

-------------------------------------
Cognome e Nome	: Casamassima Michele
Matricola	: 621831
-------------------------------------

*/

import java.sql.*;

public class ProvaDB20150120 {

	public static void main(String[] args) {
		// sezione dichiarazione variabili locali
		String titolo;
		String nome;
		int numero;
		
		
		Connection connessione = null;

		// es. 1: creazione stringa contenente comando SQL
		
		String stringa1 = "ALTER TABLE Libri "
				        + "ADD FOREIGN KEY (Codice_editore) "
				        + "REFERENCES Editori(Codice_editore) ";

		// es. 2: creazione stringa contenente comando SQL
		
		String stringa2 = "DELETE FROM Editori "
				        + "WHERE Nome_editore = 'Rizzoli' ";

		// es. 3: creazione stringa contenente comando SQL
		
		String stringa3 = "CREATE VIEW LibriPubblicati_NY(Titolo_libro,Nome_editore)AS "
				        + "SELECT Titolo_libro,Nome_editore "
				        + "FROM Libri NATURAL JOIN Editori "
				        + "WHERE Stato_editore = 'NY' ";

		// es. 4: creazione stringa contenente comando SQL
		String stringa4 = "SELECT * FROM LibriPubblicati_NY "
				        + "GROUP BY Nome_editore, Nome_editore ";

		// es. 5: creazione stringa contenente comando SQL
		String stringa5 = "SELECT Nro_autore, Cognome_autore,Nome_autore,Titolo_libro,Nome_editore "
				        + "FROM Autori NATURAL JOIN LibriAutori NATURAL JOIN Libri NATURAL JOIN Editori "
				        + "WHERE Titolo_libro IN (SELECT(Titolo_libro) FROM LibriPubblicati_NY) "
				        + "ORDER BY Cognome_autore,Nome_autore ";

		// es. 6: creazione stringa contenente comando SQL
		
		String stringa6 = "SELECT Codice_libro,Titolo_libro,Count(Nro_autore) AS Nro_autori,Codice_editore,Nome_editore,Citta_editore "
		                + "FROM Autori NATURAL JOIN LibriAutori NATURAL JOIN Libri NATURAL JOIN Editori "
	                    + "GROUP BY Codice_libro "
	                    + "ORDER BY Titolo_libro ";


		// es. 7: creazione stringa contenente comando SQL
		String stringa7 = "SELECT Nome_editore,Codice_editore,Count(Codice_libro) AS Nro_libri,Avg(Prezzo_libro) AS Prezzo_medio "
		                + "FROM Editori NATURAL JOIN Libri "
		                + "GROUP BY Codice_editore ";
		
		try {
			// caricamento del driver
			new com.mysql.jdbc.Driver();
			/*
			  creazione di una connessione al database HenrysBooksDB20140120
			  con credenziali di accesso appropriate
			 */
			connessione = DriverManager.getConnection("jdbc:mysql://localhost/henrysbooksdb20150120","root","");

			// es. 1: esecuzione comando SQL
			Statement istruzione1 = connessione.createStatement();
			int ok = istruzione1.executeUpdate(stringa1);

			System.out.println();

			// es. 2: esecuzione comando SQL
			Statement istruzione2 = connessione.createStatement();
			int num = istruzione2.executeUpdate(stringa2);
			
			System.out.println("\n Il numero di tuple eliminate dalla tabella Editori è: " + num + " ");
			
			
			// es. 3: esecuzione comando SQL
			Statement istruzione3 = connessione.createStatement();
			istruzione3.execute(stringa3);

			System.out.println();

			
			// es. 4: esecuzione comando SQL
			Statement istruzione4 = connessione.createStatement();
			ResultSet risultato4 = istruzione4.executeQuery(stringa4);
			
			System.out.println("\n Il contenuto della vista LibriPubblicati_NY è:");
			while (risultato4.next()) {
				titolo = risultato4.getString("Titolo_libro");
				nome = risultato4.getString("Nome_editore");
				System.out.println("Titolo: " + titolo + "\tNome: " + nome);

			}
			
			// es. 5: esecuzione comando SQL
			Statement istruzione5 = connessione.createStatement();
			ResultSet risultato5 = istruzione5.executeQuery(stringa5);
			
			System.out.println("\n Gli autori di libri pubblicati da editori dello stato di New York sono:");
			while (risultato5.next()) {
				String cognome = risultato5.getString("Cognome_autore");
				nome = risultato5.getString("Nome_autore");
				titolo = risultato5.getString("Titolo_libro");
				System.out.println("Cognome: " + cognome + "\tNome: " + nome + "\tTitolo: " + titolo);
				
				

			}
			
			// es. 6: esecuzione comando SQL
			Statement istruzione6 = connessione.createStatement();
			ResultSet risultato6 = istruzione6.executeQuery(stringa6);
			
			System.out.println("\n I libri in ordine alfabetico di titolo sono:");
			while (risultato6.next()) {
				titolo = risultato6.getString("Titolo_libro");
				numero = risultato6.getInt("Nro_autori");
				nome = risultato6.getString("Nome_editore");
				String citta = risultato6.getString("Citta_editore");
				
				System.out.println("Titolo: " + titolo + "\tNumero autori: "+ numero + "\tNome editore: " + nome + "\tCitta editore: " + citta);

			}
			
			// es. 7: esecuzione comando SQL
			Statement istruzione7 = connessione.createStatement();
			ResultSet risultato7 = istruzione7.executeQuery(stringa7);
			
			System.out.println("\n Il numero ed il prezzo medio dei libri pubblicati da ciascun editore:");
			while (risultato7.next()) {
				nome = risultato7.getString("Nome_editore");
				numero = risultato7.getInt("Nro_libri");
				double prezzo = risultato7.getDouble("Prezzo_medio");
				
				System.out.println("Nome editore: " + nome + "\tNumero libri: " + numero + "\tPrezzo medio: " + prezzo);
				

			}
		} 
		catch (SQLException e) {
			e.printStackTrace();

		}

	}
}
