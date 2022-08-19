


/*Es.1: Aggiungere un vincolo di integrità referenziale fra le tabelle Libri ed Editori.*/
ALTER TABLE Libri ADD FOREIGN KEY (Codice_editore) REFERENCES Editori(Codice_editore);



/*Es.2: Eliminare dalla tabella Editori la tupla relativa all’editore di nome 'Rizzoli'.*/
DELETE FROM Editori WHERE Nome_editore = 'Rizzoli';



/*Es.3: Creare una vista LibriPubblicati_NY(Titolo_libro,Nome_editore) 
sui libri pubblicati da case editrici con sede nello Stato di New York (indicato con la sigla 'NY').*/
CREATE VIEW LibriPubblicati_NY(Titolo_libro, Nome_editore)
 AS SELECT Titolo_libro, Nome_editore FROM Libri NATURAL JOIN Editori WHERE Stato_editore = 'NY';
 
 
 
/*Es.4: Mostrare il contenuto della vista LibriPubblicati_NY, raggruppando i titoli rispetto al nome dell’editore.*/
SELECT * FROM LibriPubblicati_NY; /*Ricordare: In questi esercizi di stampa view, facili in sql, l'unica pseudo-difficoltà è la stampa in java*/
 
 
 
/*Es.5: Elencare gli autori, ordinati per cognome e nome, che hanno pubblicato almeno un libro con editori dello Stato di New York 
 (N.B.: risolvere l’esercizio con interrogazione sulla vista LibriPubblicati_NY precedentemente creata).*/
 
/*NB: All'es.5 con o senza view viene lo stesso numero di join.
La versione senza view è:
SELECT Cognome_autore, Nome_autore FROM Autori NATURAL JOIN LibriAutori NATURAL JOIN Libri NATURAL JOIN Editori
  WHERE Stato_editore = 'NY' ORDER BY Cognome_autore, Nome_autore;
Però (anche se è inutile semanticamente parlando) nella traccia dice di usare la view, quindi si fa con la view.
è fatto apposta per confondere chi non sa come fare nel caso manchino nella view alcuni degli attributi necessari per la query.*/ 
SELECT Cognome_autore, Nome_autore FROM Autori NATURAL JOIN LibriAutori NATURAL JOIN Libri NATURAL JOIN LibriPubblicati_NY
 ORDER BY Cognome_autore, Nome_autore;
 
 

/*Es.6: Per ciascun libro, indicare il titolo del libro, il numero di autori, il nome e la città dell’editore, 
presentando le tuple in ordine alfabetico per titolo.*/

/*Prima ho provato come usare il count in questo caso. 
 Dopo vari tentativi, ho trovato: SELECT *, count(Nro_autore) FROM LibriAutori GROUP BY Codice_libro;
 Capito il funzionamento, ho scritto la query principale.
*/
SELECT Titolo_libro, count(Nro_autore) AS Num_autori, Nome_editore, Citta_editore
 FROM LibriAutori NATURAL JOIN Libri NATURAL JOIN Editori GROUP BY Codice_libro;

 
 
/*Es.7: Per ciascun editore, indicare il numero ed il prezzo medio dei libri da esso pubblicati.*/
/*Qui avrei potuto mettere anche count(*).
  Semplicemente le funzioni come count, avg, eccetera, operano:
  - o su tutta la table (con in output una sola tupla)
  - o su ogni gruppo (in caso di group by), con in output una tupla per ogni gruppo.
  Anche prima al posto di count(Nro_autore), usando count(*), funziona [testato!!!].
  Ho scritto per chiarezza il nome dell'attributo.
  Va scritto PER forza in caso di valori che possono essere NULL, o altri casi simili.*/
SELECT Codice_editore, Nome_editore, count(Codice_editore), avg(Prezzo_libro)
 FROM Editori NATURAL JOIN Libri GROUP BY Codice_editore;

