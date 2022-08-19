package org.apache.jsp;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.jsp.*;

public final class Recchange_005fpass_jsp extends org.apache.jasper.runtime.HttpJspBase
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


if(request.getParameter("cat")!=null)
{
if(request.getParameter("cat").equals("Tester"))
{

      out.write('\r');
      out.write('\n');
      org.apache.jasper.runtime.JspRuntimeLibrary.include(request, response, "./TesterHeader.jsp", out, false);
      out.write("   \r\n");
} 
      out.write('\r');
      out.write('\n');
if(request.getParameter("cat").equals("Developer"))
{

      out.write('\r');
      out.write('\n');
      org.apache.jasper.runtime.JspRuntimeLibrary.include(request, response, "./DeveloperHeader.jsp", out, false);
      out.write("   \r\n");
}
if(request.getParameter("cat").equals("HrManager"))
{

      out.write('\r');
      out.write('\n');
      org.apache.jasper.runtime.JspRuntimeLibrary.include(request, response, "./ManagerHeader.jsp", out, false);
      out.write("   \r\n");
}

}//top if 
      out.write('\r');
      out.write('\n');
 
	String msg=request.getParameter("msg");
	if(msg==null)
	{
		 msg="";
	}

      out.write("\r\n");
      out.write("<html>\r\n");
      out.write("<head>\r\n");
      out.write("<title>Untitled Document</title>\r\n");
      out.write("<link href=\"port.css\" rel=\"stylesheet\" type=\"text/css\">\r\n");
      out.write("<link href=\"ISSCSS.css\" rel=\"stylesheet\" type=\"text/css\">\r\n");
      out.write("<meta http-equiv=\"Content-Type\" content=\"text/html; charset=iso-8859-1\">\r\n");
      out.write("<style type=\"text/css\">\r\n");
      out.write("<!--\r\n");
      out.write("\r\n");
      out.write("body,td,th {\r\n");
      out.write("\tcolor: #990099;\r\n");
      out.write("\tfont-weight: bold;\r\n");
      out.write("\tfont-style: italic;\r\n");
      out.write("}\r\n");
      out.write("-->\r\n");
      out.write("</style></head>\r\n");
      out.write("<script type=\"text/javascript\">\r\n");
      out.write("function check()\r\n");
      out.write("{\r\n");
      out.write("if(document.form1.opass.value==\"\")\r\n");
      out.write("{\r\n");
      out.write("\talert(\"Please Enter Old password First...\");\r\n");
      out.write("\treturn false;\r\n");
      out.write("}\r\n");
      out.write("if(document.form1.npass.value!=document.form1.cpass.value)\r\n");
      out.write("{\r\n");
      out.write("\talert(\"new password is not matched with confirm password .. please check!\");\r\n");
      out.write("\treturn false;\r\n");
      out.write("}\r\n");
      out.write("}\r\n");
      out.write("</script>\r\n");
      out.write("<body>\r\n");
      out.write("<h4 align=\"center\"><font color=\"red\">\r\n");
      out.write("\r\n");
      out.write("</font></h4>\r\n");
      out.write(" <h2 align=\"center\" class=\"Sitemap1\">change password </h2>\r\n");
      out.write("\r\n");
      out.write("<form name=\"form1\" method=\"post\" action=\"./pchange?cat=");
      out.print(request.getParameter("cat"));
      out.write("\" onsubmit=\"return check();\">\r\n");
      out.write("  <center>\r\n");
      out.write("    <p>&nbsp;</p>\r\n");
      out.write("    <p><font color=\"red\">");
      out.print(msg );
      out.write("</font>\r\n");
      out.write("        </p>\r\n");
      out.write("  </center>\r\n");
      out.write("  <table width=\"352\" height=\"105\" border=\"0\" align=\"center\">\r\n");
      out.write("    <tr>\r\n");
      out.write("      <td width=\"171\" class=\"text\"><div align=\"left\">Old Password : </div></td>\r\n");
      out.write("      <td width=\"171\"><input name=\"opass\" type=\"password\" class=\"borderBlue\" id=\"opass\"></td>\r\n");
      out.write("    </tr>\r\n");
      out.write("    <tr>\r\n");
      out.write("      <td class=\"text\"><div align=\"left\">New Password : </div></td>\r\n");
      out.write("      <td><input name=\"npass\" type=\"password\" class=\"borderBlue\" id=\"npass\"></td>\r\n");
      out.write("    </tr>\r\n");
      out.write("    <tr>\r\n");
      out.write("      <td class=\"text\"><div align=\"left\">Confirm Password : </div></td>\r\n");
      out.write("      <td><input name=\"cpass\" type=\"password\" class=\"borderBlue\" id=\"cpass\"></td>\r\n");
      out.write("    </tr>\r\n");
      out.write("  </table>\r\n");
      out.write("  <br>\r\n");
      out.write(" <font color=\"red\"><center></center></font>\r\n");
      out.write(" <div align=\"center\"></div>\r\n");
      out.write("  <p align=\"center\">\r\n");
      out.write("    <input name=\"Submit\" type=\"submit\" id=\"button\" value=\"Submit\">\r\n");
      out.write("  </p>\r\n");
      out.write("</form>\r\n");
      out.write("</body>\r\n");
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
