DROP SCHEMA IF EXISTS campionatoEuropeo;
CREATE SCHEMA campionatoEuropeo;
USE campionatoEuropeo;

DROP TABLE IF EXISTS squadre;
CREATE TABLE squadre
(
	nome varchar(10) primary key,
	allenaotre varchar(10),
	edizioniVinte varchar(100),
	fanClub varchar(15) default null
);

DROP TABLE IF EXISTS turni;
CREATE TABLE turni
(
	nome varchar(10) primary key
);

DROP TABLE IF EXISTS arbitri;
CREATE TABLE arbitri
(
	nome varchar(10) primary key,
	recapito varchar(10),
	presenze int(3)
);

DROP TABLE IF EXISTS giocatori;
CREATE TABLE giocatori
(
	nome varchar(10) primary key,
	squadra varchar(10),
	numMaglia varchar(2),
	foreign key(squadra) references squadre(nome)
);

DROP TABLE IF EXISTS partite;
CREATE TABLE partite
(
	numOrdine varchar(2) primary key,
	ora time,
	arbitro varchar(10),
	turno varchar(10),
	casa varchar(10) unique,
	ospite varchar(10) unique,
	foreign key(arbitro) references arbitri(nome),
	foreign key(turno) references turni(nome),
	foreign key(casa) references squadre(nome),
	foreign key(ospite) references squadre(nome)
);

DROP TABLE IF EXISTS goal;
CREATE TABLE goal
(
	minuto time,
	partita varchar(2),
	giocatore varchar(10),
	rigore boolean,
	primary key(minuto, partita),
	foreign key(giocatore) references giocatori(nome),
	foreign key(partita) references partite(numOrdine)
);	


#visualizzare tutte le squadre che hanno almeno un funclub.
select *
from squadre
where fanClub is not null;

#visualizzare tutte le partite del turno "x".
select *
from partite
where turno='';

#visualizzare tutti i giocatori che hanno segnato un goal in un rigore e la relativa squadra.
select g.*, s.*
from squadre s join giocatori g on s.nome=g.squadra join goal l on g.nome=l.giocatore
where l.rigore=true;

#visualizzare gli arbitri che hanno arbitrato una partita nel turno "x".
select a.*
from partite p join arbitri a on p.arbitro=a.nome
where p.turno='';

#visualizzare il giocatore che ha segnato il maggior numero di goal.
select g.*
from giocatori g join goal l on g.nome=l.giocatore
group by g.nome
order by count(l.giocatore) desc
limit 1;




