/*

Prova di Laboratorio di PROGETTAZIONE DI BASI DI DATI
C.d.S. in Informatica e Tecnologie per la Produzione del Software (3 anni)
Docente: dott.ssa Francesca A. Lisi

28 Gennaio 2013

-------------------------------------
Cognome e Nome	: Casamassima Michele
Matricola	: 621831
-------------------------------------

 */

package application;

import java.sql.*;

public class ProvaDB20130128 {

	public static void main(String[] args) {
		// sezione dichiarazione variabili locali
int codice;
String nome;
String cognome;
String titolo;
int numero;

		Connection connessione = null;

		// es. 1: creazione stringa contenente comando SQL
		String stringa1 = "ALTER TABLE LibriAutori "
				+ "ADD FOREIGN KEY(Nro_autore) "
				+ "REFERENCES Autori(Nro_autore) "	;

		// es. 2: creazione stringa contenente comando SQL
		String stringa2 = "INSERT INTO Autori (Nro_autore, Cognome_autore, Nome_autore) "
				+ "VALUES ('24','','Liala') ";

		// es. 3: creazione stringa contenente comando SQL
		String stringa3 = "CREATE VIEW LibriPubblicati_PB(Codice_libro, Titolo_libro, Tipo_libro) AS "
				+ "SELECT Codice_libro, Titolo_libro, Tipo_libro "
				+ "FROM Libri NATURAL JOIN Editori "
				+ "WHERE Nome_editore = 'Pocket Books' ";

		// es. 4: creazione stringa contenente comando SQL
		String stringa4 = "SELECT * FROM LibriPubblicati_PB ";

		// es. 5: creazione stringa contenente comando SQL
		String stringa5 = "SELECT Nro_autore, Cognome_autore, Nome_autore "
				+ "FROM Autori NATURAL JOIN LibriAutori "
				+ "WHERE Codice_libro NOT IN (Select Codice_libro FROM LibriPubblicati_PB) "
				+ "ORDER BY Cognome_autore, Nome_autore ";
		
		// es. 6: creazione stringa contenente comando SQL
		String stringa6 = "SELECT Titolo_libro, Tipo_libro "
				+ "FROM Libri NATURAL JOIN LibriPubblicati_PB "
				+ "WHERE Prezzo_libro = (SELECT MAX(Prezzo_libro) "
				+ "FROM Libri NATURAL JOIN LibriPubblicati_PB) ";

		// es. 7: creazione stringa contenente comando SQL
		String stringa7 = "SELECT Cognome_autore, Nome_autore, Nro_copie_disponibili "
				+ "FROM LibriPubblicati_PB NATURAL JOIN LibriAutori NATURAL JOIN Autori NATURAL JOIN Scorte NATURAL JOIN Filiali "
				+ "WHERE Nro_Seq = 1 AND Nome_Filiale = 'Henrys Books' ";

		try {
			// caricamento del driver
			new com.mysql.jdbc.Driver();
			/*
			 * creazione di una connessione al database ProdottiPremiereDB con
			 * credenziali di accesso appropriate
			 */
			connessione = DriverManager.getConnection("jdbc:mysql://localhost/henrysbooksdb20130128", "root", "");

			// es. 1: esecuzione comando SQL
			Statement istruzione1 = connessione.createStatement();
			int ok = istruzione1.executeUpdate(stringa1);

			System.out.println();

			// es. 2: esecuzione comando SQL
			Statement istruzione2 = connessione.createStatement();
			int num = istruzione2.executeUpdate(stringa2);

			System.out.println("\n Il numero di inserimenti fatti nella tabella Autori è: "
							+ num + " ");

			// es. 3: esecuzione comando SQL
			Statement istruzione3 = connessione.createStatement();
			istruzione3.execute(stringa3);

			System.out.println();

			// es. 4: esecuzione comando SQL
			Statement istruzione4 = connessione.createStatement();
			ResultSet risultato4 = istruzione4.executeQuery(stringa4);

			System.out
					.println("\n Il contenuto della vista LibriPubblicati_PB è:");
			while (risultato4.next()) {
				codice = risultato4.getInt("Codice_libro");
				titolo = risultato4.getString("Titolo_libro");
				String tipo = risultato4.getString("Tipo_libro");
				
				System.out.println("Codice_libro: " + codice + "\tTitolo_libro: " + titolo + "\tTipo_libro: " + tipo);
				
				
				

			}

			// es. 5: esecuzione comando SQL
			Statement istruzione5 = connessione.createStatement();
			ResultSet risultato5 = istruzione5.executeQuery(stringa5);

			System.out
					.println("\n Gli autori che non pubblicano libri con l’editore di nome 'Pocket Books' sono:");
			while (risultato5.next()) {
				numero = risultato5.getInt("Nro_autore");
				cognome = risultato5.getString("Cognome_autore");
				nome = risultato5.getString("Nome_autore");
				
				System.out.println("Nro_autore: " + numero + "\tCognome_autore: " + cognome + "Nome_autore: " + nome);
				
				

			}

			// es. 6: esecuzione comando SQL
			Statement istruzione6 = connessione.createStatement();
			ResultSet risultato6 = istruzione6.executeQuery(stringa6);

			System.out
					.println("\n Il titolo e tipo del libro più costoso fra quelli pubblicati dall’editore di nome 'Pocket Books' è:");
			while (risultato6.next()) {
				titolo = risultato6.getString("Titolo_libro");
			    String tipo = risultato6.getString("Tipo_libro");
				
				System.out.println("Titolo_libro: " + titolo + "\tTipo_libro: " + tipo);

			}

			// es. 7: esecuzione comando SQL
			Statement istruzione7 = connessione.createStatement();
			ResultSet risultato7 = istruzione7.executeQuery(stringa7);

			System.out
					.println("\n Per ciascun libro pubblicato dall’editore di nome 'Pocket Books', il cognome e nome del primo autore ed il numero totale di copie disponibili presso le filiali Henrys Books è:");
			while (risultato7.next()) {
				cognome = risultato7.getString("Cognome_autore");
				nome = risultato7.getString("Nome_autore");
				numero = risultato7.getInt("Nro_copie_disponibili");
				
				System.out.println("Cognome_autore: " + cognome + "\tNome_autore: "+ nome + "\tNro_copie_disponibili: " + numero);

			}
		} catch (SQLException e) {
			e.printStackTrace();

		}

	}
}
