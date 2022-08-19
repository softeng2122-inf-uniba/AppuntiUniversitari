/* Es. 1 */
ALTER TABLE LibriAutori
ADD FOREIGN KEY (Nro_Autore)
REFERENCES Autori(Nro_Autore);

/* Es. 2 */
DELETE FROM Autori
WHERE Nro_Autore = '24';

INSERT INTO Autori
VALUES ('24', '', 'Liala');

/* Es. 3 */
DROP VIEW IF EXISTS LibriPubblicati_PB;

CREATE VIEW LibriPubblicati_PB(Codice_libro, Titolo_libro, Tipo_libro) AS 
	SELECT Codice_Libro, Titolo_Libro, Tipo_Libro
	FROM Libri NATURAL JOIN Editori
	WHERE Nome_Editore = "Pocket Books";

/* Es. 4 */
SELECT * FROM LibriPubblicati_PB;

/* Es. 5 */
SELECT Nro_Autore, Cognome_Autore, Nome_Autore
FROM Autori
WHERE Nro_Autore NOT IN
	(SELECT Nro_Autore
	 FROM LibriPubblicati_PB NATURAL JOIN LibriAutori)
ORDER BY Autori.Cognome_Autore, Autori.Nome_Autore;

/* Es. 6 */
SELECT Titolo_Libro, Tipo_Libro, Prezzo_Libro
FROM Libri NATURAL JOIN Editori
WHERE Nome_Editore = "Pocket Books" 
	  AND Prezzo_Libro = 
	  (SELECT MAX(Prezzo_Libro)
	   FROM LibriPubblicati_PB JOIN Libri ON LibriPubblicati_PB.Codice_Libro = Libri.Codice_Libro);

/* Es. 7 */
SELECT Codice_Libro, Titolo_Libro, Cognome_Autore, Nome_Autore, Nro_Copie_Disponibili
FROM LibriPubblicati_PB NATURAL JOIN LibriAutori 
	 NATURAL JOIN Autori
	 NATURAL JOIN Scorte
	 NATURAL JOIN Filiali
WHERE Nro_Seq = 1 AND Nome_Filiale = "Henrys Books";

	