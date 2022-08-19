package org.apache.jsp;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.jsp.*;

public final class AddDepartment_jsp extends org.apache.jasper.runtime.HttpJspBase
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
      org.apache.jasper.runtime.JspRuntimeLibrary.include(request, response, "./Header.jsp", out, false);
      out.write(" \r\n");
      out.write("<head>\r\n");
      out.write("    <script LANGUAGE=\"Javascript\" >\r\n");
      out.write("\t\tfunction ChkMandatoryField(F,T){\r\n");
      out.write("\t\t\tvar val= F.value;\r\n");
      out.write("\t\t\tif(val==\"\"){alert(T+\" is mandatory\");return false;}\r\n");
      out.write("\t\t}\r\n");
      out.write("\t\t\r\n");
      out.write("\t\tfunction validate()\r\n");
      out.write("\t\t{\r\n");
      out.write("\t\t\t\r\n");
      out.write("\t\t\t\r\n");
      out.write("            if(ChkMandatoryField(login.dname,'DepartmentName')==false) return false;\r\n");
      out.write("            if(ChkMandatoryField(login.location,'Location')==false) return false;\r\n");
      out.write("            \r\n");
      out.write("            \r\n");
      out.write("\t\t}\r\n");
      out.write("\t\t\r\n");
      out.write("\t</script>\r\n");
      out.write("\r\n");
      out.write("<body bgcolor=\"silver\">\r\n");
      out.write("<form  name=\"login\" action=\"./AddDept\" name=\"frm\">\r\n");
      out.write("<br><br><center>\r\n");
      out.write("<h3>ADD DEPARTMENT</h3></center>\r\n");
      out.write("<center><table>\r\n");
      out.write("<tr><td>&nbsp;Department Name:</td><td><input type=\"text\" name=\"dname\" value=\"\"></td></tr>\r\n");
      out.write("<tr><td>Department Location:</td><td><input type=\"text\" name=\"location\" value=\"\"></td></tr>\r\n");
      out.write("</table><br>\r\n");
      out.write("&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;\r\n");
      out.write("<tr><td><input type=\"submit\" name=\"login\" value=\"Add\" onClick=\"return validate()\"></td></tr>\r\n");
      out.write("</center>\r\n");
      out.write("</body>\r\n");
      org.apache.jasper.runtime.JspRuntimeLibrary.include(request, response, "./footer.jsp", out, false);
      out.write(" \r\n");
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
