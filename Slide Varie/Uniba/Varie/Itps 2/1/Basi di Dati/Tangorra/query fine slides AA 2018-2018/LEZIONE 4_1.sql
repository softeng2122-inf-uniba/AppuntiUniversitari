show databases;
select * from attori;

create database esercizio;
use esercizio;
create table attori (Nome varchar(15), Cognome varchar(15));
create table registi (Nome varchar(15), Cognome varchar(15));
insert into attori values ("Sylvester","Stallone"), ("George","Clooney"), ("Woody", "Allen"), ("Tom","Cruise"),("Pippo","Franco");
insert into registi values ("Sylvester","Stallone"), ("George","Clooney"), ("Woody", "Allen"), ("Tom","Cruise"),("Pippo","Franco");
select nome,cognome from attori where nome = "pippo" or nome = "tom";
select nome,cognome from attori where nome = "tom" and cognome = "cruise";
select nome,cognome from registi order by cognome,nome;
select cognome from registi where nome = "george";