
import java.util.List;
import java.util.LinkedList;
import java.util.function.IntConsumer;

class Variance implements IntConsumer {
	private int sum = 0;
	private int sqsum = 0;
	private int count = 0;

	public double variance() {
		double meanSum = (double) sum / count;
		double meanSqsum = (double) sqsum / count;
		return meanSqsum - meanSum * meanSum;
	}

	public void accept(int i) {
		sum += i;
		sqsum += i * i;
		count++;
	}

	public void combine(Variance variance) {
		sum += variance.sum;
		sqsum += variance.sqsum;
		count += variance.count;
	}
}

public class FunctionalCollectVariance {

	public static void main(String[] args) {
		List<Integer> list = new LinkedList<Integer>();
		for (int i = 0; i < 10; i++) {
			list.add(i);
		}

		System.out.println(varianceList(list));
	}

	static double varianceList(List<Integer> list) {
		Variance variance = list.stream()
			.collect(Variance::new,
			         Variance::accept,
			         Variance::combine);
		return variance.variance();
	}
}
