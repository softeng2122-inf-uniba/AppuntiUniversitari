create database esercizio5;
use esercizio5;

drop table prodotti;
drop table sottocategorie;

#creo le tabelle dello schema
create table categorie (idcat varchar(5) primary key , nome varchar(20) );
create table sottocategorie (idsottocat varchar(5) primary key, nome varchar(20), idcat varchar(5), foreign key (idcat) references categorie(idcat));
create table prodotti ( idprod varchar(5) primary key, nome varchar(20), prezzo float, idsottocat varchar(5),foreign key(idsottocat) references sottocategorie(idsottocat));
create table dettagli (idprod varchar(5), idordine varchar(5), quantita int, primary key(idprod,idordine) , foreign key(idprod) references prodotti(idprod));
create table citta (idcitta varchar(5) primary key, nome varchar(20));
create table clienti (idcliente varchar(5) primary key, nome varchar(20), cognome varchar(20), idcitta varchar(5), foreign key (idcitta) references citta(idcitta));
create table ordini (idordine varchar(5) primary key, data varchar(8), idcliente varchar(5), foreign key (idcliente) references clienti (idcliente));
show columns from ordini;

#aggiungo la key alla tabella dettagli
alter table dettagli add constraint fk_dettagli foreign key(idordine) references ordini(idordine);

#popolazione tabelle
#popolazione categorie
insert into categorie values ("CA001","Elettronica"), ("CA002","Cura della persona"), ("CA003","Abbigliamento"), ("CA004","Casa");
#popolazione sottocategorie
insert into sottocategorie values ("SC001","Telefonia","CA001"),("SC002","Computer","CA001"),("SC03","Audio","CA001"), ("SC04","Shampoo","CA002"),("SC05","Balsamo","CA002"), ("SC06","Rasoio","CA002"), ("SC07","Preservativi","CA002"), ("SC08","Bagnoschiuma","CA002");
#faccio una select perchè sono bravo e sicuramente avevo bisogno di verificare di aver inserito bene qualcosa
select categorie.idcat as categoria, categorie.nome as categrie, sottocategorie.nome as sottocategorie, idsottocat from categorie inner join sottocategorie on categorie.idcat = sottocategorie.idcat;
#continuo a popolare
insert into sottocategorie values ("SC09","Maglie","CA003"), ("SC10","Pantaloni","CA003"),("SC11","Scarpe","CA003");
insert into sottocategorie values ("SC12","Candele","CA004"), ("SC13","Sapone per mani","CA004"), ("SC14","Detersivo","CA004"), ("SC15","Deo per Ambienti","CA004");

#popolazione città
insert into citta values ("CT001","Rutigliano"),("CT002","Triggiano"),("CT003","BARI"),("CT004","Massafra");
#popolazione clienti
insert into clienti values ("CL001","Vincenzo","Bixio","CT001"), ("CL002","Antonello","Borracci","CT001"), ("CL003","Piero","Dirutigliano","CT001"), ("CL004","Giuseppe","Delledera","CT001");
insert into clienti values ("CL005","Michaela","Milella","CT002");
insert into clienti values ("CL006","Antonio","Lovergine","CT003"),("CL007","Alessandro","Congedo","CT003"),("CL008","Christian","Buonamico","CT003");
insert into clienti values ("CL009","Simona"," Goffredo ","CT004"), ("CL010","Valeria","Spennato","CT004");
#popolazione ordini
insert into ordini values ("N0001","20180215","CL001"),("N0002","20160215","CL002"),("N0003","20181112","CL003"),("N0004","20110618","CL004"),("N0005","20010911","CL005"),("N0006","20081225","CL006"),("N0007","20190211","CL007"),("N0008","02100502","CL008"),("N0009","20170925","CL009"),("N0010","19980421","CL010");

#DATE LE NUMEROSE SOTTOCATEGORIE HO APPORTATO LE SEGUENTI MODIFICHE PER MIGLIORARLE

