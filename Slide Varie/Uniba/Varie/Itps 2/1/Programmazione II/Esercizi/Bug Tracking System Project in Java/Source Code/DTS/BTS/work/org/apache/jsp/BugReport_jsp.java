package org.apache.jsp;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.jsp.*;

public final class BugReport_jsp extends org.apache.jasper.runtime.HttpJspBase
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

      org.apache.jasper.runtime.JspRuntimeLibrary.include(request, response, "./TesterHeader.jsp", out, false);
      out.write("\r\n");
      out.write("<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01 Transitional//EN\">\r\n");
      out.write("<html>\r\n");
      out.write("  <head>\r\n");
      out.write("    <title>Login.html</title>\r\n");
      out.write("\t\r\n");
      out.write("    <meta http-equiv=\"keywords\" content=\"keyword1,keyword2,keyword3\">\r\n");
      out.write("    <meta http-equiv=\"description\" content=\"this is my page\">\r\n");
      out.write("    <meta http-equiv=\"content-type\" content=\"text/html; charset=ISO-8859-1\">\r\n");
      out.write("    \r\n");
      out.write("    <!--<link rel=\"stylesheet\" type=\"text/css\" href=\"./styles.css\">-->\r\n");
      out.write("\t<script type=\"text/javascript\" language=\"javascrpt\">\r\n");
      out.write("    \tfunction check()\r\n");
      out.write("    \t{\r\n");
      out.write("\t\t\tif(employeeForm.bug_type.value=='')\r\n");
      out.write("    \t\t{\r\n");
      out.write("    \t\t\twindow.alert(\"Bug Type is Empty !\");\r\n");
      out.write("    \t\t\treturn false;\r\n");
      out.write("    \t\t}\r\n");
      out.write("    \t\tif(employeeForm.bug_level.value=='')\r\n");
      out.write("    \t\t{\r\n");
      out.write("    \t\t\twindow.alert(\"Bug Level is Empty !\");\r\n");
      out.write("    \t\t\treturn false;\r\n");
      out.write("    \t\t}\r\n");
      out.write("    \t\tif(employeeForm.priority.value=='')\r\n");
      out.write("    \t\t{\r\n");
      out.write("    \t\t\twindow.alert(\"Bug Priority is Empty !\");\r\n");
      out.write("    \t\t\treturn false;\r\n");
      out.write("    \t\t}\r\n");
      out.write("    \t\tif(employeeForm.pname.value=='')\r\n");
      out.write("    \t\t{\r\n");
      out.write("    \t\t\twindow.alert(\"Project name is Empty !\");\r\n");
      out.write("    \t\t\treturn false;\r\n");
      out.write("    \t\t}\r\n");
      out.write("    \t\tif(employeeForm.tester_code.value=='')\r\n");
      out.write("    \t\t{\r\n");
      out.write("    \t\t\twindow.alert(\"Tester code is Empty !\");\r\n");
      out.write("    \t\t\treturn false;\r\n");
      out.write("    \t\t}\r\n");
      out.write("    \t\tif(employeeForm.bug_date.value=='')\r\n");
      out.write("    \t\t{\r\n");
      out.write("    \t\t\twindow.alert(\"Bug Date is Empty !\");\r\n");
      out.write("    \t\t\treturn false;\r\n");
      out.write("    \t\t}\r\n");
      out.write("    \t\tif(employeeForm.e_code.value=='')\r\n");
      out.write("    \t\t{\r\n");
      out.write("    \t\t\twindow.alert(\"Employee Code is Empty !\");\r\n");
      out.write("    \t\t\treturn false;\r\n");
      out.write("    \t\t}       \t\r\n");
      out.write("    \t\tif(employeeForm.bug_rectified.value=='')\r\n");
      out.write("    \t\t{\r\n");
      out.write("    \t\t\twindow.alert(\"BugRectified is Empty !\");\r\n");
      out.write("    \t\t\treturn false;\r\n");
      out.write("    \t\t}       \t\r\n");
      out.write("    \t\tif(employeeForm.status1.value=='')\r\n");
      out.write("    \t\t{\r\n");
      out.write("    \t\t\twindow.alert(\"Employee Status is Empty !\");\r\n");
      out.write("    \t\t\treturn false;\r\n");
      out.write("    \t\t}       \t\r\n");
      out.write("    \t\t\r\n");
      out.write("}\r\n");
      out.write("    </script>\r\n");
      out.write("  </head>\r\n");
      out.write("  <body bgcolor=\"\">\r\n");
      out.write("  <form name=\"employeeForm\" action=\"buginfo\" onsubmit=\"return check()\" method=\"post\">\r\n");
      out.write("\r\n");
      out.write("  \t<center>\r\n");
      out.write("  \t<h3><font color=\"#FBB117\">&nbsp;&nbsp;&nbsp;&nbsp;Bug Information</font></h3>\r\n");
      out.write("  \t<table border=\"0\" cellpadding=\"2\">\r\n");
      out.write("  \t\t<tr><td align=\"right\"><font ><b>Bug_type</b></font></td><td> <input type=\"text\" name=\"bug_type\"></td></tr>\r\n");
      out.write("  \t\t<tr><td align=\"right\"><font ><b>Bug_level</b></font></td><td> <input type=\"text\" name=\"bug_level\"></td></tr>\r\n");
      out.write("\t\t<tr><td align=\"right\"><font><b>Priority</b></font></td><td> <input type=\"text\" name=\"priority\"></td></tr>\r\n");
      out.write("  \t\t<tr><td align=\"right\"><font ><b>Pname</b></font> </td><td><input type=\"text\" name=\"pname\"></td></tr>\r\n");
      out.write("  \t\t<tr><td align=\"right\"><font ><b>Tester Code</b></font></td><td> <input type=\"text\" name=\"tester_code\"></td></tr>  \t\t\r\n");
      out.write("  \t\t<tr><td align=\"right\"><font ><b>Bug Date</b></font> </td><td><input type=\"text\" name=\"bug_date\"></td></tr>\r\n");
      out.write("  \t\t<tr><td align=\"right\"><font ><b>Employee code</b></font> </td><td><input type=\"text\" name=\"e_code\"></td></tr>\r\n");
      out.write("  \t\t<tr><td align=\"right\"><font ><b>Status</b></font></td>\r\n");
      out.write("  \t\t<td>\r\n");
      out.write("  \t\t<select name=\"status\">\r\n");
      out.write("  \t\t\t<option value=\"select\">---select---</option>\r\n");
      out.write("  \t\t\t<option>open</option>\r\n");
      out.write("  \t\t\t<option>close</option>\r\n");
      out.write("  \t\t\t<option>resolve</option>\r\n");
      out.write("  \t\t\t<option>completed</option>\r\n");
      out.write("  \t\t</select>\r\n");
      out.write("  \t\t</td></tr>  \t\t\r\n");
      out.write("  \t\t<tr><td align=\"right\"><font><b>Bug Rectified date</b></font></td><td> <input type=\"text\" name=\"bug_rectifed\"></td></tr>  \t\t\r\n");
      out.write("  \t\t<tr><td align=\"right\"><font><b>status1</b></font> </td><td><input type=\"text\" name=\"status1\"></td></tr>  \t\t\r\n");
      out.write("  \t\t<tr><td align=\"center\" colspan=\"2\"><input type=\"submit\" value=\"submit\"></td></tr>  \t\t  \t\t  \t\t\r\n");
      out.write("  \t</table>\r\n");
      out.write("  \t</center>\r\n");
      out.write("   </form>\r\n");
      out.write("   </body>\r\n");
      org.apache.jasper.runtime.JspRuntimeLibrary.include(request, response, "./footer.jsp", out, false);
      out.write("   \r\n");
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
