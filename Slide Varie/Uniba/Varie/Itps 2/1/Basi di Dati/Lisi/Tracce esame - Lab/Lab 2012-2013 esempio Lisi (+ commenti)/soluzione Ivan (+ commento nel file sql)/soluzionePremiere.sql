

/*Es.1: 
Creare la tabella per la relazione DettOrdini con il seguente schema:
NroOrdine = stringa di 6 caratteri
NroArt = stringa di 4 caratteri
QtaOrd = intero
PrezzoRichiesto = decimale con precisione 6 e scala 2
e completa di vincoli sia intrarelazionali che interrelazionali.*/
CREATE TABLE DettOrdini(
 NroOrdine CHAR(6) NOT NULL, NroArt CHAR(4), QtaOrd INT, PrezzoRichiesto DECIMAL(6,2),
 PRIMARY KEY(NroOrdine, NroArt),
 FOREIGN KEY (NroOrdine) REFERENCES Ordini(NroOrdine),
 FOREIGN KEY (NroArt) REFERENCES Articoli(NroArt));
/*Fix: Meglio aggiungere alla chiave esterna il ON DELETE CASCADE ON UPDATE CASCADE*/
 
 
/*Es.2: Inserire nella tabella DettOrdini la tupla con valori ('12489','AX12',11,21.95).*/
INSERT INTO DettOrdini VALUES ('12489', 'AX12', 11, 21.95);


/*Es.3: Creare una vista PiccoliClienti che seleziona i clienti con saldo inferiore a 1000.*/
CREATE VIEW PiccoliClienti
 AS SELECT CodCliente FROM Clienti WHERE Saldo < 1000;
/*Fix: La Lisi seleziona tutto, non solo il CodCliente: CREATE VIEW PiccoliClienti AS SELECT * FROM Clienti WHERE Saldo < 1000;*/


/*Es.4: Trovare i clienti che hanno emesso un ordine il 5 settembre 2002, mostrandone codice, cognome e nome.*/
SELECT CodCliente, Cognome, Nome
 FROM Clienti NATURAL JOIN Ordini
 WHERE Data = '2002/09/05';
/*Fix: Meglio usare il SELECT DISTINCT (lo stesso cliente potrebbe fare più ordini in un giorno)*/


/*Es.5: Trovare i rappresentanti che hanno almeno un cliente con fido di 1000 euro, mostrandone codice, cognome e nome.*/
/*NB:
  In Rappresentanti e Clienti ci sono 3 campi che fanno conflitto di nomi, ovvero CodRappr, Cognome, Nome.
  Quindi il join naturale non funge. Bisogna usare il join esplicito, dichiarando dove si joina.*/
SELECT r.CodRappr, r.Cognome, r.Nome
 FROM rappresentanti r JOIN clienti c
 WHERE c.CodRappr = r.CodRappr AND Fido = 1000;


/*Es.6: Calcolare, fido per fido, il numero dei clienti del rappresentante con codice 03 aventi quel fido, 
e limitandosi a considerare i fidi attribuiti a più di un solo cliente.*/

/*Ovvero: il rappr03 ha X clienti, che avranno Y possibili valori per il fido (es. 5 clienti hanno fido = 3000, 4 clienti hanno fido = 4000, eccetera).
  Vuole sapere, per ogni tipo di fido, quanti dei clienti del rappr03 hanno quel fido.*/
  
/*In questo caso, il rappr03 ha 3 clienti (visibili facendo un select * from rappr join clienti where codrappr = '03').
  Due clienti hanno fido = 1000, e uno ha fido = 2000.
  Quindi ci sono 2 gruppi di fido (1000 e 2000).
  Voglio solo i gruppi di fido il cui fido è avuto da 2+ persone (in questo caso il 1000).*/

/*L'istinto è aggiungere il group by + il count(*) > 1 all'interno del where, ma non funge.
  Bisogna ricordarsi la sintassi, e capire che se vuoi fare interrogazioni sui gruppi che hai, DOPO averli creati, devi usare HAVING.*/

/*Come lo fa la Lisi (dando informazioni sui Fidi avuti da più persone, e non dando info su clienti o rappr):  */
SELECT Fido, COUNT(*)
 FROM Clienti
 WHERE CodRappr='03'
 GROUP BY Fido
 HAVING COUNT(*)>1;

/*Se invece voglio info sui clienti che hanno i fidi in considerazione (la traccia è intendibile in più modi), si fa così:
  NB: la query più interna significa: "Dammi i fidi avuti da 2+ persone seguite dal rappr03".
  L'ho messo perché è bella difficile come query, utile da vedere.*/
SELECT r.CodRappr, r.Cognome, r.Nome, c.CodCliente, c.Cognome, c.Nome, c.Fido
 FROM Rappresentanti r JOIN Clienti c ON r.CodRappr = c.CodRappr
 WHERE r.CodRappr = '03' AND c.Fido IN (
  SELECT Fido FROM Clienti
  WHERE CodRappr = '03'
  GROUP BY Fido
  HAVING count(Fido) > 1
 );
 
/*NON funziona invece così 
SELECT r.CodRappr, r.Cognome, r.Nome, c.CodCliente, c.Cognome, c.Nome, c.Saldo, c.Fido
 FROM rappresentanti r JOIN clienti c
 WHERE c.CodRappr = r.CodRappr AND c.CodRappr = '03'
 GROUP BY c.Fido
 HAVING count(*) > 1;
*/ 
 
 
 
/*Es.7: Trovare i clienti con saldo inferiore a 1000 e fido superiore al saldo, mostrandone codice, cognome e nome 
(N.B.: risolvere mediante interrogazione sulla vista PiccoliClienti).*/
SELECT c.CodCliente, c.Cognome, c.Nome
 FROM Clienti c JOIN PiccoliClienti
 WHERE c.Fido > c.Saldo;

 
 
 
 
 