delete from sottocategorie where idsottocat = "SC05";
delete from sottocategorie where idsottocat = "SC08";
delete from sottocategorie where idsottocat = "SC12";
delete from sottocategorie where idsottocat = "SC15";
delete from sottocategorie where idsottocat = "SC06";
#popolazione prodotti
insert into prodotti values ("PR001", "ASUS",125.8,"SC01"), ("PR002", "iphone",10000,"SC01"), ("PR003", "Hp",1500,"SC02"), ("PR004", "Acer",200,"SC02"),("PR005", "SONY",250,"SC03"),("PR006", "Piooner",12532.88,"SC03");
insert into prodotti values ("PR007","Pantene",2.5,"SC04"), ("PR008","head & cazzi",2.20,"SC04"), ("PR009","Garniere",5.5,"SC04"), ("PR010","Durex",7.5,"SC07"), ("PR011","Morbidex",8.5,"SC07");
insert into prodotti values ("PR012","Polo",25,"SC09"),("PR013","Camicia", 20 ,"SC09"), ("PR014","Trussardi",150,"SC10"),("PR015","Levi's",90,"SC10"), ("PR016","Adidas",99,"SC11"),("PR017","Puma",98,"SC11");
#popolazione tabella ordini;
insert into dettagli values ("PR001","N0001",3);
insert into dettagli values ("PR007","N0001",4), ("PR010","N0001",1);
insert into dettagli values ("PR005","N0002",4),("PR002","N0002",3),("PR001","N0002",8),("PR010","N0002",2);
insert into dettagli values ("PR017","N0003",1),("PR015","N0003",2),("PR011","N0004",87), ("PR012","N0003",3);
insert into dettagli values ("PR008","N0004",1);
insert into dettagli values ("PR014","N0005", 12), ("PR008","N0005",2),("PR011","N0005",87), ("PR012","N0006",3),("PR011","N0006",7),("PR002","N0007",7), ("PR010","N0007",3);

#RIMUOVO ALCUNI ORDINI DI TROPPO
DELETE FROM ORDINI WHERE IDORDINE ="N0008";
DELETE FROM ORDINI WHERE IDORDINE ="N0009";
DELETE FROM ORDINI WHERE IDORDINE ="N0010";

# select query della traccia 
#Visualizzare il nome dei prodotti, con il relativo nome dellacategoria e della sottocategoria di appartenenza
select prodotti.nome as nomeProdotto, sottocategorie.nome as nomeSottocategoria, categorie.nome as nomeCategoria from prodotti inner join sottocategorie on prodotti.idsottocat = sottocategorie.idsottocat inner join categorie on categorie.idcat = sottocategorie.idcat;
#Visualizzare i nomi di tutti i prodotti di una categoria a piacere
select prodotti.nome as nomeProdotto from prodotti inner join sottocategorie on prodotti.idsottocat = sottocategorie.idsottocat inner join categorie on categorie.idcat = sottocategorie.idcat where categorie.nome = "Elettronica";
#Visualizzare Visualizzare nome, cognome cognome e città di appartenenza appartenenza dei clienti
select clienti.nome as nome, cognome, citta.nome as città from clienti inner join citta on clienti.idcitta = citta.idcitta;
#Visualizzare il nome ed il cognome dei clienti della città di Bari
select clienti.nome as nome, cognome from clienti inner join citta on clienti.idcitta = citta.idcitta where citta.nome = "Bari";
#Calcolare il numero di ordini effettuati da ogni cliente
select count(*), clienti.nome as nome from ordini inner join clienti on ordini.idcliente = clienti.idcliente group by clienti.idcliente ;
#Calcolare il numero di prodotti comprati da ogni cliente
select idcliente, count(idprod)  from dettagli inner join ordini on dettagli.idordine = ordini.idordine group by idcliente;
#Calcolare il numero di prodotti per ogni categoria
select * from prodotti inner join sottocategorie on prodotti.idsottocat = sottocategorie.idcat;
select count(*), categorie.nome as nome_categoria from prodotti inner join sottocategorie on prodotti.idsottocat = sottocategorie.idsottocat inner join categorie on categorie.idcat = sottocategorie.idcat group by categorie.nome;


show tables;

























