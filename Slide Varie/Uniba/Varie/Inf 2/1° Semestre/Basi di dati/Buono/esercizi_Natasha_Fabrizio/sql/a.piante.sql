DROP SCHEMA IF EXISTS piante;
CREATE SCHEMA piante;
USE piante;

DROP TABLE IF EXISTS fornitori;
CREATE TABLE fornitori
(
	codice varchar(5) primary key,
	nome varchar(10),
	CF varchar(16),
	indirizzo varchar(20)
);

insert into fornitori
	values('10000', 'Rosa', 'DF67HH99L', 'via Nuova, 15a');

insert into fornitori
	values('00000', 'Mario', 'DF68GH89J', 'via delle Falene, 5');

DROP TABLE IF EXISTS clienti;
CREATE TABLE clienti
(
	codice varchar(5) primary key,
	tipoCliente varchar(20),
	nome varchar(10),
	indirizzo varchar(20),
	CF varchar(16) default null,
	partitaIva varchar(11) default null
);

insert into clienti 
	values('12345', 'privato', 'Stefano', 'vicolo Nicolas, 4', '90GURY68ET', null);

DROP TABLE IF EXISTS speci;
CREATE TABLE speci
(
	codice varchar(5) primary key,
	nomeLatino varchar(15),
	nomeComune varchar(15),
	collocazione varchar(10),
	esotica boolean,
	tipologia varchar(10),
	colorazione varchar(15) default null,
	fornitore varchar(5),
	foreign key(fornitore) references fornitori(codice)
);

insert into speci
	values('00001', 'nls', 'cactus', 'giardino', false, 'fiorite', 'giallo', '00000');

DROP TABLE IF EXISTS listinoPrezzi;
CREATE TABLE listinoPrezzi
(
	codiceListino varchar(3) primary key,
	costo decimal(2),
	data date,
	specie varchar(5),
	foreign key(specie) references speci(codice)
);

insert into listinoPrezzi
	values('001', 34, date '2018/08/09', '00001');

insert into listinoPrezzi
	values('002', 14, date '2018/03/19', '00001');

DROP TABLE IF EXISTS acquisti;
CREATE TABLE acquisti
(
	specie varchar(5),
	cliente varchar(5),
	data date,
	primary key(specie, cliente),
	foreign key(specie) references speci(codice),
	foreign key(cliente) references clienti(codice)
);

insert into acquisti
	values('00001', '12345', date '2019/12/24');

#visualizzare tutte le piante vendute dal fornitore "x".
select s.*
from speci s join acquisti a on s.codice=a.specie
where s.fornitore='00000';

#visualizzare il ricavo totale del fornitore "x".
select sum(l.costo) as 'ricavo totale'
from speci s join listinoPrezzi l on s.codice=l.specie join acquisti a on a.specie=s.codice
where s.fornitore='00000';

#visualizzare tutti gli acquisti del cliente "x".
select *
from acquisti 
where cliente='12345';

#visualizzare tutti gli acquisti del cliente "x" con i relativi fornitori.
select a.*, f.*
from acquisti a join speci s on a.specie=s.codice join fornitori f on s.fornitore=f.codice 
where a.cliente='12345';

#visualizzare tutte le piante da giardino relative al fornitore "x".
select *
from speci
where fornitore='00000' and collocazione='giardino';

#visualizzare il fornitore che fornisce il maggior numero di piante.
select f.*
from fornitori f join speci s on f.codice=s.fornitore
group by f.codice
order by count(f.codice) desc
limit 1;
