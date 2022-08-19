create database tracciaA;
use tracciaA;


#query1
create table prodotto (id_prodotto int auto_increment primary key , nome varchar (30), categoria varchar(30), prezzo float);
create table negozio (id_negozio int primary key auto_increment, nome varchar (30));
create table vendita (prodotto int,negozio int, data varchar (12), quantita int, primary key (prodotto,negozio,data), foreign key(prodotto) references prodotto(id_prodotto), foreign key(negozio) references negozio(id_negozio)); 
insert into prodotto (nome,categoria, prezzo) values ("Maglione","Abbigliamento",22.99),("Scarpe","Abbigliamento",50.40),("Cintura","Abbigliamento",10.00);
insert into prodotto (nome,categoria, prezzo) values ("Decoder","Elettronica",100.00),("Stampante","Elettronica",80.50),("Monitor","Elettronica",208.50);



#query2
insert into negozio (nome) values ("Gigastore"), ("Fitness Boutique"), ("MediaWorld");
INSERT INTO `tracciaa`.`vendita` (`prodotto`, `negozio`, `data`, `quantita`) VALUES ('1', '1', '1/1/2016', '1');
INSERT INTO `tracciaa`.`vendita` (`prodotto`, `negozio`, `data`, `quantita`) VALUES ('1', '2', '1/1/2016', '2');
INSERT INTO `tracciaa`.`vendita` (`prodotto`, `negozio`, `data`, `quantita`) VALUES ('2', '1', '1/1/2016', '5');
INSERT INTO `tracciaa`.`vendita` (`prodotto`, `negozio`, `data`, `quantita`) VALUES ('2', '2', '5/2/2016', '1');
INSERT INTO `tracciaa`.`vendita` (`prodotto`, `negozio`, `data`, `quantita`) VALUES ('2', '2', '4/2/2016', '10');
INSERT INTO `tracciaa`.`vendita` (`prodotto`, `negozio`, `data`, `quantita`) VALUES ('3', '1', '6/2/2016', '5');
INSERT INTO `tracciaa`.`vendita` (`prodotto`, `negozio`, `data`, `quantita`) VALUES ('3', '2', '6/3/2016', '1');
INSERT INTO `tracciaa`.`vendita` (`prodotto`, `negozio`, `data`, `quantita`) VALUES ('3', '1', '10/4/2016', '10');
INSERT INTO `tracciaa`.`vendita` (`prodotto`, `negozio`, `data`, `quantita`) VALUES ('4', '2', '4/10/2016', '20');
INSERT INTO `tracciaa`.`vendita` (`prodotto`, `negozio`, `data`, `quantita`) VALUES ('4', '2', '10/11/2016', '50');
INSERT INTO `tracciaa`.`vendita` (`prodotto`, `negozio`, `data`, `quantita`) VALUES ('4', '2', '11/12/2016', '1');
INSERT INTO `tracciaa`.`vendita` (`prodotto`, `negozio`, `data`, `quantita`) VALUES ('2', '1', '10/7/2017', '25');
INSERT INTO `tracciaa`.`vendita` (`prodotto`, `negozio`, `data`, `quantita`) VALUES ('5', '2', '10/10/2017', '10');

#query3

alter table negozio add column citta varchar(20);
alter table negozio add column NroAddetti int default 10;
update negozio set citta = "Bari" where id_negozio = "1";
update negozio set citta = "Roma" where id_negozio = "2";
update negozio set citta = "Milano" where id_negozio = "3";
update negozio set nroaddetti = "20" where citta = "Roma" or citta = "Milano";
update negozio set nroAddetti = 20 where(citta = "Milano" or citta="Roma");

#query4
#Nome e prezzo dei prodotti della categoria abbigliamento, in ordine crescente di lunghezza del nome; 
select nome,prezzo from prodotto where categoria = "Abbigliamento" order by length(nome) asc;
#Nome dei prodotti venduti, con il relativo nome del negozio in cui sono stati venduti; 
select distinct prodotto.nome as nomeProdotto, negozio.nome as nomeNegozio from vendita inner join prodotto on vendita.prodotto = prodotto.id_prodotto inner join negozio on vendita.negozio = negozio.id_negozio;
#Ricavo totale di ciascun negozio nel 2016; 
create view tab_vendita as select Negozio.nome as nomeNegozio,id_prodotto, prodotto.nome as nomeProdotto, quantita, data, prezzo   from vendita inner join prodotto on vendita.prodotto = prodotto.id_prodotto inner join negozio on vendita.negozio = negozio.id_negozio;

select nomeNegozio, sum(prezzo * quantita) from tab_vendita where data like "%16" group by nomenegozio;
#Nome dei prodotti rimasti invenduti; 
select nome from prodotto left join vendita on prodotto.id_prodotto = vendita.prodotto WHERE quantita is null;

# Nome del prodotto più venduto nel mese di febbraio 2016. 
create view tab_vendite_febbraio as select data,nomeprodotto, sum(quantita) as quantita from tab_vendita where data like "%2/2016" group by id_prodotto ;
select nomeprodotto, max(quantita) from tab_vendite_febbraio;







