//********************************************************************
//  QuotesControls.java       
//
//  Demonstrates the use of various button types.
//********************************************************************

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class QuotesControls extends JFrame
{
   private String[] text;
   private JLabel quote;

   private JButton uppercase, lowercase;
   private JCheckBox bold, italic;
   private JRadioButton comedy, philosophy, carpentry;
   private ButtonGroup topic;

   private JPanel letters, domain, style, app;

   //-----------------------------------------------------------------
   //  Sets up the GUI for the Quotes program.
   //-----------------------------------------------------------------
   public QuotesControls ()
   {
      super ("Quotes");
      setSize (300, 150);

      text = new String[3];
      text[0] = "Take my wife, please.";
      text[1] = "I think, therefore I am.";
      text[2] = "Measure twice, cut once.";

      quote = new JLabel (text[0], SwingConstants.CENTER);
      quote.setFont (new Font ("Serif", Font.PLAIN, 12));

      uppercase = new JButton ("Uppercase");
      lowercase = new JButton ("Lowercase");

      bold = new JCheckBox ("Bold");
      italic = new JCheckBox ("Italic");

      comedy = new JRadioButton ("Comedy", true);
      philosophy = new JRadioButton ("Philosophy", false);
      carpentry = new JRadioButton ("Carpentry", false);

      topic = new ButtonGroup();
      topic.add (comedy);
      topic.add (philosophy);
      topic.add (carpentry);

      QuoteActionListener actionListener = new QuoteActionListener();
      
      uppercase.addActionListener (actionListener);
      lowercase.addActionListener (actionListener);
      comedy.addActionListener (actionListener);
      philosophy.addActionListener (actionListener);
      carpentry.addActionListener (actionListener);

      QuoteItemListener itemListener = new QuoteItemListener();

      bold.addItemListener (itemListener);
      italic.addItemListener (itemListener);

      // Organize the components
      letters = new JPanel();
      letters.setLayout (new BoxLayout (letters, BoxLayout.Y_AXIS));
      letters.add (uppercase);
      letters.add (lowercase);
      
      domain = new JPanel();
      domain.setLayout (new BoxLayout (domain, BoxLayout.Y_AXIS));
      domain.add (comedy);
      domain.add (philosophy);
      domain.add (carpentry);

      style = new JPanel();
      style.setLayout (new BoxLayout (style, BoxLayout.Y_AXIS));
      style.add (bold);
      style.add (italic);
 
      app = new JPanel();
      app.setLayout (new BorderLayout(15,10));
      app.add (quote, BorderLayout.NORTH);
      app.add (letters, BorderLayout.WEST);
      app.add (domain, BorderLayout.CENTER);
      app.add (style, BorderLayout.EAST);

      setContentPane (app);
   }

   //*****************************************************************
   //  Inner class to handle the uppercase and lowercase buttons, as
   //  well as the topic buttons.
   //*****************************************************************
   private class QuoteActionListener implements ActionListener
   {
      //--------------------------------------------------------------
      //  Sets the quote to the correct string or the correct case
      //  depending on which button was pressed.
      //--------------------------------------------------------------
      public void actionPerformed (ActionEvent event)
      {
         Object source = event.getSource();

         if (source == uppercase)
            quote.setText (quote.getText().toUpperCase());
         else if (source == lowercase)
            quote.setText (quote.getText().toLowerCase());
         else if (source == comedy)
            quote.setText (text[0]);
         else if (source == philosophy)
            quote.setText (text[1]);
         else  // must be carpentry
            quote.setText (text[2]);
      }
   }

   //*****************************************************************
   //  Inner class to handle the check boxes for bold and italic.
   //*****************************************************************
   private class QuoteItemListener implements ItemListener
   {
      //--------------------------------------------------------------
      //  Toggles bold or italic as appropriate.
      //--------------------------------------------------------------
      public void itemStateChanged (ItemEvent event)
      {
         Font font = quote.getFont();
         int style = font.getStyle();

	// Font.Plain=0, Font.BOLD=1, Font.ITALIC=2 

         if (event.getSource() == bold)
         {
            if (event.getStateChange() == ItemEvent.SELECTED)
               style += Font.BOLD;
            else
               style -= Font.BOLD;

            quote.setFont (new Font (font.getName(), style, 12));
         }
         else  // must be italic
         {
            if (event.getStateChange() == ItemEvent.SELECTED)
               style += Font.ITALIC;
            else
               style -= Font.ITALIC;

            quote.setFont (new Font (font.getName(), style, 12));
         }
      }
   }
}
