package Biblioteca2;

import java.util.Iterator;

public class DoubleLinkedList<T> implements AddOnlyList<T> {

	Puntatore inizio, fine = null;
	int n;

	@Override
	public Iterator<T> iterator() {
		return new DoubleLinkedListIterator(this);
	}

	@Override
	public void add(T e) {

		if (inizio == null) {

			Puntatore p = new Puntatore(new Cella(e));
			inizio = fine = p;
			n++;

		} else {
			Puntatore temp = fine;
			fine.c.next = new Puntatore(new Cella(e));
			fine = fine.c.next;
			fine.c.prev = temp;
			temp.c.next = fine;
			n++;

		}

	}
	public String toString(){
		String res = "";
		
		for(T str:this){
			
			res+=" "+str.toString();
			
			
		}
		return res;
	}
	
	public static void main(String[]args){
		
		
	DoubleLinkedList<String> list= new DoubleLinkedList<String>();
	list.add("ciao");
	list.add("auee");
	list.add("minchia");
	DoubleLinkedList<String>list2= new DoubleLinkedList<String>();
	list2.add("ciao");
	list2.add("auee");
	list2.add("minchia");

	
	Volume vol1= new Volume ("m","d",1,list);
	Volume vol2= new Volume("m", "d",1, list2);
	
	
		
		
		
		
	}

}
