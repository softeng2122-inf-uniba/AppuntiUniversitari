DROP SCHEMA IF EXISTS Ospedale;
CREATE SCHEMA Ospedale;
USE Ospedale;

DROP TABLE IF EXISTS medici;
CREATE TABLE medici
(
	matricola varchar(10) PRIMARY KEY,
	nome varchar(10) NOT NULL,
	cognome varchar(10) NOT NULL
);

INSERT INTO medici
VALUES ('123453', 'Nat', 'NC');

INSERT INTO medici
VALUES ('123451', 'Marta', 'Yang');

INSERT INTO medici
VALUES ('123452', 'George', 'Dark');

INSERT INTO medici
VALUES ('123457', 'Miranda', 'Orwell');

DROP TABLE IF EXISTS struttura; 
CREATE TABLE struttura
(
	nome varchar(20) PRIMARY KEY,
	primario varchar(10),
	FOREIGN KEY (primario) references medici(matricola)
);

INSERT INTO struttura
VALUES ('Ricovero', '123452');

INSERT INTO struttura
VALUES ('Psichiatria', '123453');

INSERT INTO struttura
VALUES ('Ambulatorio', '123451');

DROP TABLE IF EXISTS reparti;
CREATE TABLE reparti
(
	nome varchar(10) PRIMARY KEY,
	nomeStruttura varchar(20),
	piano varchar(5),
	FOREIGN KEY (nomeStruttura) references struttura(nome)
);

INSERT INTO reparti
VALUES ('CasiPersi', 'Psichiatria', 'T');

INSERT INTO reparti
VALUES ('Urgenze', 'Ricovero', '1');

INSERT INTO reparti
VALUES ('?', 'Psichiatria', 'T');

INSERT INTO reparti
VALUES ('Audiologia', 'Ambulatorio', '3');

DROP TABLE IF EXISTS pazienti;
CREATE TABLE pazienti
(
	CF varchar(16) PRIMARY KEY,
	nome varchar(10) NOT NULL,
	cognome varchar(10) NOT NULL
);

INSERT INTO pazienti
VALUES ('1234567890', 'Saverio', 'Cassano');

INSERT INTO pazienti
VALUES ('1234567891', 'Moreno', 'Agostini');

INSERT INTO pazienti
VALUES ('1234567892', 'Michela', 'Zito');

DROP TABLE IF EXISTS associati;
CREATE TABLE associati
(
	medico varchar(10),
	reparto varchar(10),
	FOREIGN KEY (medico) references medici(matricola),
	FOREIGN KEY (reparto) references reparti(nome),
	PRIMARY KEY (medico, reparto)
);

INSERT INTO associati
VALUES ('123453', 'CasiPersi');

INSERT INTO associati
VALUES ('123452', 'Urgenze');

DROP TABLE IF EXISTS operazioni;
CREATE TABLE operazioni
(
	numOrdine int(5) PRIMARY KEY,
	paziente varchar(16),
	struttura varchar(20),
	medico varchar(10),
	esito varchar(15),
	durata varchar(5),
	data date,
	medicina varchar (20),
	quantitaMed int(3),
	descrizione text DEFAULT NULL,
	FOREIGN KEY (paziente) references pazienti(CF),
	FOREIGN KEY (struttura) references struttura(nome),
	FOREIGN KEY (medico) references medici(matricola)
);

INSERT INTO operazioni (numOrdine, paziente, struttura, medico, esito, durata, data, descrizione)
VALUES (123, '1234567890', 'Psichiatria', '123453', 'problematico', '2h', date '2021/01/21', 'ma io che cazzo ne so');

INSERT INTO operazioni (numOrdine, paziente, struttura, medico, esito, durata, data)
VALUES (133, '1234567892', 'Ricovero', '123452', 'normale', '1h', date '2020/01/03');


SELECT count(o.paziente) as 'interventi', s.nome
from operazioni o join struttura s on s.nome=o.struttura
group by s.nome;

SELECT count(a.medico) as 'medici in reparti', m.nome 
from associati a join medici m on a.medico=m.matricola
group by m.matricola; 

#versione 1
SELECT *
from operazioni o 
where o.paziente = '1234567890';

#versione 2
SELECT *
from operazioni o join pazienti p on o.paziente=p.cf
where p.cognome = 'Cassano';

SELECT p.nome, p.cognome
from operazioni o join pazienti p on p.cf=o.paziente;

#???
/* 
SELECT r.nome as 'reparti', concat(m.nome,' ',m.cognome) as 'medici', concat(p.nome,' ',p.cognome) as 'paziente operato'
from reparti r , medici m, pazienti p join operazioni o 
where p.cf=o.paziente; 

















