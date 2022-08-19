/* Es.1 */
ALTER TABLE LibriAutori
ADD FOREIGN KEY(Nro_autore)
REFERENCES Autori(Nro_autore);

/* Es. 2 */
DELETE FROM Autori
WHERE Nro_autore = '24';

INSERT INTO Autori (Nro_autore, Cognome_autore, Nome_autore)
VALUES ('24','','Liala');

/* Es. 3 */
DROP VIEW IF EXISTS LibriPubblicati_PB;

CREATE VIEW LibriPubblicati_PB(Codice_libro, Titolo_libro, Tipo_libro) AS
SELECT Codice_libro, Titolo_libro, Tipo_libro
FROM Libri NATURAL JOIN Editori 
WHERE Nome_editore = 'Pocket Books';

/* Es. 4 */
SELECT * FROM LibriPubblicati_PB;

/* Es. 5 */
SELECT Nro_autore, Cognome_autore, Nome_autore
FROM Autori NATURAL JOIN LibriAutori 
WHERE Codice_libro NOT IN (Select Codice_libro FROM LibriPubblicati_PB)
ORDER BY Cognome_autore, Nome_autore;

/* Es. 6 */
SELECT Titolo_libro, Tipo_libro
FROM Libri NATURAL JOIN LibriPubblicati_PB
WHERE Prezzo_libro = (SELECT MAX(Prezzo_libro)
FROM Libri NATURAL JOIN LibriPubblicati_PB);

/* Es. 7 */
SELECT Cognome_autore, Nome_autore, Nro_copie_disponibili
FROM LibriPubblicati_PB NATURAL JOIN LibriAutori NATURAL JOIN Autori NATURAL JOIN Scorte NATURAL JOIN Filiali
WHERE Nro_Seq = 1 AND Nome_Filiale = 'Henrys Books';