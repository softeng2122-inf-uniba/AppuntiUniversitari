package org.apache.jsp;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.jsp.*;
import java.sql.*;

public final class ViewBugs_jsp extends org.apache.jasper.runtime.HttpJspBase
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

      org.apache.jasper.runtime.JspRuntimeLibrary.include(request, response, "./DeveloperHeader.jsp", out, false);
      out.write("\r\n");
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
      out.write("    \t\t\r\n");
      out.write("    \t\t\r\n");
      out.write("       \t}\r\n");
      out.write("    </script>\r\n");
      out.write("  </head>\r\n");
      out.write("  <body bgcolor=\"\">\r\n");
      out.write("<form name=\"testerForm\" action=\"ViewBugs\" onsubmit=\"return check()\" method=\"post\">\r\n");
      out.write("<br>\r\n");
      out.write("<center>\r\n");
      out.write("<h4 align=\"center\"><font color=\"red\">\r\n");
if(request.getParameter("msg")!=null)
{ 
      out.write('\r');
      out.write('\n');
      out.print(request.getParameter("msg"));
      out.write('\r');
      out.write('\n');
} 
      out.write("\r\n");
      out.write("\t</font></h4>\r\n");
      out.write("\t\r\n");
      out.write("\t<h3><font color=\"#FBB117\" face=\"arial narrow\">&nbsp;&nbsp;&nbsp;&nbsp;View All Bugs</font></h3>\r\n");
      out.write("  \t\t\r\n");
      out.write("<table border=\"1\" cellpadding=\"2\" cellspacing=\"0\" bordercolor=\"orange\">\r\n");
      out.write("  \t\t<tr>\r\n");
      out.write("  \t\t\t<th>Bug Name</th>\r\n");
      out.write("  \t\t\t<th>Bug Type</th>\r\n");
      out.write("  \t\t\t<th>Bug Level</th>  \t\t\t\r\n");
      out.write("  \t\t\t<th>Priority</th>\r\n");
      out.write("  \t\t\t<th>Project Name</th>\r\n");
      out.write("  \t\t\t<th>Tester Code</th>\r\n");
      out.write("  \t\t\t<th>Bug Date</th>\r\n");
      out.write("  \t\t\t<th>Employee Code</th>\r\n");
      out.write("  \t\t\t<th>Status</th>\r\n");
      out.write("  \t\t\t<th>Update</th>\r\n");
      out.write("  \t\t</tr>\r\n");

		ServletContext sc=getServletContext();
		String driver=sc.getInitParameter("drivername");
		String url=sc.getInitParameter("url");
		String uname=sc.getInitParameter("username");
		String pwd=sc.getInitParameter("password");
		HttpSession hs=request.getSession();
		String s=(String)hs.getAttribute("userid");
try{
			Class.forName(driver);
			Connection  con=DriverManager.getConnection(url,uname,pwd);
			System.out.println(".......11........");
			ResultSet rs;
			PreparedStatement pstmt=con.prepareStatement("select * from bug_report where e_code=?");
			pstmt.setString(1,s);
			rs=pstmt.executeQuery();
	while(rs.next())
	{			

      out.write("\r\n");
      out.write("\r\n");
      out.write("  \t\t<tr>\r\n");
      out.write("  \t\t\t<td>");
      out.print(rs.getString(2));
      out.write("</td>\r\n");
      out.write("  \t\t\t<td>");
      out.print(rs.getString(3));
      out.write("</td>\r\n");
      out.write("  \t\t\t<td>");
      out.print(rs.getString(4));
      out.write("</td>\r\n");
      out.write("  \t\t\t<td>");
      out.print(rs.getString(5));
      out.write("</td>\r\n");
      out.write("  \t\t\t<td>");
      out.print(rs.getString(6));
      out.write("</td>\r\n");
      out.write("  \t\t\t<td>");
      out.print(rs.getString(7));
      out.write("</td>\r\n");
      out.write("  \t\t\t<td>");
      out.print(rs.getString(8));
      out.write("</td>\r\n");
      out.write("  \t\t\t<td>");
      out.print(rs.getString(9));
      out.write("</td>\r\n");
      out.write("  \t\t\t<td>");
      out.print(rs.getString(10));
      out.write("</td>\r\n");
      out.write("  \t\t\t<td><a href=\"./UpdateBug.jsp?bugid=");
      out.print(rs.getInt(1));
      out.write("\">Update</a></td>\r\n");
      out.write("\t\t</tr>\r\n");
      out.write("  \r\n");

}//while


      out.write("  \t\t\t\r\n");
      out.write("\t</table>\r\n");
      out.write(" \t\t\r\n");

}
catch(Exception e)
{
	e.printStackTrace();
}
 
      out.write("  \t\t\t\r\n");
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
