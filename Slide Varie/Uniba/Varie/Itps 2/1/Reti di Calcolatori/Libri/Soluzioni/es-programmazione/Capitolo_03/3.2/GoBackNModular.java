/**
* 	This is the class that performs modular calculation for the 
*	protocol. It find the residue, it adds, subtract, and multiply
*	numbers in modular arithmetic.  
*/ 

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.util.*;

public class GoBackNModular
{
	int modulus;

	public GoBackNModular (int modulus)
	{
		this.modulus = modulus;
	} // End constructor
    
	public int residue (int num) 
	{
		if (num >= 0)
		{
			return (num % modulus);
		}
		else 
		{
			while (num < 0)
			{
				num += modulus;
			}
		}
		return num;
	} // End residue

	public int add (int first, int second)
	{
		return residue (first + second);
	} // End add

	public int sub (int first, int second)
	{
		return residue (first - second);
	}
   
	public int mul (int first, int second)
	{
		return residue (first * second);
	}

	public boolean congruent (int first, int second)
	{
		return (residue (first) == residue (second));
	}

	public boolean isInRange (int num, int num1, int num2)
	{
		if (num2 < num1)
		{
			num2 +=modulus;
		}
		if (num < num1)
		{
			num += modulus;
		}
		return ((num >= num1) && (num <= num2));         
	}      

} // End class  