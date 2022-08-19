
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.IOException;
import java.net.Socket;
import java.net.InetAddress;

public class ClientSomma {
	private Socket socket;
	private ObjectInputStream inStream;
	private ObjectOutputStream outStream;

	ClientSomma(String ip, int port) throws IOException {
		InetAddress addr = InetAddress.getByName(ip);
		socket = new Socket(addr, port);
		outStream = new ObjectOutputStream(socket.getOutputStream());
		inStream = new ObjectInputStream(socket.getInputStream());
	}

	void run() {
		try {
			BufferedReader reader = new BufferedReader(
				new InputStreamReader(
					System.in
				)
			);

			System.out.print("First number: ");
			int a = Integer.parseInt(reader.readLine());

			System.out.print("Second number: ");
			int b = Integer.parseInt(reader.readLine()); 

			outStream.writeObject(a);
			outStream.writeObject(b);

			int sum = (int) inStream.readObject();

			System.out.println("The sum is: " + sum);

		} catch (IOException e) {
			System.err.println(e.getMessage());
		} catch (ClassNotFoundException e) {
			System.err.println(e.getMessage());
		} finally {
			try {
				socket.close();
			} catch (IOException e) {
				System.err.println(e.getMessage());
			}
		}
	}

	public static void main(String[] args) {
		try {
			new ClientSomma("127.0.0.1", 8080).run();
		} catch (IOException e) {
			System.err.println(e.getMessage());
		}
	}
}
