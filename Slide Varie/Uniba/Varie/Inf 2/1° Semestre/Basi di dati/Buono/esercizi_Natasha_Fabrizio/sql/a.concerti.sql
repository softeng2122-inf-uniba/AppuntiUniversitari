DROP SCHEMA IF EXISTS programmaConcerti;
CREATE SCHEMA programmaConcerti;
USE programmaConcerti;

DROP TABLE IF EXISTS orchestre;
CREATE TABLE orchestre
(
	nome varchar(20) PRIMARY KEY,
	nomeDirettore varchar(10),
	cognomeDirettore varchar(10) 
);

INSERT INTO orchestre
VALUES ('Stereo', 'Dario', 'Bitta');

INSERT INTO orchestre
VALUES ('Galassi', 'Fede', 'Minetti');

DROP TABLE IF EXISTS orchestrali;
CREATE TABLE orchestrali
(
	matricola varchar(5) PRIMARY KEY,
	nome varchar(10),
	cognome varchar(10)
);

INSERT INTO orchestrali
VALUES ('01', 'Renato', 'Zito');

INSERT INTO orchestrali
VALUES ('02', 'Sonia', 'Apolito');

INSERT INTO orchestrali
VALUES ('03', 'Martina', 'Bellomo');

INSERT INTO orchestrali
VALUES ('04', 'Chiara', 'Mondelli');

DROP TABLE IF EXISTS autori;
CREATE TABLE autori
(
	codice varchar(10) PRIMARY KEY,
	nome varchar(20)
);

INSERT INTO autori
VALUES ('111', 'Giorginess');

INSERT INTO autori
VALUES ('333', 'Sticky Fingers');

INSERT INTO autori
VALUES ('222', 'Cub Sport');

DROP TABLE IF EXISTS pezzi;
CREATE TABLE pezzi
(
	codice varchar(5) PRIMARY KEY,
	titolo varchar(20),
	autore varchar(20),
	FOREIGN KEY (autore) references autori(codice)
);

INSERT INTO pezzi
VALUES ('00', 'Maledetta', '111');

INSERT INTO pezzi
VALUES ('01', 'Controllo', '111');

INSERT INTO pezzi
VALUES ('02', 'Vecchi', '111');

INSERT INTO pezzi
VALUES ('12', 'Rum Rage', '333');

INSERT INTO pezzi
VALUES ('14', 'Junk', '333');

INSERT INTO pezzi
VALUES ('23', 'Hearts in Helves', '222');

INSERT INTO pezzi
VALUES ('25', 'Saint', '222');

DROP TABLE IF EXISTS sale;
CREATE TABLE sale
(
	codice varchar(5) PRIMARY KEY,
	nome varchar(10),
	capienza varchar(3)
);

INSERT INTO sale
VALUES ('09', 'Sala A', 50);

INSERT INTO sale
VALUES ('19', 'Sala B', 100);

INSERT INTO sale
VALUES ('29', 'Sala C', 20);

DROP TABLE IF EXISTS concerti;
CREATE TABLE concerti
(
	codice varchar(10) PRIMARY KEY,
	titolo varchar(15),
	descrizione text DEFAULT NULL,
	orchestra varchar(20),
	FOREIGN KEY (orchestra) references orchestre(nome)
);

INSERT INTO concerti
VALUES ('1', 'BOOM', 'AOOOO', 'Stereo');

INSERT INTO concerti
VALUES ('2', 'GREAT', 'wooow', 'Stereo');

INSERT INTO concerti
VALUES ('3', 'Gesu 3.0', 'Amen', 'Galassi');

DROP TABLE IF EXISTS tenuti;
CREATE TABLE tenuti
(
	concerto varchar(10),
	sala varchar(5),
	data date PRIMARY KEY,
	FOREIGN KEY (concerto) references concerti(codice),
	FOREIGN KEY (sala) references sale(codice)
);

INSERT INTO tenuti
VALUES ('1', '09', date '2001/09/11');

INSERT INTO tenuti
VALUES ('1', '09', date '2002/08/17');

INSERT INTO tenuti
VALUES ('3', '29', date '1990/11/03');

DROP TABLE IF EXISTS composizioni;
CREATE TABLE composizioni
(
	orchestra varchar(20),
	orchestrale varchar(5),
	strumento varchar(10),
	PRIMARY KEY (orchestra, orchestrale),
	FOREIGN KEY (orchestra) references orchestre(nome),
	FOREIGN KEY (orchestrale) references orchestrali(matricola)
);

INSERT INTO composizioni
VALUES ('Galassi', '01', 'Violino');

INSERT INTO composizioni
VALUES ('Galassi', '03', 'Chitarra');

INSERT INTO composizioni
VALUES ('Galassi', '04', 'Piano');

INSERT INTO composizioni
VALUES ('Stereo', '03', 'Basso');

INSERT INTO composizioni
VALUES ('Stereo', '02', 'Arpa');

DROP TABLE IF EXISTS scalette;
CREATE TABLE scalette
(
	concerto varchar(10),
	traccia varchar(5),
	numTrack int(3),
	PRIMARY KEY (concerto, traccia),
	FOREIGN KEY (concerto) references concerti(codice),
	FOREIGN KEY (traccia) references pezzi(codice)
);

INSERT INTO scalette
VALUES ('3', '00', 1);

INSERT INTO scalette
VALUES ('3', '01', 3);

INSERT INTO scalette
VALUES ('3', '02', 2);

INSERT INTO scalette
VALUES ('1', '12', 1);

INSERT INTO scalette
VALUES ('1', '14', 2);

INSERT INTO scalette
VALUES ('2', '23', 2);

INSERT INTO scalette
VALUES ('2', '25', 1);


select p.titolo as 'pezzo', a.nome as 'autore'
from pezzi p join autori a on p.autore=a.codice;

select p.titolo as 'pezzi concerto', s.numTrack, a.nome as 'autore'
from concerti c join scalette s on s.concerto=c.codice join pezzi p on p.codice=s.traccia 
join autori a on a.codice=p.autore
where c.titolo = 'Gesu 3.0' 
order by s.numTrack;

select c.titolo, s.nome, t.data
from concerti c join tenuti t on t.concerto=c.codice join sale s on s.codice=t.sala;

select o.nome, o.cognome
from orchestrali o join composizioni c on o.matricola=c.orchestrale
where c.strumento = 'Chitarra';

select o.nome as 'orchestra', e.nome as 'orchestrale', p.strumento as 'strumento'
from concerti c join tenuti t on c.codice=t.concerto join sale s on t.sala=s.codice 
join orchestre o on c.orchestra=o.nome join composizioni p on o.nome=p.orchestra 
join orchestrali e on p.orchestrale=e.matricola
where c.titolo = 'Gesu 3.0';

select s.nome as 'sala', o.nome as 'orchestra', e.nome as 'orchestrale', p.strumento, sc.traccia, a.nome as 'autore'
from concerti c join tenuti t on c.codice=t.concerto join sale s on t.sala=s.codice 
join orchestre o on c.orchestra=o.nome join composizioni p on o.nome=p.orchestra 
join orchestrali e on p.orchestrale=e.matricola join scalette sc on c.codice=sc.concerto
join pezzi tr on tr.codice=sc.traccia join autori a on a.codice=tr.autore
where c.titolo = 'BOOM';