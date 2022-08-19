package tree;

import java.util.Iterator;
import java.util.LinkedList;

public class TreeFCNSIterator<T> implements Iterator<T> {
	
	private int i=0;
	private LinkedList<Node<T>> visitati= new LinkedList<Node<T>>();
	private Tree<T> albero;
	
	public TreeFCNSIterator(Tree<T> a){
		this.albero=a;
		visitaAmpiezza();
	}
	
	@Override
	public boolean hasNext() {
		return (i<visitati.size());
	}

	@Override
	public T next() {
		NodeFCNS<T> n=(NodeFCNS)visitati.get(i);
		T elemRes= n.info;
		i++;
		return elemRes;
 	}

	@Override
	public void remove() {
		// TODO Auto-generated method stub
		
	}
	
	
	private void visitaAmpiezza () {
		if (albero.isEmpty()) return;
		LinkedList<Node<T>> daVisitare= new LinkedList<Node<T>>();
		daVisitare.add(albero.root());
		while (!daVisitare.isEmpty()){
			NodeFCNS<T> n= (NodeFCNS<T>)daVisitare.get(0);
			daVisitare.remove(0);
			visitati.add(n);
			if (!albero.isLeaf(n)) {
				NodeFCNS<T> z= n.figlio;
				daVisitare.add(z);
				while (!albero.endSiblings(z)){
					z=z.succ;
					daVisitare.add(z);
				}
			}
		}
	}

}
