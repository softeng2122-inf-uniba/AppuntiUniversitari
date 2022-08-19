
/*Es1
Aggiungere un opportuno vincolo di integrità referenziale nella tabella LibriAutori.*/
ALTER TABLE LibriAutori ADD FOREIGN KEY (Codice_libro) REFERENCES Libri(Codice_libro);


/*Es2
Aggiungere una tupla alla tabella Autori con valori ('24','','Liala').*/
INSERT INTO Autori VALUES ('24', '', 'Liala');


/*Es3
Creare una vista LibriPubblicati_PB(Codice_libro,Titolo_libro,Tipo_libro) 
sui libri pubblicati dall’editore di nome 'Pocket Books'.*/
CREATE VIEW LibriPubblicati_PB(Codice_libro, Titolo_libro, Tipo_libro)
 AS SELECT Codice_libro, Titolo_libro, Tipo_libro
 FROM Libri NATURAL JOIN Editori WHERE Nome_editore = 'Pocket Books';


/*Es4
Mostrare il contenuto della vista LibriPubblicati_PB.*/
SELECT * FROM LibriPubblicati_PB;


/*Es5
Trovare gli autori che non pubblicano libri con l’editore di nome 'Pocket Books', elencandoli ordinati per cognome e nome 
(N.B.: risolvere l’esercizio mediante interrogazione sulla vista LibriPubblicati_PB).*/

SELECT * FROM Autori WHERE (Nro_autore, Cognome_autore, Nome_autore) NOT IN
 (SELECT Nro_autore, Cognome_autore, Nome_autore FROM Autori NATURAL JOIN LibriAutori NATURAL JOIN LibriPubblicati_PB)
 ORDER BY Cognome_autore, Nome_autore;

/*
BOZZA di ragionamento col NOT EXISTS (non funziona, esce empty set):
SELECT * FROM Autori NATURAL JOIN LibriAutori NATURAL JOIN Libri
 WHERE NOT EXISTS (SELECT * FROM Autori NATURAL JOIN LibriAutori NATURAL JOIN LibriPubblicati_PB)
 ORDER BY Cognome_Autore, Nome_autore;
 */
 
 /*
 NB, Differenza sintassi fra EXISTS e IN.
 Diciamo che voglio tutti gli autori meno Zinbardo.
 ----
 Versione col NOT IN:
 SELECT Nro_autore, Cognome_autore, Nome_autore FROM Autori WHERE Nro_autore NOT IN (SELECT Nro_autore FROM Autori WHERE Cognome_autore = 'Zinbardo');
 ----
 Versione (sbagliata!) col NOT EXISTS (esce un empty set):
 SELECT Nro_autore, Cognome_autore, Nome_autore FROM Autori WHERE NOT EXISTS (SELECT Nro_autore, Cognome_autore, Nome_autore FROM Autori WHERE Cognome_autore = 'Zinbardo');
 ----
 Versione (corretta!) col NOT EXISTS:
 SELECT Nro_autore, Cognome_autore, Nome_autore FROM Autori notzin WHERE NOT EXISTS (SELECT Nro_autore, Cognome_autore, Nome_autore FROM Autori WHERE notzin.Cognome_autore = 'Zinbardo');
 
 Ovvero bisogna referenziare per forza la tabella più esterna nella query piu interna
 
 NB: Quindi, nel dubbio, forse conviene usare sempre il NOT IN, che non ha queste ambiguità
 
 Poi, in questo caso particolare, invece di fare query innestate, si può usare: WHERE Cognome_Autore != 'Zinbardo' ("diverso da", che nelle slide non c'era ma funziona).
 Ho usato le query innestate per mostrare questo problema.
 ----
 */
 
/*Es6
Trovare titolo e tipo del libro più costoso fra quelli pubblicati dall’editore di nome 'Pocket Books' 
(N.B.: risolvere l’esercizio utilizzando la vista LibriPubblicati_PB).*/
SELECT Titolo_libro, Tipo_libro FROM Libri NATURAL JOIN LibriPubblicati_PB
 WHERE Prezzo_libro = (SELECT max(prezzo_libro) FROM Libri NATURAL JOIN LibriPubblicati_PB);


/*Es7
Per ciascun libro pubblicato dall’editore di nome 'Pocket Books', 
trovare cognome e nome del primo autore ed il numero totale di copie disponibili presso le filiali Henrys Books 
(N.B.: risolvere l’esercizio utilizzando la vista LibriPubblicati_PB).*/
SELECT DISTINCT Titolo_libro, Cognome_autore, Nome_autore, sum(Nro_copie_disponibili) AS CopieTotali
 FROM LibriPubblicati_PB NATURAL JOIN LibriAutori NATURAL JOIN Autori NATURAL JOIN Scorte
 WHERE Nro_seq = 1
 GROUP BY (Codice_libro);





