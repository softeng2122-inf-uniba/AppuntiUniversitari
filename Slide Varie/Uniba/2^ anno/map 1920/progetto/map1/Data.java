import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;



public class Data {
	
	private Object data [][];
	private int numberOfExamples;
	private Attribute explanatorySet[];
	private ContinuousAttribute classAttribute;
	
	Data(String fileName)throws FileNotFoundException{
		
		  File inFile = new File (fileName);

		  Scanner sc = new Scanner (inFile);
	      String line = sc.nextLine();
	      if(!line.contains("@schema"))
	    	  throw new RuntimeException("Errore nello schema");
	      String s[]=line.split(" ");

		  //popolare explanatory Set 
	      //@schema 4
			
		  explanatorySet = new Attribute[new Integer(s[1])];
		  short iAttribute=0;
	      line = sc.nextLine();
	      while(!line.contains("@data")){
	    	  s=line.split(" ");
	    	  if(s[0].equals("@desc"))
	    	  { // aggiungo l'attributo allo spazio descrittivo
		    		//@desc motor discrete A,B,C,D,E  
		    		  String discreteValues[]=s[2].split(",");
		    		  explanatorySet[iAttribute] = new DiscreteAttribute(s[1],iAttribute, discreteValues);
		      }
	    	  else if(s[0].equals("@target"))
	    			  classAttribute=new ContinuousAttribute(s[1], iAttribute);
	    			  
	    	  iAttribute++;
	    	  line = sc.nextLine();
	    	  
	      }
		      
		  //avvalorare numero di esempi
	      //@data 167
	      numberOfExamples=new Integer(line.split(" ")[1]);
	      
	      //popolare data
	      data=new Object[numberOfExamples][explanatorySet.length+1];
	      short iRow=0;
	      while (sc.hasNextLine())
	      {
	    	  line = sc.nextLine();
	    	  // assumo che attributi siano tutti discreti
	    	  s=line.split(","); //E,E,5,4, 0.28125095
	    	  for(short jColumn=0;jColumn<s.length-1;jColumn++)
	    		  data[iRow][jColumn]=s[jColumn];
	    	  data[iRow][s.length-1]=new Double(s[s.length-1]);
	    	  iRow++;
	    	  
	      }
		    sc.close();

		
		
		
		

	}
	
	public String toString(){
		String value="";
		for(int i=0;i<numberOfExamples;i++){
			for(int j=0;j<explanatorySet.length;j++)
				value+=data[i][j]+",";
			
			value+=data[i][explanatorySet.length]+"\n";
		}
		return value;
		
		
	}


	void sort(Attribute attribute, int beginExampleIndex, int endExampleIndex){
	
			quicksort(attribute, beginExampleIndex, endExampleIndex);
	}
	
	// scambio esempio i con esempi oj
	private void swap(int i,int j){
		Object temp;
		for (int k=0;k<getNumberOfExplanatoryAttributes()+1;k++){
			temp=data[i][k];
			data[i][k]=data[j][k];
			data[j][k]=temp;
		}
		
	}
	

	
	
	/*
	 * Partiziona il vettore rispetto all'elemento x e restiutisce il punto di separazione
	 */
	private  int partition(DiscreteAttribute attribute, int inf, int sup){
		int i,j;
	
		i=inf; 
		j=sup; 
		int	med=(inf+sup)/2;
		String x=(String)getExplanatoryValue(med, attribute.getIndex());
		swap(inf,med);
	
		while (true) 
		{
			
			while(i<=sup && ((String)getExplanatoryValue(i, attribute.getIndex())).compareTo(x)<=0){ 
				i++; 
				
			}
		
			while(((String)getExplanatoryValue(j, attribute.getIndex())).compareTo(x)>0) {
				j--;
			
			}
			
			if(i<j) { 
				swap(i,j);
			}
			else break;
		}
		swap(inf,j);
		return j;

	}
	
	/*
	 * Algoritmo quicksort per l'ordinamento di un array di interi A
	 * usando come relazione d'ordine totale "<="
	 * @param A
	 */
	private void quicksort(Attribute attribute, int inf, int sup){
		
		if(sup>=inf){
			
			int pos;
			
			pos=partition((DiscreteAttribute)attribute, inf, sup);
					
			if ((pos-inf) < (sup-pos+1)) {
				quicksort(attribute, inf, pos-1); 
				quicksort(attribute, pos+1,sup);
			}
			else
			{
				quicksort(attribute, pos+1, sup); 
				quicksort(attribute, inf, pos-1);
			}
			
			
		}
		
	}
	
	public static void main(String args[])throws FileNotFoundException{
		Data trainingSet=new Data("servo.dat");
		System.out.println(trainingSet);
		
		
		
		for(int jColumn=0;jColumn<trainingSet.getNumberOfExplanatoryAttributes();jColumn++)
		{
			System.out.println("ORDER BY "+trainingSet.getExplanatoryAttribute(jColumn));
			trainingSet.quicksort(trainingSet.getExplanatoryAttribute(jColumn),0 , trainingSet.getNumberOfExamples()-1);
			System.out.println(trainingSet);
		}
		

	
	
	
	}

}
