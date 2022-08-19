package org.apache.jsp;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.jsp.*;

public final class Employee_jsp extends org.apache.jasper.runtime.HttpJspBase
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
      out.write("<head><center><h3>DEFECT TRACKING SYSTEM</h3></center></head>\r\n");
      out.write("<body bgcolor=\"silver\"><br>\r\n");
      out.write("<form name=\"employee\" action=\"Login.html\">\r\n");
      out.write("<center>\r\n");
      out.write("<h4>EMPLOYEE</h4>\r\n");
      out.write("<tr><td>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<a href=\"Home.jsp\"><h5>HOME</h5></a></td></tr>\r\n");
      out.write("<tr><td><a href=\"Adminresponse.jsp\"><h5>INBOX</h5></a></td></tr>\r\n");
      out.write("<tr><td><a href=\"Employeerequest.html\"><h5>COMPOSE MAIL</h5></a></td></tr>\r\n");
      out.write("<tr><td><a href=\"Status.html\"><h5>STATUS</h5></a></td></tr>\r\n");
      out.write("</center>\r\n");
      out.write("<br>\r\n");
      out.write("<center>\r\n");
      out.write("<input type=\"submit\" name=\"Logout\" value=\"Logout\"></center>\r\n");
      out.write("</body>\r\n");
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
