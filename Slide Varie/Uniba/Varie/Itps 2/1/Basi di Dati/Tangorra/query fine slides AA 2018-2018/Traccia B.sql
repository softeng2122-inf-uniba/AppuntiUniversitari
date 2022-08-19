create database tracciaB_cinema;
use tracciaB_cinema;
#creazione tabelle
create table regista (id_regista varchar(5) primary key, nome varchar(20), cognome varchar(20));
create table film (id_film varchar(5) primary key, titolo varchar(40), genere varchar(40), regista varchar (5), annoproduzione varchar(4), foreign key(regista) references regista(id_regista), unique (titolo,regista));
create table attore(id_attore varchar(5) primary key,  nome varchar(20), cognome varchar(20));
create table partecipazione(film varchar(5), attore varchar(5), primary key(film,attore), foreign key (film) references film(id_film), foreign key (attore) references attore(id_attore));

select * from regista;

#popolamento tabella regista
INSERT INTO `tracciab_cinema`.`regista` VALUES ('0000A', 'Steven', 'Spilberg');
INSERT INTO `tracciab_cinema`.`regista` VALUES ('0000B', 'Stanley', 'Kubric');
INSERT INTO `tracciab_cinema`.`regista` VALUES ('0000C', 'Ridley', 'Scott');
#popolamento tabella film
INSERT INTO `tracciab_cinema`.`film` (`id_film`, `titolo`, `genere`, `regista`, `annoproduzione`) VALUES ('00A', 'Jurassic Park', 'avventura', '0000A', '2000');
INSERT INTO `tracciab_cinema`.`film` (`id_film`, `titolo`, `genere`, `regista`, `annoproduzione`) VALUES ('00B', 'Matrix', 'fantascienza', '0000B', '2001');
INSERT INTO `tracciab_cinema`.`film` (`id_film`, `titolo`, `genere`, `regista`, `annoproduzione`) VALUES ('00C', 'Star Wars', 'fantascienza', '0000A', '2000');
INSERT INTO `tracciab_cinema`.`film` (`id_film`, `titolo`, `genere`, `regista`, `annoproduzione`) VALUES ('00D', 'Indiana Jones', 'avventura', '0000B', '2002');
INSERT INTO `tracciab_cinema`.`film` (`id_film`, `titolo`, `genere`, `regista`, `annoproduzione`) VALUES ('00E', 'Rambo', 'avventura', '0000A', '2002');
INSERT INTO `tracciab_cinema`.`film` (`id_film`, `titolo`, `genere`, `regista`, `annoproduzione`) VALUES ('00F', 'Rocky I', 'sportivo', '0000A', '2001');
INSERT INTO `tracciab_cinema`.`film` (`id_film`, `titolo`, `genere`, `regista`, `annoproduzione`) VALUES ('00G', 'Rocky II', 'sportivo', '0000B', '2004');


#popolamento tabella attore
INSERT INTO `tracciab_cinema`.`attore` (`id_attore`, `nome`, `cognome`) VALUES ('000AA', 'Sylvester', 'Stallone');
INSERT INTO `tracciab_cinema`.`attore` (`id_attore`, `nome`, `cognome`) VALUES ('000AB', 'Brad', 'Pitt');
INSERT INTO `tracciab_cinema`.`attore` (`id_attore`, `nome`, `cognome`) VALUES ('000AC', 'George', 'Clooney');
INSERT INTO `tracciab_cinema`.`attore` (`id_attore`, `nome`, `cognome`) VALUES ('000AD', 'Demi', 'Moore');
INSERT INTO `tracciab_cinema`.`attore` (`id_attore`, `nome`, `cognome`) VALUES ('000AE', 'Bruce', 'Willis');
INSERT INTO `tracciab_cinema`.`attore` (`id_attore`, `nome`, `cognome`) VALUES ('000AF', 'Monica', 'Bellucci');

#POPOLAMENTO TABELLA PARTECIPAZIONE
INSERT INTO `tracciab_cinema`.`partecipazione` (`film`, `attore`) VALUES ('00A', '000AA');
INSERT INTO `tracciab_cinema`.`partecipazione` (`film`, `attore`) VALUES ('00B', '000AB');
INSERT INTO `tracciab_cinema`.`partecipazione` (`film`, `attore`) VALUES ('00C', '000AC');
INSERT INTO `tracciab_cinema`.`partecipazione` (`film`, `attore`) VALUES ('00D', '000AD');
INSERT INTO `tracciab_cinema`.`partecipazione` (`film`, `attore`) VALUES ('00E', '000AA');
INSERT INTO `tracciab_cinema`.`partecipazione` (`film`, `attore`) VALUES ('00F', '000AA');
INSERT INTO `tracciab_cinema`.`partecipazione` (`film`, `attore`) VALUES ('00G', '000AB');
INSERT INTO `tracciab_cinema`.`partecipazione` (`film`, `attore`) VALUES ('00A', '000AC');
INSERT INTO `tracciab_cinema`.`partecipazione` (`film`, `attore`) VALUES ('00B', '000AA');
INSERT INTO `tracciab_cinema`.`partecipazione` (`film`, `attore`) VALUES ('00C', '000AB');
INSERT INTO `tracciab_cinema`.`partecipazione` (`film`, `attore`) VALUES ('00D', '000AB');


#aggiungo data nascita
alter table attore add column data date not null;
UPDATE `tracciab_cinema`.`attore` SET `data` = '1960-02-5' WHERE (`id_attore` = '000AA');
UPDATE `tracciab_cinema`.`attore` SET `data` = '1985-08-15' WHERE (`id_attore` = '000AB');
UPDATE `tracciab_cinema`.`attore` SET `data` = '1998-04-21' WHERE (`id_attore` = '000AC');
UPDATE `tracciab_cinema`.`attore` SET `data` = '1990-12-12' WHERE (`id_attore` = '000AD');
UPDATE `tracciab_cinema`.`attore` SET `data` = '1967-11-10' WHERE (`id_attore` = '000AE');
UPDATE `tracciab_cinema`.`attore` SET `data` = '1956-11-22' WHERE (`id_attore` = '000AF');



#interrogazioni
#Titolo dei film prodotti nel 2000 o nel 2001, di genere fantascienza; 
select titolo from film where genere = "fantascienza" and annoproduzione between "2000" and "2001"; 
#Cognome degli attori in ordine alfabetico, con i titoli dei film a cui hanno partecipato, e loro età al momento della partecipazione alla produzione del film (convenzionalmente datata al 30 giugno);
create view film_attori as select * from film inner join partecipazione on film.id_film = partecipazione.film inner join attore on attore.id_attore = partecipazione.attore;
SELECT cognome,titolo, TIMESTAMPDIFF(YEAR,data,CONCAT(annoproduzione, '-06-30')) AS eta FROM film_attori ORDER BY cognome;
#Titolo dei film con almeno 2 attori; 
select titolo, count(id_attore) as numAttori from film_attori group by titolo having numAttori > 1 ;
#Nome e cognome dei registi che non hanno girato alcun film e degli attori che non hanno partecipato ad alcun film; 
create view persone as select id_regista as id, nome,cognome from regista union select id_attore as id, nome,cognome from attore;
select id, nome,cognome from persone where id not in (select regista as id from film union select attore as id from partecipazione);

#Cognome e nome degli attori con il più alto numero di partecipazioni a film. 
select nome,cognome, count(film) from attore inner join partecipazione on attore.id_attore = partecipazione.attore group by attore;















