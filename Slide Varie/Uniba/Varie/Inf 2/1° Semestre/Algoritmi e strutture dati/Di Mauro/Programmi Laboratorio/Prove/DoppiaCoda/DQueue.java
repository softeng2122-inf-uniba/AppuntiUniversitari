package DoppiaCoda;

public interface DQueue<T> {
	
	public void push(T elem);
	public void pop();
	public boolean isEmpty();
	public T top();
	
	public void dequeue();
	public T first();
	
	
	

}
