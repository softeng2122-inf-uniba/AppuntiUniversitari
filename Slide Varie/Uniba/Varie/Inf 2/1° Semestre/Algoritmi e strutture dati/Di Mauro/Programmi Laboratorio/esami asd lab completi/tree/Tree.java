package tree;

public interface Tree <T> extends Iterable<T>{
	
	public boolean isEmpty();
	public void addRoot(T info);
	public Node<T> root();
	public Node<T> parent(Node<T> v);
	public boolean isLeaf(Node<T> v);
	public Node<T> firstChild(Node<T> v);
	public Node<T> nextChild(Node<T> v);
	public boolean endSiblings(Node<T> v);
	public void addFirstSubTree(Node<T> u,Tree<T> a);
	public void addSubbTree(Node<T> u, Tree<T> a);
	public int noNodes();
	public T getInfo(Node<T> v);
	public void setInfo(Node<T> v, T info);
}
