package PriorityQueue;

import PriorityQueue.Enum.State;

public class Test {

	public static void main(String[] args) {

		CodaLL<Process> unrunnables = new CodaLL<Process>();
		CodaLL<Process> runnables = new CodaLL<Process>();
		CodaLL<Process> stopped = new CodaLL<Process>();

		for (int i = 1; i < 16; i++) {
			Process p = new Process("C:/"
					+ String.valueOf(i + (int) (Math.random() * 80)),
					(int) (Math.random() * 80));
			unrunnables.insert(p, p.getPriority());
		}
		for (Process i : unrunnables) {
			System.out.println(i);
		}

		System.out.println("\n \n"); // a capo

		while (unrunnables.size() > 0) {
			Process first = unrunnables.first();
			unrunnables.delFirst();
			first.setState();
			runnables.insert(first, first.getPriority());
		}
		for (Process i : runnables) {
			System.out.println(i);
		}

		while (runnables.size() > 0) {

			Process first = runnables.first();
			runnables.delFirst();

			int dado = (int) (Math.random() * 2);
			switch (dado) {
			case 0:
				first.setState();
				break;
			case 1:
				first.setState();
				first.setState();
				break;
			default:
				break;
			}
			if (first.getState().equals(State.STOP))
				stopped.insert(first, first.getPriority());
			else if (first.getState().equals(State.UNRUNNABLE))
				unrunnables.insert(first, first.getPriority());

		}

		System.out.println("\n \n");

		for (Process p : stopped)
			System.out.println(p);

		System.out.println("\n \n");

		for (Process p : unrunnables)
			System.out.println(p);

	}

}
