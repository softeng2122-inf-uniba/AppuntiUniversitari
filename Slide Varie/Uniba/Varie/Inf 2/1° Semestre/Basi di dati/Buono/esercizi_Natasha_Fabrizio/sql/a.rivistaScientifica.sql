DROP SCHEMA IF EXISTS rivistaScientifica;
CREATE SCHEMA rivistaScientifica;
USE rivistaScientifica;

DROP TABLE IF EXISTS articoli;
CREATE TABLE articoli
(
	titolo varchar(10) PRIMARY KEY,
	sottotitolo text(20) DEFAULT NULL,
	testo text(200)
);

DROP TABLE IF EXISTS istituzioni;
CREATE TABLE istituzioni
(
	nome varchar(10) PRIMARY KEY,
	indirizzo text(20),
	nazione text(10)
);

DROP TABLE IF EXISTS autori;
CREATE TABLE autori
(
	email varchar(20) PRIMARY KEY,
	nome varchar(10),
	cognome varchar(10),
	nomeIstituione varchar(15),
	FOREIGN KEY (nomeIstituione) references istituzioni(nome)
);

DROP TABLE IF EXISTS riviste;
CREATE TABLE riviste
(
	numero int(10) PRIMARY KEY,
	dataPubblicazione date
);

DROP TABLE IF EXISTS volumi;
CREATE TABLE volumi
(
	titoloComplessivo varchar(20) PRIMARY KEY,
	annoPubblicazione int(4)
);

DROP TABLE IF EXISTS scritture;
CREATE TABLE scritture
(
	titolo varchar(10),
	autore varchar(20),
	FOREIGN KEY (titolo) references articoli(titolo),
	FOREIGN KEY (autore) references autori(email) 
);

DROP TABLE IF EXISTS inserimenti;
CREATE TABLE inserimenti
(
	titolo varchar(10),
	numero int(10),
	paginaIniziale int(2),
	paginaFinale int(4),
	FOREIGN KEY (titolo) references articoli(titolo),
	FOREIGN KEY (numero) references	riviste(numero)
);

DROP TABLE IF EXISTS raccolte;
CREATE TABLE raccolte
(
	numero int(10),
	titoloComplessivo varchar(20),
	FOREIGN KEY	(numero) references riviste(numero),
	FOREIGN KEY (titoloComplessivo) references volumi(titoloComplessivo)
);

INSERT INTO articoli
VALUES ('SHOCK', 'because', 'seeeeeeeeeeeeeeeee');

INSERT INTO articoli
VALUES ('Progetto', 'ModelliProgetti', 'X,Y,M,Z');

INSERT INTO istituzioni
VALUES ('GoodJob', 'via Sole', 'Italia');

INSERT INTO autori
VALUES ('g@gmail.it', 'Gino', 'Palmieri', 'GoodJob');

INSERT INTO autori
VALUES ('m@gmail.it', 'Moreno', 'Piuma', 'GoodJob');

INSERT INTO riviste
VALUES ('234', date '2005/07/28');

INSERT INTO volumi
VALUES ('Gnorry', 2005);

INSERT INTO scritture
VALUES ('SHOCK', 'm@gmail.it');

INSERT INTO scritture
VALUES ('Progetto', 'g@gmail.it');

INSERT INTO inserimenti
VALUES ('SHOCK', '234', 1, 5);

INSERT INTO inserimenti
VALUES ('Progetto', '234', 1, 30);

INSERT INTO raccolte
VALUES ('234', 'Gnorry');


SELECT a.nome, a.cognome
from autori a join scritture t on t.autore=a.email join articoli c on c.titolo=t.titolo
where c.titolo like 'S%';

SELECT a.nome, a.cognome, i.nome as 'istituzione'
from autori a join istituzioni i on i.nome=a.nomeIstituione;

SELECT a.titolo, a.sottotitolo, a.testo, t.nome, t.cognome
from autori t join scritture s on s.autore=t.email join articoli a on a.titolo=s.titolo
join inserimenti i on i.titolo=a.titolo join riviste r on r.numero=i.numero;

SELECT * from raccolte;


















