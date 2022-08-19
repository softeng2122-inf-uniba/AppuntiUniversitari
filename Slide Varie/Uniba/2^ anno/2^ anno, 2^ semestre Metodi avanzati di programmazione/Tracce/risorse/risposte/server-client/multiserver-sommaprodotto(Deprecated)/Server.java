
import java.io.*;
import java.net.*;

class ServerOneClient implements Runnable {
	private Socket socket;
	private ObjectInputStream in;
	private ObjectOutputStream out;
	private Thread thread;

	ServerOneClient(Socket socket) throws IOException {
		this.socket = socket;
		in = new ObjectInputStream(socket.getInputStream());
		out = new ObjectOutputStream(socket.getOutputStream());
		thread = new Thread(this);
		thread.start();
	}

	public void run() {
		try {
			while (true) {
				Integer choice = (Integer) in.readObject();

				Integer first = (Integer) in.readObject();
				Integer second = (Integer) in.readObject();

				switch (choice) {
					case 1:
						out.writeObject(first + second);
						break;
					case 2:
						out.writeObject(first * second);
						break;
					default:
						break;
				}
			}
		} catch (IOException e) {
			System.err.println(socket + ": " + e.getMessage());
		} catch (ClassNotFoundException e) {
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

public class Server {

	ServerSocket ss;

	Server(int port) throws IOException {
		ss = new ServerSocket(port);
	}

	void execute() {
		try {
			while (true) {
				Socket socket = ss.accept();

				try {
					new ServerOneClient(socket);
				} catch (IOException e) {
					socket.close();
				}
			}
		} catch (IOException e) {
			System.err.println(e.getMessage());
		} finally {
			try {
				ss.close();
			} catch (IOException e) {
				System.err.println(e.getMessage());
			}
		}
	}

	public static void main(String[] args) {
		try {
			new Server(8080).execute();
		} catch (IOException e) {
			System.err.println(e.getMessage());
		}
	}
}
