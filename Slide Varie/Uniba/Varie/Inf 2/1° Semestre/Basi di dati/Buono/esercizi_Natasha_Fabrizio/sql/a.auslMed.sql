DROP SCHEMA IF EXISTS ASUL;
CREATE SCHEMA ASUL;
USE ASUL;

DROP TABLE IF EXISTS farmaci;
CREATE TABLE farmaci
(
	codice varchar(3) primary key,
	tipo varchar(10),
	descrizione text
);

DROP TABLE IF EXISTS esami;
CREATE TABLE esami
(
	tipo varchar(10) primary key,
	risultato varchar(10)
);

DROP TABLE IF EXISTS medGenerici;
CREATE TABLE medGenerici
(
	matricola varchar(5) primary key,
	cf varchar(16), 
	nome varchar(10),
	cognome varchar(10),
	indirizzo varchar(20),
	telefono varchar(10),
	numAssistiti int(3)
);

DROP TABLE IF EXISTS specialisti;
CREATE TABLE specialisti
(
	matricola varchar(5) primary key,
	cf varchar(16), 
	nome varchar(10),
	cognome varchar(10),
	indirizzo varchar(20),
	telefono varchar(10),
	specializzazione varchar(20)
);

DROP TABLE IF EXISTS pazienti;
CREATE TABLE pazienti
(
	SSN varchar(4) primary key,
	cf varchar(16),
	nome varchar(10),
	cognome varchar(10),
	dataNascita date,
	telefono varchar(10) default null,
	medBase varchar(5),
	foreign key(medBase) references medGenerici(matricola)
);

DROP TABLE IF EXISTS controlli;
CREATE TABLE controlli
(
	tipoEsame varchar(10),
	paziente varchar(4),
	data date,
	prescrizione varchar(5),
	primary key(tipoEsame, paziente),
	foreign key(tipoEsame) references esami(tipo),
	foreign key(paziente) references  pazienti(SSN),
	foreign key(prescrizione) references medGenerici(matricola)
);

DROP TABLE IF EXISTS visiteSpecialistiche;
CREATE TABLE visiteSpecialistiche
(
	specialista varchar(5),
	paziente varchar(4),
	data date,
	primary key(specialista, paziente),
	foreign key(specialista) references specialisti(matricola),
	foreign key(paziente) references pazienti(SSN)
);

DROP TABLE IF EXISTS visite;
CREATE TABLE visite
(
	specialista varchar(5),
	paziente varchar(4),
	data date,
	primary key(specialista, paziente, data),
	foreign key(specialista) references specialisti(matricola),
	foreign key(paziente) references pazienti(SSN)
);

DROP TABLE IF EXISTS allergie;
CREATE TABLE allergie
(
	paziente varchar(4),
	farmaco varchar(3),
	primary key(paziente, farmaco),
	foreign key(paziente) references pazienti(SSN),
	foreign key(farmaco) references farmaci(codice)
);

#visualizzare il medico curante del paziente "x".
select medBase
from pazienti 
where SSN='';

#visualizzare la lista dei medici specialisti che hanno visitato il paziente "x".
select s.*
from specialisti s join visiteSpecialistiche v on s.matricola=v.specialista
where v.paziente='';

#visualizza tutti gli esami in laboratorio prescritti dal medico "x" e i dati del paziente.
select e.*, p.*
from esami e join controlli c on e.tipo=c.tipoEsame join pazienti p on p.SSN=c.paziente 
where c.prescrizione='';

#visualizzare tutti i farmaci ai quali il paziente "x" è allergico.
select f.*
from allergie a join farmaci f on a.farmaco=f.codice
where a.paziente='';

#dato un medico "x" visualizzare tutti i suoi pazienti e l'eventuali informazioni relative all'esame di laboratorio.
select p.*, e.*
from pazienti p join controlli c on p.SSN=c.paziente join esami e on c.tipoEsame=e.tipo 
where p.medBase='';