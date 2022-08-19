import java.io.FileNotFoundException;

class MainTest {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws FileNotFoundException{
		Data trainingSet= new Data("servo.dat");
		
		RegressionTree tree=new RegressionTree(trainingSet);
		
		tree.printRules();
		
		tree.printTree();
		
	}

}
