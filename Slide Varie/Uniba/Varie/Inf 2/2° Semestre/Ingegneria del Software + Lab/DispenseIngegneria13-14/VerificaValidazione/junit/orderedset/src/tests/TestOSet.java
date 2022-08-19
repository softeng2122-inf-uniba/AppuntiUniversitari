package tests;

import domain.OrderedSet;
import exceptions.NumberTooBigException;
import exceptions.NumberTooSmallException;
import junit.framework.TestCase;

/**
 * 
 * This class is a JUnit Test suite that contains tests 
 * cases to test the class "OrderedSet".
 * It extends the class "TestCase". This indicates
 * to the JUnit framework that the class is a test suite,
 * thus all the method of this class that their name starts with
 * the word "test" will be considered as test cases. 
 *
 */
public class TestOSet extends TestCase {

	//A default constructor.
	public TestOSet(String name) {
		super(name);
	}

	//This field represent the system under test. This filed
	//will be initialized for each test case and it will be used
	//to check the behavior of the OrderedSet class.
	private OrderedSet fixture;
	
	//This method is the setUp method provided by the JUnit framework.
	//It is executed by the framework before each test case.
	//This method will initialize the fixture before each test, thus
	//before the execution of each test case, an empty ordered set
	//will be available.
	protected void setUp() throws Exception {
		super.setUp();
		fixture = new OrderedSet();
	}

	//This method is a test case, since its name start with the word "test"
	//It implements the test case: "insert the value 3 in the ordered set".
	//The test case execute the "addElement" method of the class "OrderedSet",
	//and then, it checks if the set really contains the inserted number.
	public void testAddElement() throws Exception {
		fixture.addElement(3);
		
		//The next instruction is the oracle of the test.
		//It check that the set really contains the element 
		//inserted in the previous instruction
		assertTrue(fixture.contains(3));
	}

	
	//This method is a test case, since its name start with the word "test"
	//It implements the test case: "get the element in the position 0 from a
	//set that contains only the value 4".
	//The test case execute the "addElement" method of the class "OrderedSet"
	//in order to put the system under test in the correct state (a set that only
	//contains the value 4), and then the test executes the method "getElement"
	//to obtain the value in the position 0. Finally, the test checks that
	//the obtained element is the value 4.
	public void testGetElement() throws Exception {
		fixture.addElement(4);
		int a = fixture.getElement(0);
		
		//The next instruction is the oracle of the test.
		//It check that the obtained value 
		//is the value that we expected, value 4
		assertTrue(a==4);
	}

	//This method is a test case, since its name start with the word "test"
	//It implements the test case: "remove the value 5 from a
	//set that contains only the value 5".
	//The test case execute the "addElement" method of the class "OrderedSet"
	//in order to put the system under test in the correct state (a set that only
	//contains the value 5), and then the test executes the method "removeElement"
	//to remove the value 5. Finally, the test checks that
	//the value 5 is not included in the ordered set.
	public void testRemoveElement() throws Exception {
		fixture.addElement(5);
		fixture.removeElement(5);

		//The next instruction is the oracle of the test.
		//It check that the set really the value 5 was 
		//remove from the set
		assertTrue(!fixture.contains(5));
	}
	
	//This method is a test case, since its name start with the word "test"
	//It implements the test case: "insert the value 1 in an empty set".
	//The test case execute the "addElement" method of the class "OrderedSet"
	//in order to add the value 1.Then, the test checks that
	//the returned value is true, since the number one was not previously
	//included.
	public void testIsIncluded() throws Exception{
		boolean r = fixture.addElement(1);

		//The next instruction is the oracle of the test.
		//It check that the result value is true, 
		//since value 1 was not included in the set previously.
		assertTrue(r==true);
	}
	
	
	//This method is a test case, since its name start with the word "test"
	//It implements the test case: "insert a number lower than 0".
	//The test case execute the "addElement" method of the class "OrderedSet"
	//in order to insert a number lower than 0. Then, the test checks that
	//exception throw by the system is of type "NumberTooSmallException".
	public void testTooSmallNumber(){
		
		try{
			fixture.addElement(-1);
			//If the next instruction is executed, there is an error in the system because
			//an exception must be thrown when a number lower than 0 is inserted in the set.
			fail("No exception thrown"); 
		}catch(NumberTooSmallException e){
			assertTrue(e.getMessage().equals("The value is lower than 0"));
		}catch(NumberTooBigException e){
			//If this catch block is executed, there is an error in the system because
			//the exception caught by this block is not the exception
			//that must be thrown when a number lower than 0 is inserted in the set.
			fail();
		}catch(Exception e){
			//If this catch block is executed, there is an error in the system because
			//the exception caught by this block is not the exception
			//that must be thrown when a number lower than 0 is inserted in the set.
			fail();
		}
	}
	
	

	//This method is a test case, since its name start with the word "test"
	//It implements the test case: "insert a number bigger than 1000".
	//The test case execute the "addElement" method of the class "OrderedSet"
	//in order to insert a number bigger than 1000. Then, the test checks that
	//exception throw by the system is of type "NumberTooBigException".
	public void testTooBigNumber(){
		try{
			fixture.addElement(1100);
			//If the next instruction is executed, there is an error in the system because
			//an exception must be thrown when a number lower than 0 is inserted in the set.
			fail("No exception thrown");
		}catch(NumberTooSmallException e){
			//If this catch block is executed, there is an error in the system because
			//the exception caught by this block is not the exception
			//that must be thrown when a number lower than 0 is inserted in the set.
			fail();
		}catch(NumberTooBigException e){
			assertTrue(e.getMessage().equals("The number is bigger than 1000"));
		}catch(Exception e){
			//If this catch block is executed, there is an error in the system because
			//the exception caught by this block is not the exception
			//that must be thrown when a number lower than 0 is inserted in the set.
			fail();
		}
	}
}

