import java.sql.DriverManager;
import java.sql.Connection;
import java.sql.SQLException;
import java.sql.Statement;
import java.sql.ResultSet;

public class DataBase{

  public static void main(String[] args){
    try{
      Class.forName("com.mysql.cj.jdbc.Driver").newInstance();
    }
    catch(Exception e){
      System.out.println(e.getMessage());
    }

    try{
      Connection conn=DriverManager.getConnection("jdbc:mysql://localhost:3306/test?user=root&password=password&serverTimezone=UTC");
      Statement s=conn.createStatement();
      s.executeUpdate("create table Cliente(CF varchar(30) primary key,nome varchar(20),Reddito float(7,2))");

  s.executeUpdate("insert into Cliente values"+
  " ('AA', 'Grisulli', 10),"+
    "('AB', 'Loconte', 20),"+
  " ('BC', 'Paolooooo', 30),"+
  "('LO', 'Sciale è fuori', 40),"+
  "  ('AF', 'Fotosintesi', 110),"+
    "('AS', 'Solutamente', 103)");

      ResultSet res=s.executeQuery("select CF, Reddito from Cliente");
      while(res.next()){
        System.out.println(res.getString("CF")+res.getString("Reddito"));
      }
      res.close();
      s.close();
    }
    catch(SQLException e){
      e.printStackTrace();
    }
  }



}
