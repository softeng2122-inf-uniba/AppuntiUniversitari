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
		
		int ok, num;
		Connection connessione = null;

		

		// es. 1: creazione stringa contenente comando SQL
		String stringa1 = "ALTER TABLE LibriAutori"
				+ " ADD FOREIGN KEY (Codice_libro) REFERENCES Libri(Codice_libro);";

		// es. 2: creazione stringa contenente comando SQL
		String stringa2 = "INSERT INTO Autori VALUES ('24', '', 'Liala');";

		// es. 3: creazione stringa contenente comando SQL
		String stringa3 = "CREATE VIEW LibriPubblicati_PB(Codice_libro, Titolo_libro, Tipo_libro)"
				+ " AS SELECT Codice_libro, Titolo_libro, Tipo_libro"
				+ " FROM Libri NATURAL JOIN Editori"
				+ " WHERE Nome_editore = 'Pocket Books';";

		// es. 4: creazione stringa contenente comando SQL
		String stringa4 = "SELECT * FROM LibriPubblicati_PB;";

		// es. 5: creazione stringa contenente comando SQL
		String stringa5 = "SELECT * FROM Autori"
				+ " WHERE (Nro_autore, Cognome_autore, Nome_autore)"
				+ " NOT IN (SELECT Nro_autore, Cognome_autore, Nome_autore"
				+ " FROM Autori NATURAL JOIN LibriAutori NATURAL JOIN LibriPubblicati_PB)"
				+ " ORDER BY Cognome_autore, Nome_autore;";

		// es. 6: creazione stringa contenente comando SQL
		String stringa6 = "SELECT Titolo_libro, Tipo_libro"
				+ " FROM Libri NATURAL JOIN LibriPubblicati_PB"
				+ " WHERE Prezzo_libro = ("
				+ " SELECT max(prezzo_libro)"
				+ " FROM Libri NATURAL JOIN LibriPubblicati_PB);";

		// es. 7: creazione stringa contenente comando SQL
		String stringa7 = "SELECT DISTINCT Titolo_libro, Cognome_autore, Nome_autore, sum(Nro_copie_disponibili) AS CopieTotali"
				+ " FROM LibriPubblicati_PB NATURAL JOIN LibriAutori NATURAL JOIN Autori NATURAL JOIN Scorte"
				+ " WHERE Nro_seq = 1"
				+ " GROUP BY (Codice_libro);";
			
		try {
			// caricamento del driver
			new com.mysql.jdbc.Driver();
			/*
			  creazione di una connessione al database ProdottiPremiereDB
			  con credenziali di accesso appropriate
			 */
			connessione = DriverManager.getConnection("jdbc:mysql://localhost/HenrysBooksDB20130128", "root", "");

			// es. 1: esecuzione comando SQL
			Statement istruzione1 = connessione.createStatement();
			ok = istruzione1.executeUpdate(stringa1);
			
			System.out.println("Es1: Aggiunto vincolo referenziale fra l'attributo Codice_libro della relazione LibriAutori e la relazione Libri");

			// es. 2: esecuzione comando SQL
			Statement istruzione2 = connessione.createStatement();
			num = istruzione2.executeUpdate(stringa2);
			
			System.out.println("\nEs2: Aggiunta una tupla in Autori. Il numero di inserimenti fatti nella tabella Autori è: " + num + " ");
			
			
			// es. 3: esecuzione comando SQL
			Statement istruzione3 = connessione.createStatement();
			istruzione3.execute(stringa3);

			System.out.println("\nEs3: Creata vista LibriPubblicati_PB.");

			
			// es. 4: esecuzione comando SQL
			Statement istruzione4 = connessione.createStatement();
			ResultSet risultato4 = istruzione4.executeQuery(stringa4);
			
			System.out.println("\nEs4: Il contenuto della vista LibriPubblicati_PB è:");
			while (risultato4.next()) {
				String codice = risultato4.getString("Codice_libro");
				String titolo = risultato4.getString("Titolo_libro");
				String tipo = risultato4.getString("Tipo_libro");
				System.out.println("Codice: " + codice + ", Titolo: " + titolo + ", Tipo: " + tipo);
			}
			
			// es. 5: esecuzione comando SQL
			Statement istruzione5 = connessione.createStatement();
			ResultSet risultato5 = istruzione5.executeQuery(stringa5);
			
			System.out.println("\nEs5: Gli autori che non pubblicano libri con l’editore di nome 'Pocket Books' sono:");
			while (risultato5.next()) {
				String numero = risultato5.getString("Nro_autore");
				String cognome = risultato5.getString("Cognome_autore");
				String nome = risultato5.getString("Nome_autore");
				System.out.println("Numero: " + numero + ", Cognome: " + cognome + ", Nome: " + nome);
			}
			
			// es. 6: esecuzione comando SQL
			Statement istruzione6 = connessione.createStatement();
			ResultSet risultato6 = istruzione6.executeQuery(stringa6);
			
			System.out.println("\nEs6: Il titolo e tipo del libro più costoso fra quelli pubblicati dall’editore di nome 'Pocket Books' è:");
			while (risultato6.next()) {
				String titolo = risultato6.getString("Titolo_libro");
				String tipo = risultato6.getString("Tipo_libro");
				System.out.println("Titolo: " + titolo + ", Tipo: " + tipo);
			}
			
			// es. 7: esecuzione comando SQL
			Statement istruzione7 = connessione.createStatement();
			ResultSet risultato7 = istruzione7.executeQuery(stringa7);
			
			System.out.println("\nEs7: Per ciascun libro pubblicato dall’editore di nome 'Pocket Books', il cognome e nome del primo autore ed il numero totale di copie disponibili presso le filiali Henrys Books è:");
			while (risultato7.next()) {
				String titolo = risultato7.getString("Titolo_libro");
				String cognome = risultato7.getString("Cognome_autore");
				String nome = risultato7.getString("Nome_autore");
				String somma = risultato7.getString("CopieTotali");
				System.out.print("Titolo: " + titolo + ", Cognome: " + cognome);
				System.out.println(", Nome: " + nome + ", Copie: " + somma);
			}
		} 
		catch (SQLException e) {
			e.printStackTrace();

		}

	}
}
