package pq;

public interface PQ<Item> extends Iterable<Item> {
	
	public boolean isNew();
	public void insert (Item i, int p);
	public Item first();
	public void delFirst();
	public void changePriority(Item i, int p);
	public int getPriority(Item i );
	public int size();
	
}
