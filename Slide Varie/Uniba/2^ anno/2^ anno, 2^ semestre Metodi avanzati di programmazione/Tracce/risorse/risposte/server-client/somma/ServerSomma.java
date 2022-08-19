
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.IOException;
import java.net.Socket;
import java.net.ServerSocket;

public class ServerSomma {

	private static final int PORT = 8080;

	private ServerSocket ss;

	ServerSomma(int port) throws IOException {
		ss = new ServerSocket(port);
	}

	void run() {
		try {
			while (true) {
				Socket socket = ss.accept();
				new SingleClientSomma(socket).start();
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
			new ServerSomma(PORT).run();
		} catch (IOException e) {
			System.err.println(e.getMessage());
		}
	}
}

class SingleClientSomma extends Thread {

	private Socket socket;
	private ObjectInputStream inStream;
	private ObjectOutputStream outStream;

	SingleClientSomma(Socket socket) throws IOException {
		this.socket = socket;
		inStream = new ObjectInputStream(socket.getInputStream());
		outStream = new ObjectOutputStream(socket.getOutputStream());
	}

	public void run() {
		try {
			int a = (int) inStream.readObject();
			int b = (int) inStream.readObject();
			int sum = a + b;
			outStream.writeObject(sum);
		} catch (IOException e) {
			System.err.println(socket + ": " + e.getMessage());
		} catch (ClassNotFoundException e) {
			System.err.println(socket + ": " + e.getMessage());
		}
	}	
}
