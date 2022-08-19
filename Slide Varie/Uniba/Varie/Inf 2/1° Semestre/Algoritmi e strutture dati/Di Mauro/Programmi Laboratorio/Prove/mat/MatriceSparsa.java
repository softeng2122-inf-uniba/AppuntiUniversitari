package mat;

import java.util.ArrayList;

public class MatriceSparsa<T> {

	protected ArrayList<Record<T>>[]valori=new ArrayList[1];
	
	
	private class Record<T>{
		
		T elem;
		
		public Record(T e){
			elem=e;
		}
		
		
	}
	void add(){
		valori[0]=new ArrayList();
		valori[0].add(new Record("ciao"));
	}
	public static void main(String[]args){
		MatriceSparsa<String>mat=new MatriceSparsa<String>();
		mat.add();
		System.out.println(mat.valori[0].toString());
	}
	
}
