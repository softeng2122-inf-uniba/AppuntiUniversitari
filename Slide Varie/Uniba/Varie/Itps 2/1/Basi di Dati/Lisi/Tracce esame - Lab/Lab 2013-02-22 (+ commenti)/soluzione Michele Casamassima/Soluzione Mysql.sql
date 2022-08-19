/* Es. 1 */ 
ALTER TABLE Libri
ADD FOREIGN KEY (Codice_editore)
REFERENCES Editori (Codice_editore);

/* Es. 2 */
DELETE FROM Editori 
WHERE Nome_editore = 'Schoken Books';

/* Es. 3 */
DROP VIEW IF EXISTS LibriPubblicati_NY;

CREATE VIEW LibriPubblicati_NY(Titolo_libro, Nome_editore) AS
SELECT Titolo_libro, Nome_editore 
FROM Libri NATURAL JOIN Editori
WHERE Citta_editore = 'New York';

/* Es. 4 */
SELECT * FROM LibriPubblicati_NY;

/* Es. 5 */
SELECT Nro_autore, Cognome_autore, Nome_autore
FROM Autori NATURAL JOIN LibriAutori NATURAL JOIN Libri NATURAL JOIN LibriPubblicati_NY
GROUP BY Nro_autore
ORDER BY Cognome_autore, Nome_autore;

/* Es. 6 */
SELECT Titolo_libro, Count(Nro_autore) AS Nro_autori, Nome_editore, Citta_editore
FROM Autori NATURAL JOIN LibriAutori NATURAL JOIN Libri NATURAL JOIN Editori 
GROUP BY Titolo_libro
ORDER BY Titolo_libro;

/* Es. 7 */
SELECT Nome_editore, Count(Codice_libro) AS Nro_libri, Avg(Prezzo_libro) AS Prezzo_medio
FROM Libri NATURAL JOIN Editori
GROUP BY Codice_editore;