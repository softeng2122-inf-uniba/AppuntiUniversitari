package database;

public class Column{
	private String name;
	private String type;
	Column(String name,String type){
		this.name=name;
		this.type=type;
	}
	public String getColumnName(){
		return name;
	}
	public boolean isNumber(){
		return type.equals("number");
	}
	public String toString(){
		return name+":"+type;
	}
}