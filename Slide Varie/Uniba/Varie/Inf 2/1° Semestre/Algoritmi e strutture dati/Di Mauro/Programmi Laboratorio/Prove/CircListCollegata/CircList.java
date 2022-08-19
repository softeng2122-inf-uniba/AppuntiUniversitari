package CircListCollegata;

public class CircList {

	Puntatore inizioLista, ultimoLista = null;

	public boolean isEmpty() {
		return inizioLista == null;
	}

	public void add(Object e) {

		if (isEmpty()) {
			inizioLista=ultimoLista=new Puntatore (new Cella(e));
			
		} else {
			Puntatore temp = ultimoLista;
			ultimoLista.cell.next = new Puntatore(new Cella(e));
			ultimoLista = ultimoLista.cell.next;
			ultimoLista.cell.prev=temp;
			temp.cell.next=ultimoLista;
		}

	}

	public void delCircList() {

		if (inizioLista.cell.next == inizioLista)
			inizioLista = null;
		else {
			inizioLista.cell.next.cell.prev = inizioLista.cell.prev;
			inizioLista.cell.prev.cell.next = inizioLista.cell.next;
			inizioLista = inizioLista.cell.next;

		}

	}
	public Object value(){
		
		return inizioLista.cell.elem;
		
		
	}
	public static void main(String[]args){
		CircList list= new CircList();
		
	
		list.add("ciao");
		list.add("mi chiamo");
		list.add("alessandro");

		
		
		
	}

}
