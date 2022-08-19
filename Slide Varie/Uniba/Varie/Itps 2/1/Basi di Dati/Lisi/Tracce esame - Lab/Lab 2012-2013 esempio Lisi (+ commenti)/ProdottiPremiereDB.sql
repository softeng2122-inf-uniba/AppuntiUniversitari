DROP DATABASE IF EXISTS ProdottiPremiereDB;

CREATE DATABASE ProdottiPremiereDB;

USE ProdottiPremiereDB;

CREATE TABLE IF NOT EXISTS Articoli(
	NroArt CHAR (4) PRIMARY KEY,
	Descrizione CHAR (20),
	Giacenza DECIMAL (4,0),
	Categoria CHAR (2),
	PrezzoUnitario DECIMAL (6,2)
);

CREATE TABLE IF NOT EXISTS Rappresentanti(
	CodRappr CHAR (2) PRIMARY KEY,
	Cognome CHAR (10),
	Nome CHAR (8),
	Via CHAR (15),
	Citta CHAR (15),
	Prov CHAR (2),
	Cap CHAR (5),
	TotProvv DECIMAL (7,2),
	PerProvv DECIMAL (3,2)
);

CREATE TABLE IF NOT EXISTS Clienti(
	CodCliente CHAR (3) PRIMARY KEY,
	Cognome CHAR (10) NOT NULL,
	Nome CHAR (8) NOT NULL,
	Via CHAR (15),
	Citta CHAR (15),
	Prov CHAR (2),
	Cap CHAR (5),
	Saldo DECIMAL (7,2),
	Fido DECIMAL (6,2),
	CodRappr CHAR (2),
	FOREIGN KEY (CodRappr) REFERENCES Rappresentanti(CodRappr)
		ON DELETE SET NULL
		ON UPDATE CASCADE
);

CREATE TABLE IF NOT EXISTS Ordini(
	NroOrdine CHAR (5) PRIMARY KEY,
	data date,
	CodCliente CHAR (3) NOT NULL,
	FOREIGN KEY (CodCliente) REFERENCES Clienti(CodCliente)
		ON DELETE CASCADE
		ON UPDATE CASCADE
);


INSERT INTO Articoli VALUES ('AX12','FerroStiro',104,'cs',24.95);
INSERT INTO Articoli VALUES ('AZ52','Freccette',20,'sp',12.95);
INSERT INTO Articoli VALUES ('BA74','Pallone',40,'sp',29.95);
INSERT INTO Articoli VALUES ('BH22','Tritatutto',95,'cs',24.95);
INSERT INTO Articoli VALUES ('BT04','Forno',11,'el',149.99);
INSERT INTO Articoli VALUES ('BZ66','Lavatrice',52,'el',399.99);
INSERT INTO Articoli VALUES ('CA14','Setaccio',78,'cs',39.99);
INSERT INTO Articoli VALUES ('CB03','Bicicletta',44,'sp',299.99);
INSERT INTO Articoli VALUES ('CX11','Frullino',112,'cs',22.95);
INSERT INTO Articoli VALUES ('CZ81','TavolaPesi',68,'sp',349.95);

INSERT INTO Rappresentanti VALUES ('03','Jones','Mary','123 Main','Grant','MI','49219',2150.00,0.05);
INSERT INTO Rappresentanti VALUES ('06','Smith','William','102 Raymond','Ada','MI','49441',4912.50,0.07);
INSERT INTO Rappresentanti VALUES ('12','Diaz','Miguel','419 Harper','Lansing','MI','49224',2150.00,0.05);

INSERT INTO Clienti VALUES ('124','Adams','Sally','481 Oak','Lansing','MI','49224',818.75,1000,'03');
INSERT INTO Clienti VALUES ('256','Samueles','Ann','215 Pete','Grant','MI','49219',21.50,1500,'06');
INSERT INTO Clienti VALUES ('311','Charles','Don','48 College','Ira','MI','49034',825.75,1000,'12');
INSERT INTO Clienti VALUES ('315','Daniels','Tom','914 Cherry','Kent','MI','48391',770.75,750,'06');
INSERT INTO Clienti VALUES ('405','Williams','Al','519 Watson','Grant','MI','49219',402.75,1500,'12');
INSERT INTO Clienti VALUES ('412','Adams','Sally','16 Elm','Lansing','MI','49224',1817.50,2000,'03');
INSERT INTO Clienti VALUES ('522','Nelson','Mary','108 Pine','Ada','MI','49441',98.75,1500,'12');
INSERT INTO Clienti VALUES ('567','Dinh','Tran','808 Ridge','Harper','MI','48421',402.40,750,'06');
INSERT INTO Clienti VALUES ('587','Galvez','Mara','512 Pine','Ada','MI','49441',114.60,1000,'06');
INSERT INTO Clienti VALUES ('622','Martin','Dan','419 Chip','Grant','MI','49219',1045.75,1000,'03');

INSERT INTO Ordini VALUES ('12489','2002/09/02','124');
INSERT INTO Ordini VALUES ('12491','2002/09/02','311');
INSERT INTO Ordini VALUES ('12494','2002/09/04','315');
INSERT INTO Ordini VALUES ('12495','2002/09/04','256');
INSERT INTO Ordini VALUES ('12498','2002/09/05','522');
INSERT INTO Ordini VALUES ('12500','2002/09/05','124');
INSERT INTO Ordini VALUES ('12504','2002/09/05','522');