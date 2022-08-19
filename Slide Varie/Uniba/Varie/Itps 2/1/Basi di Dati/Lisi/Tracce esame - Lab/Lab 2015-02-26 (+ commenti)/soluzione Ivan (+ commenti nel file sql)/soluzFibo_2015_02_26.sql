

	/* Es1
	 * Aggiungere nella tabella Libri un vincolo di integrità 
	 * referenziale relativo alla tabella Editori.
	 */
	 
	/*Provato vari modi per ricordare semantica:
	 *NON accetta:
	 *-) l'attributo in Libri fuori da parentesi
	 *-) la scritta Editori.Codice_editore
	 *-) la scritta (Editori.Codice_editore)
	 */
		
	ALTER TABLE Libri ADD FOREIGN KEY (Codice_editore) REFERENCES Editori(Codice_editore);
		
	/* Es2
	 * Eliminare dalla tabella Editori la tupla relativa all’editore di nome 'Arcade Publishing'.
	 */

	/*
	 * NB: Non ricordando sintassi, ho provato in vari modi.
	 * NON accetta:
	 * -) DELETE * FROM ....
	 * -) DROP * FROM ...
	 * -) DROP FROM ...
	 */
	
	DELETE FROM Editori WHERE Nome_Editore = 'Arcade Publishing';

	/* Es3
	 * Creare una vista LibriPubblicati_MA(Titolo_libro,Nome_editore) 
	 * sui libri pubblicati da editori con sede nello stato del Massachusetts.
	 */
		
	/* Bisogna ricordarsi cenni sulla sintassi (come la keyword "AS")
	 * Da notare:
	 * 1) Usando il natural join, se trova un vincolo refenziale, fa il join senza specificare su quali attributi
	 * 2) Avevo messo CREATE VIEW (Attr1, Attr2) AS SELECT * FROM ... (invece di SELECT Attr1, Attr2 FROM ...)
	 * 3) CONTROLLARE IL FORMATO DEI DATI INSERITI NEL DB (Io cercavo WHERE Stato_Editore = 'Massachusetts', invece di 'MA')
	*/
		
	CREATE VIEW LibriPubblicati_MA(Titolo_libro, Nome_editore) AS SELECT Titolo_libro, Nome_editore FROM Libri NATURAL JOIN Editori WHERE Stato_editore = 'MA';
		
	/* Es4
	 * Mostrare il contenuto della vista LibriPubblicati_MA.
	 */
		
	SELECT * FROM LibriPubblicati_MA;

	/* Es5
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
	SELECT DISTINCT Nro_autore, Cognome_autore, Nome_autore FROM Autori
	 NATURAL JOIN LibriAutori NATURAL JOIN LibriPubblicati_MA ORDER BY Cognome_autore, Nome_autore;

	/* Es6
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
		
	SELECT Cognome_autore, Nome_autore, Titolo_libro, Nome_editore FROM Autori
	 NATURAL LEFT JOIN LibriAutori NATURAL LEFT JOIN Libri NATURAL LEFT JOIN Editori ORDER BY Cognome_autore;

	/* Es7
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
	SELECT Nome_editore, count(*) AS Num_libri, avg(Prezzo_libro) AS Prezzo_medio FROM Libri NATURAL JOIN Editori GROUP BY Codice_editore;
			