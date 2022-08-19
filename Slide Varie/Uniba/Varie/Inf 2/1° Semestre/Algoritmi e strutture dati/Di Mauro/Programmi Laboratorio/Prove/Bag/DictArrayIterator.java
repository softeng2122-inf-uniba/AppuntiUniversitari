package Bag;

import java.util.Iterator;

public class DictArrayIterator<K> implements Iterator<K> {
	
	DictArray diz;
	int n;
	
	 public DictArrayIterator(DictArray diz) {
		this.diz=diz;
		this.n=0;
	}

	@Override
	public boolean hasNext() {
		return diz.S[n]!=null;
	}

	@Override
	public K next() {
		int p=n;
		n++;
		return (K) ((Coppia)diz.S[p]).key;
	}

	@Override
	public void remove() {
		// TODO Auto-generated method stub
		
	}

}
