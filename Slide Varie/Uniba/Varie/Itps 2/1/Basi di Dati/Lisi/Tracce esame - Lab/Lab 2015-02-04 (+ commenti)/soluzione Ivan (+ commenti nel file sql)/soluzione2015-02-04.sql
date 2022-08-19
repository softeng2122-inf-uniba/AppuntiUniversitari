

/*Es.1: Aggiungere un vincolo di integrità referenziale fra le tabelle Scorte e Filiali.
*/
ALTER TABLE Scorte ADD FOREIGN KEY (Nro_filiale) REFERENCES Filiali(Nro_filiale);


/*Es.2: Aggiungere una tupla con valori ('5','Henrys Manhattan', 'Broadway',) alla tabella Filiali.*/
INSERT INTO Filiali VALUES ('5', 'Henrys Manhattan', 'Broadway', default);


/*Es.3: Creare una vista LibriDisponibili_HD(Titolo_libro) sui libri disponibili presso la filiale di nome 'Henrys Downtown'.*/
CREATE VIEW LibriDisponibili_HD(Titolo_libro)
 AS SELECT Titolo_libro FROM Libri NATURAL JOIN Scorte NATURAL JOIN Filiali
 WHERE Nome_filiale = 'Henrys Downtown' AND Nro_copie_disponibili >= 1;
 
 
/*Es.4: Mostrare il contenuto della vista LibriDisponibili_HD(Titolo_libro).*/
SELECT * FROM LibriDisponibili_HD;


/*Es.5: Per ciascuna filiale, indicare nome della filiale, i titoli ed il numero di copie disponibili dei libri in vendita presso la filiale, 
 * presentando le tuple in ordine alfabetico per nome e titolo.*/
SELECT Nome_filiale, Titolo_libro, Nro_copie_disponibili
 FROM Filiali NATURAL JOIN Scorte NATURAL JOIN Libri
 ORDER BY Nome_filiale, Titolo_libro;

 
/*Es.6: Trovare il titolo del libro meno costoso fra quelli disponibili presso la filiale di nome 'Henrys Downtown' 
* (N.B.: risolvere l’esercizio con interrogazione sulla vista LibriDisponibili_HD).*/

/*Versione 1, Non funge, restituisce in output il titolo della prima tupla ("shyness", che costa 7.65), unito al prezzo più basso (ovvero 6.65)*/

/*SELECT Titolo_libro, min(Prezzo_libro) AS Costo FROM LibriDisponibili_HD NATURAL JOIN Libri; */

/*Versione 2, corretta*/
SELECT Titolo_libro, Prezzo_libro AS Costo FROM Libri NATURAL JOIN LibriDisponibili_HD
 WHERE Prezzo_libro = (SELECT min(prezzo_libro) FROM Libri NATURAL JOIN LibriDisponibili_HD); 
 
 
/*Es.7: Elencare i libri, ordinati per titolo e completi di informazione su nome dell’editore e prezzo, 
* che non sono disponibili presso la filiale di nome 'Henrys Downtown' 
* (N.B.: risolvere l’esercizio con interrogazione sulla vista LibriDisponibili_HD).*/
SELECT Titolo_libro, Nome_editore, Prezzo_libro FROM Libri tutti NATURAL JOIN Editori
 WHERE NOT EXISTS (SELECT * FROM LibriDisponibili_HD hd WHERE tutti.Titolo_libro = hd.Titolo_libro)
 ORDER BY Titolo_libro;

/*Sintassi alternativa (usando NOT IN invece di NOT EXISTS)*/
SELECT Titolo_libro, Nome_editore, Prezzo_libro FROM Libri tutti NATURAL JOIN Editori
 WHERE Titolo_libro NOT IN (SELECT * FROM LibriDisponibili_HD hd WHERE tutti.Titolo_libro = hd.Titolo_libro)
 ORDER BY Titolo_libro;
