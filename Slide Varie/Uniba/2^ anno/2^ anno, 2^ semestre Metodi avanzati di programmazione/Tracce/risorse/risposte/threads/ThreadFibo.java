
public class ThreadFibo extends Thread {

	private String name;

	private int mills;

	public ThreadFibo(String name, int mills) {
		this.name = name;
		this.mills = mills;
	}

	@Override
	public void run() {
		long i = 0;
		long j = 1;

		System.out.println(name + ": " + i);
		
		try {
			Thread.sleep(mills);
		} catch (InterruptedException e) {
			System.err.println(name + ": " + e);
			return;
		}
		
		System.out.println(name + ": " + j);

		try {
			Thread.sleep(mills);
		} catch (InterruptedException e) {
			System.err.println(name + ": " + e);
			return;
		}

		while (true) {
			long sum = i + j;
			i = j;
			j = sum;

			System.out.println(name + ": " + sum);

			try {
				Thread.sleep(mills);
			} catch (InterruptedException e) {
				System.err.println(name + ": " + e);
				return;
			}
		}
	}

	public static void main(String[] args) {
		new ThreadFibo("A", 1000).start();
		new ThreadFibo("B", 2000).start();
	}
}
