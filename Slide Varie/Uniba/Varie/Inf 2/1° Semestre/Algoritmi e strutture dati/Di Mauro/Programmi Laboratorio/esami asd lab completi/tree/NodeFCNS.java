package tree;

public class NodeFCNS <T> implements Node<T>{

	T info;
	NodeFCNS<T> padre,figlio,succ;
	Tree<T> albero;
	
	public NodeFCNS (T info){
		this.info=info;
	}

}
