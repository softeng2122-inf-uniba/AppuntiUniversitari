/*

Prova di Laboratorio di PROGETTAZIONE DI BASI DI DATI
C.d.S. in Informatica e Tecnologie per la Produzione del Software (3 anni)
Docente: dott.ssa Francesca A. Lisi

4 Febbraio 2015

-------------------------------------
Cognome e Nome	:
Matricola	:
-------------------------------------

*/


package application;

import java.sql.*;

public class ProvaDB20150204 {

	public static void main(String[] args) {
		// sezione dichiarazione variabili locali
		int ok, num;
		
		Connection connessione = null;

		

		// es. 1: creazione stringa contenente comando SQL
		String stringa1 = "ALTER TABLE Scorte ADD FOREIGN KEY (Nro_filiale) REFERENCES Filiali(Nro_filiale);";

		// es. 2: creazione stringa contenente comando SQL
		String stringa2 = "INSERT INTO Filiali VALUES ('5', 'Henrys Manhattan', 'Broadway', default);";

		// es. 3: creazione stringa contenente comando SQL
		String stringa3 = "CREATE VIEW LibriDisponibili_HD(Titolo_libro)"
				+ " AS SELECT Titolo_libro FROM Libri NATURAL JOIN Scorte NATURAL JOIN Filiali"
				+ " WHERE Nome_filiale = 'Henrys Downtown' AND Nro_copie_disponibili >= 1;";

		// es. 4: creazione stringa contenente comando SQL
		String stringa4 = "SELECT * FROM LibriDisponibili_HD;";

		// es. 5: creazione stringa contenente comando SQL
		String stringa5 = "SELECT Nome_filiale, Titolo_libro, Nro_copie_disponibili"
				+ " FROM Filiali NATURAL JOIN Scorte NATURAL JOIN Libri"
				+ " ORDER BY Nome_filiale, Titolo_libro;";

		// es. 6: creazione stringa contenente comando SQL
		String stringa6 = "SELECT Titolo_libro, Prezzo_libro AS Costo FROM Libri NATURAL JOIN LibriDisponibili_HD"
				+ " WHERE Prezzo_libro = (SELECT min(prezzo_libro) FROM Libri NATURAL JOIN LibriDisponibili_HD);";

		// es. 7: creazione stringa contenente comando SQL
		String stringa7 = "SELECT Titolo_libro, Nome_editore, Prezzo_libro FROM Libri nothd NATURAL JOIN Editori"
				+ " WHERE NOT EXISTS (SELECT * FROM LibriDisponibili_HD hd WHERE nothd.Titolo_libro = hd.Titolo_libro)"
				+ " ORDER BY Titolo_libro;";
			
		try {
			// caricamento del driver
			new com.mysql.jdbc.Driver();
			/*
			  creazione di una connessione al database HenrysBooksDB20140204
			  con credenziali di accesso appropriate
			 */
			connessione = DriverManager.getConnection("jdbc:mysql://localhost/HenrysBooksDB20150204", "root", "");

			// es. 1: esecuzione comando SQL
			Statement istruzione1 = connessione.createStatement();
			ok = istruzione1.executeUpdate(stringa1);
			
			System.out.println("Es1: Aggiunto vincolo fra Scorte e Filiali.");

			// es. 2: esecuzione comando SQL
			Statement istruzione2 = connessione.createStatement();
			num = istruzione2.executeUpdate(stringa2);
			
			System.out.println("\nEs2: Il numero di inserimenti fatti nella tabella Filiali è: " + num + " ");
			
			
			// es. 3: esecuzione comando SQL
			Statement istruzione3 = connessione.createStatement();
			istruzione3.execute(stringa3);

			System.out.println("\nEs3: Creata la vista LibriPubblicatiHD.");

			
			// es. 4: esecuzione comando SQL
			Statement istruzione4 = connessione.createStatement();
			ResultSet risultato4 = istruzione4.executeQuery(stringa4);
			
			System.out.println("\nEs4: Il contenuto della vista LibriDisponibili_HD è:");
			while (risultato4.next()) {
				String titolo = risultato4.getString("Titolo_libro");
				System.out.println(titolo);
			}
			
			// es. 5: esecuzione comando SQL
			Statement istruzione5 = connessione.createStatement();
			ResultSet risultato5 = istruzione5.executeQuery(stringa5);
			
			System.out.println("\nEs5: I titoli ed il numero di copie disponibili dei libri in vendita presso ciascuna filiale sono:");
			while (risultato5.next()) {
				String nome = risultato5.getString("Nome_filiale");
				String titolo = risultato5.getString("Titolo_libro");
				int copie = risultato5.getInt("Nro_copie_disponibili");
				System.out.println("Filiale: " + nome + ";   Libro: " + titolo + ";   Copie disponibili: " + copie);
			}
			
			// es. 6: esecuzione comando SQL
			Statement istruzione6 = connessione.createStatement();
			ResultSet risultato6 = istruzione6.executeQuery(stringa6);
			
			System.out.println("\nEs6: Il titolo del libro meno costoso fra quelli disponibili presso la filiale 'Henrys Downtown' è:");
			while (risultato6.next()) {
				String titolo = risultato6.getString("Titolo_libro");
				String costo = risultato6.getString("Costo");
				System.out.println("Titolo: " + titolo + ", Costo: " + costo);
			}
			
			// es. 7: esecuzione comando SQL
			Statement istruzione7 = connessione.createStatement();
			ResultSet risultato7 = istruzione7.executeQuery(stringa7);
			
			System.out.println("\nEs7: I libri che non sono disponibili presso la filiale 'Henrys Downtown' sono:");
			while (risultato7.next()) {
				String titolo = risultato7.getString("Titolo_libro");
				String editore = risultato7.getString("Nome_editore");
				String costo = risultato7.getString("Prezzo_libro");
				System.out.println("Libro: " + titolo + ",  Editore: " + editore + ",  Costo: " + costo);
			}
		} 
		catch (SQLException e) {
			e.printStackTrace();

		}

	}
}

