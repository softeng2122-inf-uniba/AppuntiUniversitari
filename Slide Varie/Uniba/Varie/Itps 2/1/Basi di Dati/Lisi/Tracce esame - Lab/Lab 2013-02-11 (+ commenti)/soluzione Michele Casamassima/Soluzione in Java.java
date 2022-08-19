package application;
/*

Prova di Laboratorio di PROGETTAZIONE DI BASI DI DATI
C.d.S. in Informatica e Tecnologie per la Produzione del Software (3 anni)
Docente: dott.ssa Francesca A. Lisi

11 Febbraio 2013

-------------------------------------
Cognome e Nome	: CASAMASSIMA MICHELE
Matricola	: 621831
-------------------------------------

 */

import java.sql.*;

public class ProvaDB20130211 {

	public static void main(String[] args) {
		// sezione dichiarazione variabili locali
		String titolo;
		String nome;
		int numero;

		Connection connessione = null;

		// es. 1: creazione stringa contenente comando SQL
		
		String stringa1 = "ALTER TABLE Scorte "
				        + "ADD FOREIGN KEY (Nro_Filiale) "
				        + "REFERENCES Filiali(Nro_filiale) ";

		// es. 2: creazione stringa contenente comando SQL
		//String stringa02 = "DELETE FROM Filiali"
		 //               + "WHERE Nro_Filiale = '5'";
		String stringa2 = "INSERT INTO Filiali (Nro_filiale, Nome_filiale, Sede_filiale) "
				        + "VALUES ('5','Henrys Manhattan','Broadway')";

		// es. 3: creazione stringa contenente comando SQL
		String stringa3 = "CREATE VIEW LibriInVendita_HB(Titolo_libro) AS "
				        + "SELECT Titolo_libro "
			          	+ "FROM Libri NATURAL JOIN Scorte NATURAL JOIN Filiali "
				        + "WHERE Nome_Filiale = \"Henrys Brentwood\"";

		// es. 4: creazione stringa contenente comando SQL
		String stringa4 = "SELECT * FROM LibriInVendita_HB";

		// es. 5: creazione stringa contenente comando SQL
		String stringa5 = "SELECT Nome_filiale, Titolo_libro, Nro_copie_disponibili "
			          	+ "FROM Filiali NATURAL JOIN scorte NATURAL JOIN libri "
			         	+ "ORDER BY Nome_filiale, Titolo_libro";

		// es. 6: creazione stringa contenente comando SQL
		String stringa6 = "SELECT Titolo_libro "
				        + "FROM libri NATURAL JOIN LibriInVendita_HB "
				        + "WHERE prezzo_libro = (SELECT MIN(Prezzo_libro) "
				        + "FROM Libri NATURAL JOIN LibriInVendita_HB)";

		// es. 7: creazione stringa contenente comando SQL
		String stringa7 = "SELECT Codice_libro, Titolo_libro, Tipo_libro, Prezzo_libro, Codice_editore, Nome_editore "
			           	+ "FROM Libri NATURAL JOIN Editori "
			         	+ "WHERE titolo_libro NOT IN "
			           	+ "(SELECT titolo_libro "
			          	+ "FROM LibriInVendita_HB)";

		try {
			// caricamento del driver
			new com.mysql.jdbc.Driver();
			/*
			 * creazione di una connessione al database HenrysBooksDB20130222
			 * con credenziali di accesso appropriate
			 */
			connessione = DriverManager.getConnection("jdbc:mysql://localhost/henrysbooksdb20130211","root","");

			// es. 1: esecuzione comando SQL
			Statement istruzione1 = connessione.createStatement();
			int ok = istruzione1.executeUpdate(stringa1);

			System.out.println();

			// es. 2: esecuzione comando SQL
			Statement istruzione2 = connessione.createStatement();
			//int delete = istruzione2.executeUpdate(stringa02);
			int num = istruzione2.executeUpdate(stringa2);
           
			//System.out.println("\n La tupla eliminata è: " + delete + ".");
			System.out.println("\nIl numero di linee modificate è: " + num + ".");

			// es. 3: esecuzione comando SQL
			Statement istruzione3 = connessione.createStatement();
			istruzione3.execute(stringa3);

			System.out.println();

			// es. 4: esecuzione comando SQL
			Statement istruzione4 = connessione.createStatement();
			ResultSet risultato4 = istruzione4.executeQuery(stringa4);

			System.out
					.println("\nIl contenuto della vista LibriInVendita_HB è:");
			while (risultato4.next()) {
				titolo = risultato4.getString("Titolo_libro");
				System.out.println("Titolo: " + titolo);

			}

			// es. 5: esecuzione comando SQL
			Statement istruzione5 = connessione.createStatement();
			ResultSet risultato5 = istruzione5.executeQuery(stringa5);

			System.out.println("\nIl titolo dei libri per filiale e il numero copie è: ");
			while (risultato5.next()) {
				titolo = risultato5.getString("Titolo_libro");
				nome = risultato5.getString("Nome_filiale");
				numero = risultato5.getInt("Nro_copie_disponibili");
				System.out.println("Filiale: " + nome + "\tTitolo: " + titolo + "\tCopie: " + numero);

			}

			// es. 6: esecuzione comando SQL
			Statement istruzione6 = connessione.createStatement();
			ResultSet risultato6 = istruzione6.executeQuery(stringa6);

			System.out.println("\nIl titolo del libro più economico è: ");
			while (risultato6.next()) {
				titolo = risultato6.getString("Titolo_libro");
				System.out.println("Titolo: " + titolo);

			}

			// es. 7: esecuzione comando SQL
			Statement istruzione7 = connessione.createStatement();
			ResultSet risultato7 = istruzione7.executeQuery(stringa7);

			System.out.println("\nI titoli dei libri, i nomi degli editori e il prezzo dei libri non presenti sulla vista LibriInVendita_HB sono: ");
			while (risultato7.next()) {
				titolo = risultato7.getString("Titolo_libro");
				nome = risultato7.getString("Nome_editore");
				double prezzo = risultato7.getDouble("Prezzo_libro");
				System.out.println("Titolo: " + titolo + "\tNome editore: " + nome +  "\tPrezzo: " +prezzo );

			}
		} catch (SQLException e) {
			e.printStackTrace();

		}

	}
}