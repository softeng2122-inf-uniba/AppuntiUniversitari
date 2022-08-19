
import java.io.*;
import java.net.*;

public class Client {

	private Socket socket;
	private ObjectInputStream in;
	private ObjectOutputStream out;

	Client(String ip, int port) throws IOException {
		InetAddress addr = InetAddress.getByName(ip);
		socket = new Socket(addr, port);
		out = new ObjectOutputStream(socket.getOutputStream());
		in = new ObjectInputStream(socket.getInputStream());
	}

	void execute() {
		try {
			BufferedReader keyboard = new BufferedReader(
				new InputStreamReader(System.in)
			);

			while (true) {
				System.out.print("0: exit, 1: sum, 2: product = ");

				Integer choice = Integer.parseInt(keyboard.readLine());

				if (choice == 0) {
					break;
				} else if (choice > 2) {
					continue;
				}

				System.out.print("Enter the first number: ");
				Integer first = Integer.parseInt(keyboard.readLine());

				System.out.print("Enter the second number: ");
				Integer second = Integer.parseInt(keyboard.readLine());

				out.writeObject(choice);
				out.writeObject(first);
				out.writeObject(second);

				System.out.println("Result: " + (Integer) in.readObject());
			}
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
			new Client("localhost", 8080).execute();
		} catch (IOException e) {
			System.err.println(e.getMessage());
		}
	}
}
