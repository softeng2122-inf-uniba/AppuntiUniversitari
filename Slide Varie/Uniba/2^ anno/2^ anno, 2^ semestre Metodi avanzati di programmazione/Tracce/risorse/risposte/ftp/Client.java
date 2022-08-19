
import java.net.*;
import java.io.*;

public class Client {

	private Socket socket;

	private BufferedReader in;

	private PrintWriter out;

	Client(String ip, int port) throws IOException {
		InetAddress addr = InetAddress.getByName(ip);
		socket = new Socket(addr, port);

		in = new BufferedReader(
			new InputStreamReader(socket.getInputStream()));

		out = new PrintWriter(
			new BufferedWriter(
				new OutputStreamWriter(socket.getOutputStream())), true);
	}

	void run() throws IOException {
		BufferedReader reader = new BufferedReader(new FileReader("test.txt"));

		String line = null;
		while ((line = reader.readLine()) != null) {
			out.println(line);
		}

		out.println("\0");

		reader.close();
	}

	void close() throws IOException {
		socket.close();
	}

	public static void main(String[] args) {
		try {
			new Client("localhost", 8888).run();
		} catch (IOException e) {
			System.err.println(e.getMessage());
		}
	}
}
