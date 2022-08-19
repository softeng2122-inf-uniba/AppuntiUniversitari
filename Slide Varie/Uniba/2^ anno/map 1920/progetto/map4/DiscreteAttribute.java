package data;

import java.util.Iterator;
import java.util.Set;
import java.util.TreeSet;

public class DiscreteAttribute extends Attribute implements Iterable<String>{
	private Set<String> values=new TreeSet<>(); // order by asc
	
	public DiscreteAttribute(String name, int index, Set<String> values) {
		super(name,index);
		this.values=values;
	}
	
	public int getNumberOfDistinctValues(){
		return values.size();
	}

	@Override
	public Iterator<String> iterator() {
		// TODO Auto-generated method stub
		return values.iterator();
	}
	
	
}
