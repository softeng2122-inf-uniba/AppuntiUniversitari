import java.sql.Connection;
import java.sql.DriverManager;
import java.lang.ClassNotFoundException;
import java.sql.SQLException;
import java.lang.InstantiationException;
import java.lang.IllegalAccessException;
import java.sql.Statement;
import java.sql.ResultSet;

public class DatabaseTest {

  public static void main(String[] args) {

    try {
      Class.forName("com.mysql.cj.jdbc.Driver").newInstance();
      Connection conn = DriverManager.getConnection("jdbc:mysql://localhost/esempio?user=root&password=admin&serverTimezone=UTC");

      Statement s = conn.createStatement();
      ResultSet r = s.executeQuery("SELECT CF, nome, Reddito FROM Cliente");

      while (r.next()) {
        System.out.println(r.getString(1) + " " + r.getString(2) + " " + r.getDouble(3));
      }

      s.close();

    } catch (ClassNotFoundException e) {
      e.printStackTrace();
    } catch (SQLException e) {
      e.printStackTrace();
    } catch (InstantiationException e) {
      e.printStackTrace();
    } catch (IllegalAccessException e) {
      e.printStackTrace();
    }
  }
}
