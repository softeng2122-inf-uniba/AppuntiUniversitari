package sequenzeBiologiche;
import listaSemplice.*;
public abstract class  Polimero {
	protected ListaSemplice sequenza=null;
	
	public String toString(){
		String s= "";
		
		while (sequenza.hasNext()){
			s=s+((Monomero)sequenza.next()).getSymbol();
		}
		
		return s;
	}
}
