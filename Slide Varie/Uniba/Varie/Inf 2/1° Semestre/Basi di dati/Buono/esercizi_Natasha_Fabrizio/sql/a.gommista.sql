DROP SCHEMA IF EXISTS gommista;
CREATE SCHEMA gommista;
USE gommista;

DROP TABLE IF EXISTS pneumatici;
CREATE TABLE pneumatici
(
	modello varchar(10) PRIMARY KEY,
	marca varchar(10),
	prezzo int(5),
	raggio int(3),
	larghezza int(3),
	altezza int(3),
	indicatoreSicurezza varchar(10)
);

INSERT INTO pneumatici 
VALUES ('FPMC', 'Pirelli', 200, 10, 2, 5, '100km');

DROP TABLE IF EXISTS clienti;
CREATE TABLE clienti
(
	nome varchar(10),
	cognome varchar(10),
	via varchar(20),
	citta varchar(10),
	PRIMARY KEY (nome, cognome)
);

INSERT INTO clienti
VALUES ('Paolo', 'Buono', 'via Fiore, 3', 'Bari');

INSERT INTO clienti
VALUES ('Marta', 'Cassano', 'via delle Palme, 5', 'Modugno');

DROP TABLE IF EXISTS forniture;
CREATE TABLE forniture
(
	modelloPneumatico varchar(10),
	nomeCliente varchar(10),
	cognomeCliente varchar(10),
	data date,
	FOREIGN KEY (modelloPneumatico) references pneumatici(modello),
	FOREIGN KEY (nomeCliente, cognomeCliente) references clienti(nome, cognome)
);

INSERT INTO forniture
VALUES ('FPMC', 'Marta', 'Cassano', date '2021/01/21');

INSERT INTO forniture
VALUES ('FPMC', 'Marta', 'Cassano', date '2019/11/09');

DROP TABLE IF EXISTS automobili;
CREATE TABLE automobili
(
	modello varchar(10),
	nomeProprietario varchar(10),
	cognomeProprietario varchar(10),
	marca varchar(10),
	cilindrata varchar(10),
	PRIMARY KEY (modello, nomeProprietario, cognomeProprietario),
	FOREIGN KEY (nomeProprietario, cognomeProprietario) references clienti(nome, cognome)
);

INSERT INTO automobili
VALUES ('GrandeP', 'Marta', 'Cassano', 'Fiat', '80cc');

DROP TABLE IF EXISTS tecnici;
CREATE TABLE tecnici
(
	nome varchar(10),
	cognome varchar(10),
	qualifica varchar(20),
	PRIMARY KEY (nome, cognome)
);

INSERT INTO tecnici
VALUES ('Gino', 'Flash', 'apprendista');

DROP TABLE IF EXISTS controlli;
CREATE TABLE controlli
(
	data date,
	ora time(2),
	nomeTecnico varchar(10),
	cognomeTecnico varchar(10),
	modelloAuto varchar(10),
	nomeCliente varchar(10),
	cognomeCliente varchar(10),
	elemAuto varchar(15),
	unitaMisura varchar(2),
	tipoControllo varchar(20),
	valore integer check (valore >= 1 and valore <= 100),
	durataIntervento varchar(5),
	costo int(5),
	PRIMARY KEY (data, ora, nomeTecnico, cognomeTecnico),
	FOREIGN KEY (modelloAuto) references automobili(modello),
	FOREIGN KEY (nomeCliente, cognomeCliente) references clienti(nome, cognome),
	FOREIGN KEY (nomeTecnico, cognomeTecnico) references tecnici(nome, cognome)
);

INSERT INTO controlli
VALUES (date '2020/11/03', '13:30', 'Gino', 'Flash', 'GrandeP', 'Marta', 'Cassano', 
		'anteriore', 'cm', 'revisione', 45, '10m', 80);

INSERT INTO controlli
VALUES (date '2021/01/03', '15:20', 'Gino', 'Flash', 'GrandeP', 'Marta', 'Cassano', 
		'posteriore', 'cm', 'revisione', 19, '10m', 90);

INSERT INTO controlli
VALUES (date '2019/12/13', '08:20', 'Gino', 'Flash', 'GrandeP', 'Marta', 'Cassano', 
		'posteriore', 'cm', 'revisione', 10, '10m', 90);

INSERT INTO controlli
VALUES (date '2020/11/23', '15:20', 'Gino', 'Flash', 'GrandeP', 'Marta', 'Cassano', 
		'anteriore', 'cm', 'revisione', 20, '10m', 80);

SELECT count(c.nomeCliente) as 'numero revisioni'
from controlli c #join cliente p on c.nomeCliente=p.nome and c.cognomeCliente=p.cognome 
where c.nomeCliente = 'Marta' and c.cognomeCliente = 'Cassano';

SELECT c.data, c.costo
from controlli c #join cliente p on c.nomeCliente=p.nome and c.cognomeCliente=p.cognome 
where c.nomeCliente = 'Marta' and c.cognomeCliente = 'Cassano';

SELECT distinct c.nomeTecnico, c.cognomeTecnico
from controlli c
where c.nomeCliente = 'Marta' and c.cognomeCliente = 'Cassano';

SELECT sum(p.prezzo) as 'ammontare totale'
from clienti c join forniture f on c.nome=f.nomeCliente and c.cognome=f.cognomeCliente 
join pneumatici p on p.modello=f.modelloPneumatico
where c.nome = 'Marta' and c.cognome = 'Cassano' and data between date '2018/01/01' and date '2020/12/31';








