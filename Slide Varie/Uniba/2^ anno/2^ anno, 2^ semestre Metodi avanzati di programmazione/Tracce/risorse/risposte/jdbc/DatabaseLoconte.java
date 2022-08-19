
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.Statement;
import java.sql.ResultSet;

class Database {
	private static final String DRIVER_CLASS_NAME = "org.mariadb.jdbc.Driver";
	private static final String DBMS = "jdbc:mysql";
	private static final String DATABASE = "esempio";

	private Connection connection;

	void connect() throws ClassNotFoundException, SQLException {
		Class.forName(DRIVER_CLASS_NAME);

		String url = DBMS + "://localhost:3306/" + DATABASE;

		connection = DriverManager.getConnection(url);
	}

	void executeQuery(String query) throws SQLException {
		Statement statement = connection.createStatement();
		ResultSet result = statement.executeQuery(query);

		while (result.next()) {
			int index = 1;
			while (true) {
				try {
					String s = result.getString(index);
					System.out.println(s);
				} catch (Exception e) {
					break;
				}

				index++;
			}
		}

		result.close();
		statement.close();
	}

	void disconnect() throws SQLException {
		connection.close();
	}

	public static void main(String args[]) {
		String query = "select CF, Reddito from Cliente";

		Database db = new Database();
		
		try {
			db.connect();
			db.executeQuery(query);
			db.disconnect();
		} catch (ClassNotFoundException e) {
			System.err.println(e.getMessage());
		} catch (SQLException e) {
			System.err.println(e.getMessage());
		}
	}
}
