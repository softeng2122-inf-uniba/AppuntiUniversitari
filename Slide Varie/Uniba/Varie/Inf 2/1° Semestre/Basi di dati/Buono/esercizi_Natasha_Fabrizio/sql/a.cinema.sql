DROP SCHEMA IF EXISTS saleCinematografiche;
CREATE SCHEMA saleCinematografiche;
USE saleCinematografiche;

DROP TABLE IF EXISTS registi;
CREATE TABLE registi
(
	codice varchar(3) PRIMARY KEY,
	nome varchar(10),
	cognome varchar(10),
	annoNascita varchar(4)
);

INSERT INTO registi
VALUES ('011', 'Antonio', 'Rossi', '1968');

DROP TABLE IF EXISTS generi;
CREATE TABLE generi
(
	codice varchar(5) PRIMARY KEY,
	nome varchar(10)
);

INSERT INTO generi
VALUES ('00001', 'Drammatico');

INSERT INTO generi
VALUES ('00005', 'Giallo');

DROP TABLE IF EXISTS film;
CREATE TABLE film
(
	titolo varchar(15) PRIMARY KEY,
	nazionalita varchar(10),
	genere varchar(5),
	regista varchar(3),
	FOREIGN KEY (genere) references generi(codice),
	FOREIGN KEY (regista) references registi(codice)
);

INSERT INTO film
VALUES ('Come Ieri', 'Italiana', '00001', '011');

INSERT INTO film
VALUES ('Finalmente', 'Italina', '00001', '011');

DROP TABLE IF EXISTS cinema;
CREATE TABLE cinema
(
	nome varchar(15) PRIMARY KEY,
	indirizzo varchar(20),
	telefono varchar(13)
);

INSERT INTO cinema
VALUES ('Grande Sala', 'via Roma, 5', '+393383456789');

DROP TABLE IF EXISTS sale;
CREATE TABLE sale
(
	codice varchar(3),
	posti int(3),
	giornata varchar(50),
	oraInizio time,
	cinema varchar(15),
	PRIMARY KEY (codice, cinema),
	FOREIGN KEY (cinema) references cinema(nome)
);

INSERT INTO sale
VALUES ('000', 50, 'Maratona X', '18:20', 'Grande Sala');

INSERT INTO sale
VALUES ('001', 70, 'Memoria', '17:00', 'Grande Sala');

DROP TABLE IF EXISTS proiezioni;
CREATE TABLE proiezioni
(
	sala varchar(3),
	film varchar(15),
	cinema varchar(15),
	PRIMARY KEY (sala, film, cinema),
	FOREIGN KEY (sala, cinema) references sale(codice, cinema),
	FOREIGN KEY (film) references film(titolo)
);

INSERT INTO proiezioni
VALUES ('000', 'Come Ieri', 'Grande Sala');


select p.film
from  sale s join proiezioni p on s.codice=p.sala and s.cinema=p.cinema join film f on p.film=f.titolo 
join registi r on f.regista=r.codice
where s.codice = '000';

select s.codice, s.posti, s.giornata, s.oraInizio, s.cinema
from sale s 
where s.cinema = 'Grande Sala';

select *
from sale s
where s.posti > 50;

select concat(s.codice,' ', s.posti,' ', s.giornata,' ', s.oraInizio) as 'sala', p.film, concat(r.nome,' ',r.cognome) as 'registac' 
from cinema c join sale s on c.nome=s.cinema join proiezioni p on s.codice=p.sala and s.cinema=p.cinema join film f on p.film=f.titolo
join registi r on f.regista=r.codice
where c.nome = 'Grande Sala';