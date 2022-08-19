DROP SCHEMA IF EXISTS corsiFormazione;
CREATE SCHEMA corsiFormazione;
USE corsiFormazione;

DROP TABLE IF EXISTS docenti;
CREATE TABLE docenti
(
	cf varchar(16) primary key,
	nome varchar(10),
	cognome varchar(10),
	dataNascita date,
	residenza varchar(15),
	disciplina varchar(10),
	livello varchar(10),
	telefono varchar(15),
	note varchar(30) default null
);

insert into docenti
values ('12ED6T', 'Federica', 'Finn', date '1989/06/17', 'Salice', 'matematica', 'superiore', '3313456768', null);

insert into docenti
values ('12ET5F', 'Ciro', 'Dalo', date '1970/12/07', 'Lecce', 'italiano', 'base', '3334355768', null);

DROP TABLE IF EXISTS corsi;
CREATE TABLE corsi
(
	codice varchar(5),
	ente varchar(10),
	titolare varchar(16),
	titolo varchar(15),
	annoSvolgimento int(4),
	dataInizio date,
	primary key(codice, ente),
	foreign key(titolare) references docenti(cf)
);

insert into corsi
values ('001', 'boh', '12ET5F', 'Formazione', '2017', date '2017/01/07');

insert into corsi
values ('003', 'boh1', '12ED6T', 'AESO', '2019', date '2019/02/08');

insert into corsi
values ('002', 'boh2', '12ET5F', 'Inglese', '2019', date '2019/11/07');

DROP TABLE IF EXISTS docenze;
CREATE TABLE docenze
(
	docente varchar(16),
	codiceCorso varchar(5),
	enteCorso varchar(10),
	mese int(2),
	stipendio int(5),
	oreLezioni decimal(5),
	primary key(docente, codiceCorso, enteCorso, mese),
	foreign key(docente) references docenti(cf),
	foreign key(codiceCorso, enteCorso) references corsi(codice, ente)
);

insert into docenze
values ('12ET5F', '002', 'boh2', '02', 20000, 3.00);

insert into docenze
values ('12ED6T', '001', 'boh', '02', 15600, 3.45);

insert into docenze
values ('12ED6T', '003', 'boh1', '03', 1600, 1.15);

DROP TABLE IF EXISTS partecipanti;
CREATE TABLE partecipanti
(
	codice varchar(5) primary key,
	cf varchar(16),
	nome varchar(10),
	cognome varchar(10),
	luogoNascita varchar(10),
	dataNascita date,
	residenza varchar(15),
	titoloStudio varchar(15)
);

insert into partecipanti
values ('01', '23FR6T8', 'Claudio', 'Ren', 'Taranto', date '1990/09/19', 'Otranto', 'Laureando');

insert into partecipanti
values ('03', '23FS5E8', 'Rino', 'Zero', 'Lecce', date '1993/11/29', 'Lecce', 'Laureando');

DROP TABLE IF EXISTS frequenze;
CREATE TABLE frequenze
(
	partecipante varchar(5),
	codiceCorso varchar(5),
	enteCorso varchar(10),
	primary key(partecipante, codiceCorso, enteCorso),
	foreign key(partecipante) references partecipanti(codice),
	foreign key(codiceCorso, enteCorso) references corsi(codice, ente)
);

insert into frequenze
values ('01', '002', 'boh2');

insert into frequenze
values ('01', '001', 'boh');

insert into frequenze
values ('03', '002', 'boh2');

DROP TABLE IF EXISTS lezioni;
CREATE TABLE lezioni
(
	codiceCorso varchar(5),
	enteCorso varchar(10),
	partecipante varchar(5),
	mese int(4),
	oreEffettive decimal(5),
	presenza decimal(5),
	primary key(codiceCorso, enteCorso, partecipante, mese),
	foreign key(codiceCorso, enteCorso) references corsi(codice, ente),
	foreign key(partecipante) references partecipanti(codice)
);

insert into lezioni
values ('003', 'boh1', '03', '02', 4.00, 3.40);

insert into lezioni
values ('003', 'boh1', '03', '03', 3.00, 5.00);

select sum(l.presenza) as 'ore totali'
from corsi c join lezioni l on c.codice=l.codiceCorso and c.ente=l.enteCorso join partecipanti p on
l.partecipante=p.codice 
where p.cognome='Zero' and c.titolo='AESO';

select concat(d.nome, ' ', d.cognome) as 'docente'
from docenti d join docenze z on d.cf=z.docente
group by d.cognome
order by sum(z.oreLezioni) desc
limit 1;

select c.titolo as 'corso', concat(d.nome, ' ', d.cognome) as 'docente'
from docenti d join corsi c on d.cf=c.titolare join frequenze f on f.codiceCorso=c.codice and f.enteCorso=c.ente
join partecipanti p on p.codice=f.partecipante
where p.nome = 'Claudio' and p.cognome = 'Ren';

select concat(t.nome, ' ', t.cognome) as 'docente'
from corsi c join docenze d on c.codice=d.codiceCorso and c.ente=d.enteCorso join docenti t on d.docente=t.cf
where c.codice='001';