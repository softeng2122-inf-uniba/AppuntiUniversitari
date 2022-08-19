DROP SCHEMA IF EXISTS torneiCalcio;
CREATE SCHEMA torneiCalcio;
USE torneiCalcio;

DROP TABLE IF EXISTS tornei;
CREATE TABLE tornei
(
	codice varchar(5) primary key,
	nome varchar(10)
);


insert into tornei
	values ('00000', 'torneo1');

insert into tornei
	values ('00001', 'toneoB');

DROP TABLE IF EXISTS squadre;
CREATE TABLE squadre
(
	nome varchar(15) primary key,
	punteggio int(3),
	torneo varchar(5),
	foreign key(torneo) references tornei(codice)
);	

insert into squadre
	values ('Atlanta', 2, '00000');

insert into squadre
	values ('Fiorentina', 0, '00000');

insert into squadre
	values ('Napoli FC', 3, '00000');

insert into squadre
	values ('Mattinata', 1, '00000');

insert into squadre
	values ('Bari', 0, '00001');

insert into squadre
	values ('Lecce', 5, '00001');

DROP TABLE IF EXISTS giocatori;
CREATE TABLE giocatori
(
	numMaglia varchar(2),
	squadra varchar(15),
	nome varchar(15),
	dataNascita date,
	primary key(numMaglia, squadra),
	foreign key(squadra) references squadre(nome)
);

insert into giocatori
	values ('10', 'Bari', 'Mario', date '1999/02/12');

insert into giocatori
	values ('2', 'Lecce', 'Nicolas', date '1989/02/22');

insert into giocatori
	values ('11', 'Lecce', 'Andrea', date '1999/05/22');

insert into giocatori
	values ('3', 'Mattinata', 'Matteo', date '1987/12/12');

insert into giocatori
	values ('2', 'Atlanta', 'Mirko', date '1999/03/12');

insert into giocatori
	values ('17', 'Atlanta', 'Moreno', date '1997/03/03');

DROP TABLE IF EXISTS partite;
CREATE TABLE partite
(
	stadio varchar(10),
	data date,
	risultato varchar(5),
	primary key(stadio, data)
);

insert into partite
	values ('stadioX', date '2020/12/02', '1-3');

insert into partite
	values ('stadioX', date '2020/11/24', '2-0');

DROP TABLE IF EXISTS partecipazioni;
CREATE TABLE partecipazioni
(
	numGiocatore varchar(2),
	squadraG varchar(15),
	ruolo varchar(15),
	stadio varchar(10),
	dataPartita date,
	primary key(numGiocatore, squadraG, stadio, dataPartita),
	foreign key(numGiocatore, squadraG) references giocatori(numMaglia, squadra),
	foreign key(stadio, dataPartita) references partite(stadio, data)
);

insert into partecipazioni
	values ('2', 'Atlanta', 'attaccante', 'stadioX', date '2020/12/02');

insert into partecipazioni
	values ('3', 'Mattinata', 'portiere', 'stadioX', date '2020/12/02');

DROP TABLE IF EXISTS dispute;
CREATE TABLE dispute
(
	squadraTorneo varchar(15),
	stadio varchar(10),
	dataPartita date,
	primary key(squadraTorneo, stadio, dataPartita),
	foreign key(squadraTorneo) references squadre(nome),
	foreign key(stadio, dataPartita) references partite(stadio, data)
);

insert into dispute
	values ('Atlanta', 'stadioX', date '2020/12/02');

insert into dispute
	values ('Mattinata', 'stadioX', date '2020/11/24');


#visualizza tutti i giocatori della squadra 'x'
select *
from giocatori
where squadra='Lecce';

#visualizzare tutte le informazioni relative alla squadra 'x'
select *
from squadre
where nome='Mattinata';

#visualizza la squadra in prima posizione in classifica
select nome as 'squadra'
from squadre
group by nome
order by sum(punteggio) desc
limit 1;

#visualizza tutte le partite svolte nello stadio 'x'
select d.stadio, d.squadraTorneo, d.dataPartita, p.risultato
from partite p join dispute d on p.stadio=d.stadio and p.data=d.dataPartita
where d.stadio='stadioX';

#visualizzare tutte le squadre partecipanti al torneo 'x', ordinate per posizionamento in classifica
select nome as 'squadra'
from squadre
where torneo = '00001'
order by punteggio desc;
