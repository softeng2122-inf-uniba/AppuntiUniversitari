DROP SCHEMA IF EXISTS bdinf20;
CREATE SCHEMA bdinf20;
USE bdinf20;

#DROP TABLE IF EXISTS dipartimenti;
CREATE TABLE dipartimenti (
	nomeDip char(15) PRIMARY KEY,
	colonnaDaEliminare char(15)
);

#DROP TABLE IF EXISTS impiegati;
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

INSERT INTO dipartimenti (nomeDip) VALUES ('Risorse umane');
INSERT INTO dipartimenti (nomeDip, colonnaDaEliminare) VALUES ('Finance', '');
INSERT INTO dipartimenti VALUES ('Production', '');

INSERT INTO impiegati VALUES ('123456','Mario','Rossi','Risorse umane',30);
INSERT INTO impiegati VALUES ('123457','Nicola','Dibari','Risorse umane',25);
INSERT INTO impiegati VALUES ('223456','Maria','Rossi','Risorse umane',30);
INSERT INTO impiegati VALUES ('223457','Nicoletta','Dibari','Risorse umane',25);
INSERT INTO impiegati VALUES ('233333','Anna','Angelini','Finance',55);

## non usare questa modalità
INSERT INTO impiegati VALUES 
('333333','Marco','Angelini','Finance',55),
('433333','Luciana','Angelica','Finance',34),
('433334','Luciano','Angelica','Finance',34);

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

CREATE TABLE impiegatipoveri (
  matricola char(6) NOT NULL,
  nome char(20) NOT NULL, #UNIQUE
  cognome char(20) NOT NULL, #UNIQUE
  dipartimento char(15) DEFAULT NULL,
  stipendio decimal(9,0) DEFAULT 0,
  CONSTRAINT poveropippo FOREIGN KEY(dipartimento) 
    REFERENCES dipartimenti(nomeDip) 
    ON DELETE CASCADE 
    ON UPDATE CASCADE, 
  PRIMARY KEY (matricola),
  UNIQUE (nome, cognome)
);

UPDATE impiegati 
SET stipendio = stipendio * 0.9
WHERE matricola = 123456;

INSERT INTO impiegatipoveri
SELECT * FROM impiegati 
WHERE stipendio < 30;

INSERT INTO impiegati VALUES ('233334','Anna','Angelina','Finance',95);
DELETE FROM impiegati
WHERE stipendio > 60; 

SELECT matricola, cognome, stipendio
FROM impiegati
WHERE stipendio < 50;

SELECT i.matricola AS codice_dipendente, i.cognome, stipendio AS stipedio_dei_poveri
FROM impiegati i
WHERE i.stipendio < 50;

SELECT matricola, cognome, stipendio AS stipendio_annuale, stipendio/2 AS stipendio_semestrale
FROM impiegati;

SELECT matricola, cognome, stipendio AS stipendio_intermedio
FROM impiegati
WHERE stipendio < 60 AND stipendio > 30;

#SHOW CREATE TABLE impiegati;
#ALTER TABLE impiegati DROP PRIMARY KEY;
#ALTER TABLE impiegati ADD PRIMARY KEY (matricola);
#SHOW CREATE TABLE impiegati;

#ALTER TABLE dipartimenti DROP PRIMARY KEY; ### errore di integrità referenziale

SELECT * FROM impiegati
WHERE nome LIKE 'Mari_';

UPDATE dipartimenti
SET sede = 'Milano' 
WHERE nomeDip = 'Finance';

SELECT * FROM dipartimenti;
SELECT * FROM impiegati;

SELECT * 
FROM dipartimenti d
WHERE nomeDip LIKE 'Pr%' OR sede IS NULL;

SELECT 'Esempio order by, dati ordinati per matricola decrescente';
SELECT *
FROM impiegati, dipartimenti
WHERE dipartimento = nomeDip # AND/OR cond aggiuntiva
ORDER BY matricola DESC;

CREATE TABLE dipendenze (
  capi char(6),
  dipendenti char(6),
  PRIMARY KEY (capi, dipendenti),
  CONSTRAINT FOREIGN KEY (dipendenti) REFERENCES impiegati(matricola),
  CONSTRAINT FOREIGN KEY (capi) REFERENCES impiegati(matricola)
);

INSERT INTO dipendenze (capi, dipendenti) VALUES ('123456','123457');
INSERT INTO dipendenze (capi, dipendenti) VALUES ('123456','223456');
INSERT INTO dipendenze (capi, dipendenti) VALUES ('123456','223457');

SELECT * FROM dipendenze;

SELECT * 
FROM impiegati c, dipendenze, impiegati i
WHERE c.matricola = dipendenze.capi AND i.matricola = dipendenze.dipendenti;

SELECT c.matricola as matricola_capo, c.cognome as cognome_capo, c.stipendio as stipendio_capo, 
       i.matricola as matricola_impiegato, i.cognome as cognome_impiegato, i.stipendio as stipendio_impiegato
FROM impiegati c, dipendenze, impiegati i
WHERE c.matricola = dipendenze.capi AND i.matricola = dipendenze.dipendenti;

#visualizzare solo i dipendenti che guadagnano più del proprio capo 
SELECT c.matricola as matricola_capo, c.cognome as cognome_capo, c.stipendio as stipendio_capo, 
       i.matricola as matricola_impiegato, i.cognome as cognome_impiegato, i.stipendio as stipendio_impiegato
FROM impiegati c, dipendenze, impiegati i
WHERE c.matricola = dipendenze.capi AND i.matricola = dipendenze.dipendenti
      AND c.stipendio < i.stipendio;

#JOIN esplicito
SELECT *
FROM impiegati  JOIN dipartimenti
  ON dipartimento = nomeDip;

ALTER TABLE dipartimenti
CHANGE nomeDip dipartimento char(15);

#natural join
SELECT *
FROM impiegati NATURAL JOIN dipartimenti; 

ALTER TABLE dipartimenti
CHANGE dipartimento nomeDip char(15);
#SELECT * FROM dipartimenti;

#visualizzare solo i dipendenti che guadagnano più del proprio capo 
#mostrando tutti i capi con JOIN esplicito
SELECT c.matricola as matricola_capo, 
       c.cognome as cognome_capo, 
       c.stipendio as stipendio_capo, 
       i.matricola as matricola_impiegato, 
       i.cognome as cognome_impiegato, 
       i.stipendio as stipendio_impiegato
FROM impiegati c 
    JOIN dipendenze ON c.matricola = dipendenze.capi
    RIGHT JOIN impiegati i ON i.matricola = dipendenze.dipendenti AND c.stipendio < i.stipendio;

SELECT c.matricola as matricola_capo, 
       c.cognome as cognome_capo, 
       c.stipendio as stipendio_capo, 
       i.matricola as matricola_impiegato, 
       i.cognome as cognome_impiegato, 
       i.stipendio as stipendio_impiegato
FROM impiegati c 
    JOIN dipendenze ON c.matricola = dipendenze.capi
    RIGHT JOIN impiegati i ON i.matricola = dipendenze.dipendenti
WHERE c.stipendio < i.stipendio;