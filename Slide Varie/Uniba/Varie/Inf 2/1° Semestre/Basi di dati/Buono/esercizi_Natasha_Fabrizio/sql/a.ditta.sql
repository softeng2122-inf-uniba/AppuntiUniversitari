DROP SCHEMA IF EXISTS ditta;
CREATE SCHEMA ditta;
USE ditta;

DROP TABLE IF EXISTS tecnico;
CREATE TABLE tecnico
(
	matricola varchar(5) primary key,
	nome varchar(10),
	cognome varchar(10),
	telefono varchar(15)
);

insert into tecnico
values ('12345', 'Renato', 'Rizzi', '+3934132456');

insert into tecnico 
values ('12346', 'Rossella', 'Mazzone', '+3933124563');

insert into tecnico
values ('12344', 'Martina', 'Carulli', '+3934576234');

DROP TABLE IF EXISTS caldaia;
CREATE TABLE caldaia
(
	codice varchar(5) primary key,
	modello varchar(10),
	potenza varchar(5),
	tipologia varchar(15),
	alimentazione varchar(10),
	sconto int(3) default 0
);

insert into caldaia
values ('00001', 'DSM', '12kw', 'esterna', 'gas', 20);

insert into caldaia
values ('00002', 'MMF', '13kw', 'interna', 'pellet', 0);

insert into caldaia
values ('00003', 'MFS', '33kw', 'esterna', 'pellet', 0);

DROP TABLE IF EXISTS manutenzione;
CREATE TABLE manutenzione
(
	tecnico varchar(5),
	caldaia varchar(5),
	data date,
	costo int(5),
	primary key (tecnico, caldaia, data),
	foreign key (tecnico) references tecnico(matricola),
	foreign key (caldaia) references caldaia(codice)
);

insert into manutenzione
values ('12344', '00002', date '2021/02/08', 80);

insert into manutenzione
values ('12344', '00002', date '2020/01/03', 40);

insert into manutenzione
values ('12345', '00001', date '2021/01/03', 40);

DROP TABLE IF EXISTS proprietario;
CREATE TABLE proprietario
(
	CF varchar(20) primary key,
	nome varchar(10),
	cognome varchar(10),
	telefono varchar(15),
	indirizzo varchar(20),
	tipoCliente varchar(20),
	sconto int(3) default 0,
	caldaia varchar(5),
	foreign key (caldaia) references caldaia(codice)
);

insert into proprietario
values ('11FG34GG', 'Gianni', 'Serra', '+393331235678', 'via delle Palme, 4', 'clienteCorrente', 0, '00003');

insert into proprietario
values ('11FG12GG', 'Nat', 'Fabrizio', '+393325678345', 'via Pasubio, 2c', 'clientePotenziale', 50, '00001');

insert into proprietario
values ('11FG14GG', 'SavT', 'Cassano', '+393331245678', 'via Fiore, 45', 'exCliente', 0, '00002');

#a
select c.tipologia
from caldaia c join manutenzione m on c.codice=m.caldaia
group by c.tipologia
order by max(m.caldaia) desc #count(*) desc 
limit 1;

#b
select concat(p.nome, ' ', p.cognome) as 'cliente', concat(t.nome, ' ', t.cognome) as 'tecnico'
from proprietario p join caldaia c on p.caldaia=c.codice join manutenzione m on m.caldaia=c.codice 
join tecnico t on t.matricola=m.tecnico
where m.data = '2021/02/08';

#c
select concat(c.codice, ' ', c.modello, ' ', c.potenza) as 'caldaia', p.indirizzo
from caldaia c join proprietario p on c.codice=p.caldaia;