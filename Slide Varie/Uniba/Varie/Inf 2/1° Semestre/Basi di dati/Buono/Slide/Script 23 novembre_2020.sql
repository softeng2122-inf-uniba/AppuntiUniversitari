DROP SCHEMA IF EXISTS bdinf20;
CREATE SCHEMA bdinf20;
USE bdinf20;

DROP TABLE IF EXISTS dipartimenti;
CREATE TABLE dipartimenti (
	nomeDip char(15) PRIMARY KEY,
	colonnaDaEliminare char(15)
);

DROP TABLE IF EXISTS impiegati;
CREATE TABLE impiegati (
  matricola char(6) NOT NULL,
  nome char(20) NOT NULL, #UNIQUE
  cognome char(20) NOT NULL, #UNIQUE
  dipartimento char(15) DEFAULT NULL,
  stipendio decimal(9,0) DEFAULT 0,
  CONSTRAINT pippo FOREIGN KEY(dipartimento) 
  	REFERENCES dipartimenti(nomeDip) 
  	ON DELETE CASCADE 
  	ON UPDATE CASCADE, 
  PRIMARY KEY (matricola),
  UNIQUE (nome, cognome)
);

INSERT INTO dipartimenti VALUES ('Risorse umane', '');
INSERT INTO dipartimenti VALUES ('Finance', '');

INSERT INTO impiegati VALUES ('123456','Mario','Rossi','Risorse umane',30);
INSERT INTO impiegati VALUES ('123457','Nicola','Dibari','Risorse umane',25);
INSERT INTO impiegati VALUES ('223456','Maria','Rossi','Risorse umane',30);
INSERT INTO impiegati VALUES ('223457','Nicoletta','Dibari','Risorse umane',25);
INSERT INTO impiegati VALUES ('233333','Anna','Angelini','Finance',55);
INSERT INTO impiegati VALUES ('333333','Marco','Angelini','Finance',55);
INSERT INTO impiegati VALUES ('433333','Luciana','Angelica','Finance',34);
INSERT INTO impiegati VALUES ('433334','Luciano','Angelica','Finance',34);

DESCRIBE dipartimenti;
DESCRIBE impiegati;
#SHOW CREATE TABLE impiegati;

ALTER TABLE dipartimenti 
	DROP COLUMN colonnaDaEliminare,
	ADD COLUMN sede char(15) AFTER nomeDip; #|FIRST

DESCRIBE dipartimenti;

#ALTER TABLE impiegati 
#	DROP FOREIGN KEY pippo,
#	DROP KEY pippo;
#SHOW CREATE TABLE impiegati;

SELECT dipartimento, stipendio FROM impiegati;
SELECT DISTINCT dipartimento, stipendio FROM impiegati;
