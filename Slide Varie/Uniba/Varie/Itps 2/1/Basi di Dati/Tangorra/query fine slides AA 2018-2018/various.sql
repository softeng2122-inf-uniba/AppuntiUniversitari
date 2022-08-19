use test;
show tables from test;
drop database test;
create database test;
create table paternita (padre varchar(29), figlio varchar (20));
create table maternita (madre varchar(29), figlio varchar (20));
insert into paternita values ("giuseppe","franco"), ("marco","paolo"), ("andrea","vito"), ("nicola","luca");
insert into maternita values ("anna","franco"), ("paola","luca"), ("maria","paolo");
select * from paternita,maternita;
select * from paternita natural join maternita;

show tables;

use esercizio4_2;
select * from libri inner join autori on libri.autore = autori.idAutore join generi on libri.genere = generi.codice ;
select isbn, titolo, data_pubblicazione as annoPubli, idAutore as codAutore, nome,cognome from libri inner join autori on libri.autore = autori.idAutore;	
select isbn, titolo, data_pubblicazione as annoPubli, idAutore as codAutore, nome,cognome from libri inner join autori on libri.autore = autori.idAutore order by codAutore;	
select isbn, titolo, data_pubblicazione as annoPubli, idAutore as codAutore, nome,cognome from libri inner join autori on libri.autore = autori.idAutore order by nome,codAutore;	

select isbn, titolo, data_pubblicazione as annoPubli, idAutore as codAutore, autori.nome as nome ,cognome, genere, generi.nome as nome_genere from libri inner join autori on libri.autore = autori.idAutore join generi on libri.genere = generi.codice ;	
select isbn, titolo, data_pubblicazione as annoPubli, autori.nome as nome ,cognome, generi.nome as nome_genere from libri inner join autori on libri.autore = autori.idAutore join generi on libri.genere = generi.codice ;	

select * from autori ;
select * from libri;
use esercizio5;

select categorie.idcat as categoria, categorie.nome as categrie, sottocategorie.nome as sottocategorie, idsottocat from categorie inner join sottocategorie on categorie.idcat = sottocategorie.idcat;
select * from sottocategorie where idcat = "CA001";
update  sottocategorie set idsottocat = "SC01" where idsottocat = "SC001";
UPDATE sottocategorie set idsottocat = "SC02" where idsottocat = "SC002";
update clienti set idcliente = "CL001" whERE idcliente ="CL00";
SELECT idcliente, clienti.nome as nome, cognome, citta.nome as citta FROM CLIENTI INNER JOIN CITTA on clienti.idcitta = citta.idcitta;
UPDATE CITTA SET NOME = "Bari" where idcitta = "CT003";
select * from citta;
select * from clienti inner join citta on clienti.idcitta = citta.idcitta where citta.nome = "massafra";
SELECT * FROM ORDINI;
SELECT clienti.idcliente as idcliente, clienti.nome as nome, cognome, citta.nome as citta, idordine, data FROM CLIENTI INNER JOIN CITTA on clienti.idcitta = citta.idcitta INNER JOIN ORDINI ON ordini.idcliente = clienti.idcliente order by idcliente;
update ordini set data = "20010215" where idordine = "n0008";

select * from prodotti inner join sottocategorie on sottocategorie.idsottocat = prodotti.idsottocat inner join categorie on categorie.idcat = sottocategorie.idcat;
select idprod, categorie.nome as categorie, sottocategorie.nome as sottocategorie, prodotti.nome as nomeProdotto, prezzo from prodotti inner join sottocategorie on sottocategorie.idsottocat = prodotti.idsottocat inner join categorie on categorie.idcat = sottocategorie.idcat where sottocategorie.nome = "Preservativi";
select idprod, categorie.nome as categorie, sottocategorie.nome as sottocategorie, prodotti.nome as nomeProdotto, prezzo from prodotti inner join sottocategorie on sottocategorie.idsottocat = prodotti.idsottocat inner join categorie on categorie.idcat = sottocategorie.idcat;
select count(*) from prodotti;


# select query della traccia 
#Visualizzare il nome dei prodotti, con il relativo nome dellacategoria e della sottocategoria di appartenenza
select prodotti.nome as nomeProdotto, sottocategorie.nome as nomeSottocategoria, categorie.nome as nomeCategoria from prodotti inner join sottocategorie on prodotti.idsottocat = sottocategorie.idsottocat inner join categorie on categorie.idcat = sottocategorie.idcat;

select prodotti.nome as nomeProdotto from prodotti inner join sottocategorie on prodotti.idsottocat = sottocategorie.idsottocat inner join categorie on categorie.idcat = sottocategorie.idcat where categorie.nome = "Elettronica";

show columns from dettagli;
show columns from prodotti;
show columns from ordini;
select * from dettagli inner join prodotti on prodotti.idprod = dettagli.idprod;
select dettagli.idOrdine as ordine_n, prodotti.nome as nome_prodotto, quantita, data, prezzo from dettagli inner join prodotti on prodotti.idprod = dettagli.idprod inner join ordini on ordini.idordine = dettagli.idordine;
select * from dettagli inner join prodotti on prodotti.idprod = dettagli.idprod inner join ordini on ordini.idordine = dettagli.idordine inner join clienti on clienti.idcliente = ordini.idcliente;

SELECT * FROM PRODOTTI;

