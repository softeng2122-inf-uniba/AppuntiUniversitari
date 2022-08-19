package PriorityQueue;

import java.util.Iterator;
import java.util.List;

import PriorityQueue.Exceptions.CodaVuotaException;
import PriorityQueue.Interface.PQ;

public abstract class PQL<Item> implements PQ<Item> {

	List<Record> coda;

	class PQLIterator implements Iterator<Item> {

		PQL<Item> pq;
		Record pos;
		Iterator<Record> it;

		public PQLIterator(PQL<Item> pql) {
			pq = pql;
			pos = null;
			it = pq.coda.iterator();
		}

		@Override
		public boolean hasNext() {
			return it.hasNext();
		}

		@Override
		public Item next() {
			return it.next().it;
		}
	}

	class Record {
		private Item it;
		private int priority;

		public Record(Item it, int priority) {
			this.it = it;
			this.priority = priority;
		}
	}

	@Override
	public Iterator<Item> iterator() {
		return new PQLIterator(this);
	}

	@Override
	public boolean isNew() {
		return coda.isEmpty();
	}

	@Override
	public void insert(Item item, int priority) {
		coda.add(new Record(item, priority));

	}

	@Override
	public Item first() {
		if (isNew())
			throw new CodaVuotaException("La coda è vuota!");
		else {
			coda.iterator();
			Record first = coda.get(0);
			for (Record rec : coda) {
				if (rec.priority > first.priority)
					first = rec;
			}
			return first.it;

		}
	}

	@Override
	public void delFirst() {
		if(isNew())
			throw new CodaVuotaException("La coda è vuota!");
		Record first = coda.get(0);
		for (Record rec : coda) {
			if (rec.priority > first.priority)
				first = rec;
		}
		coda.remove(coda.indexOf(first));

	}

	@Override
	public void changePriority(Item item, int priority) {

		for (Record rec : coda) {
			if (rec.it.equals(item))
				rec.priority = priority;
		}
		throw new ItemNonPresenteException("Item non presente nella coda");

	}

	@Override
	public int getPriority(Item item) {
		for (Record rec : coda) {
			if (rec.it.equals(item))
				return rec.priority;
		}
		throw new ItemNonPresenteException("Item non presente nella coda");
	}

	@Override
	public int size() {
		return coda.size();
	}

}
