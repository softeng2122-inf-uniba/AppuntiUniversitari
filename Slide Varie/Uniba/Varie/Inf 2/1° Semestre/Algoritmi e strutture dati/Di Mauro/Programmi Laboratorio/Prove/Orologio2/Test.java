package Orologio2;

public class Test {
	
	public static void main(String[]args){
		
		OrologioDaPolso or1= new OrologioDaPolso();
		OrologioDaPolso or2 = new OrologioDaPolso();
		
		or1.start();
		System.out.println(or1.equals(or2));
		
		
	}

}
