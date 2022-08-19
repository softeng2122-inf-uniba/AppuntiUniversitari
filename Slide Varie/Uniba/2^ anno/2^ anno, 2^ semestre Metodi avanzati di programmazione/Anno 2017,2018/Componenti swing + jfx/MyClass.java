// costruisce un frame e una finestra di dialogo

import javax.swing.*;

public class MyClass  {

  static public void main(String[] args) {

   JFrame myframe= new JFrame("one frame");
   myframe.resize(100,200);
   myframe.show();

  Dialog1 dialog1=new Dialog1();
  dialog1.resize(100,200);
  dialog1.show();
}
  public MyClass() {
  }

}


