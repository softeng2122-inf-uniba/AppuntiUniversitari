
public class Synchronized {

	private TwoCounter tc = new TwoCounter();

	Synchronized() {
		tc.start();
		new Watcher();
	}

	class TwoCounter extends Thread {
		private int a = 0;
		private int b = 0;

		public void run() {
			while (true) {
				increment();

				try {
					Thread.sleep(500);
				} catch (InterruptedException e) {
					System.err.println("interrupted");
				}
			}
		}

		synchronized void increment() {
			a++;
			b++;
		}

		synchronized public void check() {
			System.out.println("A: " + a + " B: " + b);
		}
	}

	class Watcher extends Thread {
		Watcher() {
			start();
		}

		public void run() {
			while (true) {
				tc.check();

				try {
					Thread.sleep(500);
				} catch (InterruptedException e) {
					System.err.println("interrupted");
				}
			}
		}
	}

	public static void main(String[] args) {
		new Synchronized();
	}
}
