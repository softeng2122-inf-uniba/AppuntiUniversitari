DROP SCHEMA IF EXISTS repartoOspedale;
CREATE SCHEMA repartoOspedale;
USE repartoOspedale;

DROP TABLE IF EXISTS pazienti;
CREATE TABLE pazienti
(
    CF varchar(16) PRIMARY KEY,
    nome varchar(20),
    cognome varchar(20),
    dataNascita date
);

INSERT INTO pazienti
VALUES ('GIDN42J9K9F3J4G5','Giovanni','Rossi', date '1998/02/26');

INSERT INTO pazienti
VALUES ('GJEND93J8F1J8F48','Maria','Bianchi', date '1988/05/29');

INSERT INTO pazienti
VALUES ('FJDIF4NDSJFN94FF','Marta','Garofalo', date '2003/02/2');

DROP TABLE IF EXISTS medici;
CREATE TABLE medici
(
    matricola varchar(5) PRIMARY KEY,
    cognome varchar(20),
    nome varchar(20),
    dataLaurea date
);

INSERT INTO medici
VALUES ('12345', 'Cassano', 'Marco', date '1967/08/30');

INSERT INTO medici
VALUES ('12347', 'Fabrizio', 'Zio', date '1969/03/29');

INSERT INTO medici
VALUES ('12348', 'Verdura', 'Anna', date '1978/05/27');

DROP TABLE IF EXISTS ricoveri;
CREATE TABLE ricoveri
(
    dataInizio date,
    paziente varchar(16),
    medico varchar(5),
    tipo varchar(10),
    recapitoParente varchar(15) DEFAULT NULL,
    motivazione text(30) DEFAULT NULL,
    dataFine date DEFAULT NULL,
    PRIMARY KEY (dataInizio, paziente, medico),
    FOREIGN KEY (paziente) references pazienti(CF),
    FOREIGN KEY (medico) references medici(matricola)
);

INSERT INTO ricoveri
VALUES (date '2020/05/23', 'GIDN42J9K9F3J4G5', '12345', 'concluso', null, 'Dio', date '2021/05/31');

INSERT INTO ricoveri
VALUES (date '2020/12/23', 'GIDN42J9K9F3J4G5', '12345', 'in corso', '3245673453', null, null);

INSERT INTO ricoveri(dataInizio, paziente, medico, tipo, recapitoParente)
VALUES (date '2020/03/23', 'FJDIF4NDSJFN94FF', '12348', 'in corso', '3356575908');

DROP TABLE IF EXISTS medicine;
CREATE TABLE medicine
(
    codice varchar(3) PRIMARY KEY,
    nome varchar(15),
    costo int(3),
    quantita int(2)
);

INSERT INTO medicine
VALUES ('001', 'Vaginix', 30, 1);

INSERT INTO medicine
VALUES ('002', 'Oki', 11, 2);

DROP TABLE IF EXISTS malattie;
CREATE TABLE malattie
(
    codice varchar(5) PRIMARY KEY,
    nome varchar(16)
);

INSERT INTO malattie
VALUES ('00333', 'Covid');

INSERT INTO malattie
VALUES ('00412', 'Varicella');

DROP TABLE IF EXISTS visite;
CREATE TABLE visite
(
    data date,
    ora time,
    paziente varchar(16),
    diagnosi varchar(5),
    farmacoPrescritto varchar(3) DEFAULT NULL,
    PRIMARY KEY (data, ora, paziente),
    FOREIGN KEY (paziente) references pazienti(CF),
    FOREIGN KEY (diagnosi) references malattie(codice),
    FOREIGN KEY (farmacoPrescritto) references medicine(codice)
);

INSERT INTO visite
VALUES (date '2021/03/17', '13:30', 'GIDN42J9K9F3J4G5', '00333', '002');

INSERT INTO visite
VALUES (date '2021/03/17', '12:30', 'GIDN42J9K9F3J4G5', '00333', null);

INSERT INTO visite
VALUES (date '2021/01/10', '11:30', 'GIDN42J9K9F3J4G5', '00333', null);

INSERT INTO visite
VALUES (date '2021/02/17', '16:30', 'FJDIF4NDSJFN94FF', '00412', null);

DROP TABLE IF EXISTS consulti;
CREATE TABLE consulti
(
    medico varchar(5),
    dataVisita date,
    oraVisita time,
    paziente varchar(16),
    PRIMARY KEY (medico, dataVisita, oraVisita, paziente),
    FOREIGN KEY (medico) references medici(matricola),
    FOREIGN KEY (dataVisita, oraVisita, paziente) references visite(data, ora, paziente)
);

INSERT INTO consulti
VALUES ('12345', date '2021/01/10', '11:30', 'GIDN42J9K9F3J4G5');

INSERT INTO consulti
VALUES ('12347', date '2021/02/17', '16:30', 'FJDIF4NDSJFN94FF');

DROP TABLE IF EXISTS controlli;
CREATE TABLE controlli
(
	data date,
	ora time,
	paziente varchar(16),
	FOREIGN KEY(paziente) references pazienti(CF),
	FOREIGN KEY(data, ora, paziente) references visite(data, ora, paziente),
	PRIMARY KEY(data, ora, paziente) 
);

INSERT INTO controlli
VALUES (date '2021/03/17', '13:30', 'GIDN42J9K9F3J4G5');


select p.nome, p.cognome
from pazienti p join controlli c on p.CF=c.paziente join visite v on v.data=c.data and v.ora=c.ora 
join malattie m on m.codice=v.diagnosi
where m.nome='Covid';

select m.nome, m.cognome
from medici m join consulti c on c.medico=m.matricola;

select p.nome, p.cognome
from pazienti p join ricoveri r on p.CF=r.paziente
group by p.cognome
order by max(r.paziente) desc
limit 1;

select v.data, v.ora, m.nome as 'diagnosi', n.nome as 'farmacoPrescritto'
from controlli c join visite v on v.data=c.data and v.ora=c.ora and v.paziente=c.paziente 
join malattie m on v.diagnosi=m.codice join medicine n on v.farmacoPrescritto=n.codice
where c.paziente = 'GIDN42J9K9F3J4G5';