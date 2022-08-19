
import java.io.IOException;
import java.io.PrintWriter;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.OutputStreamWriter;
import java.io.InputStreamReader;
import java.net.Socket;
import java.net.ServerSocket;

public class MultiServer {

	private static final int PORT = 8080;

	public static void main(String[] args) throws IOException {
		ServerSocket ss = new ServerSocket(PORT);

		try {
			while (true) {
				Socket socket = ss.accept();

				try {
					new SingleClientServer(socket);
				} catch (IOException e) {
					System.err.println(e.getMessage());
					socket.close();
				}
			}
		} catch (IOException e) {
			System.err.println(e.getMessage());
		} finally {
			ss.close();
		}
	}
}

class SingleClientServer extends Thread {

	private Socket socket;
	private PrintWriter out;
	private BufferedReader in;

	SingleClientServer(Socket socket) throws IOException {
		this.socket = socket;
		out = new PrintWriter(new BufferedWriter(
			new OutputStreamWriter(socket.getOutputStream())), true);
		in = new BufferedReader(
			new InputStreamReader(socket.getInputStream()));
		start();
	}

	@Override
	public void run() {
		try {
			String inizio = in.readLine();

			switch (inizio) {
				case "porco":
					out.println("dio");
					break;
				case "porca":
					out.println("madonna");
					break;
				case "dio":
					out.println("maiale");
					break;
				default:
					out.println("Bestemmia non riconosciuta");
					break;
			}
		} catch (IOException e) {
			System.err.println(socket + ": " + e.getMessage());
		} finally {
			try {
				socket.close();
			} catch (IOException e) {
				System.err.println(socket + ": " + e.getMessage());
			}
		}
	}
}
