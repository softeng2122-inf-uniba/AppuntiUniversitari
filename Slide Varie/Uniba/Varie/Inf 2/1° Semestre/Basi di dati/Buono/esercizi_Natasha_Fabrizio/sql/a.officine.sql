DROP SCHEMA IF EXISTS cateneOfficine;
CREATE SCHEMA cateneOfficine;
USE cateneOfficine;

DROP TABLE IF EXISTS officine;
CREATE TABLE officine
(
	nome varchar(10) primary key,
	indirizzo varchar(20),
	telefono varchar(15)
);

insert into officine
	values('officinaX', 'via giardini, 3', '3345674567');

insert into officine
	values('RiparaAuto', 'via Notte, 3b', '3334524667');

DROP TABLE IF EXISTS pezzi;
CREATE TABLE pezzi
(
	codice varchar(3) primary key,
	nome varchar(15),
	costo int(5),
	quantita int(5)
);

insert into pezzi
	values('001', 'cerchione', 80, 2);

insert into pezzi
	values('002', 'specchietto', 100, 1);

insert into pezzi
	values('003', 'gomma', 100, 4);

DROP TABLE IF EXISTS manutenzioni;
CREATE TABLE manutenzioni
(
	num varchar(5),
	officina varchar(10),
	dataInizio date,
	dataFine date,
	oreLavoro decimal(4),
	pezziRicambio varchar(3),
	primary key(num, officina),
	foreign key(officina) references officine(nome),
	foreign key(pezziRicambio) references pezzi(codice)
);

insert into manutenzioni
	values('00000', 'officinaX', date '2020/08/17', date '2020/09/20', 5, '002');


insert into manutenzioni
	values('00001', 'officinaX', date '2020/8/17', date '2020/08/20', 3, '003');


DROP TABLE IF EXISTS clienti;
CREATE TABLE clienti
(
	cf varchar(16) primary key,
	nome varchar(10),
	cognome varchar(10),
	telefono varchar(15)
);

insert into clienti
	values('12efT657D', 'Sara', 'Potenza', '3323433678');

insert into clienti
	values('23gsT689F', 'Miriam', 'Vecchio', '3315687245');

insert into clienti
	values('12esJ297D', 'Giusy', 'Sapone', '3290917890');

DROP TABLE IF EXISTS automobili;
CREATE TABLE automobili
(
	targa varchar(7) primary key,
	modello varchar(20),
	proprietario varchar(16),
	foreign key(proprietario) references clienti(cf)
);

insert into automobili
	values('FD567HI', 'Punto', '12efT657D');

insert into automobili
	values('GT673FG', '500', '12efT657D');

insert into automobili
	values('FG453GJ', 'Focus', '12esJ297D');

insert into automobili
	values('GA569IO', '600', '23gsT689F');

DROP TABLE IF EXISTS interventi;
CREATE TABLE interventi
(
	numIntervento varchar(5),
	officina varchar(10),
	auto varchar(7),
	primary key(numIntervento, officina, auto),
	foreign key(numIntervento, officina) references manutenzioni(num, officina),
	foreign key(auto) references automobili(targa)
);

insert into interventi
	values('00000', 'officinaX', 'FD567HI');


#Visualizzare tutte le automobili del cliente "x"
select *
from automobili 
where proprietario='12efT657D';

#Visualizzare l'officina che ha riparato il veicolo del proprietario "x"
select o.nome as 'officina'
from officine o join manutenzioni m on o.nome=m.officina join interventi i on m.num=i.numIntervento join automobili a 
on i.auto=a.targa
where a.proprietario='12efT657D';

#Visualizza i pezzi di ricambio utilizzati per la ripartizione della macchina di "x"
select p.nome as 'pezzi di ricambio'
from pezzi p join manutenzioni m on m.pezziRicambio=p.codice join interventi i on i.numIntervento=m.num 
join automobili a on a.targa=i.auto 
where a.proprietario='FD567HI';

#Visualizza la riparazione che ha richiesto il maggior tempo di riparazione
select num as 'riparazione piu lunga'
from manutenzioni
group by num
order by sum(oreLavoro) desc
limit 1;
