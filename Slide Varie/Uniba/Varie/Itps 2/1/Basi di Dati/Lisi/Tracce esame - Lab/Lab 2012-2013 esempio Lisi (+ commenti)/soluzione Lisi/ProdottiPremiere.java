/*

Prova di Laboratorio di PROGETTAZIONE DI BASI DI DATI
C.d.S. in Informatica e Tecnologie per la Produzione del Software (3 anni)
Docente: dott.ssa Francesca A. Lisi

21 Dicembre 2012

-------------------------------------
Cognome e Nome	: Lisi Francesca
Matricola	: 271110N
-------------------------------------

*/


package application;

import java.sql.*;

public class ProdottiPremiere {

	public static void main(String[] args) {
		// sezione dichiarazione variabili locali
		
		Connection connessione = null;
		String codice;
		String nome;
		String cognome;
		Double fido;
		Integer num;
		boolean ok;
		

		// es. 1: creazione stringa contenente comando SQL
		String stringa1 = 
				"CREATE TABLE IF NOT EXISTS DettOrdini(" +
				"NroOrdine CHAR (5)," +
				"NroArticolo CHAR (4)," +
				"QtaOrdinata DECIMAL (3,0)," +
				"PrezzoRichiesto DECIMAL (6,2)," +
				"PRIMARY KEY (NroOrdine, NroArticolo)," +
				"FOREIGN KEY (NroOrdine) REFERENCES Ordini (NroOrdine) ON DELETE CASCADE ON UPDATE CASCADE," +
				"FOREIGN KEY (NroArticolo) REFERENCES Articoli(NroArt) ON DELETE CASCADE ON UPDATE CASCADE)";
		// es. 2: creazione stringa contenente comando SQL
		String stringa2 = 
				"INSERT INTO DettOrdini VALUES ('12489','AX12',11,21.95)";
		// es. 3: creazione stringa contenente comando SQL
		String stringa3 = 
				"CREATE VIEW PiccoliClienti AS " +
				"SELECT * FROM Clienti WHERE Fido<=1000";
		// es. 4: creazione stringa contenente comando SQL
		String stringa4 = 
				"SELECT DISTINCT Clienti.CodCliente, Nome, Cognome " +
				"FROM Clienti NATURAL JOIN Ordini " +
				"WHERE Data='2002-09-05'";
		// es. 5: creazione stringa contenente comando SQL
		String stringa5 = 
				"SELECT CodRappr, Cognome, Nome " +
				"FROM Rappresentanti " +
				"WHERE CodRappr IN (" +
				"SELECT CodRappr " +
				"FROM Clienti " +
				"WHERE Fido=1000)";
		// es. 6: creazione stringa contenente comando SQL
		String stringa6 = 
				"SELECT Fido, COUNT(*) " +
				"FROM Clienti " +
				"WHERE CodRappr='03' " +
				"GROUP BY Fido " +
				"HAVING COUNT(*)>1";
		// es. 7: creazione stringa contenente comando SQL
		String stringa7 = 
				"SELECT CodCliente, Cognome, Nome " +
				"FROM PiccoliClienti " +
				"WHERE Saldo > Fido";
			
		try {
			// caricamento del driver
			new com.mysql.jdbc.Driver();
			/*
			  creazione di una connessione al database ProdottiPremiereDB
			  con credenziali di accesso appropriate
			 */
			connessione = DriverManager.getConnection(
					"jdbc:mysql://localhost/ProdottiPremiereDB", "root", "root");

			// es. 1: esecuzione comando SQL
			Statement istruzione1 = connessione.createStatement();
			ok = istruzione1.execute(stringa1);
			
			num = (ok)?1:0;
			System.out.println("Il numero di righe coinvolte dal comando di creazione della tabella DettOrdini è: " + num + " ");

			// es. 2: esecuzione comando SQL
			Statement istruzione2 = connessione.createStatement();
			num = istruzione2.executeUpdate(stringa2);
			
			System.out.println("\n Il numero di inserimenti fatti nella tabella DettOrdini è: " + num + " ");
			
			// es. 3: esecuzione comando SQL
			Statement istruzione3 = connessione.createStatement();
			istruzione3.execute(stringa3);

			Statement istruzione3_1 = connessione.createStatement();
			ResultSet risultato3_1 = istruzione3_1.executeQuery("SELECT * FROM PiccoliClienti");
			
			System.out.println("\n I clienti con saldo inferiore a 1000 sono:");
			while (risultato3_1.next()) {
				codice = risultato3_1.getString("CodCliente");
				cognome = risultato3_1.getString("Cognome");
				nome = risultato3_1.getString("Nome");
				System.out.println("Codice: " + codice + "  Cognome: "
						+ cognome + "  Nome: " + nome + " ");
			}
			
			// es. 4: esecuzione comando SQL
			Statement istruzione4 = connessione.createStatement();
			ResultSet risultato4 = istruzione4.executeQuery(stringa4);
			
			System.out.println("\n I clienti che hanno emesso un ordine il 5 settembre 2002 sono:");
			while (risultato4.next()) {
				codice = risultato4.getString("CodCliente");
				cognome = risultato4.getString("Cognome");
				nome = risultato4.getString("Nome");
				System.out.println("Codice: " + codice + "  Cognome: "
						+ cognome + "  Nome: " + nome + " ");
			}
			
			// es. 5: esecuzione comando SQL
			Statement istruzione5 = connessione.createStatement();
			ResultSet risultato5 = istruzione5.executeQuery(stringa5);
			
			System.out.println("\n I rappresentanti che hanno almeno un cliente con fido di 1000 euro sono:");
			while (risultato5.next()) {
				codice = risultato5.getString("CodRappr");
				cognome = risultato5.getString("Cognome");
				nome = risultato5.getString("Nome");
				System.out.println("Codice: " + codice + "  Cognome: "
						+ cognome + "  Nome: " + nome + " ");
			}
			
			// es. 6: esecuzione comando SQL
			Statement istruzione6 = connessione.createStatement();
			ResultSet risultato6 = istruzione6.executeQuery(stringa6);
			
			System.out.println("\n Il numero dei clienti del rappresentante con codice 03 aventi un certo fido è:");
			while (risultato6.next()) {
				fido = risultato6.getDouble("Fido");
				num = risultato6.getInt("COUNT(*)");
				System.out.println("Fido: " + fido + "  Numero clienti: " + num + " ");
			}
			
			// es. 7: esecuzione comando SQL
			Statement istruzione7 = connessione.createStatement();
			ResultSet risultato7 = istruzione7.executeQuery(stringa7);
			
			System.out.println("\n I clienti con saldo inferiore a 1000 e fido superiore al saldo sono:");
			while (risultato7.next()) {
				codice = risultato7.getString("CodCliente");
				cognome = risultato7.getString("Cognome");
				nome = risultato7.getString("Nome");
				System.out.println("Codice: " + codice + "  Cognome: "
						+ cognome + "  Nome: " + nome + " ");
			}
		} 
		catch (SQLException e) {
			e.printStackTrace();

		}

	}
}
