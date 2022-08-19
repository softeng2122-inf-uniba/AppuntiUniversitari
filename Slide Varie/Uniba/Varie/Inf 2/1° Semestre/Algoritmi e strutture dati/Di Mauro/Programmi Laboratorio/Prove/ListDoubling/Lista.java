package ListDoubling;


public interface Lista extends Iterable<Object> {

	public boolean isEmpty();

	public Object readList(Posizione p);

	public void writeList(Object e, Posizione p);

	public Posizione firstList();

	public boolean endList(Posizione p);

	public Posizione succ(Posizione p);

	public Posizione pred(Posizione p);

	public void insert(Object e, Posizione p);

	public void remove(Posizione p);

}
