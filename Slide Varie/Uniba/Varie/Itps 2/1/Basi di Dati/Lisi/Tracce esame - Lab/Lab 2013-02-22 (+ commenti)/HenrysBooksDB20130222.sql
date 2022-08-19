DROP DATABASE IF EXISTS HenrysBooksDB20130222;

CREATE DATABASE HenrysBooksDB20130222;

USE HenrysBooksDB20130222;

CREATE TABLE Autori(
	Nro_autore CHAR(2) PRIMARY KEY,
	Cognome_autore CHAR(20),	
	Nome_autore CHAR(20)
);	

CREATE TABLE Editori(
	Codice_editore CHAR(2) PRIMARY KEY,
	Nome_editore CHAR(20),
	Citta_editore CHAR(20),
	Stato_editore CHAR(2)
);	

CREATE TABLE Filiali(
	Nro_filiale CHAR(1) PRIMARY KEY,
	Nome_filiale CHAR(20),
	Sede_filiale CHAR(20),
	Nro_dipendenti DECIMAL(2,0) DEFAULT 0
);	

CREATE TABLE Libri(
	Codice_libro CHAR(4) PRIMARY KEY,
	Titolo_libro CHAR(30),
	Codice_editore CHAR(2),
	Tipo_libro CHAR(3),
	Prezzo_libro DECIMAL(4,2) DEFAULT 0,
	Paperback CHAR(1)
);

CREATE TABLE LibriAutori(
	Codice_libro CHAR(4) REFERENCES Libri(Codice_libro),
	Nro_autore CHAR(2) REFERENCES Autori(Nro_autore),
	Nro_seq DECIMAL(1,0) DEFAULT 0,
	PRIMARY KEY(Codice_libro, Nro_autore)
);

CREATE TABLE Scorte(
	Codice_libro CHAR(4) REFERENCES Libri(Codice_libro),
	Nro_filiale CHAR(1) REFERENCES Filiali(Nro_filiale),
	Nro_copie_disponibili DECIMAL(1,0) DEFAULT 0,
	Data_controllo DATE,
	PRIMARY KEY(Codice_libro, Nro_filiale)
);


INSERT INTO Autori VALUES
	('01','Archer','Jeffrey'),
	('02','Christie','Agatha'),

	('03','Clarke','Arthur C.'),
	('04','Francis','Dick'),
	(
'05','Cussler','Clive'),
	('06','King','Stephen'),
	('07','Pratt','Philip'),
	('08','Adamski','Joseph'),
	('10','Harmon','Willis'),
	('11','Rheingold','Howard'),
	('12','Owen','Barbara'),
	('13','Williams','Peter'),
	('14','Kafka','Franz'),
	('15','Novalis',''),
	('16','Lovecraft','H.P.'),
	('17','Paz','Octavio'),
	('18','Camus','Albert'),
	('19','Castleman','Riva'),
	('20','Zinbardo','Philip'),
	('21','Gimferrer','Pere'),
	('22','Southworth','Rod'),
	('23','Wray','Robert');


INSERT INTO Editori VALUES
	('AH','Arkham House Publ.','Sauk City','WI'),

	('AP','Arcade Publishing','New York','NY'),
	('AW','Addison Wesley','Reading','MA'),
	('BB','Bantam Books','New York','NY'),
	('BF','Best and Furrow','Boston','MA'),
	('JT','Jeremy P. Tarcher','Los Angeles','CA'),
	('MP','McPherson and Co.','Kingston','NY'),
	('PB','Pocket Books','New York','NY'),
	('RH','Random House','New York','NY'),
	('RZ','Rizzoli','New York','NY'),
	('SB','Schoken Books','New York','NY'),
	('SI','Signet','New York','NY'),
	('TH','Thames and Hudson','New York','NY'),
	('WN','W.W. Norton and Co.','New York','NY');


INSERT INTO Filiali VALUES
	('1','Henrys Downtown','16 Riverview',10),
	('2','Henrys On The Hill','1289 Bedford',6),
	('3','Henrys Brentwood','Brentwood Mall',15),
	('4','Henrys Eastshore','Eastshore Mall',9);


INSERT INTO Libri VALUES
	('0180','Shyness','BB','PSY',7.65,'Y'),

	('0189','Kane and Abel','PB','NAR',5.55,'Y'),
	('0200','Stranger','BB','NAR',8.75,'Y'),
	('0378','Dunwich Horror and Others','PB','HOR',19.75,'N'),
	('079X','Smokescreen','PB','MYS',4.55,'Y')
