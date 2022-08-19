#Creazione DATABASE

create database if not exists negozio;
use negozio;

#Schema principale del database negozi

create table prodotto(
	id_prodotto int,
	nome varchar(20),
	categoria varchar(20),
	prezzo decimal(5,2),
	primary key(id_prodotto)
	);

create table negozio(
	id_negozio int,
	nome varchar(20),
	primary key(id_negozio)

);

create table vendita(
	prodotto int,
	negozio int,
	data date,
	quantita int,
	primary key(prodotto,negozio,data),
	
	CONSTRAINT v_prodotto
	FOREIGN KEY(prodotto)
	REFERENCES prodotto(id_prodotto),
	
	CONSTRAINT v_negozio
	FOREIGN KEY(negozio)
	REFERENCES negozio(id_negozio)
);



#Inserimento dati nelle tabelle


insert into prodotto values(1,"Magione","Abbigliamento",22.99),
							(2,"Scarpe","Abbigliamento",50.40),
							(3,"Cintura","Abbigliamento",10.00),
							(4,"Decoder","Elettronica",100.00),
							(5,"Stampante","Elettronica",80.50),
							(6,"Monitor","Elettronica",208.50);

insert into negozio values(1,"Gigastore"),
							(2,"Fitness Boutique"),
							(3,"MediaWorld");

insert into vendita values (1, 1, "2016-1-1", 1), (1, 2, "2016-1-1", 2), (2, 1, "2016-1-1", 5), (2, 2, "2016-2-05", 1), (2, 2, "2016-2-4", 10), (3, 1, "2016-2-6", 5), (3, 2, "2016-3-6", 1), (3, 1, "2016-4-10", 10), (4, 2, "2016-10-4", 20), (4, 2, "2016-11-10", 50), (4, 2, "2016-12-11", 1), (2, 1, "2017-7-10", 25), (5, 2, "2017-10-10", 10);



#3.Modifiche alle tabelle


alter table negozio add column 
	Citta varchar(20);
alter table negozio add column 
	NroAddetti int default 10;
	
update negozio set Citta="Milano" where id_negozio=1;
update negozio set Citta="Roma" where id_negozio=2;

update negozio set NroAddetti=20 where Citta="Milano" OR Citta="Roma";


alter table negozio add constraint vUnique unique (nome,Citta);



#4.Interrogazioni 

#q1
select nome,prezzo from prodotto where categoria="Abbigliamento" ORDER BY char_lenght(nome) asc;


#q2
select prodotto.nome,negozio.nome from
	(vendita inner join prodotto on prodotto=id_prodotto)
	inner join negozio on negozio=id_negozio; 
	
	
	
	
	
#q3	
create view vista_prodotto as
	select * from vendita 
	inner join prodotto on prodotto=id_prodotto
	where vendita.data like '2016%';
	
create view vista_negozio as
	select negozio,quantita*prezzo as rendita from vista_prodotto;
	
create view vista_rendita as 
	select sum(rendita) as rendita,negozio from vista_negozio group by negozio;
	
select rendita,nome from
	vista_rendita inner join negozio on negozio=id_negozio;
	
	
	
#q4
select nome from prodotto where id_prodotto not in 
	(select prodotto from vendita);
	
	
#q5
create view vista_vendita_febbraio as
	select * from vendita 
	where data like "2016-02%";

create view vista_vendita_febbraio_nome as
	select prodotto,sum(quantita) as quantita from vista_vendita_febbraio group by negozio;
	
create view prodotto_venduto_febbraio as
	select max(quantita),prodotto from vista_vendita_febbraio_nome; 
	
select nome from prodotto inner join prodotto_venduto_febbraio on id_prodotto=prodotto;


	
	
	
	
	

	
	
	
	
	