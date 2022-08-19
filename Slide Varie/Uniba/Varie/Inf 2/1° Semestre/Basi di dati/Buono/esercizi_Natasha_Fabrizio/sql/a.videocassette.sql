DROP SCHEMA IF EXISTS noleggioVideocassette;
CREATE SCHEMA noleggioVideocassette;
USE noleggioVideocassette;

DROP TABLE IF EXISTS centriServizio;
CREATE TABLE centriServizio
(
	codice varchar(3) primary key,
	indirizzo varchar(15),
	telefono varchar(10)
);

DROP TABLE IF EXISTS impiegati;
CREATE TABLE impiegati
(
	CF varchar(16) primary key,
	nome varchar(10),
	titoloStudio varchar(20),
	recapito varchar(10)
);

DROP TABLE IF EXISTS settori;
CREATE TABLE settori
(
	codice varchar(4),
	codiceCentro varchar(3),
	primary key(codice, codiceCentro),
	foreign key(codiceCentro) references centriServizio(codice)
);

DROP TABLE IF EXISTS film;
CREATE TABLE film
(
	titolo varchar(15),
	regista varchar(10),
	annoRegistrazione varchar(4),
	attoriPrincipali text,
	costoNoleggio decimal(2),
	remake boolean,
	settore varchar(4),
	centroS varchar(3),
	posizioneSettore varchar(10),
	copie int(5),
	primary key(titolo, regista),
	foreign key(settore, centroS) references settori(codice, codiceCentro)
);

DROP TABLE IF EXISTS centriDistribuzione;
CREATE TABLE centriDistribuzione
(
	codice varchar(3) primary key,
	nome varchar(10),
	recapito varchar(10)
);

DROP TABLE IF EXISTS forniture;
CREATE TABLE forniture
(
	film varchar(15),
	regista varchar(10),
	fornitore varchar(3),
	costo decimal(2),
	primary key(film, regista, fornitore), 
	foreign key (film, regista) references film(titolo, regista),
	foreign key(fornitore) references centriDistribuzione(codice) 
);

DROP TABLE IF EXISTS impieghi;
CREATE TABLE impieghi
(
	centroServizio varchar(3),
	impiegato varchar(16),
	carica varchar(15),
	inizio date,
	fine date,
	primary key(centroServizio, impiegato, inizio),
	foreign key(centroServizio) references centriServizio(codice),
	foreign key(impiegato) references impiegati(CF)
);

#visualizzare tutti i film, catalogati per registra.
select *
from film
group by regista;

#visualizzare tutti i film ordinati per anno, partendo dal più recente.
select *
from film
order by annoRegistrazione desc;

#visualizzare tutti i film del registra "x" e anche il relativo distributore.
select f.*, r.fornitore
from film f join forniture r on f.titolo=r.film and f.regista=r.regista 
where f.regista='';

#visualizzare tutti gli impiegati che nel 2020 nel centro "x".
select i.*
from impiegati i join impieghi m on i.CF=m.impiegato
where m.inizio='2020' and m.centroServizio='';

#visualizzare il film con il noleggio più costoso.
select titolo
from film
group by titolo
order by costoNoleggio desc
limit 1;

#visualizzare tutti i film che hanno ricevuto un remake, indicando le informazioni del film originale e del suo remake.
select *
from film
where remake = true;

#dato un film "x", visualizzare il settore in cui è collocato, il distributore e il relativo registra.
select f.settore, cd.nome as 'distributore', f.regista
from film f join forniture r on f.titolo=r.film and f.regista=r.regista join centriDistribuzione cd on cd.codice=r.fornitore
where f.titolo='';

























