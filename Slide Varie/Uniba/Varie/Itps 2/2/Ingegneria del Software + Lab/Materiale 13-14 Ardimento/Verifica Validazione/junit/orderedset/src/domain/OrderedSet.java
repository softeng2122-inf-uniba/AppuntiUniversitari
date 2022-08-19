package domain;

import java.util.Vector;

import exceptions.NumberTooBigException;
import exceptions.NumberTooSmallException;


/*
 * This class implements an ordered set of integer values.
 * There are four features of this set:
 * 1- The set cannot contain repeated elements.
 * 2- The elements must be ordered, from smallest to largest.
 * 3- The set does not accept elements lower than 0
 * 4- The set does not accept elements bigger than 1000
 */

public class OrderedSet {

	//The integer values of the set are stored in a vector.
	//The implementation of the method is responsible
	//too fulfill the features of the ordered set.
	Vector<Integer> set;
	
	//constructor of the class
	public OrderedSet(){
		set=new Vector<Integer>();
	}
	
	//This method is used to insert an integer value in the set.
	//This method check if the the value is too big or too small
	//and if the value is already in the set.
	//Also this method is responsible to insert the integer value
	//in the correct place in order to keep the integer values ordered
	public boolean addElement(int n)throws Exception{
		
		//If the value n is too big or too small an exception is throw
		if(n<0){
			throw new NumberTooSmallException("The value is lower than 0");
		}else if(n > 1000){
			throw new NumberTooBigException("The number is bigger than 1000");
		}
		
		//If the value is already in the set, it is not inserted.
		boolean inserted = false;
		if(!set.contains(n)){
			
			//If the value must be inserted, the correct place in searched
			for(int i = 0; i<set.size() && !inserted;i++){
				if(set.get(i)>n){
					set.add(i, n);
					inserted = true;
				}
			}
			if(!inserted){
				set.add(n);
				inserted=true;
			}
		}
		
		//Finally, this method return if the value was inserted or not
		return inserted;
	}
	
	
	//This method remove an element from the ordered set
	//This method check is the element is the set. In that case
	//the element is removed.
	public void removeElement(int n){
		if(set.contains(n)){
			boolean removed = false;
			for(int i = 0; i<set.size() && !removed;i++){
				if(set.get(i)==n){
					set.remove(i);
					removed = true;
				}
			}
		}
	}
	
	//This method return the element in the position "pos"
	public int getElement(int pos){
		return this.set.get(pos);
	}
	
	//This method return the first element of the ordered set
	public int getFirst(){
		return this.set.get(0);
	}
	
	//This method return the first element of the ordered set
	public int getLast(){
		return this.set.get(this.set.size()-1);
	}
	
	//This method return the number of values included in the ordered set
	public int size(){
		return this.set.size();
	}
	
	//This method determines if a concrete value is included in the set
	public boolean contains(int n){
		return this.set.contains(n);
	}
}
