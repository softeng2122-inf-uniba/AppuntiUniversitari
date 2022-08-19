DROP SCHEMA IF EXISTS spettacolo;
CREATE SCHEMA spettacolo;
USE spettacolo;

DROP TABLE IF EXISTS spettacoli;
CREATE TABLE spettacoli
(
	nome varchar(15) primary key,
	regista varchar(10)
);

DROP TABLE IF EXISTS teatri;
CREATE TABLE teatri
(
	nome varchar(15) primary key,
	indirizzo varchar(20),
	telefono varchar(10),
	paginaWeb varchar(50) default null,
	fax varchar(10)
);

DROP TABLE IF EXISTS allestiti;
CREATE TABLE allestiti
(
	spettacolo varchar(15),
	teatro varchar(15),
	inizio date,
	fine date,
	primary key(spettacolo, teatro, inizio),
	foreign key(spettacolo) references spettacoli(nome),
	foreign key(teatro) references teatri(nome)
);

DROP TABLE IF EXISTS attori;
CREATE TABLE attori
(
	nome varchar(10),
	spettacolo varchar(15),
	primary key(nome, spettacolo),
	foreign key(spettacolo) references spettacoli(nome)
);

DROP TABLE IF EXISTS biglietti;
CREATE TABLE biglietti
(
	numPosto varchar(3), 
	data date,
	spettacolo varchar(15),
	tipo varchar(20),
	primary key(numPosto, data, spettacolo),
	foreign key(spettacolo) references spettacoli(nome)
);

DROP TABLE IF EXISTS abbonamenti;
CREATE TABLE abbonamenti
(
	indice varchar(5) primary key,
	tipo varchar(10),
	costo int(3)
);

DROP TABLE IF EXISTS persone;
CREATE TABLE persone
(
	CF varchar(16) primary key,
	nome varchar(10),
	recapito varchar(10),
	cartaCredito varchar(7) default null,
	abbonamento varchar(5),
	foreign key(abbonamento) references abbonamenti(indice)
);

DROP TABLE IF EXISTS prevendite;
CREATE TABLE prevendite
(
	persona varchar(16),
	posto varchar(3),
	data date,
	spettacolo varchar(15),
	primary key(persona, posto, data, spettacolo),
	foreign key(persona) references persone(CF),
	foreign key(posto, data, spettacolo) references biglietti(numPosto, data, spettacolo)
);

#visualizzare tutte le persone che hanno acquistato un abbonamento.
select *
from persone p join abbonamenti a on p.abbonamento=a.indice;

#visualizzare tutte le persone che hanno assistito allo spettacolo "x".


#visualizzare tutti gli spettacoli tenuti nel teatro "x".
#visualizzare tutte le persone che hanno acquistato un biglietto in fila "x" dello spettacolo "x".
#visualizzare tutte le persone che non hanno mai visto uno spettacolo nel teatro "x".










