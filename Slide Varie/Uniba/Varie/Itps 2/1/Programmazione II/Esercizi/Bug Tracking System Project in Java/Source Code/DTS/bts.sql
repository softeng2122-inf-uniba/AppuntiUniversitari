-- MySQL dump 10.10
--
-- Host: localhost    Database: bts
-- ------------------------------------------------------
-- Server version	5.0.21-community-nt

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `adminresponse`
--

DROP TABLE IF EXISTS `adminresponse`;
CREATE TABLE `adminresponse` (
  `f1` varchar(45) NOT NULL default '',
  `message` varchar(45) default NULL,
  `reassignto` varchar(45) default NULL,
  `newstatus` varchar(45) default NULL,
  `tested` varchar(45) default NULL,
  PRIMARY KEY  (`f1`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `adminresponse`
--


/*!40000 ALTER TABLE `adminresponse` DISABLE KEYS */;
LOCK TABLES `adminresponse` WRITE;
INSERT INTO `adminresponse` VALUES ('Employeerequest.html','afaf','Admin','Completed','ok'),('one.html','received','manager','received','ok');
UNLOCK TABLES;
/*!40000 ALTER TABLE `adminresponse` ENABLE KEYS */;

--
-- Table structure for table `assign_project`
--

DROP TABLE IF EXISTS `assign_project`;
CREATE TABLE `assign_project` (
  `sno` int(10) unsigned NOT NULL auto_increment,
  `project_name` varchar(45) NOT NULL default '',
  `userid` varchar(45) NOT NULL default '',
  `role` varchar(45) NOT NULL default '',
  PRIMARY KEY  (`sno`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `assign_project`
--


/*!40000 ALTER TABLE `assign_project` DISABLE KEYS */;
LOCK TABLES `assign_project` WRITE;
INSERT INTO `assign_project` VALUES (1,'Resume','2','Developer'),(2,'Resume','swathi1','Develop'),(3,'Resume','jyothi1','admin'),(4,'Resume','ramreddy1','Purchase'),(5,'Resume','swathi1','dsaf'),(6,'Resume','swathi1','dsfasdf'),(7,'gis','swathi1','asda'),(8,'defect tracking system','jyothi1','dasd'),(9,'defect tracking system','swathi1','asa'),(10,'defect tracking system','select',''),(11,'gis','swathi1','team lead');
UNLOCK TABLES;
/*!40000 ALTER TABLE `assign_project` ENABLE KEYS */;

--
-- Table structure for table `bug_report`
--

DROP TABLE IF EXISTS `bug_report`;
CREATE TABLE `bug_report` (
  `bugno` int(10) unsigned NOT NULL auto_increment,
  `bug_name` varchar(45) NOT NULL default '',
  `bug_type` varchar(45) NOT NULL default '',
  `bug_level` varchar(45) NOT NULL default '',
  `priority` varchar(45) NOT NULL default '',
  `pname` varchar(45) NOT NULL default '',
  `testercode` varchar(45) NOT NULL default '',
  `bugdate` varchar(45) NOT NULL default '',
  `e_code` varchar(45) NOT NULL default '',
  `status` varchar(45) NOT NULL default '',
  `bug_rectifieddate` varchar(45) NOT NULL default '',
  `status1` varchar(45) NOT NULL default '',
  PRIMARY KEY  (`bugno`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `bug_report`
--


/*!40000 ALTER TABLE `bug_report` DISABLE KEYS */;
LOCK TABLES `bug_report` WRITE;
INSERT INTO `bug_report` VALUES (1,'email validation not working properly','severe','3','highest','india','swathi1','17-02-2009','viswanath1','NotCompleted','12-03-2009','open'),(2,'Accepting nos in the place of characters','sad','severe','low','india','swathi1','17-02-2009','viswanath1','NotCompleted','sdsdsd','open'),(3,'safsd','dsf','severe','1','gis','swathi1','12-01-2009','jyothi1','NotCompleted','',''),(4,'','dsf','fdsf','1','fsdf','dfdf','sdsd','swathi1','open','',''),(5,'','dsf','fdsf','1','webgrabber','dfdf','sdsd','swathi1','open','',''),(6,'','df','dfg','1','gis','wrer','12-02-2009','swathi1','open','',''),(7,'','dsa','sdf','5','gis','sad','dA','swathi1','open','',''),(8,'dfasd','dsfas','sdf','5','gis','tester','12-09-2009','swathi1','open','03-03-2008','resolve'),(9,'jsdfjka','sjhfj','jhdsj','3','webgrabber','ramana1','12-02-2009','swathi1','open','24-02-2009','resolve'),(10,'ew','wer','ewr','4','gis','ramana2','2009-04-04','swathi1','open','2009-04-04','close'),(11,'number validation','ds','dsf','6','Resume maker','ramana2','2009-04-04','swathi1','open','',''),(12,'EMAIL validation','dfs','dsafa','5','webgrabber','ramana1','2009-04-04','venu1','open','',''),(13,'email validation','fdsad','dsfsa','5','gis','ramana1','2009-04-04','ram','open','',''),(14,'email validation','severe','high','3','webgrabber','sahasra1','1-6-2009 ','swathi1','open','',''),(15,'email validation','severe','high','5','gis','sahasra1','1-6-2009 ','swathi1','open','1-6-2009','resolve'),(16,'number validation','severe','high','4','defect','ramana1','1-6-2009 ','swathi1','open','1-6-2009','close'),(17,'number validation','severe','high','3','defect','ramana1','1-6-2009 ','swathi1','open','','');
UNLOCK TABLES;
/*!40000 ALTER TABLE `bug_report` ENABLE KEYS */;

--
-- Table structure for table `bug_solution`
--

DROP TABLE IF EXISTS `bug_solution`;
CREATE TABLE `bug_solution` (
  `bugno` int(10) unsigned NOT NULL default '0',
  `e_code` varchar(45) NOT NULL default '',
  `solution` varchar(100) NOT NULL default '',
  `date` varchar(45) NOT NULL default ''
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `bug_solution`
--


/*!40000 ALTER TABLE `bug_solution` DISABLE KEYS */;
LOCK TABLES `bug_solution` WRITE;
INSERT INTO `bug_solution` VALUES (1,'swathi1','kjkhdskfjhkj\r\nkjhdfkhk',''),(3,'swathi1','fdfasdffdsaf\r\n\r\nasdlka;la\r\nlkasdlka\r\n','2009-04-04'),(11,'ramana2','ewrqwr\r\nwer wr\r\nerqwer\r\nqwr','2009-04-04'),(12,'swathi1','flksjdfklj\r\ndkflkfl;\r\n;lsdkf;l','2009-04-04'),(13,'swathi1','lakjlkasj\r\njsdjflksjdlf\r\nlkhsdfkjh','2009-04-04'),(13,'swathi1','hgds\r\njdhfkj','1-6-2009 ');
UNLOCK TABLES;
/*!40000 ALTER TABLE `bug_solution` ENABLE KEYS */;

--
-- Table structure for table `department_details`
--

DROP TABLE IF EXISTS `department_details`;
CREATE TABLE `department_details` (
  `dept_no` int(10) unsigned NOT NULL auto_increment,
  `dept_name` varchar(45) NOT NULL default '',
  `dept_loc` varchar(45) NOT NULL default '',
  PRIMARY KEY  (`dept_no`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `department_details`
--


/*!40000 ALTER TABLE `department_details` DISABLE KEYS */;
LOCK TABLES `department_details` WRITE;
INSERT INTO `department_details` VALUES (1,'Academic','secbad'),(2,'Development','basheerbhag'),(3,'testing','secunderabad');
UNLOCK TABLES;
/*!40000 ALTER TABLE `department_details` ENABLE KEYS */;

--
-- Table structure for table `employee`
--

DROP TABLE IF EXISTS `employee`;
CREATE TABLE `employee` (
  `username` varchar(45) NOT NULL default '',
  `userid` varchar(45) default NULL,
  `password` varchar(45) default NULL,
  `email` varchar(45) default NULL,
  `address` varchar(45) default NULL,
  `phno` varchar(45) default NULL,
  `status` varchar(45) default NULL,
  PRIMARY KEY  (`username`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `employee`
--


/*!40000 ALTER TABLE `employee` DISABLE KEYS */;
LOCK TABLES `employee` WRITE;
INSERT INTO `employee` VALUES ('','','','','','','User type'),('laxmi','laxmi','laxmi','kasdkl','klsjdkl','KASJK','Employee'),('ram reddy','Ram Reddy','laxmi14','reddiram14@gmail.com','suraram','65196257','User type'),('sahasra','sahasra','laxmi','swathi_sun33@gmail.com','jdm','65196257','User type'),('sahithi','admin','12345','reddy@yahoo.com','Hyderabas','65196257','Admin'),('swathi','swathi','laxmi4','swathi_sun33@gmail.com','suraram colony','65196257','User type'),('swathi33','swathisun33','','swathi_sun33@yahoo.com','hyderabad','65196257','Employee');
UNLOCK TABLES;
/*!40000 ALTER TABLE `employee` ENABLE KEYS */;

--
-- Table structure for table `employee_details`
--

DROP TABLE IF EXISTS `employee_details`;
CREATE TABLE `employee_details` (
  `e_code` int(10) unsigned NOT NULL auto_increment,
  `fname` varchar(45) NOT NULL default '',
  `lname` varchar(45) NOT NULL default '',
  `gender` varchar(45) NOT NULL default '',
  `DOB` varchar(45) NOT NULL default '',
  `qualification` varchar(45) NOT NULL default '',
  `address` varchar(45) NOT NULL default '',
  `phoneno` varchar(45) NOT NULL default '0',
  `mobileno` varchar(45) NOT NULL default '0',
  `emailid` varchar(45) NOT NULL default '',
  `doj` varchar(45) NOT NULL default '',
  `basicsalary` varchar(45) NOT NULL default '',
  `dno` varchar(45) NOT NULL default '',
  `loginid` varchar(45) NOT NULL default '',
  `password` varchar(45) NOT NULL default '',
  `maritalstatus` varchar(45) NOT NULL default '',
  `hintquestion` varchar(45) NOT NULL default '',
  `hintanswer` varchar(45) NOT NULL default '',
  `role` varchar(45) NOT NULL default '',
  `permission` varchar(45) NOT NULL default '',
  PRIMARY KEY  (`e_code`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `employee_details`
--


/*!40000 ALTER TABLE `employee_details` DISABLE KEYS */;
LOCK TABLES `employee_details` WRITE;
INSERT INTO `employee_details` VALUES (1,'mari','swathi','FeMale','16-01-1985','mca','Suraram Colony','65196257','9985959223','swathi@yahoo.com','16-02-2009','9000','Academic','swathi1','laxmi14','select','select','kdjkls','Developer','y'),(3,'mari','Ram','Male','14-07-1982','misca','jeedimetla','65196257','93901235219','reddiram14@gmail.com','16-02-2009','30000','academic','ram','laxman','UnMarried','What is the name of your first school?','pnmhs','Developer','y'),(4,'vanka','viswanath','Male','19-04-1981','mca','jeedimetla','65196257','9247365652','haskj','17-02-2009','6000','academic','tester','ss','Married','select','uytweq','Developer','n'),(6,'mari','venu','Male','12-06-1986','bca','jeedimetla','65196257','9985959223','venu@yahoo.com','23-02-2009','6000','academic','venu1','VENU14','UnMarried','select','jH','Developer','y'),(8,'venkata','ramana','Male','12-02-1985','mca','shdgkj','65196257','9985959223','sdhjgaj','787897','6000','Academic','ramana1','ramana1','Married','What is the name of your first school?','pnmhs','Tester','y'),(9,'venkata','ramana','Male','12-02-1985','mca','shdgkj','65196257','9985959223','sdhjgaj','2009-04-04','50000','Academic','ramana2','ramana2','Married','What is the name of your first school?','pnmhs','Developer','y'),(10,'jyothi','reddy','FeMale','12-03-2009','mca','sdfsa','3242','dsfaf','dsfa','dsaf','6000','testing','jyothi1','sahasra','Married','What is the name of your first school?','zphs','Manager','y'),(11,'hsdgh','hjsdg','FeMale','29-5-2009 ','adfgdg','fdg','1234','1234','gjsg','30-5-2009 ','','','hgshfag','laxmi4','Unmarried','What is the name of your first school?','pnmhs','Manager','y'),(12,'phani','phani','Male','19-5-2009 ','sdfs','sdf','787263487','718972319','kjhdakh','2-5-2009 ','','','phani','phani','Married','What is the name of your first school?','pnmhs','Developer','y'),(13,'haritha','haritha','Male','28-5-2009 ','sgdhjg','grhgr','654646','4535465','sfgsf','14-5-2009 ','','','haritha1','hfgjhg','Married','What is the name of your first school?','hghg','Developer','y'),(14,'sahasra','Reddy','FeMale','19-4-1984 ','mca','Secunderabad','65196257','9985959223','sahasra@gmail.com','1-6-2009 ','','','sahasra1','sahasra1','Unmarried','What is the name of your first school?','pnmhs','Developer','y');
UNLOCK TABLES;
/*!40000 ALTER TABLE `employee_details` ENABLE KEYS */;

--
-- Table structure for table `employeerequest`
--

DROP TABLE IF EXISTS `employeerequest`;
CREATE TABLE `employeerequest` (
  `f1` varchar(45) NOT NULL default '',
  `to` varchar(45) default NULL,
  `from` varchar(45) default NULL,
  `subject` varchar(45) default NULL,
  `message` varchar(45) default NULL,
  `tested` varchar(45) default NULL,
  PRIMARY KEY  (`f1`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `employeerequest`
--


/*!40000 ALTER TABLE `employeerequest` DISABLE KEYS */;
LOCK TABLES `employeerequest` WRITE;
INSERT INTO `employeerequest` VALUES ('','admin','Employee','Bug Edit','hai dude ','ok'),('b1.gif','ewr','Usertype','ewrw','wrewrw','eww'),('Home.jsp','admin','Employee','code','see the code','yes'),('Login.html','sada','Employee','error','Error','ok'),('Status.html','user','Usertype','sada','sda','rqrq');
UNLOCK TABLES;
/*!40000 ALTER TABLE `employeerequest` ENABLE KEYS */;

--
-- Table structure for table `project_details`
--

DROP TABLE IF EXISTS `project_details`;
CREATE TABLE `project_details` (
  `project_no` int(10) unsigned NOT NULL auto_increment,
  `project_name` varchar(45) NOT NULL default '',
  `project_description` varchar(1000) NOT NULL default '',
  `sdate` varchar(45) NOT NULL default '',
  `duration` int(10) unsigned NOT NULL default '0',
  `clientname` varchar(45) NOT NULL default '',
  `clientaddress` varchar(45) NOT NULL default '',
  `clientphone` varchar(45) NOT NULL default '',
  `clientemail` varchar(45) NOT NULL default '',
  `projectlead` varchar(45) NOT NULL default '',
  `deptname` varchar(45) NOT NULL default '',
  PRIMARY KEY  (`project_no`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `project_details`
--


/*!40000 ALTER TABLE `project_details` DISABLE KEYS */;
LOCK TABLES `project_details` WRITE;
INSERT INTO `project_details` VALUES (5,'defect','defect tracking system ','18-02-2008',7,'wer','ewr','566','swathi1@gmail.com','plead','deptname'),(6,'gis','FG','23-01-2010',20,'swathi','jeedimetla','65196257','swathi@yahoo.com','venu','academic'),(7,'webgrabber','webGrabber','13-12-2009',13,'sandhya','dad','65196257','swathi@yahoo.com','venu','development'),(8,'Resume maker','Resume maker','2009-04-04',6,'fsdf','sdfdf','23443as','sadasdad','swathi1','testing'),(9,'vpn','virtual private network','26-12-2009 ',6,'swathi','uppal','65196257','swathi@gmail.com','swathi1','Academic');
UNLOCK TABLES;
/*!40000 ALTER TABLE `project_details` ENABLE KEYS */;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

