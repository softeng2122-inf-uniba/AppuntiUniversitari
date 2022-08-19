DROP SCHEMA IF EXISTS calcio;
CREATE SCHEMA calcio;
USE calcio;

DROP TABLE IF EXISTS arbitri;
CREATE TABLE arbitri
(
	cognome varchar(10) PRIMARY KEY,
	nome text(10),
	citta text(8),
	regione text(15)
);

INSERT INTO arbitri
VALUES ('Rossi','Mario','Palermo','Sicilia');

INSERT INTO arbitri
VALUES ('Verdi','Luigi','Roma','Lazio');

INSERT INTO arbitri
VALUES ('Bianchi','Marco','Bari','Puglia');

DROP TABLE IF EXISTS squadre;
CREATE TABLE squadre
(
	nome varchar(10) PRIMARY KEY,
	allenatore text(10),
	citta text(8)
);

INSERT INTO squadre
VALUES ('Bari F.C.','Mario Cardo','Bari');

INSERT INTO squadre
VALUES ('Napoli','Danilo Vessio','Napoli');

INSERT INTO squadre
VALUES ('Lazio F.C.','Mario Gattuso','Bari');

INSERT INTO squadre
VALUES ('Milan F.C.','Carlo Buono','Milano');

DROP TABLE IF EXISTS giornate;
CREATE TABLE giornate
(
	numero int(2),
	girone int(2),
	giorno int(2),
	mese int(2),
	anno int(4),
	PRIMARY KEY (numero, girone)
);

INSERT INTO giornate
VALUES (1, 1, 12, 09, 2020);

INSERT INTO giornate
VALUES (2, 1, 19, 09, 2020);

DROP TABLE IF EXISTS partite;
CREATE TABLE partite
(
	numero int(2),
	risultato text(5) DEFAULT NULL,
	citta text(8) DEFAULT NULL,
	data date,
	motivoRinvio text(20) DEFAULT NULL,
	numeroGiornata int(2),
	girone int(2),
	ospite varchar(10),
	casa varchar(10),
	arbitro varchar(10),
	FOREIGN KEY (numeroGiornata, girone) references giornate(numero, girone),			
	FOREIGN KEY (ospite) references squadre(nome),
	FOREIGN KEY (casa) references squadre(nome),
	FOREIGN KEY (arbitro) references arbitri(cognome),
	PRIMARY KEY (numero, numeroGiornata, girone)
);

INSERT INTO partite
VALUES (1, '0:0', 'Bari', date '2000-09-12','Nessuno', 1, 1, 'Bari F.C.', 'Napoli', 'Rossi');

INSERT INTO partite
VALUES (2, '0:1', 'Roma', date '2000-09-12','Nessuno', 1, 1, 'Milan F.C.', 'Lazio F.C.', 'Rossi');

DROP TABLE IF EXISTS posizioni;
CREATE TABLE posizioni
(
	numero int(2),
	girone int(2),
	squadra varchar(10),
	punti int(2),
	FOREIGN KEY (numero, girone) references giornate(numero, girone),
	FOREIGN KEY (squadra) references squadre(nome),
	PRIMARY KEY (numero, girone, squadra)
);

INSERT INTO posizioni
VALUES (1, 1, 'Bari F.C.', 1);

INSERT INTO posizioni
VALUES (1, 1, 'Milan F.C.', 0);

INSERT INTO posizioni
VALUES (1, 1, 'Lazio F.C.', 3);

INSERT INTO posizioni
VALUES (1, 1, 'Napoli', 1);

DROP TABLE IF EXISTS giocatori;
CREATE TABLE giocatori
(
	numeroMaglia int(2),
	nomeSquadra varchar(10),
	nome varchar(10),
	cognome varchar(10),
	ruolo text(10) DEFAULT NULL,
	giorno int(2) DEFAULT NULL,
	mese int(2) DEFAULT NULL,
	anno int(4) DEFAULT NULL,
	cittaNascita text(8) DEFAULT NULL,
	FOREIGN KEY (nomeSquadra) references squadre(nome),
	PRIMARY KEY (numeroMaglia, nomeSquadra)
);

INSERT INTO giocatori
VALUES (10, 'Napoli', 'Luca', 'Abete', 'Difensore', 31, 12, 1979, 'Noicattaro');

INSERT INTO giocatori
VALUES (22, 'Bari F.C.', 'Banana', 'Cipolla', 'Attacante', 11, 09, 2001, 'Nuova York');

DROP TABLE IF EXISTS partecipazioni;
CREATE TABLE partecipazioni
(
	giocatore int(2),
	nomeSquadra varchar(10),
	numeroGiornata int(2),
	girone int(2),
	numeroPartita int(2),
	ruolo text(10) DEFAULT NULL,
	FOREIGN KEY (giocatore, nomeSquadra) references giocatori(numeroMaglia, nomeSquadra),
	FOREIGN KEY (numeroGiornata, girone, numeroPartita) references partite(numeroGiornata, girone, numero),
	PRIMARY KEY (giocatore, nomeSquadra, numeroGiornata, girone, numeroPartita)	
);

INSERT INTO partecipazioni
VALUES (10, 'Napoli', 1, 1, 1, 'Difensore');

INSERT INTO partecipazioni
VALUES (22, 'Bari F.C.', 1, 1, 1, 'Attacante');


SELECT p.casa as 'casa', p.ospite as 'ospite', g.nome
from squadre s join partite p on s.nome=p.casa or s.nome=p.ospite join giocatore g on g.nomeSquadra=s.nome 
join partecipazioni t on t.giocatore=g.numeroMaglia;

SELECT s.nome, g.nome, g.cognome
from squadre s join giocatori g on s.nome=g.nomeSquadra
where s.nome = 'Napoli';

SELECT *
from partite p join arbitri a on p.arbitro=a.cognome
where a.cognome = 'Rossi';