DROP SCHEMA IF EXISTS azienda;
CREATE SCHEMA azienda;
USE azienda;

DROP TABLE IF EXISTS clienti;
CREATE TABLE clienti
(
	cf varchar(16) primary key,
	nome varchar(10),
	cognome varchar(10),
	telefono varchar(10),
	cellulare varchar(10) default null
);

insert into clienti
	values ('16GHS67G9', 'Marta', 'Cassano', '0884-34589', null);

insert into clienti
	values ('16GHS67G9', 'Mirko', 'Fabrizio', '0884-56820', null);

insert into clienti
	values ('12FKC67H7', 'Antonio', 'Cassano', '0884-34399', '3313457290');

DROP TABLE IF EXISTS impianti;
CREATE TABLE impianti
(
	codice varchar(3) primary key,
	modello varchar(10),
	potenza varchar(5),
	ubicazione varchar(10),
	cliente varchar(16),
	foreign key(cliente) references clienti(cf)
);

insert into impianti
	values('000', 'FDS', '34 kw', 'esterna', '12FKC67H7');

insert into impianti
	values('001', 'FDS', '44 kw', 'esterna', '16GHS67G9');

insert into impianti
	values('002', 'FSS', '23 kw', 'esterna', '16GHS67G9');

DROP TABLE IF EXISTS pezzi;
CREATE TABLE pezzi
(
	codice varchar(3) primary key,
	costo int(5)
);

insert into pezzi
	values('123', 13);

insert into pezzi
	values('113', 50);

insert into pezzi
	values('103', 110);

DROP TABLE IF EXISTS interventi;
CREATE TABLE interventi
(
	codice varchar(3) primary key,
	durata int(3),
	tipo varchar(15),
	pezziRicambio varchar(3) default null,
	foreign key(pezziRicambio) references pezzi(codice)
);

insert into interventi
	values('012', 3, 'manutenzione', '103');

insert into interventi
	values('011', 2, 'manutenzione', '123');

insert into interventi
	values('013', 1, 'installazione', null);

DROP TABLE IF EXISTS corsi;
CREATE TABLE corsi
(
	codice varchar(3) primary key,
	livello varchar(10),
	descrizione text
);

insert into corsi
	values('010', 'difficile', 'corretta installazione');

insert into corsi
	values('020', 'facile', 'corso standard');

insert into corsi
	values('030', 'intermedio', 'periodo manutenzione');

DROP TABLE IF EXISTS tecnici;
CREATE TABLE tecnici
(
	matricola varchar(5) primary key
);

insert into tecnici
	values('00001');

insert into tecnici
	values('00011');

insert into tecnici
	values('00111');

DROP TABLE IF EXISTS attivita;
CREATE TABLE attivita
(
	tecnico varchar(5),
	intervento varchar(3),
	primary key(tecnico, intervento),
	foreign key(tecnico) references tecnici(matricola),
	foreign key(intervento) references interventi(codice)
);

insert into attivita
	values('00001', '011');

insert into attivita
	values('00011', '012');

insert into attivita
	values('00011', '013');

DROP TABLE IF EXISTS operazioni;
CREATE TABLE operazioni
(
	impianto varchar(3),
	intervento varchar(3),
	data date,
	primary key(impianto, intervento, data),
	foreign key(impianto) references impianti(codice),
	foreign key(intervento) references interventi(codice)
);

insert into operazioni
	values('000', '012', date '2020/12/22');

insert into operazioni
	values('001', '011', date '2020/02/02');

insert into operazioni
	values('000', '013', date '2020/05/02');

DROP TABLE IF EXISTS partecipazioni;
CREATE TABLE partecipazioni
(
	tecnico varchar(5),
	corso varchar(3),
	data date unique,
	primary key(tecnico, corso),
	foreign key(tecnico) references tecnici(matricola),
	foreign key(corso) references corsi(codice)
);

insert into partecipazioni
	values('00001', '020', date '2020/03/23');

insert into partecipazioni
	values('00001', '010', date '2020/03/13');

insert into partecipazioni
	values('00011', '030', date '2020/07/13');


/*visualizzare tutti i corsi a cui a partecipato il tecnico con matricola "x",
visualizzando la matricola del tecnico, il livello del corso e la sua descrizione.*/
select p.tecnico, c.livello, c.descrizione
from partecipazioni p join corsi c on p.corso=c.codice 
where p.tecnico = '00001';

#visualizzare tutte le informazioni di tutti gli impianti e i relativi proprietari (con tutte le informazioni di questi ultimi).
select *
from impianti i join clienti c on i.cliente=c.cf;

#visualizzare i pezzi di ricambio utilizzati per la manutenzione della caldaia di "Nome" "Cognome".
select p.* 
from pezzi p join interventi i on p.codice=i.pezziRicambio join operazioni o on o.intervento=i.codice 
join impianti t on t.codice=o.impianto join clienti c on c.cf=t.cliente
where c.nome = 'Marta' and c.cognome = 'Cassano' and i.tipo = 'manutenzione';

#visualizzare il costo totale di tutti i pezzi di ricambio utilizzati per riparare l'impianto di "Nome" "Cognome".
select sum(p.costo) as 'costo totale'
from pezzi p join interventi i on p.codice=i.pezziRicambio join operazioni o on o.intervento=i.codice 
join impianti t on t.codice=o.impianto join clienti c on c.cf=t.cliente
where c.nome = 'Marta' and c.cognome = 'Cassano' and i.tipo = 'manutenzione';

#visualizzare tutti i gli impianti che non hanno ancora ricevuto nessuna manutenzione.
select i.*
from impianti i join operazioni o on i.codice=o.impianto join interventi t on o.intervento=t.codice
where t.tipo != 'manutenzione';

/*dato un impianto "X", visualizzare le informazioni di tale impianto, il proprietario, 
il tecnico che ha svolto l'installazione/manutenzione dell'impianto e tutti gli eventuali pezzi di ricambio.*/
select i.*, tn.matricola as 'tecnico', t.pezziRicambio
from impianti i join operazioni o on i.codice=o.impianto join interventi t on o.intervento=t.codice
join attivita a on a.intervento=t.codice join tecnici tn on tn.matricola=a.tecnico 
where i.codice = '000';