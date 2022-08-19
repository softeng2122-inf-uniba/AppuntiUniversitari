/**
* 	This is the interface that creates a liaison in the State Pattern design.
*	The interface defines four signatures that each state class needs to implement
*/

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.util.*;

public interface SelectiveRepeatState
{
	public void requestToSend ();
	public void timeout ();
	public void errorFreeACK (int ackNO);
	public void corruptedACK ();  
} // End class