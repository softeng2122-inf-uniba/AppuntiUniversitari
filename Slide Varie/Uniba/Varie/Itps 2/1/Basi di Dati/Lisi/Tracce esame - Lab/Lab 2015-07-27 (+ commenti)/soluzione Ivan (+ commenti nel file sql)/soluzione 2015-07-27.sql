
/*Es1
Aggiungere un vincolo di integrità referenziale fra le tabelle Scorte e Filiali.*/
ALTER TABLE Scorte ADD FOREIGN KEY (Nro_filiale) REFERENCES Filiali(Nro_filiale);


/*Es2
Aggiungere una tupla con valori ('5','Henrys Manhattan', 'Broadway',) alla tabella Filiali.*/
INSERT INTO Filiali(Nro_filiale, Sede_filiale, Nome_filiale) VALUES ('5','Henrys Manhattan', 'Broadway');  
/*Ho specificicato quali attributi perché NON sto inserendo il numero di dipendenti, che rimane al default*/


/*Es3
Creare una vista LibriSottoScorta(Codice_libro, Nro_filiale, Nro_copie_disponibili) sui libri sotto scorta 
(ovvero con numero di copie disponibili inferiore a tre) nelle varie filiali.*/
CREATE VIEW LibriSottoScorta(Codice_libro, Nro_filiale, Nro_copie_disponibili)
 AS SELECT Codice_libro, Nro_filiale, Nro_copie_disponibili
 FROM Libri NATURAL JOIN Scorte NATURAL JOIN Filiali 
 WHERE Nro_copie_disponibili < 3;

 
/*Es4
Mostrare il contenuto della vista LibriSottoScorta definita nell’esercizio 3), presentando le tuple in ordine crescente rispetto al codice del libro.*/
SELECT * FROM LibriSottoScorta ORDER BY Codice_libro;


/*Es5
Per ciascuna filiale, indicare nome della filiale, i titoli ed il numero di copie disponibili dei libri in vendita presso la filiale, 
presentando le tuple in ordine alfabetico per nome e titolo.*/
SELECT Nome_filiale, Titolo_libro, Nro_copie_disponibili
 FROM Filiali NATURAL JOIN Scorte NATURAL JOIN Libri
 ORDER BY Nome_filiale, Titolo_libro;

 
/*Es6
Per ogni libro sotto scorta, trovare il numero totale di copie disponibili nell’intera catena 
(N.B.: risolvere l’esercizio con interrogazione sulla vista LibriSottoScorta).*/
SELECT Codice_libro, sum(Nro_copie_disponibili) AS CopieTotali
 FROM LibriSottoScorta
 GROUP BY Codice_libro;

 
/*Es7
Per ciascuna filiale, elencare i libri, ordinati per titolo e completi di informazione su nome dell’editore e prezzo, 
che non sono sotto scorta presso la filiale (N.B.: risolvere l’esercizio con interrogazione sulla vista LibriSottoScorta).*/
SELECT Nome_filiale, Titolo_libro, Nome_editore, Prezzo_libro
 FROM Filiali f NATURAL JOIN Scorte NATURAL JOIN Libri l NATURAL JOIN Editori
 WHERE (f.Nro_filiale, l.Codice_libro) NOT IN
 (SELECT Nro_filiale, Codice_libro FROM LibriSottoScorta)
 ORDER BY Titolo_libro;
 

