DROP SCHEMA IF EXISTS 717446FabrizioNatashaDB;
CREATE SCHEMA 717446FabrizioNatashaDB;
USE 717446FabrizioNatashaDB;

DROP TABLE IF EXISTS orchestre;
CREATE TABLE orchestre
(
	nome varchar(10) primary key,
	tipologia varchar(20)
);

insert into orchestre
	values('LA', 'lirica');

insert into orchestre
	values('OFF', 'gtn');

insert into orchestre
	values('Fina', 'classica');

DROP TABLE IF EXISTS musicisti;
CREATE TABLE musicisti
(
	codice varchar(3) primary key,
	nome varchar(10),
	annoNascita varchar(4)
);

insert into musicisti
	values('001', 'Saverio', '1989');

insert into musicisti
	values('002', 'Marta', '1979');

insert into musicisti
	values('003', 'Martina', '1999');

DROP TABLE IF EXISTS strumenti;
CREATE TABLE strumenti
(
	sigla varchar(5) primary key,
	descrizione varchar(50)
);

insert into strumenti
	values('FMN', 'bassi particolari');

insert into strumenti
	values('CFN', 'legno a tre strati');

insert into strumenti
	values('FUI', 'suoni acuti');

insert into strumenti
	values('FTI', 'quattro corde');

DROP TABLE IF EXISTS configurazioni;
CREATE TABLE configurazioni
(
	musicista varchar(3),
	orchestra varchar(10),
	strumento varchar(5),
	stagione varchar(4),
	primary key(musicista, orchestra, strumento, stagione),
	foreign key(musicista) references musicisti(codice),
	foreign key(orchestra) references orchestre(nome),
	foreign key(strumento) references strumenti(sigla)
);

insert into configurazioni
	values('001', 'LA', 'FUI', '2020');

insert into configurazioni
	values('001', 'LA', 'FTI', '2020');

insert into configurazioni
	values('002', 'Fina', 'FMN', '1999');

insert into configurazioni
	values('003', 'Fina', 'FTI', '1999');

/*
DROP TABLE IF EXISTS suonati;
CREATE TABLE suonati
(
	musicista varchar(3),
	strumento varchar(5),
	primary key(musicista, strumento),
	foreign key(musicista) references musicisti(codice),
	foreign key(strumento) references strumenti(sigla)
);

insert into suonati
	values('001', 'FUI');

insert into suonati
	values('001', 'CFN');

insert into suonati
	values('002', 'FMN');

insert into suonati
	values('003', 'FTI');


#a
select m.nome, s.*
from musicisti m join suonati t on m.codice=t.musicista join strumenti s on s.sigla=t.strumento;
*/

#a
select m.nome, s.*
from musicisti m join configurazioni c on c.musicista=m.codice join strumenti s on c.strumento=s.sigla;

#b
select m.nome, c.strumento
from musicisti m join configurazioni c on m.codice=c.musicista
where c.orchestra='LA'
group by c.strumento ;

#c
select m.nome, c.stagione
from musicisti m join configurazioni c on c.musicista=m.codice
where c.orchestra='Fina';

		