#crea database
create database if not exists cinema;
use cinema;

#creazione tabelle
create table regista(
	id_regista char(5) primary key,
	nome varchar(30), 
	cognome varchar(30) not null
	);
	
create table film(
	id_film char(3) primary key,
	titolo varchar(30),
	genere varchar(30) not null,
	regista char(5),
	anno_produzione int,
	unique(titolo, regista),
	
	constraint v_regista foreign key(regista) references regista(id_regista)
	);
	
create table attore(
	id_attore char(5) primary key,
	nome varchar(30),
	cognome varchar(30) not null
	);
	
create table partecipazione(
	film char(3),
	attore char(5),
	primary key(film, attore),
	
	constraint v_film foreign key(film) references film(id_film),

	constraint v_attore foreign key(attore) references attore(id_attore)
	);

	
#inserimento valori nelle tabelle
insert into regista values("0000A", "Steven", "Spielberg"),
							("0000B", "Stanley", "Kubrick"),
							("0000C", "Ridley", "Scott");
							
insert into attore values("000AA", "Sylvester", "Stallone"),
							("000AB", "Brad", "Pitt"),
							("000AC", "George", "Clooney"),
							("000AD", "Demi", "Moore"),
							("000AE", "Bruce", "Willis"),
							("000AF", "Monica", "Bellucci");
							
insert into film values("00A", "Jurassic Park", "Avventura", "0000A", 2000),
						("00B", "Matrix", "Fantascienza", "0000B", 2001),
						("00C", "Star Wars", "Fantascienza", "0000A", 2000),
						("00D", "Indiana Jones", "Avventura", "0000B", 2002),
						("00E", "Rambo", "Avventura", "0000A", 2002),
						("00F", "RockyI", "Sportivo", "0000A", 2001),
						("00G", "RockyII", "Sportivo", "0000B", 2004);
						
insert into partecipazione values("00A", "000AA"),
								("00B", "000AB"),
								("00C", "000AC"),
								("00D", "000AD"),
								("00E", "000AA"), 
								("00F", "000AA"),
								("00G", "000AB"),
								("00A", "000AC"), 
								("00B", "000AA"), 
								("00C", "000AB"), 
								("00D", "000AB");


#punto 3;
alter table attore add column dataNascita int;
update attore set dataNascita=1950 where id_attore="000AA";
update attore set dataNascita=1953 where id_attore="000AB";
update attore set dataNascita=1954 where id_attore="000AC";
update attore set dataNascita=1956 where id_attore="000AD";
update attore set dataNascita=1957 where id_attore="000AE";
update attore set dataNascita=1958 where id_attore="000AF";


#Interrogazioni


#q1
select titolo from film 
	where genere="Fantascienza" and (anno_produzione="2000" or anno_produzione="2001");
	
#q2
create view vista_Ordinata as
	select distinct cognome,film from 
	attore inner join partecipazione on id_attore=attore order by cognome asc;
	
create view vista_Ordinata2 as
	select distinct cognome,titolo,anno_produzione from
	vista_Ordinata inner join film on film=id_film;
	
create view vista_OrdinataFinale as
	select distinct vista_Ordinata2.cognome, titolo, (anno_produzione)-(dataNascita) as anni_durante_riprese from
	vista_Ordinata2 inner join attore on vista_Ordinata2.cognome=attore.cognome;
	

#q3
create view vista_NroAttori as
	select count(attore) as NroAttori,film from partecipazione group by film;
 
select titolo from (film inner join vista_NroAttori on id_film=film)
	where NroAttori>=2;
	
#q4
select nome, cognome from regista 
	where id_regista not in
	(select regista from film);
	
select nome, cognome from attore 
	where id_attore not in
	(select attore from partecipazione);
	
#q5
create view vista_NroFilm as
	select count(film) as NroFilm,attore from partecipazione group by attore;
	
select cognome,nome from 
	attore inner join vista_NroFilm on id_attore=attore
	where NroFilm=(select max(NroFilm) from vista_NroFilm);



