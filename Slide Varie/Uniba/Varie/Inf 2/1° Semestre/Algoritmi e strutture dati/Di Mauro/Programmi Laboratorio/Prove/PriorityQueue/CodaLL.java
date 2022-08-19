package PriorityQueue;

import java.util.LinkedList;

public class CodaLL<Item> extends PQL<Item> {

	public CodaLL() {
		coda = new LinkedList<Record>();
	}

	public static void main(String[] args) {

		CodaLL<String> pq = new CodaLL<String>();
		pq.insert("aeee", 0);
		pq.insert("aasddd", 10);
		pq.insert("minchia", 7);

	}

}
