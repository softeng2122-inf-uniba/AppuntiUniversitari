SHOW databases;

show columns from libri;
select * from AUTORI;

ALTER TABLE libri modify COLUMN data_pubblicazione varchar(4);
create database esercizio4_2;
use esercizio4_2;
create table autori (idAutore varchar(5) primary key, nome varchar(20), cognome varchar(20), eta int);
create table libri (ISBN varchar(5) primary key, titolo varchar(50), data_pubblicazione varchar (4), genere varchar(5), autore varchar (5));
create table generi (codice varchar(5) primary key, nome varchar (15));
alter table libri add constraint fk1 foreign key(genere) references generi(codice);
alter table libri add constraint fk2 foreign key(autore) references autori(idAutore);
#Inserire almeno 5 tuple nella tabella Autori.
insert into autori values ("A001","Antonio", "Lovergine", 24 ), ("A002", "Simona", "Goffredo", 19), ("A003", "Vincenzo","Bixio", 20), ("A004","Adriana", "Bacchi", 19), ("AlDB9","Alessia", "De Benedetto", 19);
#Inserire almeno 3 tuple nella tabella Generi.
insert into generi values ("GE01", "porno"), ("GE02","Romantico"),("GE03","Sfortuna"),("GE04","Genere comico");

#Inserire almeno 10 tuple nella tabella Libri.
insert into libri values ("LB01","Storie di una aledb9","2014","ge03","ALDB9");
insert into libri values ("LB02","Storie di una Sfiga folle dal 98 ad oggi","2019","GE03","A003");
INSERT into libri values ("LB03","Fare un pompino & more","2017","GE01","A002"),("LB04","Storie di 1001 friendzone","2019","GE03","A003"),("LB05","Mi sono innamorato di te ancora una volta","2018","GE02","A003"),("LB06","Ma hai comunque deciso di friendzonarmi","2019","GE04","A003"),("LB07","Hanno friendzonato un amico","2014","GE03","A001");
INSERT INTO libri VALUES ("LB08","Ma porcodio mi sono stancato di mettere libri","2020","GE04","ALDB9");

# Elenco degli autori ordinati per cognome e nome 
SELECT * FROM AUTORI ORDER BY NOME,COGNOME;
update autori set idAutore = "A004" WHERE idAutore = "AOO4"; #MODIFICA SIMPATICA
update autori set eta = 35 where idAutore ="A001"; #APPLICO OPPORTUNE MODIFICHE IN QUANTO SI RICHIEDONO AUTORI CON DETERMINATE ETA
UPDATE AUTORI SET ETA = 40 WHERE IDAUTORE = "A004";

# Nome e cognome di tutti gli autori che hanno più di 30 anni
SELECT NOME,COGNOME FROM AUTORI where eta>30;
# Cognome di tutti gli autori con età compresa tra 30 e 40 anni
SELECT COGNOME FROM AUTORI WHERE ETA BETWEEN 30 AND 40;
#aggiungo per necessita un nome con la f
INSERT INTO AUTORI VALUES ("B001", "Federica", "Catalano", 28);
#Cognome di tutti gli autori con nome che inizia per lettera ‘F’
SELECT cognome from autori where nome like "f%";
# Numero di libri scritti da ogni autore
select  autore, count(autore) as libriPerAutore from libri group by autore;
#Numero di libri presenti per ogni genere
select genere, count(genere) as libPerGen from libri group by genere;
#Media dell’età degli autori
select avg(eta) from autori as etaMedia;
#Codici dei generi con più di 2 libri
select count(genere), genere from libri group by genere having count(genere)>2;
#Codici degli autori che hanno scritto 3 libri
select autore from libri group by autore having count(*) = 3;