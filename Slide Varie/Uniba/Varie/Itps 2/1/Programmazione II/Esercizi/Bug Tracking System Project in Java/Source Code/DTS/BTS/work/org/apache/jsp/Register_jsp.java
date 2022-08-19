package org.apache.jsp;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.jsp.*;

public final class Register_jsp extends org.apache.jasper.runtime.HttpJspBase
    implements org.apache.jasper.runtime.JspSourceDependent {

  private static java.util.Vector _jspx_dependants;

  public java.util.List getDependants() {
    return _jspx_dependants;
  }

  public void _jspService(HttpServletRequest request, HttpServletResponse response)
        throws java.io.IOException, ServletException {

    JspFactory _jspxFactory = null;
    PageContext pageContext = null;
    HttpSession session = null;
    ServletContext application = null;
    ServletConfig config = null;
    JspWriter out = null;
    Object page = this;
    JspWriter _jspx_out = null;
    PageContext _jspx_page_context = null;


    try {
      _jspxFactory = JspFactory.getDefaultFactory();
      response.setContentType("text/html");
      pageContext = _jspxFactory.getPageContext(this, request, response,
      			null, true, 8192, true);
      _jspx_page_context = pageContext;
      application = pageContext.getServletContext();
      config = pageContext.getServletConfig();
      session = pageContext.getSession();
      out = pageContext.getOut();
      _jspx_out = out;

      out.write("<HTML>\r\n");
      out.write("\r\n");
      out.write("<script LANGUAGE=\"Javascript\" >\r\n");
      out.write("\t\tfunction ChkMandatoryField(F,T){\r\n");
      out.write("\t\t\tvar val= F.value;\r\n");
      out.write("\t\t\tif(val==\"\"){alert(T+\" is mandatory\");return false;}\r\n");
      out.write("\t\t}\r\n");
      out.write("\t\t\r\n");
      out.write("\t\tfunction validate()\r\n");
      out.write("\t\t{\r\n");
      out.write("\t\t\talert(\"hai\");\r\n");
      out.write("\t\t\t\r\n");
      out.write("            if(ChkMandatoryField(editform.fname,'FirstName')==false) return false;\r\n");
      out.write("            alert(\"hai\")\r\n");
      out.write("            if(ChkMandatoryField(editform.lname,'LastName')==false) return false;\r\n");
      out.write("            if(editform.gender.value==\"select\")\r\n");
      out.write("    \t\t{\r\n");
      out.write("    \t\t\twindow.alert(\"Select Gender !\");\r\n");
      out.write("    \t\t\treturn false;\r\n");
      out.write("    \t\t}\r\n");
      out.write("    \t\talert(\"hai1\")\r\n");
      out.write("            if(ChkMandatoryField(editform.dob,'Date of Birth')==false) return false;\r\n");
      out.write("            if(ChkMandatoryField(editform.qualification,'Qualification')==false) return false;\r\n");
      out.write("            if(ChkMandatoryField(editform.address,'Address')==false) return false;\r\n");
      out.write("            if(ChkMandatoryField(editform.phoneno,'PhoneNo')==false) return false;\r\n");
      out.write("             if(ChkMandatoryField(editform.mobileno,'MobileNo')==false) return false;\r\n");
      out.write("             if(ChkMandatoryField(editform.emailid,'EmailID')==false) return false;\r\n");
      out.write("             if(ChkMandatoryField(editform.doj,'Date Of Joining')==false) return false;\r\n");
      out.write("             \r\n");
      out.write("             if(editform.role.value==\"select\")\r\n");
      out.write("    \t\t{\r\n");
      out.write("    \t\t\twindow.alert(\"Select Designation !\");\r\n");
      out.write("    \t\t\treturn false;\r\n");
      out.write("    \t\t}\r\n");
      out.write("    \t\t\r\n");
      out.write("    \t\tif(editform.maritalstatus.value==\"select\")\r\n");
      out.write("    \t\t{\r\n");
      out.write("    \t\t\twindow.alert(\"Select MaritalStatus !\");\r\n");
      out.write("    \t\t\treturn false;\r\n");
      out.write("    \t\t}\r\n");
      out.write("    \t\tif(editform.HintQuestion.value==\"select\")\r\n");
      out.write("    \t\t{\r\n");
      out.write("    \t\t\twindow.alert(\"Select HintQuestion !\");\r\n");
      out.write("    \t\t\treturn false;\r\n");
      out.write("    \t\t}\r\n");
      out.write("             \r\n");
      out.write("             if(ChkMandatoryField(editform.hintanswer,'HintAnswer')==false) return false;\r\n");
      out.write("             \r\n");
      out.write("\t\t   \r\n");
      out.write("\t\r\n");
      out.write("\r\n");
      out.write("}\r\n");
      out.write("\r\n");
      out.write("\r\n");
      out.write("\r\n");
      out.write("</script>\r\n");
      out.write("\r\n");
      out.write("</head>\r\n");
      out.write("<body bgcolor=\"white\">\r\n");
      out.write("<form  name=\"editform\" action=\"./Reg\">\r\n");
      out.write("\t<table width=\"100%\">\r\n");
      out.write("\t<tr>\r\n");
      out.write("\t<td align=\"\"><img src=\"./Images/header.jpeg\" height=\"120\"></img></td>\r\n");
      out.write("\t<td align=\"\"><font face=\"arial narrow\" size=\"5px\" color=\"orange\"><b> Defect Tracking System</b></font></td>\r\n");
      out.write("\t</tr>\r\n");
      out.write("\t<tr>\r\n");
      out.write("\t<td align=right colspan=2><b>[ <a href=\"./Home.jsp\"><font color=\"#FBC61\" size=\"3px\">Home</font></a> ]</b>\r\n");
      out.write("\t</td>\r\n");
      out.write("\t</tr>\r\n");
      out.write("\t</table>\r\n");
      out.write("\t<hr>\r\n");
      out.write("<center><tr><td><h4>REGISTRATION FORM</h4></td></tr></center>\r\n");
      out.write("<center>\r\n");
      out.write("<table>\r\n");
      out.write("<tr><td><b>UserID*</td><td><input type=\"text\" name=\"userid\" value=\"\"></tc></td></tr>\r\n");
      out.write("<tr><td><b>Fname*</td><td><input type=\"text\" name=\"fname\" value=\"\"></td></tr>\r\n");
      out.write("<tr><td><b>Lname*</td><td><input type=\"text\" name=\"lname\" value=\"\"></td></tr>\r\n");
      out.write("<tr>\r\n");
      out.write("<td>Gender:</td>\r\n");
      out.write("<td><select name=\"gender\">\r\n");
      out.write("<option value=\"select\">-----select----</option>\r\n");
      out.write("<option>Male</option>\r\n");
      out.write("<option>FeMale</option></td>\r\n");
      out.write("</tr>\r\n");
      out.write("<tr>\r\n");
      out.write("<td>DOB</td>\r\n");
      out.write("<td><input type=\"text\" name=\"dob\" value=\"\"></td>\r\n");
      out.write("</tr>\r\n");
      out.write("\r\n");
      out.write("<tr>\r\n");
      out.write("<td>Qualification</td>\r\n");
      out.write("<td><input type=\"text\" name=\"qualification\" value=\"\"></td>\r\n");
      out.write("</tr>\r\n");
      out.write("\r\n");
      out.write("<tr>\r\n");
      out.write("<td>Address</td>\r\n");
      out.write("<td><input type=\"text\" name=\"address\" value=\"\"></td>\r\n");
      out.write("</tr>\r\n");
      out.write("\r\n");
      out.write("<tr>\r\n");
      out.write("<td>PhoneNo</td>\r\n");
      out.write("<td><input type=\"text\" name=\"phoneno\" value=\"\"></td>\r\n");
      out.write("</tr>\r\n");
      out.write("\r\n");
      out.write("<tr>\r\n");
      out.write("<td>MobileNo</td>\r\n");
      out.write("<td><input type=\"text\" name=\"mobileno\" value=\"\"></td>\r\n");
      out.write("</tr>\r\n");
      out.write("\r\n");
      out.write("<tr>\r\n");
      out.write("<td>EmailID</td>\r\n");
      out.write("<td><input type=\"text\" name=\"mailid\" value=\"\"></td>\r\n");
      out.write("</tr>\r\n");
      out.write("\r\n");
      out.write("<tr>\r\n");
      out.write("<td>DOJ</td>\r\n");
      out.write("<td><input type=\"text\" name=\"doj\" value=\"\"></td>\r\n");
      out.write("</tr>\r\n");
      out.write("<tr>\r\n");
      out.write("<td>Designation</td>\r\n");
      out.write("<td>\r\n");
      out.write("<select name=\"designation\">\r\n");
      out.write("<option value=\"select\">-----select----</option>\r\n");
      out.write("<option>Developer</option>\r\n");
      out.write("<option>Tester</option>\r\n");
      out.write("<option>Manager</option></td>\r\n");
      out.write("</tr>\r\n");
      out.write("\r\n");
      out.write("<tr>\r\n");
      out.write("<td>MaritalStatus</td>\r\n");
      out.write("<td>\r\n");
      out.write("<select name=\"maritalstatus\">\r\n");
      out.write("<option value=\"select\">-----select----</option>\r\n");
      out.write("<option>Married</option>\r\n");
      out.write("<option>Unmarried<option></td>\r\n");
      out.write("</tr>\r\n");
      out.write("\r\n");
      out.write("<tr>\r\n");
      out.write("<td>Password</td>\r\n");
      out.write("<td><input type=\"password\" name=\"password\" value=\"\"></td>\r\n");
      out.write("</tr>\r\n");
      out.write("<tr>\r\n");
      out.write("           <td class=\"text1\"><div align=\"right\" class=\"style2\">Hint Question</div></td>\r\n");
      out.write("           <td><div align=\"left\">\r\n");
      out.write("             <select name=\"HintQuestion\" class=\"borderBlue\">\r\n");
      out.write("\t\t       <OPTION value=\"select\">[Select One]\r\n");
      out.write("               <OPTION value=\"What is the name of your first school?\">What is the name of your first school?\r\n");
      out.write("               <OPTION value=\"What is your favourite pass-time?\">What is your favourite pass-time?\r\n");
      out.write("               <OPTION value=\"What is your mother maiden name?\">What is your mother's maiden name?\r\n");
      out.write("               <OPTION value=\"What is your favourite food?\">What is your favourite food?\r\n");
      out.write("             </select>\r\n");
      out.write("           </div></td>\r\n");
      out.write("         </tr>\r\n");
      out.write("        \r\n");
      out.write("\r\n");
      out.write("<tr>\r\n");
      out.write("<td>HintAnswer</td>\r\n");
      out.write("<td><input type=\"text\" name=\"hintanswer\" value=\"\"></td>\r\n");
      out.write("</tr>\r\n");
      out.write("\r\n");
      out.write("\r\n");
      out.write("</table><br><br>\r\n");
      out.write("&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp\r\n");
      out.write("&nbsp&nbsp&nbsp&nbsp&nbsp\r\n");
      out.write("<tr><td><b><input type=\"submit\" name=\"sub\" value=\"Register\" onclick=\"return validate()\">\r\n");
      out.write("<b><input type=\"Reset\" name=\"reset\" value=\"Reset\"></td></tr>\r\n");
      out.write("</center>\r\n");
      out.write("</form>\r\n");
      out.write("</body>\r\n");
      org.apache.jasper.runtime.JspRuntimeLibrary.include(request, response, "footer.jsp", out, true);
      out.write("\r\n");
      out.write("</html>\r\n");
    } catch (Throwable t) {
      if (!(t instanceof SkipPageException)){
        out = _jspx_out;
        if (out != null && out.getBufferSize() != 0)
          out.clearBuffer();
        if (_jspx_page_context != null) _jspx_page_context.handlePageException(t);
      }
    } finally {
      if (_jspxFactory != null) _jspxFactory.releasePageContext(_jspx_page_context);
    }
  }
}
