/* Es. 1 */
ALTER TABLE Libri
ADD FOREIGN KEY (Codice_editore)
REFERENCES Editori(Codice_editore);

/* Es. 2 */
DELETE FROM Editori
WHERE Nome_editore = 'Arcade Publishing';

/* Es. 3 */
DROP VIEW IF EXISTS LibriPubblicati_MA;

CREATE VIEW LibriPubblicati_MA(Titolo_libro, Nome_editore) AS 
	SELECT Titolo_libro, Nome_editore
	FROM Libri NATURAL JOIN Editori
	WHERE Stato_editore = 'MA';

/* Es. 4 */
SELECT * FROM LibriPubblicati_MA;

/* Es. 5 */
/* Commento Ivan: Qui si poteva usare un SELECT DISTINCT (invece di usare il GROUP BY)*/
SELECT Nro_autore, Cognome_autore, Nome_autore
FROM Autori NATURAL JOIN LibriAutori NATURAL JOIN Libri NATURAL JOIN LibriPubblicati_MA
GROUP BY Nro_autore 
ORDER BY Cognome_autore, Nome_autore;

/* Es. 6 */
/* Commento Ivan: Nella traccia chiedeva di mostrare anche gli autori senza libri (che non compaiono in LibriAutori). 
 * Bisogna usare i NATURAL LEFT JOIN per essere corretti.*/
SELECT Cognome_autore, Nome_autore, Titolo_libro, Nome_editore
FROM Autori NATURAL JOIN LibriAutori NATURAL JOIN Libri NATURAL JOIN Editori
GROUP BY Titolo_libro
ORDER BY Cognome_autore;

/* Es. 7 */
SELECT Nome_editore, Count(Codice_libro) AS Libri_pubblicati, Avg(Prezzo_libro) AS Prezzo_medio
FROM Editori NATURAL JOIN Libri
GROUP BY Nome_editore;



	