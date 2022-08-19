
import java.util.List;
import java.util.LinkedList;

public class FunctionalReduceSum {
	public static void main(String[] args) {
		List<Integer> list = new LinkedList<Integer>();
		list.add(2);
		list.add(3);
		list.add(4);
		list.add(6);
		list.add(9);
		
		System.out.println(sum(list));
		System.out.println(sumEven(list));
	}

	static int sum(List<Integer> list) {
		int sum;

		sum = list.stream()
			.reduce(0, (a, b) -> a + b);

		return sum;
	}

	static int sumEven(List<Integer> list) {
		int sum;

		sum = list.stream()
			.filter(i -> (i % 2 == 0))
			.reduce(0, (a, b) -> a + b);

		return sum;
	}
}