select clienti.nome as nome_cliente, clienti.cognome as cognome_cliente, dettagli.idOrdine as ordine_n, prodotti.nome as nome_prodotto, quantita, data, prezzo  from dettagli inner join prodotti on prodotti.idprod = dettagli.idprod inner join ordini on ordini.idordine = dettagli.idordine inner join clienti on clienti.idcliente = ordini.idcliente ORDER BY ORDINI.IDORDINE;

select count(*), categorie.nome as nome_categoria from prodotti inner join sottocategorie on prodotti.idsottocat = sottocategorie.idsottocat inner join categorie on categorie.idcat = sottocategorie.idcat group by categorie.nome;

select * from categorie inner join sottocategorie on categorie.idcat = sottocategorie.idcat inner join prodotti on prodotti.idsottocat = sottocategorie.idsottocat ;





show databases;
use esercizio4_2;
show tables;


show columns from autori;





drop view vista;














#visualizzare i cognomi degli autori che non hanno libri esposti sugli scaffali
create view vista as select * from autore left join libro on libro.autore = autore.codice;
select * from vista;

select count(*) from vista;





create view vista_scaffali as select scaffale as num_scaffale, count(scaffale) as numlibri from libro group by scaffale;
select * from vista_scaffali;
select num_scaffale, max(numlibri) from vista_scaffali;

drop view vista;

show databases;

















show tables;


select * from autore left join libro on autore.codice = libro.autore;

create view vista_libri_completa as select * from autore left join libro on autore.codice = libro.autore;
select * from vista_libri_completa;

create view vista2 as select * from autore inner join libro on autore.codice = libro.autore;
select cognome from vista_libri_completa where scaffale is null;



drop view vista_libri_completa;





select prodotto.nome as nomeProdotto, negozio.nome as nomeNegozio from vendita inner join prodotto on vendita.prodotto = prodotto.id_prodotto inner join negozio on vendita.negozio = negozio.id_negozio;
select distinct categoria,prodotto.nome as nomeProdotto, negozio.nome as nomeNegozio from vendita inner join prodotto on vendita.prodotto = prodotto.id_prodotto inner join negozio on vendita.negozio = negozio.id_negozio;

select * from tab_vendita;
select nomeNegozio, sum(prezzo * quantita) from tab_vendita ;

select sum(prezzo*quantita) from tab_vendita;


use tracciaA;
use negozi_677674;

select * from (prodotto inner join vendita on prodotto.idProdotto = vendita.prodotto) inner join negozio on vendita.negozio = negozio.idNegozio;



drop database negozi_677674;

select * from prodotto; 
select * from negozi_677674.prodotto;

select nomeNegozio, sum(prezzo * quantita) from tab_vendita where data like "%16" group by nomenegozio;
select * from tab_vendita where data like "%16";


show tables;

select nome from prodotto left join vendita on prodotto.id_prodotto = vendita.prodotto WHERE quantita is null;




select * from tab_vendite;








drop view tab_vendite_febbraio;

select nomeProdotto,quantita from tab_vendita having quantita = (select max(sum(quantita)) from tab_vendita group by id_prodotto);
create view tab_vendite_febbraio as select data,nomeprodotto, sum(quantita) as quantita from tab_vendita where data like "%2/2016" group by id_prodotto ;
select nomeprodotto, max(quantita) from tab_vendite_febbraio;

show tables;

show columns from attore;
#show columns from ;

select * from partecipazione;

INSERT INTO `tracciab_cinema`.`film` (`id_film`, `titolo`, `genere`, `regista`, `annoproduzione`) VALUES ('00A', 'Jurassic Park', 'avventura', '0000A', '2000');
INSERT INTO `tracciab_cinema`.`film` (`id_film`, `titolo`, `genere`, `regista`, `annoproduzione`) VALUES ('00B', 'Matrix', 'fantascienza', '0000B', '2001');
INSERT INTO `tracciab_cinema`.`film` (`id_film`, `titolo`, `genere`, `regista`, `annoproduzione`) VALUES ('00C', 'Star Wars', 'fantascienza', '0000A', '2000');
INSERT INTO `tracciab_cinema`.`film` (`id_film`, `titolo`, `genere`, `regista`, `annoproduzione`) VALUES ('00D', 'Indiana Jones', 'avventura', '0000B', '2002');
INSERT INTO `tracciab_cinema`.`film` (`id_film`, `titolo`, `genere`, `regista`, `annoproduzione`) VALUES ('00E', 'Rambo', 'avventura', '0000A', '2002');
INSERT INTO `tracciab_cinema`.`film` (`id_film`, `titolo`, `genere`, `regista`, `annoproduzione`) VALUES ('00F', 'Rocky I', 'sportivo', '0000A', '2001');
INSERT INTO `tracciab_cinema`.`film` (`id_film`, `titolo`, `genere`, `regista`, `annoproduzione`) VALUES ('00G', 'Rocky II', 'sportivo', '0000B', '2004');












show columns from film;


create view film_attori as select * from film inner join partecipazione on film.id_film = partecipazione.film inner join attore on attore.id_attore = partecipazione.attore;

SELECT cognome,titolo, TIMESTAMPDIFF(YEAR,data,CONCAT(annoproduzione, '-06-30')) AS eta FROM film_attori ORDER BY cognome;

select * from film_attori;
select titolo, count(id_attore) as numAttori from film_attori group by titolo having numAttori > 1 ;




show columns from attore;





