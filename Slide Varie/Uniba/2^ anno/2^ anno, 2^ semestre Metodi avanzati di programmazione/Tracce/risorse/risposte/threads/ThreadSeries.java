
public class ThreadSeries implements Runnable {

	private int x;

	private Thread thread;

	public ThreadSeries(int x) {
		this.x = x;
		thread = new Thread(this);
		thread.start();
	}

	@Override
	public void run() {
		while (true) {
			System.out.println(x++);
		}
	}

	public static void main(String[] args) {
		for (int i = 0; i < 10; i++) {
			new ThreadSeries(i);
		}
	}
}
