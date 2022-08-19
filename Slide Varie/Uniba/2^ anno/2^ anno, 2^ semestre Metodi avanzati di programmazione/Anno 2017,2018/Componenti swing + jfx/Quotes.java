//********************************************************************
//  Quotes.java      
//
//  Demonstrates the use of various button types.
//********************************************************************

import QuotesControls;
import GenericWindowListener;
import java.awt.event.*;

public class Quotes
{
   //-----------------------------------------------------------------
   //  Creates and displays the QuotesControls frame.
   //-----------------------------------------------------------------
   public static void main (String[] args)
   {
      QuotesControls frame = new QuotesControls();
      frame.addWindowListener (new GenericWindowListener());
      frame.show();
   }
}
