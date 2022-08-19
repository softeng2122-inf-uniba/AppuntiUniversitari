#1.Creazione database

create database if not exists esami;
use esami;

create table docente(
	IDdoc int,
	nome varchar(20),
	cognome varchar(20) not null,
	primary key(IDdoc)
);

create table studente(
	matricola int(5) zerofill,
	nome varchar(20),
	cognome varchar(20) not null,
	primary key(matricola)
);

create table esame(
	codice char(2),
	denominazione varchar(20),
	docente int not null,
	primary key(codice),
	
	constraint v_docente foreign key (docente) references docente(IDdoc)
);

create table verbale(
	studente int(5) zerofill,
	esame char(2),
	voto tinyint,
	lode bit,
	dataEsame date,
	primary key(studente,esame),
	
	constraint v_studente foreign key (studente) references studente(matricola),
	constraint v_esame foreign key (esame) references esame(codice)
);

#2.Inserimento dati

insert into docente values(1,"Francesca","Mazoni"),
							(2,"Beppe","Garibaldi"),
							(3,"Filippo","Baudo"),
							(4,"Marco","Scotti"),
							(5,"Antonella","Rossi");
							
insert into studente values(00001,"Maria","Verdi"),
							(00002,"Giuseppe","Rossi"),
							(00003,"Andrea","Neri"),
							(00004,"Marco","Bruni"),
							(00005,"Stefania","Bianchi");
							
insert into esame values("0A","Programmazione",1),
							("1B","Matematica",2),
							("0B","Architettura",3),
							("2B","Statistica",3),
							("3Q","Basi Di Dati",4);
							
insert into verbale values(00001,"0A",29,0,"2016-11-10"),
							(00002,"0A",30,1,"2016-11-10"),
							(00003,"0A",19,0,"2016-11-10"),
							(00001,"0B",25,0,"2016-09-05"),
							(00002,"0B",30,1,"2016-09-05"),
							(00004,"0B",18,0,"2016-09-05"),
							(00001,"1B",30,0,"2016-03-07"),
							(00002,"1B",20,0,"2016-03-07"),
							(00002,"2B",30,1,"2016-01-10");
							
							
							
#3.Interrogazioni

#q1
create view vista_verbale as
	select * from verbale 
		where (esame="0A" and lode=1 and (dataEsame between 2016-01-01 and 2016-08-01)) or (voto=30 and dataEsame="2016-12%");
		
select matricola from
	studente inner join vista_verbale on matricola=studente;
	

#q2
create view vista_giusepperossi as
	select matricola from studente
		where nome="Giuseppe" and cognome="Rossi";
		
create view vista_giusepperossi2 as
	select esame from 
	verbale inner join vista_giusepperossi on studente=matricola;
	
select denominazione as Esami_mat00002 from
esame inner join vista_giusepperossi2 on codice=esame;


#q3
create view vista_professori as
	select count(codice) as NroCorsi,docente from esame group by docente;
 
select nome,upper(cognome) from
	docente inner join vista_professori on IDdoc=docente
	where NroCorsi>=2;

#q4
create view vista_p as
	select codice from esame where denominazione like "P%";
	

create view vista_studenteNP as 
	select distinct studente from verbale where studente not in 
		(select distinct studente from 
		verbale inner join vista_p on esame=codice);
	
	
select distinct nome,cognome from 
	studente inner join vista_studenteNP on matricola=studente;

#q5
create view vista_esame_meno as
	select count(esame) as NroEsSup,esame from verbale;
create view vista_esame_min as
	select min(NroEsSup),esame from vista_esame_meno;
select denominazione from
esame inner join vista_esame_min on codice=esame;

#4.Aggiunta colonna(ERRATO)

alter table studente add column dataNascita date;

create view vista_calcola_eta as
	select min(dataEsame) as minData from verbale where studente=000001;
create view vista_calcola_data as
	select (mindata-200000) as dataN from vista_calcola_eta;
update studente set dataNascita=(20160307-200000);

	
	