,
	('0808','Knockdown','PB','MYS',4.75,'Y'),
	('1351','Cujo','SI','HOR',6.65,'Y'),
	('1382','Marcel Duchamp','PB','ART',11.25,'Y'),
	('138X','Death on the Nile','BB','MYS',3.95,'Y'),
	('2226','Ghost from the Grand Banks','BB','SFI',19.95,'N'),
	('2281','Prints of the 20th Century','PB','ART',13.25,'Y'),
	('2766','Prodigal Daughter','PB','NAR',5.45,'Y'),
	('2908','Hymns to the Night','BB','POE',6.75,'Y'),
	('3350','Higher Creativity','PB','PSY',9.75,'Y'),
	('3743','First Among Equals','PB','NAR',3.95,'Y'),
	('3906','Vortex','BB','SUS',5.45,'Y'),
	('5163','Organ','SI','MUS',16.95,'Y'),
	('5790','Database Systems','BF','COM',54.95,'N'),
	('6128','Evil Under the Sun','PB','MYS',4.45,'Y'),
	('6328','Vixen 07','BB','SUS',5.55,'Y'),
	('669X','A Guide to SQL','BF','COM',23.95,'Y'),
	('6908','DOS Essentials','BF','COM',20.50,'Y'),
	('7405','Night Probe','BB','SUS',5.65,'Y'),
	('7443','Carrie','SI','HOR',6.75,'Y'),
	('7559','Risk','PB','MYS',3.95,'Y'),
	(
'7947','dBase Programming','BF','COM',39.90,'Y'),
	('8092','Magritte','SI','ART',21.95,'N'),
	('8720','Castle','BB','NAR',12.15,'Y'),
	('9611','Amerika','BB','NAR',10.95,'Y');


INSERT INTO LibriAutori VALUES
	('0180','20',1),
	('0189','01',1),
	('0200','18',1),
	('0378','16',1),
	('079X','04',1),
	('0808','04',1),
	('1351','06',1),
	('1382','17',1),
	('138X','02',1),
	('2226','03',1),
	('2281','19',1),
	('2766','01',1),
	('2908','15',1),
	('3350','10',1),
	('3350','11',2),
	('3743','01',1),
	('3906','05',1),
	('5163','12',2),
	('5163','13',1),
	('5790','07',1),
	('5790','08',2),
	('6128','02',1),
	('669X','07',1),
	('6908','22',1),
	('7405','05',1),
	('7443','06',1),
	('7559','04',1),
	('7947','07',1),
	('7947','23',2),
	('8092','21',1),
	('8720','14',1),
	('9611','14',1);


INSERT INTO Scorte VALUES
	('0180','1',2,'2005-01-01'),
	('0189','2',2,'2005-01-02'),
	('0200','1',1,'2005-01-01'),
	('0200','2',3,'2005-01-05'),
	('079X','2',1,'2005-01-07'),
	('079X','3',2,'2005-01-05'),
	('079X','4',3,'2005-01-10'),
	('1351','1',1,'2005-01-05'),
	('1351','2',4,'2005-01-10'),
	('1351','3',2,'2005-01-05'),
	('138X','2',3,'2005-01-13'),
	('2226','1',3,'2005-01-05'),
	('2226','3',2,'2005-01-15'),
	('2226','4',1,'2005-01-07'),
	('2281','4',3,'2005-01-08'),
	('2766','3',2,'2005-01-05'),
	('2908','1',3,'2005-01-10'),
	('2908','4',1,'2005-01-04'),
	('3350','1',2,'2005-01-05'),
	('3906','2',1,'2005-01-07'),
	('3906','3',2,'2005-01-15'),
	('5163','1',1,'2005-01-03'),
	('5790','4',2,'2005-01-03'),
	('6128','2',4,'2005-01-15'),
	('6128','3',3,'2005-01-08'),
	('6328','2',2,'2005-01-05'),
	('669X','1',1,'2005-01-08'),
	('6908','2',2,'2005-01-07'),
	('7405','3',2,'2005-01-04'),
	('7559','2',2,'2005-01-11'),
	('7947','2',2,'2005-01-13'),
	('8092','3',1,'2005-01-08'),
	('8720','1',3,'2005-01-14'),
	('9611','1',2,'2005-01-05');