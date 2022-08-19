package Orologio2;

import java.util.Iterator;

public class OrologioIterator<S> implements Iterator<S> {

	Orologio<S> or;
	int n=0;
	
	public OrologioIterator(Orologio<S> or){
		this.or=or;
		n=0;
	}
	
	@Override
	public boolean hasNext() {
		return or.S[n]!=null;
	}

	@Override
	public S next() {
		int p=n;
		n++;
		return (S) or.S[p];
	}

}
