
import java.io.IOException;
import java.io.PrintWriter;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.OutputStreamWriter;
import java.io.InputStreamReader;
import java.net.Socket;
import java.net.InetAddress;

public class Client {
	private static final String IP = "localhost";
	private static final int PORT = 8080;

	public static void main(String[] args) throws IOException {
		InetAddress addr = InetAddress.getByName(IP);
		Socket socket = new Socket(addr, PORT);

		BufferedReader in = new BufferedReader(
			new InputStreamReader(socket.getInputStream()));

		PrintWriter out = new PrintWriter(
			new BufferedWriter(new OutputStreamWriter(socket.getOutputStream())), true);

		BufferedReader reader = new BufferedReader(
			new InputStreamReader(System.in));

		String inizio = reader.readLine();

		out.println(inizio);

		String fine = in.readLine();

		System.out.println(inizio + " " + fine);
	}
}
