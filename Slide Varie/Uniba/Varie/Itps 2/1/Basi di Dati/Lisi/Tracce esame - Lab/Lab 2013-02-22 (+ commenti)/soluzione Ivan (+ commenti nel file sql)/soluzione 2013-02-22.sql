
/*1) [punti 3] Aggiungere un vincolo di integrità referenziale fra le tabelle Libri ed Editori.*/
ALTER TABLE Libri ADD FOREIGN KEY (Codice_editore) REFERENCES Editori(Codice_editore)
 ON DELETE CASCADE ON UPDATE CASCADE;


/*2) [punti 3] Eliminare dalla tabella Editori la tupla relativa all’editore di nome 'Schoken Books'.*/
DELETE FROM Editori WHERE Codice_editore = 'SB';
/*Nota bene: non c'è nessun libro che ha come codice editore 'SB' (lo ha fatto apposta).
  Altrimenti (se ad esempio voglio cancellare l'editore 'SI'): 
  - se c'è ON DELETE CASCADE: cancella anche alcune tuple da Libri.
  - se non c'è il cascade: dà errore quando tenti di cancellare da Editori*/
  
  
/*3) [punti 3] Creare una vista LibriPubblicati_NY(Titolo_libro,Nome_editore) sui libri pubblicati da case editrici con sede nella città di New York.*/
CREATE VIEW LibriPubblicati_NY(Titolo_libro,Nome_editore)
 AS SELECT Titolo_libro, Nome_editore FROM Libri NATURAL JOIN Editori
 WHERE Citta_editore = 'New York';
/*Attenzione, c'è Citta = 'New York', e Stato = 'NY' (è fatto apposta per confondere)*/
 

/*4) [punti 3] Mostrare il contenuto della vista LibriPubblicati_NY.*/
SELECT * FROM LibriPubblicati_NY;


/*5) [punti 6] Elencare gli autori, ordinati per cognome e nome, che hanno pubblicato almeno un libro con editori di New York 
(N.B.: risolvere l’esercizio con interrogazione sulla vista LibriPubblicati_NY precedentemente creata).*/
SELECT Cognome_autore, Nome_autore 
 FROM Autori NATURAL JOIN LibriAutori NATURAL JOIN Libri NATURAL JOIN LibriPubblicati_NY ORDER BY Cognome_autore, Nome_autore;
/*Qui ha poco senso usare la view, si risparmia poco codice.
Si poteva usare un where:
[...] NATURAL JOIN Libri NATURAL JOIN Editori WHERE Citta_editore = 'New York' [...]

Però devi fare come chiede nella traccia, con la view...*/
 

/*6) [punti 6] Per ciascun libro, indicare il titolo del libro, il numero di autori, il nome e la città dell’editore, 
presentando le tuple in ordine alfabetico per titolo.*/
SELECT Titolo_libro, count(nro_autore) AS NumAutori, Nome_editore, Citta_editore
 FROM Libri NATURAL JOIN LibriAutori NATURAL JOIN Editori
 GROUP BY Codice_libro
 ORDER BY Titolo_libro;

 
/*7) [punti 6] Per ciascun editore, indicare il numero ed il prezzo medio dei libri da esso pubblicati.*/
SELECT Nome_editore, count(Codice_editore) AS NumLibri, avg(Prezzo_libro) AS CostoMedio
 FROM Libri NATURAL JOIN Editori
 GROUP BY Codice_editore;


