/*

Prova di Laboratorio di PROGETTAZIONE DI BASI DI DATI
C.d.S. in Informatica e Tecnologie per la Produzione del Software (3 anni)
Docente: dott.ssa Francesca A. Lisi

22 Febbraio 2013

-------------------------------------
Cognome e Nome	:
Matricola	:
-------------------------------------

*/


package application;

import java.sql.*;

public class ProvaDB20130222 {

	public static void main(String[] args) {
		// sezione dichiarazione variabili locali
		
		Connection connessione = null;

		

		// es. 1: creazione stringa contenente comando SQL
		String stringa1 = "";

		// es. 2: creazione stringa contenente comando SQL
		String stringa2 = "";

		// es. 3: creazione stringa contenente comando SQL
		String stringa3 = "";

		// es. 4: creazione stringa contenente comando SQL
		String stringa4 = "";

		// es. 5: creazione stringa contenente comando SQL
		String stringa5 = "";

		// es. 6: creazione stringa contenente comando SQL
		String stringa6 = "";

		// es. 7: creazione stringa contenente comando SQL
		String stringa7 = "";
			
		try {
			// caricamento del driver
			new com.mysql.jdbc.Driver();
			/*
			  creazione di una connessione al database HenrysBooksDB20130222
			  con credenziali di accesso appropriate
			 */
			connessione = DriverManager.getConnection();

			// es. 1: esecuzione comando SQL
			Statement istruzione1 = connessione.createStatement();
			ok = istruzione1.executeUpdate(stringa1);
			
			System.out.println();

			// es. 2: esecuzione comando SQL
			Statement istruzione2 = connessione.createStatement();
			num = istruzione2.executeUpdate(stringa2);
			
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

			}
			
			// es. 5: esecuzione comando SQL
			Statement istruzione5 = connessione.createStatement();
			ResultSet risultato5 = istruzione5.executeQuery(stringa5);
			
			System.out.println("\n Gli autori che hanno pubblicato almeno un libro con editori di New York sono:");
			while (risultato5.next()) {

			}
			
			// es. 6: esecuzione comando SQL
			Statement istruzione6 = connessione.createStatement();
			ResultSet risultato6 = istruzione6.executeQuery(stringa6);
			
			System.out.println("\n I titoli dei libri con numero di autori, e il nome e la città dell’editore:");
			while (risultato6.next()) {

			}
			
			// es. 7: esecuzione comando SQL
			Statement istruzione7 = connessione.createStatement();
			ResultSet risultato7 = istruzione7.executeQuery(stringa7);
			
			System.out.println("\n Il numero ed il prezzo medio dei libri pubblicati da ciascun editore:");
			while (risultato7.next()) {

			}
		} 
		catch (SQLException e) {
			e.printStackTrace();

		}

	}
}
