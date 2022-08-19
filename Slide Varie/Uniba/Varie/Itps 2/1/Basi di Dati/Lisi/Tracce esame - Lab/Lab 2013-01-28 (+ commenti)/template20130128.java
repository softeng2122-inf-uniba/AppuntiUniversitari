/*

Prova di Laboratorio di PROGETTAZIONE DI BASI DI DATI
C.d.S. in Informatica e Tecnologie per la Produzione del Software (3 anni)
Docente: dott.ssa Francesca A. Lisi

28 Gennaio 2013

-------------------------------------
Cognome e Nome	:
Matricola	:
-------------------------------------

*/


package application;

import java.sql.*;

public class ProvaDB20130128 {

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
			  creazione di una connessione al database ProdottiPremiereDB
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
			
			System.out.println("\n Il numero di inserimenti fatti nella tabella Autori è: " + num + " ");
			
			
			// es. 3: esecuzione comando SQL
			Statement istruzione3 = connessione.createStatement();
			istruzione3.execute(stringa3);

			System.out.println();

			
			// es. 4: esecuzione comando SQL
			Statement istruzione4 = connessione.createStatement();
			ResultSet risultato4 = istruzione4.executeQuery(stringa4);
			
			System.out.println("\n Il contenuto della vista LibriPubblicati_PB è:");
			while (risultato4.next()) {

			}
			
			// es. 5: esecuzione comando SQL
			Statement istruzione5 = connessione.createStatement();
			ResultSet risultato5 = istruzione5.executeQuery(stringa5);
			
			System.out.println("\n Gli autori che non pubblicano libri con l’editore di nome 'Pocket Books' sono:");
			while (risultato5.next()) {

			}
			
			// es. 6: esecuzione comando SQL
			Statement istruzione6 = connessione.createStatement();
			ResultSet risultato6 = istruzione6.executeQuery(stringa6);
			
			System.out.println("\n Il titolo e tipo del libro più costoso fra quelli pubblicati dall’editore di nome 'Pocket Books' è:");
			while (risultato6.next()) {

			}
			
			// es. 7: esecuzione comando SQL
			Statement istruzione7 = connessione.createStatement();
			ResultSet risultato7 = istruzione7.executeQuery(stringa7);
			
			System.out.println("\n Per ciascun libro pubblicato dall’editore di nome 'Pocket Books', il cognome e nome del primo autore ed il numero totale di copie disponibili presso le filiali Henrys Books è:");
			while (risultato7.next()) {

			}
		} 
		catch (SQLException e) {
			e.printStackTrace();

		}

	}
}
