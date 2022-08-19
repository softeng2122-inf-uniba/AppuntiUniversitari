/**
* 	This is the input class. Using GUI, it takes the event from the user
*	and passes it to the mother class for creating the action and 
*	providing state transition. 
*/ 

import javax.swing.*;
import javax.swing.border.*;
import java.awt.*;
import java.awt.event.*;
import java.util.*;

public class GoBackNInput
{
	private int intInput, option;
	private String strInput, warning;
	boolean validInput;
  
	public int getIntInput (String message, int lowerLimit, int upperLimit)
	{
		strInput = JOptionPane.showInputDialog (null, message).trim();    
		do
		{   
			try
			{           
				intInput =  Integer.parseInt (strInput);              
				if ((intInput < lowerLimit) || (intInput > upperLimit))
				{
					throw new RangeException ("Out of range.");
				}
				validInput = true;
			}       
			catch (RangeException re)
			{
				warning =  "The input " + strInput + " is out of range.  "+ message;
				strInput  = JOptionPane.showInputDialog (null, warning).trim();    
			} 
			catch (NumberFormatException ne)
			{
				if (strInput.length() == 0) 
				{
					warning  =  "You did not enter any input! " + message;
				}
				else
				{
					warning =  "The input " + strInput+  " is not a valid input. "+ message;
				}
				strInput  = JOptionPane.showInputDialog (null, warning).trim();
			}
		} while (!validInput);
		return intInput;   
	} // End getInput

	public int getOption (String message, String [] options)
	{           
		option = JOptionPane.showOptionDialog(null, message, null, 0, 3, null, options, null);
		return option;                
	} // End  event 
             
	class RangeException extends ArithmeticException
	{  
		public RangeException (String message)
		{
			super (message); 
		}
	} // End RangeException
 
} // End class