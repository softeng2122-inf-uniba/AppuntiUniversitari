create database tracciaC_esami;
use tracciaC_esami;

create table Studente (matricola varchar(5) primary key, nome varchar(30), cognome varchar(30));
create table Docente (ID_doc varchar(5) primary key, nome varchar(30), cognome varchar(30));
create table esame (codice varchar(5) primary key, denominazione varchar(30), docente varchar(5), foreign key (docente) references docente(id_doc));
create table verbale (studente varchar(5), esame varchar(5),voto int check (voto >= 18 and voto <= 30), lode varchar(3) default "no" check (voto = 30) , dataEsame date not null,
		primary key (studente,esame), foreign key (studente) references studente(matricola), foreign key (esame) references esame(codice));

#popolamento studente
INSERT INTO `tracciac_esami`.`studente` (`matricola`, `nome`, `cognome`) VALUES ('00001', 'Maria', 'Verdi');
INSERT INTO `tracciac_esami`.`studente` (`matricola`, `nome`, `cognome`) VALUES ('00002', 'Giuseppe', 'Rossi');
INSERT INTO `tracciac_esami`.`studente` (`matricola`, `nome`, `cognome`) VALUES ('00003', 'Andrea', 'Neri');
INSERT INTO `tracciac_esami`.`studente` (`matricola`, `nome`, `cognome`) VALUES ('00004', 'Marco', 'Bruni');
INSERT INTO `tracciac_esami`.`studente` (`matricola`, `nome`, `cognome`) VALUES ('00005', 'Stefania', 'Bianchi');
#popolamento docente
INSERT INTO `tracciac_esami`.`docente` (`ID_doc`, `nome`, `cognome`) VALUES ('1', 'Francesca', 'Manzoni');
INSERT INTO `tracciac_esami`.`docente` (`ID_doc`, `nome`, `cognome`) VALUES ('2', 'Beppe', 'Garibaldi');
INSERT INTO `tracciac_esami`.`docente` (`ID_doc`, `nome`, `cognome`) VALUES ('3', 'Filippo', 'Baudo');
INSERT INTO `tracciac_esami`.`docente` (`ID_doc`, `nome`, `cognome`) VALUES ('4', 'Marco', 'Scotti');
INSERT INTO `tracciac_esami`.`docente` (`ID_doc`, `nome`, `cognome`) VALUES ('5', 'Antontella', 'Rossi');
#popolamento esame
INSERT INTO `tracciac_esami`.`esame` (`codice`, `denominazione`, `docente`) VALUES ('0A', 'Programmazione', '1');
INSERT INTO `tracciac_esami`.`esame` (`codice`, `denominazione`, `docente`) VALUES ('1B', 'Matematica', '2');
INSERT INTO `tracciac_esami`.`esame` (`codice`, `denominazione`, `docente`) VALUES ('0B', 'Architettura', '3');
INSERT INTO `tracciac_esami`.`esame` (`codice`, `denominazione`, `docente`) VALUES ('2B', 'Statistica', '3');
INSERT INTO `tracciac_esami`.`esame` (`codice`, `denominazione`, `docente`) VALUES ('3Q', 'Basi Di Dati', '4');
#popolamento verbale
INSERT INTO `tracciac_esami`.`verbale` (`studente`, `esame`, `voto`, `dataEsame`) VALUES ('00001', '0A', '29', '2016-11-10');
INSERT INTO `tracciac_esami`.`verbale` (`studente`, `esame`, `voto`, `lode`, `dataEsame`) VALUES ('00002', '0A', '30', 'SI', '2016-11-10');
INSERT INTO `tracciac_esami`.`verbale` (`studente`, `esame`, `voto`, `dataEsame`) VALUES ('00003', '0A', '19', '2016-11-10');
INSERT INTO `tracciac_esami`.`verbale` (`studente`, `esame`, `voto`, `dataEsame`) VALUES ('00001', '0B', '25', '2016-9-5');
INSERT INTO `tracciac_esami`.`verbale` (`studente`, `esame`, `voto`, `lode`, `dataEsame`) VALUES ('00002', '0B', '30', 'SI', '2016-9-5');
INSERT INTO `tracciac_esami`.`verbale` (`studente`, `esame`, `voto`, `dataEsame`) VALUES ('00004', '0B', '18', '2016-9-5');
INSERT INTO `tracciac_esami`.`verbale` (`studente`, `esame`, `voto`, `dataEsame`) VALUES ('00001', '1B', '30', '2016-3-7');
INSERT INTO `tracciac_esami`.`verbale` (`studente`, `esame`, `voto`, `dataEsame`) VALUES ('00002', '1B', '20', '2016-3-7');
INSERT INTO `tracciac_esami`.`verbale` (`studente`, `esame`, `voto`, `lode`, `dataEsame`) VALUES ('00002', '2B', '30', 'SI', '2016-1-10');

 #QUERY
 #Matricola degli studenti che hanno preso la lode all’esame di programmazione prima di agosto 2016 o che hanno preso 30 nel mese di dicembre 2016; 
 create view tabellone_voti as select * from studente inner join verbale on studente.matricola = verbale.studente inner join esame on verbale.esame = esame.codice;
 select * from tabellone_voti where dataEsame < "2016-8-1" and denominazione = "Programmazione"
 union
 select * from tabellone_voti where dataEsame between "2016-12-1" and "2016-12-31" having voto = 30;
 #Esami superati da Giuseppe Rossi nel novembre 2016; 
 select denominazione from tabellone_voti where nome = "giuseppe" and cognome = "Rossi" and dataesame between "2016-11-1" and "2016-11-30";
#Nome (prima lettera maiuscola, resto minuscolo) e cognome (tutto maiuscolo) dei professori chehanno almeno 2 insegnamenti; 
create view doc1 as select nome, upper(cognome), count(denominazione) as num_insegnamento from docente inner join esame on docente.id_Doc = esame.docente group by id_doc order by num_insegnamento ;
select * from doc1 where num_insegnamento > 1;
#Nome e cognome degli studenti che non hanno mai superato un esame che inizia con la lettera p; 
select nome, cognome from studente where matricola not in (select studente from verbale inner join esame on verbale.esame = esame.codice and denominazione like "p%");

select denominazione,count(*) as promossi from verbale inner join esame on esame.codice = verbale.esame  group by denominazione order by promossi ;


