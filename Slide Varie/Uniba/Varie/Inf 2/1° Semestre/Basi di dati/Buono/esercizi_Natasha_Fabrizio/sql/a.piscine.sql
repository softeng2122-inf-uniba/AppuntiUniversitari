DROP SCHEMA IF EXISTS piscineTorino;
CREATE SCHEMA piscineTorino;
USE piscineTorino;

DROP TABLE IF EXISTS piscine;
CREATE TABLE piscine
(
	nome varchar(10) primary key,
	indirizzo varchar(15),
	telefono varchar(10),
	responsabile varchar(10),
	vasca boolean,
	utilizzoVasca varchar(30)
);

insert into piscine
	values('Vigone', 'via Serra, 5c', '081-56789', 'Damiano', true, 'giovedi - sabato');

DROP TABLE IF EXISTS insegnanti;
CREATE TABLE insegnanti
(
	CF varchar(16) primary key,
	nome varchar(10),
	cellulare varchar(10),
	disponibilita boolean,
	qualifiche varchar(50)
);

insert into insegnanti
	values('23GJ78GJ8', 'Rossella', '3346829086', false, 'esperto');

DROP TABLE IF EXISTS persone;
CREATE TABLE persone
(
	CF varchar(16) primary key,
	nome varchar(10),
	indirizzo varchar(15),
	telefono varchar(10)
);

DROP TABLE IF EXISTS insegnamenti;
CREATE TABLE insegnamenti
(
	piscina varchar(10),
	insegnante varchar(16),
	inizioImpiego date,
	fineImpiego date,
	primary key(piscina, insegnante),
	foreign key(piscina) references piscine(nome),
	foreign key(insegnante) references insegnanti(CF)
);

insert into insegnamenti
	values('Vigone', '23GJ78GJ8', date '2018/09/17', date '2018/10/17');

DROP TABLE IF EXISTS ingressi;
CREATE TABLE ingressi
(
	piscina varchar(10),
	persona varchar(16),
	dataIngresso date,
	primary key(piscina, persona),
	foreign key(piscina) references piscine(nome),
	foreign key(persona) references persone(CF)
);

DROP TABLE IF EXISTS corsi;
CREATE TABLE corsi
(
	attivita varchar(20) primary key,
	costo int(3),
	minPartecipanti varchar(3),
	maxPartecipanti varchar(3),
	giorni varchar(50),
	ora time
);

DROP TABLE IF EXISTS iscritti;
CREATE TABLE iscritti
(
	persona varchar(16),
	corso varchar(20),
	eta varchar(2),
	medico varchar(10),
	presentazioneCertificato date,
	primary key(persona, corso),
	foreign key(persona) references persone(CF),
	foreign key(corso) references corsi(attivita)
);

DROP TABLE IF EXISTS corsiSvolti;
CREATE TABLE corsiSvolti
(
	piscina varchar(10),
	corso varchar(20),
	modalita varchar(30),
	data date, 
	primary key(piscina, corso),
	foreign key(piscina) references piscine(nome),
	foreign key(corso) references corsi(attivita)
);

#visualizzare tutte le informazioni relative a tutte le piscine con i relativi insegnati nel tempo.
select p.*, t.*, i.inizioImpiego, i.fineImpiego
from piscine p join insegnamenti i on p.nome=i.piscina join insegnanti t on t.CF=i.insegnante;

#visualizzare il corso, la piscina e l'insegnante della persona "x".
select c.*, p.nome as 'piscina', t.nome as 'insegnate'
from iscritti i join corsi c on i.corso=c.attivita join corsiSvolti cs on cs.corso=c.attivita
join piscine p on cs.piscina=p.nome join insegnamenti m on p.nome=m.piscina join insegnanti t on t.CF=m.insegnante
where i.persona='';

#visualizzare tutte le persone iscritta ad un corso e la relativa piscina.
select p.*, ps.nome as 'piscina'
from persone p join iscritti i on p.CF=i.persona join corsi c on c.attivita=i.corso join corsiSvolti cs on cs.corso=c.attivita
join piscine ps on ps.nome=cs.piscina;

#visualizzare gli insegnati che hanno insegnato almeno una volta in una una piscina esterna.
select t.*
from insegnanti t join insegnamenti i on i.insegnante=t.CF join piscine p on p.nome=i.piscina
where p.vasca = true;

