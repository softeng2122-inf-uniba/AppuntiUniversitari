package org.apache.jsp;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.jsp.*;

public final class Administration_jsp extends org.apache.jasper.runtime.HttpJspBase
    implements org.apache.jasper.runtime.JspSourceDependent {

  private static java.util.List _jspx_dependants;

  public Object getDependants() {
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
      out.write("<head><center><h2>Defect Tracking System</h2></center></head>\r\n");
      out.write("<a href=\"Home.jsp\"><h5>HOME</h5></a>\r\n");
      out.write("<body bgcolor=\"silver\">\r\n");
      out.write("<form action=\"Login.html\">\r\n");
      out.write("<center><tr><td><h3>ADMINISTRATION</h3></td>\r\n");
      out.write("<table>\r\n");
      out.write("<tr><td><a href=\"Employeerequest.jsp\"><h5>INBOX</h5></a></td></tr>\r\n");
      out.write("<tr><td><a href=\"Status.html\" ><h5>STATUS</h5></a></td></tr>\r\n");
      out.write("<tr><td><a href=\"ListRequests.jsp\"><h5>USER LIST</h5></a></td></tr>\r\n");
      out.write("</table>\r\n");
      out.write("</center>\r\n");
      out.write("<center><br>\r\n");
      out.write("<input type=\"submit\" name=\"Logout\" value=\"Logout\">\r\n");
      out.write("</center>\r\n");
      out.write("</form>\r\n");
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
