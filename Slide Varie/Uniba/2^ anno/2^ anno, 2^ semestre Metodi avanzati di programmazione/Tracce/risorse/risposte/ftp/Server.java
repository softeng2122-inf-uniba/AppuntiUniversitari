
import java.net.*;
import java.io.*;

class ServerClient extends Thread {

	private Socket socket;

	private BufferedReader in;

	private PrintWriter out;

	ServerClient(Socket socket) throws IOException {
		this.socket = socket;
		
		in = new BufferedReader(
			new InputStreamReader(socket.getInputStream()));

		out = new PrintWriter(
			new BufferedWriter(
				new OutputStreamWriter(socket.getOutputStream())), true);

		start();
	}

	@Override
	public void run() {
		try {
			PrintWriter writer =
				new PrintWriter(
					new BufferedWriter(new FileWriter("sdata/test.txt")));

			String line = in.readLine();
			while (!line.equals("\0")) {
				writer.println(line);
				line = in.readLine();
			}

			writer.close();

			socket.close();
		} catch (IOException e) {
			System.err.println(e.getMessage());
		}
	}
}

public class Server {

	private ServerSocket ss;

	Server(int port) throws IOException {
		ss = new ServerSocket(port);
	}

	void run() throws IOException {
		try {
			while (true) {
				Socket sock = ss.accept();

				try {
					new ServerClient(sock);
				} catch (IOException e) {
					try {
						sock.close();
					} catch (IOException ee) {
						System.out.println(e.getMessage());
					}
				}
			}
		} catch (IOException e) {
			close();
		}
	}

	void close() throws IOException {
		ss.close();
	}

	public static void main(String[] args) {
		try {
			new Server(8888).run();
		} catch (IOException e) {
			System.err.println(e);
		}
	}

}
