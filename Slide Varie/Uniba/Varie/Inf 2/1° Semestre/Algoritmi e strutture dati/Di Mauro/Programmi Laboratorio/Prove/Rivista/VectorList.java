package Rivista;

import java.util.Iterator;

public class VectorList<S> implements AddOnlyList<S> {

	 Object[] S = new Object[1];
	 int n = 0;

	@Override
	public Iterator<S> iterator() {
		return new VectorListIterator(this);
	}

	public String toString() {
		String res="";
		for(int i=0;i<n;i++)
			res+=" "+S[i].toString();
		return res;
	}

	

	@Override
	public void add(S e) {

		S[n] = e;
		n++;
		if (n == S.length) {
			Object[] temp = new Object[S.length * 2];
			for (int i = 0; i < n; i++)
				temp[i] = S[i];
			S = temp;
		}

	}
	public static void main(String[]args){
	}

}
