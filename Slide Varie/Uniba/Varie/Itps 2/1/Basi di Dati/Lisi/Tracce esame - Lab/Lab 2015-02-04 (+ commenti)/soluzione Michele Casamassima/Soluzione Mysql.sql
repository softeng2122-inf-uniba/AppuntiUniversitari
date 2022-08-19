/* Es. 1 */
ALTER TABLE Scorte
ADD FOREIGN KEY (Nro_filiale)
REFERENCES Filiali(Nro_filiale);

/* Es. 2 */
DELETE FROM Filiali
WHERE Nro_filiale = '5';

INSERT INTO Filiali(Nro_filiale, Nome_filiale, Sede_filiale) 
VALUES ('5', 'Henrys Manhattan', 'Broadway');

/* Es. 3 */
DROP VIEW IF EXISTS LibriDisponibili_HD;

CREATE VIEW LibriDisponibili_HD(Titolo_libro) AS 
	SELECT Titolo_libro
	FROM Libri NATURAL JOIN Scorte NATURAL JOIN Filiali
	WHERE Nome_filiale = 'Henrys Downtown';

/* Es. 4 */
SELECT * FROM LibriDisponibili_HD;

/* Es. 5 */
SELECT Nome_filiale, Titolo_libro, Count(Codice_libro) AS Nro_copie 
FROM Filiali NATURAL JOIN Scorte NATURAL JOIN Libri
GROUP BY Nome_filiale
ORDER BY Nome_filiale, Titolo_libro;

/* Es. 6 */
SELECT Titolo_libro
FROM LibriDisponibili_HD NATURAL JOIN Libri 
WHERE Prezzo_libro = (SELECT MIN(Prezzo_libro)
FROM Libri NATURAL JOIN LibriDisponibili_HD);

/* Es. 7 */
SELECT Titolo_libro, Nome_editore, Prezzo_libro
FROM Libri NATURAL JOIN Editori 
WHERE Titolo_libro NOT IN (SELECT Titolo_libro FROM LibriDisponibili_HD)
ORDER BY Titolo_libro;



	