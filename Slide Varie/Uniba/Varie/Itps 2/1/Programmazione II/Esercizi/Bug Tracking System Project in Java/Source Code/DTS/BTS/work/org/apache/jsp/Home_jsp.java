package org.apache.jsp;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.jsp.*;

public final class Home_jsp extends org.apache.jasper.runtime.HttpJspBase
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

      out.write("<html>\r\n");

String msg=null;

msg=request.getParameter("msg");

 
      out.write("\r\n");
      out.write("<head>\r\n");
      out.write("<script type=\"text/javascript\">\r\n");
if(request.getParameter("msg")!=null){
      out.write("\r\n");
      out.write("var msg='Please Check your userid and password';\r\n");
      out.write("function check()\r\n");
      out.write("{\r\n");
      out.write("//if(msg!=null)\r\n");
      out.write("//{\r\n");
      out.write("alert(msg);\r\n");
      out.write("//return false;\r\n");
      out.write("}");
}
      out.write("\r\n");
      out.write("//}\r\n");
      out.write("</script>\r\n");
      out.write("</head>\r\n");
      out.write("<body onload=\"return check()\"><center>\r\n");
      out.write("<table width=\"100%\">\r\n");
      out.write("\t<tr>\r\n");
      out.write("\t<td align=\"\"><img src=\"./Images/header.jpeg\" height=\"120\"></img></td>\r\n");
      out.write("\t<td align=\"\"><font face=\"arial narrow\" size=\"5px\" color=\"orange\"><b> Defect Tracking System</b></font></td>\r\n");
      out.write("\t</tr>\r\n");
      out.write("</table>\r\n");
      out.write("<hr>\r\n");
      out.write("<br><br>\r\n");
      out.write("<table width=\"80%\" border=0 cellpadding=12>\r\n");
      out.write("<tr><td>\r\n");
      out.write("<p align=\"justify\"> <font face=\"arial narrow\"><b>\r\n");
      out.write("\tThe Project entitled DEFECT TRACKING SYSTEM is a web based and intranet application aimed for the tracking \r\n");
      out.write("and resolution of bugs. All businesses have issues that need to be tracked and managed to resolution. Resolution \r\n");
      out.write("of these issues requires the coordination of multiple individuals within and perhaps even outside the company.\r\n");
      out.write("This application can be used by all team members to coordinate their work and to make sure that reported bugs can \r\n");
      out.write("use this application and enhancement requests wont be forgotten. In this way Tester delivers up to the minute \r\n");
      out.write("project information and status to the team members everywhere to foster better communication and collaboration.\r\n");
      out.write(" The Online handling of reporting ensure that the project working hours will be prompt.\r\n");
      out.write("This also ensures well-disciplined authorization of users according to the project specification. \r\n");
      out.write("Usage of this application increases the productivity and quality of the project.\r\n");
      out.write("</font></b></p>\r\n");
      out.write("<td>");
      org.apache.jasper.runtime.JspRuntimeLibrary.include(request, response, "./Login.html", out, false);
      out.write("</td>\r\n");
      out.write("</tr>\r\n");
      out.write("</table>\r\n");
      out.write("<br><br><br>\r\n");
      out.write("</center>\r\n");
      out.write("</body>\r\n");
      org.apache.jasper.runtime.JspRuntimeLibrary.include(request, response, "./footer.jsp", out, false);
      out.write("   \r\n");
      out.write("\r\n");
      out.write("</html>");
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