//Output console

//Es1: Aggiunto vincolo fra Scorte e Filiali.
//
//Es2: Il numero di inserimenti fatti nella tabella Filiali è: 1 
//
//Es3: Creata la vista LibriPubblicatiHD.
//
//Es4: Il contenuto della vista LibriDisponibili_HD è:
//Shyness
//Stranger
//Cujo
//Ghost from the Grand Banks
//Hymns to the Night
//Higher Creativity
//Organ
//A Guide to SQL
//Castle
//Amerika
//
//Es5: I titoli ed il numero di copie disponibili dei libri in vendita presso ciascuna filiale sono:
//Filiale: Henrys Brentwood;   Libro: Cujo;   Copie disponibili: 2
//Filiale: Henrys Brentwood;   Libro: Evil Under the Sun;   Copie disponibili: 3
//Filiale: Henrys Brentwood;   Libro: Ghost from the Grand Banks;   Copie disponibili: 2
//Filiale: Henrys Brentwood;   Libro: Magritte;   Copie disponibili: 1
//Filiale: Henrys Brentwood;   Libro: Night Probe;   Copie disponibili: 2
//Filiale: Henrys Brentwood;   Libro: Prodigal Daughter;   Copie disponibili: 2
//Filiale: Henrys Brentwood;   Libro: Smokescreen;   Copie disponibili: 2
//Filiale: Henrys Brentwood;   Libro: Vortex;   Copie disponibili: 2
//Filiale: Henrys Downtown;   Libro: A Guide to SQL;   Copie disponibili: 1
//Filiale: Henrys Downtown;   Libro: Amerika;   Copie disponibili: 2
//Filiale: Henrys Downtown;   Libro: Castle;   Copie disponibili: 3
//Filiale: Henrys Downtown;   Libro: Cujo;   Copie disponibili: 1
//Filiale: Henrys Downtown;   Libro: Ghost from the Grand Banks;   Copie disponibili: 3
//Filiale: Henrys Downtown;   Libro: Higher Creativity;   Copie disponibili: 2
//Filiale: Henrys Downtown;   Libro: Hymns to the Night;   Copie disponibili: 3
//Filiale: Henrys Downtown;   Libro: Organ;   Copie disponibili: 1
//Filiale: Henrys Downtown;   Libro: Shyness;   Copie disponibili: 2
//Filiale: Henrys Downtown;   Libro: Stranger;   Copie disponibili: 1
//Filiale: Henrys Eastshore;   Libro: Database Systems;   Copie disponibili: 2
//Filiale: Henrys Eastshore;   Libro: Ghost from the Grand Banks;   Copie disponibili: 1
//Filiale: Henrys Eastshore;   Libro: Hymns to the Night;   Copie disponibili: 1
//Filiale: Henrys Eastshore;   Libro: Prints of the 20th Century;   Copie disponibili: 3
//Filiale: Henrys Eastshore;   Libro: Smokescreen;   Copie disponibili: 3
//Filiale: Henrys On The Hill;   Libro: Cujo;   Copie disponibili: 4
//Filiale: Henrys On The Hill;   Libro: dBase Programming;   Copie disponibili: 2
//Filiale: Henrys On The Hill;   Libro: Death on the Nile;   Copie disponibili: 3
//Filiale: Henrys On The Hill;   Libro: DOS Essentials;   Copie disponibili: 2
//Filiale: Henrys On The Hill;   Libro: Evil Under the Sun;   Copie disponibili: 4
//Filiale: Henrys On The Hill;   Libro: Kane and Abel;   Copie disponibili: 2
//Filiale: Henrys On The Hill;   Libro: Risk;   Copie disponibili: 2
//Filiale: Henrys On The Hill;   Libro: Smokescreen;   Copie disponibili: 1
//Filiale: Henrys On The Hill;   Libro: Stranger;   Copie disponibili: 3
//Filiale: Henrys On The Hill;   Libro: Vixen 07;   Copie disponibili: 2
//Filiale: Henrys On The Hill;   Libro: Vortex;   Copie disponibili: 1
//
//Es6: Il titolo del libro meno costoso fra quelli disponibili presso la filiale 'Henrys Downtown' è:
//Titolo: Cujo, Costo: 6.65
//
//Es7: I libri che non sono disponibili presso la filiale 'Henrys Downtown' sono:
//Libro: Carrie,  Editore: Signet,  Costo: 6.75
//Libro: Database Systems,  Editore: Best and Furrow,  Costo: 54.95
//Libro: dBase Programming,  Editore: Best and Furrow,  Costo: 39.90
//Libro: Death on the Nile,  Editore: Bantam Books,  Costo: 3.95
//Libro: DOS Essentials,  Editore: Best and Furrow,  Costo: 20.50
//Libro: Dunwich Horror and Others,  Editore: Pocket Books,  Costo: 19.75
//Libro: Evil Under the Sun,  Editore: Pocket Books,  Costo: 4.45
//Libro: First Among Equals,  Editore: Pocket Books,  Costo: 3.95
//Libro: Kane and Abel,  Editore: Pocket Books,  Costo: 5.55
//Libro: Knockdown,  Editore: Pocket Books,  Costo: 4.75
//Libro: Magritte,  Editore: Signet,  Costo: 21.95
//Libro: Marcel Duchamp,  Editore: Pocket Books,  Costo: 11.25
//Libro: Night Probe,  Editore: Bantam Books,  Costo: 5.65
//Libro: Prints of the 20th Century,  Editore: Pocket Books,  Costo: 13.25
//Libro: Prodigal Daughter,  Editore: Pocket Books,  Costo: 5.45
//Libro: Risk,  Editore: Pocket Books,  Costo: 3.95
//Libro: Smokescreen,  Editore: Pocket Books,  Costo: 4.55
//Libro: Vixen 07,  Editore: Bantam Books,  Costo: 5.55
//Libro: Vortex,  Editore: Bantam Books,  Costo: 5.45

