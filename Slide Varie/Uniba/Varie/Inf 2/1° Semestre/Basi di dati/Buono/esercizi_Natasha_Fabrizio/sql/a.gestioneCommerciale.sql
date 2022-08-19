DROP SCHEMA IF EXISTS offertaTV;
CREATE SCHEMA offertaTV;
USE offertaTV;

DROP TABLE IF EXISTS programmi;
CREATE TABLE programmi
(
	codice varchar(3) primary key,
	prezzo int(3),
	commento text
);

insert into programmi
	values('000', 50, 'bello bello');

insert into programmi
	values('001', 30, 'oh beh');

insert into programmi
	values('002', 160, 'wooow');

DROP TABLE IF EXISTS abbonamenti;
CREATE TABLE abbonamenti
(
	codice varchar(3) primary key,
	dataSottoscrizione date
); 

insert into abbonamenti
	values('010', date '2019/08/28');

insert into abbonamenti
	values('020', date '2020/08/28');

DROP TABLE IF EXISTS decoder;
CREATE TABLE decoder
(
	codice varchar(2) primary key,
	tipo varchar(10),
	dataSostituzione date default null,
	abbonamento varchar(3),
	foreign key(abbonamento) references abbonamenti(codice)
);

insert into decoder
	values('01', 'digitale', null, '010');

DROP TABLE IF EXISTS bollette;
CREATE TABLE bollette
(
	numero varchar(5),
	abbonamento varchar(3),
	dataScadenza date,
	pagamento int(5) default 0,
	data date,
	primary key(numero, abbonamento),
	foreign key(abbonamento) references abbonamenti(codice)
);

insert into bollette
	values('00000', '010', date '2020/08/28', 23, date '2019/09/28');

insert into bollette
	values('00001', '010', date '2020/08/28', 23, date '2019/10/28');

insert into bollette
	values('00002', '010', date '2020/08/28', 22, date '2019/11/30');

insert into bollette
	values('00003', '010', date '2020/08/28', 25, date '2019/12/27');

insert into bollette
	values('00200', '020', date '2020/08/28', 33, date '2020/09/28');

DROP TABLE IF EXISTS acquisti;
CREATE TABLE acquisti
(
	programma varchar(3),
	abbonamento varchar(3),
	data date,
	gratis boolean,
	primary key(programma, abbonamento, data),
	foreign key(programma) references programmi(codice),
	foreign key(abbonamento) references abbonamenti(codice)
);

insert into acquisti
	values('000', '010', date '2019/08/30', true);

insert into acquisti
	values('001', '010', date '2019/09/03', true);


#visualizzare tutti gli abbonamenti che hanno al loro interno, il noleggio di un decoder.
select a.*
from decoder d join abbonamenti a on d.abbonamento=a.codice;

#visualizzare le ultime 3 bollette relative all'abbonamento "x".
select b.*
from bollette b join abbonamenti a on b.abbonamento=a.codice
where a.codice='010'
order by b.numero asc
limit 3;

#visualizzare la spesa totale dell'abbonamento "x".
select sum(p.prezzo + b.pagamento) as 'spesa totale'
from programmi p join acquisti t on p.codice=t.programma join abbonamenti a on a.codice=t.abbonamento 
join bollette b on b.abbonamento=a.codice
where a.codice='010';

#visualizzare tutti i programmi che sono presenti in almeno un abbonamento.
select p.*
from programmi p join acquisti t on p.codice=t.programma join abbonamenti a on a.codice=t.abbonamento;

#visualizzare tutti i programmi che non sono presenti in nessun abbonamento.
select distinct p.*
from programmi p join acquisti t 
where p.codice not in (
    select t.programma
    from acquisti t
);

#visualizzare il numero di programmi sottoscritti nell'abbonamento "x".
select p.*
from programmi p join acquisti t on p.codice=t.programma join abbonamenti a on a.codice=t.abbonamento;
where a.codice='010';

