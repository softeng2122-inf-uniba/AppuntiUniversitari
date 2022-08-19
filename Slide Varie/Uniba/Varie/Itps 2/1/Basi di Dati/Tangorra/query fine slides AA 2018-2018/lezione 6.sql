create database esercizio6;
use esercizio6;

#creo le tabelle;
create table autore (codice varchar (5) primary key, cognome varchar (20), nazione varchar(20));
create table genere (id varchar(5) primary key, nome varchar(20));
create table libro (isbn varchar(5) primary key, nome varchar(50), prezzo float, scaffale int, autore varchar (5), genere varchar (5), foreign key (autore) references autore(codice), foreign key (genere) references genere(id));

alter table autore CHANGE COLUMN nome nazione varchar(20);
show columns from autore;

# popolazione tabelle
insert into autore values ("A1","Baudelaire","Francia"), ("A2","Collodi","Italia"), ("A3","Hack","Italia"), ("A4","Lovercraft","Francia"), ("A5","Poe","USA"),("A6","Threepwood","Caribbean"),("A7","Tolstoy","Russia");
insert into genere values ("1","Romanzo"),("2","Giallo"), ("3","Horror");
insert into libro values ("K01","Gianni & Pinotto",20.10,1,"A1","1");
insert into libro values ("K02","Basi di dati",10,7,"A5","3"),("K03","Boole VS shannon",10,7,"A4","2"), ("K04","Escape From monkey island",34.99,5,"A6","2");
INSERT into libro values ("K05","Vivere a plunder island",15.50,1,"A6","1"), ("K06","Laplace Vs Weistrass",44.20,5,"A2","2"), ("K07","Ma sull'Hessiano c'è vita",15,5,"A5","1");

select * from libro;
#visualizzare il nome ed il genere (id) del libro con prezzo più basso
select libro.nome as titolo, genere.nome as genere from libro inner join genere on libro.genere = genere.id where prezzo = (select min(prezzo) from libro);
#visualizzare la nazione in cui vive l’autore di “Gianni & Pinotto”
select autore.nazione from autore inner join libro on libro.autore = autore.codice where libro.nome = "Gianni & pinotto";
#visualizzare i cognomi degli autori che non hanno libri esposti sugli scaffali
create view vista_libri_completa as select * from autore left join libro on autore.codice = libro.autore;
select cognome from vista_libri_completa where scaffale is null;
#creare una vista con i nomi delle nazioni ed il relativo numero  di autori che ci vivono
create view nazioni as select nazione,count(codice) as conteggio from autore group by nazione;
select * from nazioni;
#utilizzando la vista al punto 4, visualizzare il nome di tutte le nazioni, escludendo quelle in cui il numero di autori è pari al valore massimo
select nazione as nome from nazioni where conteggio != (select max(conteggio) from nazioni);
#visualizzare lo scaffale con il maggior numero di libri
create view vista_scaffali as select scaffale as num_scaffale, count(scaffale) as numlibri from libro group by scaffale;
select * from vista_scaffali;
select num_scaffale, max(numlibri) from vista_scaffali;


