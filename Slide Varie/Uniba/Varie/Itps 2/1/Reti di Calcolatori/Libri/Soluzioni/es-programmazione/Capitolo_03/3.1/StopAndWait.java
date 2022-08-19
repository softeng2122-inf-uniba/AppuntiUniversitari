/**
* 	This is the mother class in this program that uses five other classes to
*	simulate the theoretical Stop-And-Wait Protocol at the transport layer.
*	This class is responsible to get the event from the user and calls the class 
*	that handles that even. The main method in this class is the driver
*	for the whole program. The protocol uses two states: ready and blocking.
*	Each state is defined in its own class and and interface is responsible for
*	the liaison between the states and the mother classes.  The code first
*	gets the event (using the StopAndWaitInput class). The class then passes 
*	event to the appropriate state for handling. It is also responsible for setting
* 	and getting the values of variables in the protocol. 
*/ 

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.util.*;
import java.math.*;

public class StopAndWait
{
	private  StopAndWaitState  ready, blocking, current;
	private int s, ackNo;				// s is the only variable in the sending window
	private boolean timer;			// true, running; false, otherwise.
	StopAndWaitInput input;
      
	public StopAndWait ()
	{         
		ready = new StopAndWaitReady (this);
		blocking = new StopAndWaitBlocking (this);
		current = ready; 
		s = 0;
		ackNo = 0;
		timer = false; 
		input = new StopAndWaitInput ();
		getEvent();         
	} // End constructor 
       
	private void getEvent ()
	{
		int event = -1;
		String title = "Stop and Wait Protocol: Sender Side";
		String message = "Give the ackNo, a positive value";  
		String[] options = 	{"Request to Send", "Timeout", "Error Free ACK", "Corrupted ACK", "Quit"};        
		do 
		{
			event  = input.getOption ("Select the event", options);
			switch (event)    
			{
				case 0:	requestToSend ();
						break;
				case 1:	timeout ();
						break;
				case 2:	ackNo = input.getIntInput (message);
						errorFreeACK (ackNo);
						break;
				case 3:	corruptedACK ();
						break;
				case 4:	break;
			}// End switch

		} while (event != 4);
	} // End  getEvent 

	public void requestToSend ()
	{
		current.requestToSend (); 
	} // End requestToSend

	public void timeout ()
	{
		current.timeout();
	} // End timeout

	public void errorFreeACK (int an)
	{
		current.errorFreeACK(an);
	} // End errorFreeACK

	public void corruptedACK()
	{
		current.corruptedACK();
	} // End corruptedACK 
    
	public void setState (StopAndWaitState state)
	{
		current = state;
	} // End setState

	public StopAndWaitState getReady()
	{
		return ready;
	}// End getReady

	public StopAndWaitState getBlocking()
	{
		return blocking;
	} // End getBlocking
      
	public void setS (int value)
	{
		s = value % 2;
	}// End setState

	public void setTimer (boolean t)
	{
		timer = t;
	}// End setTimer
      
	public int getS ()
	{
		return s;
	} // getState

	public boolean getTimer ()
	{
		return timer;
	} // End getTimer

	public boolean validAck (int ackNo)
	{ 
		return (ackNo == (s + 1)% 2);
	}

	public static void main (String[] args)
	{
		StopAndWait sw = new StopAndWait();
	} // End main
      
} // End class