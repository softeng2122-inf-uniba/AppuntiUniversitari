
import java.util.List;
import java.util.LinkedList;
import java.util.function.IntConsumer;

class Mean implements IntConsumer {
	private int total = 0;
	private int count = 0;

	public double average() {
		return (double) total / count;
	}

	public void accept(int i) {
		total += i;
		count++;
	}

	public void combine(Mean mean) {
		total += mean.total;
		count += mean.count;
	}
}

public class FunctionalCollectMean {

	public static void main(String[] args) {
		List<Integer> list = new LinkedList<Integer>();
		for (int i = 0; i < 10; i++) {
			list.add(i);
		}

		System.out.println(meanList(list));
	}

	static double meanList(List<Integer> list) {
		Mean mean = list.stream()
			.collect(Mean::new, Mean::accept, Mean::combine);
		return mean.average();
	}
}
