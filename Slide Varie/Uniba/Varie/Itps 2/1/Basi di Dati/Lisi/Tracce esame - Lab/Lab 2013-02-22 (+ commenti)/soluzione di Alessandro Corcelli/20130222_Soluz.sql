USE HenrysBooksDB20130222;

/* Es. 1 */
ALTER TABLE Libri
ADD FOREIGN KEY (Codice_Editore)
REFERENCES Editori(Codice_Editore);

/* Es. 2 */
DELETE FROM Editori
WHERE Nome_Editore = "Schoken Books";

/* Es. 3 */
DROP VIEW IF EXISTS LibriPubblicati_NY;

CREATE VIEW LibriPubblicati_NY(Titolo_Libro,Nome_Editore) AS
	SELECT Titolo_Libro, Nome_Editore
	FROM Libri NATURAL JOIN Editori
	WHERE Citta_Editore = "New York";

/* Es. 4 */
SELECT * FROM LibriPubblicati_NY;

/* Es. 5 */
SELECT DISTINCT Nro_Autore, Cognome_Autore, Nome_Autore
FROM Autori NATURAL JOIN LibriAutori
			NATURAL JOIN Libri
			JOIN LibriPubblicati_NY ON Libri.Titolo_Libro = LibriPubblicati_NY.Titolo_Libro
ORDER BY Cognome_Autore, Nome_Autore;

/* Es. 6 */
SELECT Titolo_Libro, COUNT(Nro_Autore) AS "Numero Autori", Nome_Editore, Citta_Editore
FROM Libri NATURAL JOIN LibriAutori
		   NATURAL JOIN Editori
GROUP BY Titolo_Libro
ORDER BY Titolo_Libro;

/* Es. 7 */
SELECT Codice_Editore, Nome_Editore, COUNT(Codice_Libro) AS "Numero Libri", AVG(Prezzo_Libro) AS "Prezzo Medio"
FROM Editori NATURAL JOIN Libri
GROUP BY Codice_Editore;



