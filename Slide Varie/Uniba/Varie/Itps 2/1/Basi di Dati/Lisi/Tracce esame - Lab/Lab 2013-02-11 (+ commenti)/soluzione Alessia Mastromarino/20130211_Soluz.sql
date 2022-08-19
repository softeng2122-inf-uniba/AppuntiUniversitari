/* Es. 1 */
ALTER TABLE Scorte
ADD FOREIGN KEY (Nro_Filiale)
REFERENCES Filiali(Nro_filiale);

/* Es. 2 */
DELETE FROM Filiali
WHERE Nro_Filiale = '5';

INSERT INTO Filiali (Nro_filiale, Nome_filiale, Sede_filiale)
VALUES ('5','Henrys Manhattan','Broadway');

/* Es. 3 */
DROP VIEW IF EXISTS LibriInVendita_HB;

CREATE VIEW LibriInVendita_HB(Titolo_libro) AS 
	SELECT Titolo_libro
	FROM Libri NATURAL JOIN Scorte NATURAL JOIN Filiali
	WHERE Nome_Filiale = "Henrys Brentwood";

/* Es. 4 */
SELECT * FROM LibriInVendita_HB;

/* Es. 5 */
SELECT Nome_filiale, Titolo_libro, Nro_copie_disponibili 
FROM Filiali NATURAL JOIN scorte NATURAL JOIN libri 
ORDER BY Nome_filiale, Titolo_libro;

/* Es. 6 */
SELECT Titolo_libro
FROM libri NATURAL JOIN LibriInVendita_HB
WHERE prezzo_libro = (SELECT MIN(Prezzo_libro)
					  FROM Libri NATURAL JOIN LibriInVendita_HB);

/* Es. 7 */
SELECT Codice_libro, Titolo_libro, Tipo_libro, Prezzo_libro, Codice_editore, Nome_editore
FROM Libri NATURAL JOIN Editori
WHERE titolo_libro NOT IN
				  (SELECT titolo_libro
				   FROM LibriInVendita_HB);

	