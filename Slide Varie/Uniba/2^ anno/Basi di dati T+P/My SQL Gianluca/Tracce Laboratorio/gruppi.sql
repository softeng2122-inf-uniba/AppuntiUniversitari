#1.Creazione database
drop database if exists gruppi;
create database gruppi;
use gruppi;

create table comune(
	codComune int primary key,
	comune varchar(20)
);

create table persona(
	CF char(2) primary key,
	nome varchar(20),
	cognome varchar(20),
	dataNascita date,
	comune int,
	
	constraint v_comune foreign key (comune) references comune(codComune)
);

create table gruppo(
	ID int,
	proprietario char(2),
	nome varchar(20) not null,
	primary key(ID,proprietario),
	
	constraint v_proprietario foreign key (proprietario) references persona(CF)
);

create table iscrizione(
	membro char(2),
	idGruppo int,
	proprietario char(2),
	dataIscrizione date,
	primary key(membro,idGruppo,proprietario),
	
	
	constraint v_idGruppo foreign key (idGruppo) references gruppo(ID)
	
);

#2.Inserimento Dati

insert into comune values (1,"Bari"),
						(2,"Lecce"),
						(3,"Foggia");
						
insert into persona values("A1","Marco","Bruni","1980-11-10",1),
						("B2","Gianna","Verdi","1981-7-15",3),
						("A5","Marco","Bruni","1975-8-9",2);
						
insert into gruppo values(1,"A1","Salviamo_la_foca"),
						(2,"A1","Cinofili_vs_cinefili"),
						(1,"B2","Forza_Mudu");
						
insert into iscrizione values("B2",1,"A1","2010-10-10"),
						("A5",1,"A1","2010-10-12"),
						("A5",2,"A1","2010-10-15");
						
						
#3.Modifiche al db

alter table gruppo add column maxPartecipanti int;
update gruppo set maxPartecipanti=100 where ID=1 and proprietario="A1";

#4.Interrogazioni

#q1
create view vista_omonimi as
	select CF as O_CF,nome as O_nome,cognome as O_cognome from persona;
	
select distinct nome,cognome from 
persona inner join vista_omonimi on ((nome,cognome)=(O_nome,O_cognome) and not(CF=O_CF));


#q2
create view vista_persone7079 as
	select CF from persona where dataNascita="1970%" or dataNascita="1979%";
	
create view vista_gruppo7079 as
	select idGruppo from 
		iscrizione inner join vista_persone7079 on membro=CF; 

select nome from 
	gruppo inner join vista_gruppo7079 on ID=idGruppo; 
	
#q3
create view vista_gruppi3 as
	select count(membro) as NroIscr,idGruppo,proprietario from iscrizione group by idGruppo;

select nome from 
	gruppo inner join vista_gruppi3 on (ID,gruppo.proprietario)=(idGruppo,vista_gruppi3.proprietario) where NroIscr>=3;
	
#q4
select nome from gruppo where nome not in (select distinct nome from gruppo inner join iscrizione on (ID,gruppo.proprietario)=(idGruppo,iscrizione.proprietario));

#q5

create view vista_corsoMax as
	select max(NroIscr),idGruppo,proprietario from vista_gruppi3;
	
select nome from gruppo inner join vista_corsoMax on (ID,gruppo.proprietario)=(idGruppo,vista_corsoMax.proprietario);

	