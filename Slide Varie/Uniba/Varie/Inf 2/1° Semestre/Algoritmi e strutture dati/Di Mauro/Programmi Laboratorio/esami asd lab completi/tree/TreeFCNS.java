package tree;

import java.util.Iterator;

public class TreeFCNS<T> implements Tree<T> {

	private NodeFCNS<T> radice=null;
	

	public Iterator<T> iterator() {
		return new TreeFCNSIterator<T>(this);
	}


	public boolean isEmpty() {
		return (radice==null);
	}

	
	public void addRoot(T info) {
		if (radice!=null) throw new EccezioneNodoNonValido("l'albero è già dotato di radice");
		radice= new NodeFCNS<T>(info);	
		radice.albero=this;
	}

	
	public Node<T> root() {
		if (radice==null) throw new EccezioneNodoInesistente("l'albero non ha una radice");
	    return radice;
	}

	@Override
	public Node<T> parent(Node<T> v) {
		if (checkNode(v)) throw new EccezioneNodoNonValido("nodo non valido");
		return ((NodeFCNS<T>)v).padre;
	}

	@Override
	public boolean isLeaf(Node<T> v) {
		if (checkNode(v)) throw new EccezioneNodoNonValido("nodo non valido");
		return (((NodeFCNS<T>)v).figlio==null);
	}

	@Override
	public Node<T> firstChild(Node<T> v) {
		if (checkNode(v)) throw new EccezioneNodoNonValido("nodo non valido");
		return ((NodeFCNS<T>)v).figlio;
	}

	@Override
	public Node<T> nextChild(Node<T> v) {
		if (checkNode(v)) throw new EccezioneNodoNonValido("nodo non valido");
		return ((NodeFCNS<T>)v).succ;
	}

	@Override
	public boolean endSiblings(Node<T> v) {
		if (checkNode(v)) throw new EccezioneNodoNonValido("nodo non valido");
		return (((NodeFCNS<T>)v).succ==null);
	}

	@Override
	public void addFirstSubTree(Node<T> u, Tree<T> a) {
		if (checkNode(u)) throw new EccezioneNodoNonValido("nodo non valido");
		if (a.isEmpty()) return ;
		
		NodeFCNS<T> n= (NodeFCNS)u;
		NodeFCNS<T> z= (NodeFCNS)a.root();
		
		z.succ=n.figlio;
		n.figlio=z;
		z.padre=n;
		((TreeFCNS<T>)a).radice=null;
		updateIdAlbero(n.figlio);
	}


	public void addSubbTree(Node<T> u, Tree<T> a) {
		if (checkNode(u)) throw new EccezioneNodoNonValido("nodo non valido");
		if (a.isEmpty()) return ;
		
		NodeFCNS<T> n= (NodeFCNS)u;
		NodeFCNS<T> z= (NodeFCNS)a.root();
		
		z.succ=n.succ;
		n.succ=z;
		z.padre=n.padre;
		((TreeFCNS<T>)a).radice=null;
		updateIdAlbero(n.succ);
	}

	@Override
	public int noNodes() {
		int n=0;
		for (T i: this) {
			n++;
		}
		return n;
	}

	@Override
	public T getInfo(Node<T> v) {
		if (checkNode(v)) throw new EccezioneNodoNonValido("nodo non valido");
		return ((NodeFCNS<T>)v).info;
	}

	@Override
	public void setInfo(Node<T> v, T info) {
		if (checkNode(v)) throw new EccezioneNodoNonValido("nodo non valido");
		((NodeFCNS<T>)v).info=info;
	}

	private boolean checkNode(Node<T> v){
		if (v==null) return true;
		if (((NodeFCNS<T>)v).albero!=this) return true;
		return false ;
	}
	
	private void updateIdAlbero (Node<T> u ){
		((NodeFCNS<T>)u).albero=this;
		if (!isLeaf(u)) {
			Node <T> v= firstChild(u);
			while (((NodeFCNS)v).succ!=null) {
				updateIdAlbero(v);
				v=nextChild(v);
			}
			updateIdAlbero(v);
		}
	}
	
}
