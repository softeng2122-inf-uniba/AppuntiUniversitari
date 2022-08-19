DROP SCHEMA IF EXISTS attrezzatureSub;
CREATE SCHEMA attrezzatureSub;
USE attrezzatureSub;

DROP TABLE IF EXISTS campagne;
CREATE TABLE campagne
(
	codice varchar(3) primary key,
	descizione text
);

insert into campagne
	values('124', 'omino');

DROP TABLE IF EXISTS clienti;
CREATE TABLE clienti
(
	numCI varchar(10),
	comune varchar(10),
	nome varchar(10),
	cognome varchar(10),
	telefono varchar(10),
	tipo varchar(15),
	cartaFed varchar(5) default null,
	campagna varchar(3) unique default null,
	mesePub varchar(2) default null,
	foreign key(campagna) references campagne(codice),
	primary key(numCI, comune)
);

insert into clienti
	values('01GH67G', 'Napoli', 'Mario', 'Neri', '081-89302', 'fedele', '0013H', '124', '02');

insert into clienti
	values('01YU37G', 'Verona', 'Rosa', 'Rizzi', '0881-9024', 'occasionale', null, null, null);

DROP TABLE IF EXISTS attrezzature;
CREATE TABLE attrezzature
(
	codice varchar(3) primary key,
	dataAcquisto date,
	tipologia varchar(20),
	casaProd varchar(10) default null,
	taglia varchar(3) default null
);

insert into attrezzature
	values('123', date '2018/09/14', 'Abbigliamento', null, 'M');

DROP TABLE IF EXISTS noleggi;
CREATE TABLE noleggi
(
	attrezzatura varchar(3),
	cliente varchar(7),
	comuneC varchar(15),
	data date,
	primary key(attrezzatura, cliente, data),
	foreign key(attrezzatura) references attrezzature(codice),
	foreign key(cliente, comuneC) references clienti(numCI, comune)
);

insert into noleggi
	values('123', '01GH67G', 'Napoli', date '2020/01/03');

DROP TABLE IF EXISTS polize;
CREATE TABLE polize
(
	codice varchar(3) primary key,
	tipo varchar(15),
	capitale int(5),
	cliente varchar(7),
	comuneC varchar(15),
	foreign key(cliente, comuneC) references clienti(numCI, comune)
);

insert into polize
	values('001', 'assicurativa', 101, '01GH67G', 'Napoli');

insert into polize
	values('021', 'incendio', 167, '01GH67G', 'Napoli');

insert into polize
	values('012', 'vita', 360, '01YU37G', 'Verona');


#visualizzare tutte le polize con capitale superiore a "x"
select *
from polize
where capitale > 100;

#visualizzare tutti i clienti fedeli con le relative campagne
select c.*, e.descizione
from clienti c join campagne e on c.campagna=e.codice
where c.tipo='fedele';

#visualizzare tutte le attrezzature noleggiate in data "x"
select a.*
from attrezzature a join noleggi n on a.codice=n.attrezzatura
where n.data='2020/01/03';

#visualizzare tutte le attrezzature noleggiate dai soli clienti che partecipano alla campagna "x"
select  a.*
from attrezzature a join noleggi n on a.codice=n.attrezzatura join clienti c on c.numCI=n.cliente and c.comune=n.comuneC
where c.campagna='124';

#visualizzarre le 3 polize più costose
select *
from polize
order by capitale desc
limit 3;






