
/*1) [punti 3] Aggiungere un vincolo di integrità referenziale fra le tabelle Scorte e Filiali.*/
ALTER TABLE Scorte ADD FOREIGN KEY (Nro_filiale) REFERENCES Filiali(Nro_filiale);
/*Oppure, meglio (spesso lo scordo):*/
ALTER TABLE Scorte ADD FOREIGN KEY (Nro_filiale) REFERENCES Filiali(Nro_filiale) ON DELETE CASCADE ON UPDATE CASCADE;


/*2) [punti 3] Aggiungere una tupla con valori ('5','Henrys Manhattan', 'Broadway',) alla tabella Filiali.*/
INSERT INTO Filiali(Nro_filiale, Sede_filiale, Nome_filiale) VALUES ('5','Henrys Manhattan', 'Broadway');


/*3) [punti 3] Creare una vista LibriInVendita_HB(Titolo_libro) sui libri in vendita presso la filiale di nome 'Henrys Brentwood'.*/
CREATE VIEW LibriInVendita_HB(Titolo_libro)
 AS SELECT Titolo_libro
 FROM Libri NATURAL JOIN Scorte NATURAL JOIN Filiali
 WHERE Nome_filiale = 'Henrys Brentwood';


/*4) [punti 3] Mostrare il contenuto della vista LibriInVendita_HB(Titolo_libro).*/
SELECT * FROM LibriInVendita_HB;


/*5) [punti 6] Per ciascuna filiale, indicare nome della filiale, i titoli ed il numero di copie disponibili dei libri in vendita presso la filiale, 
presentando le tuple in ordine alfabetico per nome e titolo.*/
SELECT Nome_filiale, Titolo_libro, Nro_copie_disponibili
 FROM Filiali NATURAL JOIN Scorte NATURAL JOIN Libri
 ORDER BY Nome_filiale, Titolo_libro;


/*6) [punti 6] Trovare il titolo del libro più economico fra quelli in vendita presso la filiale di nome 'Henrys Brentwood' 
(N.B.: risolvere l’esercizio con interrogazione sulla vista LibriInVendita_HB).*/

/*VERSIONE GIUSTA 
In LibriHB JOIN Libri ci sono varie tuple. La prima tupla è [titolo: Smokescreen, prezzo: 4.55], poi ..., poi [titolo: Evil under, prezzo: 4.45].
Qui esce, correttamente, Evil under 
*/
SELECT Titolo_libro FROM LibriInVendita_HB NATURAL JOIN Libri
 WHERE Prezzo_libro = (SELECT min(Prezzo_libro) FROM LibriInVendita_HB NATURAL JOIN Libri);

/*Se vuoi mostrare anche il prezzo:*/
SELECT Titolo_libro, Prezzo_libro FROM LibriInVendita_HB NATURAL JOIN Libri
 WHERE Prezzo_libro = (SELECT min(Prezzo_libro) FROM LibriInVendita_HB NATURAL JOIN Libri);
 
/*VERSIONE SBAGLIATA (attenzione a questo errore!!!). 

SELECT Titolo_libro, min(Prezzo_libro) AS Costo
 FROM LibriInVendita_HB NATURAL JOIN Libri;

Esce il titolo della prima tupla del join (ovvero Smokescreen), unito al prezzo minimo (ovvero 4.45).
Ma il prezzo NON è 4.45. 
L'errore nasce dal fatto che il select NON è omogeneo. (ne parla a pag. 58 delle slide).
In un select ci devono essere o solo attributi, o solo funzioni.
Possono esserci coppie [attributo, funzione] solo se c'è un group by.

*/

  
/*7) [punti 6] Elencare i libri, ordinati per titolo e completi di informazione su nome dell’editore e prezzo, 
che non sono in vendita presso la filiale di nome 'Henrys Brentwood' 
(N.B.: risolvere l’esercizio con interrogazione sulla vista LibriInVendita_HB).*/
SELECT Titolo_libro, Nome_editore, Prezzo_libro
 FROM Libri NATURAL JOIN Editori
 WHERE Titolo_libro NOT IN
 (SELECT Titolo_libro FROM LibriInVendita_HB);



