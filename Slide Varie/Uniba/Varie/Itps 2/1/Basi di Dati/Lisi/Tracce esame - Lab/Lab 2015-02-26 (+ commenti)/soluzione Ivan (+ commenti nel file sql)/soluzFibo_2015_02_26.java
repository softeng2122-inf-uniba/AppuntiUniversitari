/*

Prova di Laboratorio di PROGETTAZIONE DI BASI DI DATI
C.d.S. in Informatica e Tecnologie per la Produzione del Software (3 anni)
Docente: dott.ssa Francesca A. Lisi

26 Febbraio 2015

-------------------------------------
Cognome e Nome	: Lamparelli Ivan
Matricola	: 
-------------------------------------

*/


package application;

import java.sql.*;

public class soluzFibo_2015_02_26 {

	public static void main(String[] args) {
		
		
		// sezione dichiarazione variabili locali

		/* 
		 * NB: ti dice che vuole QUI la dichiarazione delle variabili (invece che in mezzo al codice)
		 */
		int ok, num;
				
		Connection connessione = null;

		// es. 1: creazione stringa contenente comando SQL

		
		/*
		 * Aggiungere nella tabella Libri un vincolo di integrità 
		 * referenziale relativo alla tabella Editori.
		 */
		
		/*Test semantica comando*/
		//String stringa1 = "ALTER TABLE Libri ADD Prova CHAR(1);";
		
		/*Provato vari modi per ricordare semantica:
		 *NON accetta:
		 *-) l'attributo in Libri fuori da parentesi
		 *-) la scritta Editori.Codice_editore
		 *-) la scritta (Editori.Codice_editore)*/
		String stringa1 = "ALTER TABLE Libri ADD FOREIGN KEY (Codice_editore) "
				+ "REFERENCES Editori(Codice_editore);";
		
		// es. 2: creazione stringa contenente comando SQL
		
		/*
		 * Eliminare dalla tabella Editori la tupla relativa all’editore di nome 'Arcade Publishing'.
		 */
		
		/*
		 * NB: Non ricordando sintassi, ho provato in vari modi.
		 * NON accetta:
		 * -) DELETE * FROM ....
		 * -) DROP * FROM ...
		 * -) DROP FROM ...
		 */
		String stringa2 = "DELETE FROM Editori WHERE Nome_Editore = 'Arcade Publishing';";

		// es. 3: creazione stringa contenente comando SQL
		
		/*
		 * Creare una vista LibriPubblicati_MA(Titolo_libro,Nome_editore) 
		 * sui libri pubblicati da editori con sede nello stato del Massachusetts.
		 */
		
		/*
		 * Bisogna ricordarsi cenni sulla sintassi (come la keyword "AS")
		 * Da notare:
		 * 1) Usando il natural join, se trova un vincolo refenziale, fa il join senza specificare su quali attributi
		 * 2) Avevo messo CREATE VIEW (Attr1, Attr2) AS SELECT * FROM ... (invece di SELECT Attr1, Attr2 FROM ...)
		 * 3) CONTROLLARE IL FORMATO DEI DATI INSERITI NEL DB (Io cercavo WHERE Stato_Editore = 'Massachusetts', invece di 'MA')
		 */
		String stringa3 = "CREATE VIEW LibriPubblicati_MA(Titolo_libro, Nome_editore) "
				+ "AS SELECT Titolo_libro, Nome_editore FROM Libri NATURAL JOIN Editori "
				+ "WHERE Stato_editore = 'MA';";
		
		// es. 4: creazione stringa contenente comando SQL
		
		/*
		 * Mostrare il contenuto della vista LibriPubblicati_MA.
		 */
		
		/*
		 * NB: a questo tipo di query, che fornisce X tuple, segue un while per stamparle tutte
		 * (Il while va messo più giù, nel blocco try, dove si esegue la query)
		 */
		
		String stringa4 = "SELECT * FROM LibriPubblicati_MA;";

		// es. 5: creazione stringa contenente comando SQL
		
		/*
		 * Elencare gli autori, ordinati per cognome e nome, 
		 * che hanno pubblicato almeno un libro mediante editori con sede nello stato del Massachusetts 
		 * (N.B.: usare la vista LibriPubblicati_MA precedentemente creata).
		 */
		
		/*
		 * Per provare se effettivamente, a parità di cognome, funzionasse l'ordinamento per nome:
		 * 1) Ho lanciato la query risultato di questo esercizio, e scelto un autore: 'Clarke', 'Arthur')
		 * 2) Ho inserito due varianti con nome minore e maggiore
		 *       INSERT INTO Autori VALUES (80, 'Clarke', 'Arprovaxxx'), (81, 'Clarke', 'Arxxprova');
		 * 3) Ho scelto un libro presente nella view (il libro 'Database Systems');
		 * 4) Ho controllato il codice di questo libro (5790)
		 * 5) Ho inserito i due attori fittizi come autori del 5790
		 *       (altrimenti non comparivano fra gli autori del Massachusetts)
		 *       INSERT INTO LibriAutori VALUES (5790, 80, 07), (5790, 81, 08);
		 * 6) Ho rilanciato la query, per vedere se ordinava per nome a parità di cognome
		 */
		
		/*
		 * Notare l'uso di DISTINCT (altrimenti mostrava gli stessi autori più volte per ogni libro scritto)
		 */
		String stringa5 = "SELECT DISTINCT Nro_autore, Cognome_autore, Nome_autore "
				+ "FROM Autori NATURAL JOIN LibriAutori NATURAL JOIN LibriPubblicati_MA "
				+ "ORDER BY Cognome_autore, Nome_autore;";

		// es. 6: creazione stringa contenente comando SQL
		
		/*
		 * Per ciascun autore (indicato mediante cognome e nome), 
		 * elencare i libri pubblicati riportandone il titolo e l’editore 
		 * (indicato mediante il nome), 
		 * presentando le tuple in ordine alfabetico per cognome 
		 * ed evidenziando anche i casi di autori per i quali non vi sono libri.
		 */
		
		/*
		 * Bisogna usare un left join per gli autori senza libri.
		 * Per provare la sintassi del left join, ho fatto:
		 * 1) Il numero di un autore che ha pubblicato libri (es. "13", Ovvero "Williams")
		 * 2) Join fra Autori e LibriAutori, per vedere quante tuple vengono (qui 32)
		 * 3) DELETE FROM LibriAutori WHERE Nro_autore = 13;
		 * 4) Di nuovo join fra Autori e LibriAutori (ora vengono 31 tuple)
		 * 5) Faccio left join:
		 *      SELECT Cognome_autore, Codice_libro FROM Autori NATURAL LEFT JOIN LibriAutori
		 *      (risultato, di nuovo 32 tuple, fra cui "Williams" e NULL)
		 * ---------------
		 * NB: Ho provato varie sintassi, fra cui LEFT NATURAL JOIN,che non vanno,
		 * mentre NATURAL LEFT JOIN funziona
		 * ---------------
		 * Dopo aver provato il left join su due tabelle, l'ho fatto su tutte.
		 * Anche nel join su tutte, facevo il left join solo fra Autori e LibAut, il resto join normali.
		 * Di nuovo si perdeva un dato, e venivano 31 tuple.
		 * Bisogna mettere SEMPRE il "left", non solo fra Autori e LibAut.
		 * Perché in caso di più join, li fa uno dopo l'altro, e bisogna sempre dire di conservare tuple con NULL.
		 */
		
		String stringa6 = "SELECT Cognome_autore, Nome_autore, Titolo_libro, Nome_editore "
				+ "FROM Autori NATURAL LEFT JOIN LibriAutori NATURAL LEFT JOIN Libri "
				+ "NATURAL LEFT JOIN Editori ORDER BY Cognome_autore;";

		// es. 7: creazione stringa contenente comando SQL
		
		/*
		 * Per ciascun editore (indicato mediante il nome), 
		 * indicare il numero di libri da esso pubblicati ed il loro prezzo medio.
		 */
		
		/*
		 * Ho provato singolarmente le coppie [Nome_ed, avg(prezzo)] e [Nome_ed, count(*)].
		 * Poi ho fatto la query finale. 
		 * L'ho dovuta fare mille volte perché c'erano problemi di sintassi con le funzioni.
		 * -----
		 * Notare l'uso dei rename!!!
		 */
		String stringa7 = "SELECT Nome_editore, count(*) AS Num_libri, "
				+ "avg(Prezzo_libro) AS Prezzo_medio "
				+ "FROM Libri NATURAL JOIN Editori GROUP BY Codice_editore;";
			
		try {
			
			/*
			 * QUI dava errore perché non avevo inserito JDBC fra le librerie
			 */
			
			// caricamento del driver
			new com.mysql.jdbc.Driver();
			
			/*
			 * Qui NON dà la stringa da mettere all'interno di getConnection
			 * Bisogna ricordarsi la sintassi
			 */
			
			//creazione di una connessione al database con credenziali di accesso appropriate
			connessione = DriverManager.getConnection("jdbc:mysql://localhost/HenrysBooksDB20150226", "root", "");

			// es. 1: esecuzione comando SQL
			
			Statement istruzione1 = connessione.createStatement();
			
			/*
			 * NON si può chiudere e riaprire da qui il database.
			 * Bisogna farlo ri-lanciando ogni volta i comandi sql dal prompt.
			 * */
//			istruzione1.execute("DROP DATABASE IF EXISTS HenrysBooksDB20150226;");
//			istruzione1.execute("CREATE DATABASE HenrysBooksDB20150226;");
//			istruzione1.execute("USE HenrysBooksDB20150226;");
			
			/*
			 *A che cazzo serve questa variabile "ok"
			 *NB: Come output in ok riceve il numero di tuple affette (tutte quelle della table Libri)
			 *E la println? Devo dire tipo "ha funzionato"?
			 */
			
			ok = istruzione1.executeUpdate(stringa1);
			
			System.out.println("Es1: Ho aggiunto il vincolo dalla tabella Libri verso Editori. Ho affetto " + ok + " tuple");

			// es. 2: esecuzione comando SQL
			Statement istruzione2 = connessione.createStatement();
			num = istruzione2.executeUpdate(stringa2);
			
			System.out.println("\nEs2: Il numero di tuple eliminate dalla tabella Editori è: " + num + " ");
			
			
			// es. 3: esecuzione comando SQL
			Statement istruzione3 = connessione.createStatement();
			istruzione3.execute(stringa3);

			System.out.println("\nEs3: Ho creato una view sui libri con editori del Massachusetts.");

			
			// es. 4: esecuzione comando SQL
			Statement istruzione4 = connessione.createStatement();
			ResultSet risultato4 = istruzione4.executeQuery(stringa4);
						
			System.out.println("\nEs4: Il contenuto della vista LibriPubblicati_MA è:");
			while (risultato4.next()) {
				/*
				 * STAMPO LE VARIE TUPLE DELLA VISTA
				 * Attenzione ad usare getString o getInt (in base a tipo nel DB, se CHAR o INT o DECIMAL)
				 */

				/*
				 * Si può usare sia getString(attrIndex), sia getString(attrName).
				 * Qui li ho messi entrambi come esempio.
				 * (Il nome del metodo è lo stesso, c'è override con parametri diversi).
				 * Possibili errori:
				 * 1) sbagliare con l'autocomplete e digitare getInt (che viene suggerito prima di getString)
				 * 2) in caso di getString(attrIndex), confondersi con l'indice attributo (parte a contare da 1, non da 0)
				 * 3) in caso di getString(attrName), confondersi con i nomi degli attributi (mettevo "Codice_editore" invece di "Nome_editore")
				 */

//				System.out.print("risultato mostrato estraendo gli attributi per numero: ");
//				System.out.println(risultato4.getString(1) + " ; " + risultato4.getString(2));
//				System.out.print("risultato mostrato estraendo gli attributi per nome: ");
				System.out.println(risultato4.getString("Titolo_libro") + " ; " + risultato4.getString("Nome_editore"));
//				System.out.println("-----");
			}
			
			// es. 5: esecuzione comando SQL
			Statement istruzione5 = connessione.createStatement();
			ResultSet risultato5 = istruzione5.executeQuery(stringa5);
			
			System.out.println("\nEs5: Gli autori di libri pubblicati da editori dello stato del Massachusetts sono:");
			while (risultato5.next()) {
				System.out.println(risultato5.getString(1) + ", " + risultato5.getString(2) + ", " + risultato5.getString(3));
			}
			
			// es. 6: esecuzione comando SQL
			Statement istruzione6 = connessione.createStatement();
			ResultSet risultato6 = istruzione6.executeQuery(stringa6);
			
			System.out.println("\nEs6: Gli autori in ordine alfabetico per cognome, anche senza libri, sono:");
			while (risultato6.next()) {
				System.out.println("Cognome: " + risultato6.getString(1) + ", Nome: " + risultato6.getString(2));
				System.out.println("Libro: " + risultato6.getString(3) + ", Editore: " + risultato6.getString(4));
				System.out.println("-----");
			}
			
			// es. 7: esecuzione comando SQL
			Statement istruzione7 = connessione.createStatement();
			ResultSet risultato7 = istruzione7.executeQuery(stringa7);
			
			System.out.println("\nEs7: Il numero ed il prezzo medio dei libri pubblicati da ciascun editore:");
			while (risultato7.next()) {
				System.out.print("Nome editore: " + risultato7.getString(1));
				System.out.print(", Numero libri: " + risultato7.getString(2));
				System.out.println(", Prezzo medio: " + risultato7.getString(3));
				System.out.println("-----");
			}
		} 
		catch (SQLException e) {
			e.printStackTrace();

		}

	}
	
// OUTPUT DELLA CONSOLE:
	
//	Es1: Ho aggiunto il vincolo dalla tabella Libri verso Editori. Ho affetto 29 tuple
//
//	Es2: Il numero di tuple eliminate dalla tabella Editori è: 1 
//
//	Es3: Ho creato una view sui libri con editori del Massachusetts.
//
//	Es4: Il contenuto della vista LibriPubblicati_MA è:
//	Database Systems ; Best and Furrow
//	A Guide to SQL ; Best and Furrow
//	DOS Essentials ; Best and Furrow
//	dBase Programming ; Best and Furrow
//
//	Es5: Gli autori di libri pubblicati da editori dello stato del Massachusetts sono:
//	08, Adamski, Joseph
//	01, Archer, Jeffrey
//	18, Camus, Albert
//	19, Castleman, Riva
//	02, Christie, Agatha
//	03, Clarke, Arthur C.
//	05, Cussler, Clive
//	04, Francis, Dick
//	21, Gimferrer, Pere
//	10, Harmon, Willis
//	14, Kafka, Franz
//	06, King, Stephen
//	16, Lovecraft, H.P.
//	15, Novalis, 
//	12, Owen, Barbara
//	17, Paz, Octavio
//	07, Pratt, Philip
//	11, Rheingold, Howard
//	22, Southworth, Rod
//	13, Williams, Peter
//	23, Wray, Robert
//	20, Zinbardo, Philip
//
//	Es6: Gli autori in ordine alfabetico per cognome, anche senza libri, sono:
//	Cognome: Adamski, Nome: Joseph
//	Libro: Database Systems, Editore: Best and Furrow
//	-----
//	Cognome: Archer, Nome: Jeffrey
//	Libro: Kane and Abel, Editore: Pocket Books
//	-----
//	Cognome: Archer, Nome: Jeffrey
//	Libro: Prodigal Daughter, Editore: Pocket Books
//	-----
//	Cognome: Archer, Nome: Jeffrey
//	Libro: First Among Equals, Editore: Pocket Books
//	-----
//	Cognome: Camus, Nome: Albert
//	Libro: Stranger, Editore: Bantam Books
//	-----
//	Cognome: Castleman, Nome: Riva
//	Libro: Prints of the 20th Century, Editore: Pocket Books
//	-----
//	Cognome: Christie, Nome: Agatha
//	Libro: Death on the Nile, Editore: Bantam Books
//	-----
//	Cognome: Christie, Nome: Agatha
//	Libro: Evil Under the Sun, Editore: Pocket Books
//	-----
//	Cognome: Clarke, Nome: Arthur C.
//	Libro: Ghost from the Grand Banks, Editore: Bantam Books
//	-----
//	Cognome: Cussler, Nome: Clive
//	Libro: Vortex, Editore: Bantam Books
//	-----
//	Cognome: Cussler, Nome: Clive
//	Libro: Night Probe, Editore: Bantam Books
//	-----
//	Cognome: Francis, Nome: Dick
//	Libro: Risk, Editore: Pocket Books
//	-----
//	Cognome: Francis, Nome: Dick
//	Libro: Smokescreen, Editore: Pocket Books
//	-----
//	Cognome: Francis, Nome: Dick
//	Libro: Knockdown, Editore: Pocket Books
//	-----
//	Cognome: Gimferrer, Nome: Pere
//	Libro: Magritte, Editore: Signet
//	-----
//	Cognome: Harmon, Nome: Willis
//	Libro: Higher Creativity, Editore: Pocket Books
//	-----
//	Cognome: Kafka, Nome: Franz
//	Libro: Castle, Editore: Bantam Books
//	-----
//	Cognome: Kafka, Nome: Franz
//	Libro: Amerika, Editore: Bantam Books
//	-----
//	Cognome: King, Nome: Stephen
//	Libro: Cujo, Editore: Signet
//	-----
//	Cognome: King, Nome: Stephen
//	Libro: Carrie, Editore: Signet
//	-----
//	Cognome: Lovecraft, Nome: H.P.
//	Libro: Dunwich Horror and Others, Editore: Pocket Books
//	-----
//	Cognome: Novalis, Nome: 
//	Libro: Hymns to the Night, Editore: Bantam Books
//	-----
//	Cognome: Owen, Nome: Barbara
//	Libro: Organ, Editore: Signet
//	-----
//	Cognome: Paz, Nome: Octavio
//	Libro: Marcel Duchamp, Editore: Pocket Books
//	-----
//	Cognome: Pratt, Nome: Philip
//	Libro: Database Systems, Editore: Best and Furrow
//	-----
//	Cognome: Pratt, Nome: Philip
//	Libro: A Guide to SQL, Editore: Best and Furrow
//	-----
//	Cognome: Pratt, Nome: Philip
//	Libro: dBase Programming, Editore: Best and Furrow
//	-----
//	Cognome: Rheingold, Nome: Howard
//	Libro: Higher Creativity, Editore: Pocket Books
//	-----
//	Cognome: Southworth, Nome: Rod
//	Libro: DOS Essentials, Editore: Best and Furrow
//	-----
//	Cognome: Williams, Nome: Peter
//	Libro: Organ, Editore: Signet
//	-----
//	Cognome: Wray, Nome: Robert
//	Libro: dBase Programming, Editore: Best and Furrow
//	-----
//	Cognome: Zinbardo, Nome: Philip
//	Libro: Shyness, Editore: Bantam Books
//	-----
//
//	Es7: Il numero ed il prezzo medio dei libri pubblicati da ciascun editore:
//	Nome editore: Bantam Books, Numero libri: 10, Prezzo medio: 8.680000
//	-----
//	Nome editore: Best and Furrow, Numero libri: 4, Prezzo medio: 34.825000
//	-----
//	Nome editore: Pocket Books, Numero libri: 11, Prezzo medio: 7.877273
//	-----
//	Nome editore: Signet, Numero libri: 4, Prezzo medio: 13.075000
//	-----

	
	
	
}
