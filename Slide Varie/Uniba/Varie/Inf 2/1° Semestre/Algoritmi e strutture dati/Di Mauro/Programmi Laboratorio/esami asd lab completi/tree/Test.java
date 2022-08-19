package tree;

public class Test {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Tree<Integer> t1= new TreeFCNS<Integer>();
		Tree<Integer> t3= new TreeFCNS<Integer>();
		Tree<Integer> t2= new TreeFCNS<Integer>();
		Tree<Integer> t4= new TreeFCNS<Integer>();
		Tree<Integer> t5= new TreeFCNS<Integer>();
		Tree<Integer> t6= new TreeFCNS<Integer>();
		Tree<Integer> t7= new TreeFCNS<Integer>();
		t1.addRoot(1);
		t2.addRoot(2);
		t3.addRoot(3);
		t4.addRoot(4);
		t5.addRoot(5);
		t6.addRoot(6);
		t7.addRoot(7);
		
		t3.addFirstSubTree(t3.root(), t5);
		t3.addFirstSubTree(t3.root(), t4);
		t3.addSubbTree(t3.firstChild(t3.root()), t7);
		t1.addFirstSubTree(t1.root(), t3);
		t1.addFirstSubTree(t1.root(), t2);
		t1.addSubbTree(t1.firstChild(t1.root()), t6);
		
		for (Integer i: t1){
			System.out.println(i);
		}
		
	}

}
