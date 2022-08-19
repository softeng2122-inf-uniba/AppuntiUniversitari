DROP SCHEMA IF EXISTS corsiInglese;
CREATE SCHEMA corsiInglese;
USE corsiInglese;

DROP TABLE IF EXISTS livelli;
CREATE TABLE livelli
(
	nome varchar(15) primary key,
	libro varchar(20),
	esameFinale boolean
);

DROP TABLE IF EXISTS insegnanti;
CREATE TABLE insegnanti
(
	nome varchar(10),
	provenienza varchar(15),
	indirizzo varchar(10),
	primary key(nome, provenienza)
);

DROP TABLE IF EXISTS corsi;
CREATE TABLE corsi
(
	codice varchar(3) primary key,
	attrivazione date,
	iscritti int(5),
	giorni varchar(50),
	insegnante varchar(10),
	provInsegnante varchar(15),
	foreign key(insegnante, provInsegnante) references insegnanti(nome, provenienza)
);	

DROP TABLE IF EXISTS allievi;
CREATE TABLE allievi
(
	nome varchar(10),
	recapito varchar(10),
	assenze int(3),
	corso varchar(3),
	iscrizione date,
	primary key(nome, recapito),
	foreign key(corso) references corsi(codice)
);

DROP TABLE IF EXISTS attivitaCulturali;
CREATE TABLE attivitaCulturali
(
	codice varchar(3) primary key,
	tipologia varchar(30),
	film varchar(15) default null,
	regista varchar(10) default null,
	argormento varchar(30) default null,
	conferenziere varchar(10) default null
);

DROP TABLE IF EXISTS afferenze;
CREATE TABLE afferenze
(
	livello varchar(10),
	corso varchar(3),
	primary key(livello, corso),
	foreign key(livello) references livelli(nome),
	foreign key(corso) references corsi(codice)
);

DROP TABLE IF EXISTS lezioniPrivate;
CREATE TABLE lezioniPrivate
(
	allievo varchar(10),
	recapitoAllievo varchar(10),
	insegnante varchar(10),
	provInsegnante varchar(15),
	data date,
	primary key(allievo, recapitoAllievo, insegnante, provInsegnante),
	foreign key(allievo, recapitoAllievo) references allievi(nome, recapito),
	foreign key(insegnante, provInsegnante) references insegnanti(nome, provenienza)
);

DROP TABLE IF EXISTS inscrizoneAttivita;
CREATE TABLE inscrizoneAttivita
(
	allievo varchar(10),
	recapitoAllievo varchar(10),
	attivita varchar(3),
	primary key(allievo, recapitoAllievo, attivita),
	foreign key(allievo, recapitoAllievo) references allievi(nome, recapito),
	foreign key(attivita) references attivitaCulturali(codice)
);

#visualizzare tutti i corsi con i relativi insegnati e livello.
select c.*, i.indirizzo, l.*
from corsi c join insegnanti i on c.insegnante=i.nome and c.provInsegnante=i.provenienza join afferenze a on a.corso=c.codice 
join livelli l on l.nome=a.livello;

#visualizzare il corso con il maggior numero di partecipanti.
select c.*
from corsi c join allievi a on a.corso=c.codice
group by c.codice
order by count(a.nome) desc
limit 1;

#visualizzare tutte le proiezioni.
select codice, film, regista
from attivitaCulturali
where tipologia='proiezioni';

#visualizzare tutte i partecipanti all'attività "x".
select a.*
from allievi a join inscrizoneAttivita i on i.allievo=a.nome and i.recapitoAllievo=a.recapito join attivitaCulturali ac
on ac.codice=i.attivita
where ac.tipologia='';

#visualizzare gli allievi che partecipando ad una lezione privata.
select a.*
from allievi a join lezioniPrivate l on l.allievo=a.nome and l.recapitoAllievo=a.recapito;
