package org.apache.jsp;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.jsp.*;
import java.sql.*;

public final class AssignProject_jsp extends org.apache.jasper.runtime.HttpJspBase
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

      out.write('\r');
      out.write('\n');
      org.apache.jasper.runtime.JspRuntimeLibrary.include(request, response, "./ManagerHeader.jsp", out, false);
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
      out.write("\t\t\t\r\n");
      out.write("    \t\tif(Assignproject.pname.value==\"select\")\r\n");
      out.write("    \t\t{\r\n");
      out.write("    \t\t\twindow.alert(\"Select Project Name!\");\r\n");
      out.write("    \t\t\treturn false;\r\n");
      out.write("    \t\t}       \t\r\n");
      out.write("    \t\t    \t\r\n");
      out.write("    \t\tif(Assignproject.e_code.value==\"select\")\r\n");
      out.write("    \t\t{\r\n");
      out.write("    \t\t\twindow.alert(\"Select Employee Code!\");\r\n");
      out.write("    \t\t\treturn false;\r\n");
      out.write("    \t\t}    \r\n");
      out.write("    \t\tif(Assignproject.role.value=='')\r\n");
      out.write("    \t\t{\r\n");
      out.write("    \t\t\twindow.alert(\"role is Empty !\");\r\n");
      out.write("    \t\t\treturn false;\r\n");
      out.write("    \t\t}\r\n");
      out.write("    \t\t\r\n");
      out.write("    \t\t\r\n");
      out.write("    \t\t   \t\r\n");
      out.write("    \t\t    \t\r\n");
      out.write("    \t\t\r\n");
      out.write("}\r\n");
      out.write("    </script>\r\n");
      out.write("  </head>\r\n");
      out.write("  ");

  String s=request.getParameter("msg");
  if (s==null)
   s="";
   
      out.write("\r\n");
      out.write("  <body bgcolor=\"\">\r\n");
      out.write("  <form name=\"Assignproject\" action=\"AssignProject\" onsubmit=\"return check()\" method=\"post\">\r\n");
      out.write("   <p><font color=\"red\">");
      out.print(s );
      out.write("</font></p>\r\n");
      out.write("  \t<center>\r\n");
      out.write("  \t<h3><font color=\"#FBB117\">&nbsp;&nbsp;&nbsp;&nbsp;Bug Report</font></h3>\r\n");
      out.write("  \t<table border=\"0\" cellpadding=\"2\">\r\n");
      out.write("  \t<tr><td align=\"right\"><font><b>Project Name</b></font></td><td> \r\n");
      out.write("  \t");


		ServletContext sc=getServletContext();
		String driver=sc.getInitParameter("drivername");
		String url=sc.getInitParameter("url");
		String uname=sc.getInitParameter("username");
		String pwd=sc.getInitParameter("password");
try{
			Class.forName(driver);
			Connection  con=DriverManager.getConnection(url,uname,pwd);
			System.out.println(".......11........");
			ResultSet rs,rs1;
			PreparedStatement pstmt=con.prepareStatement("select loginid from employee_details");
			rs=pstmt.executeQuery();
			
			PreparedStatement pstmt1=con.prepareStatement("select project_name from project_details");
			rs1=pstmt1.executeQuery();
			
      out.write("\r\n");
      out.write("\t\t\t\r\n");
      out.write("\t\t\t<select name=\"pname\">\r\n");
      out.write("\t\t\t<option value=\"select\">---select---</option>\r\n");

	while(rs1.next())
	{			

      out.write("\r\n");
      out.write("  \t\t\t<option>");
      out.print(rs1.getString(1));
      out.write("</option>\r\n");

}//while

      out.write("\r\n");
      out.write("  \t\t</select>\r\n");
      out.write("  \t\t<tr><td align=\"right\"><font><b>Employee code</b></font></td><td> \r\n");
      out.write("  \t\t\t\t<select name=\"e_code\">\r\n");
      out.write("  \t\t\t<option value=\"select\">---select---</option>\r\n");

			while(rs.next())
			{			

      out.write("\r\n");
      out.write("  \t\t\t<option>");
      out.print(rs.getString(1));
      out.write("</option>\r\n");

}//while
}
catch(Exception e)
{
e.printStackTrace();
}

      out.write("\r\n");
      out.write("\t\t</select>\t\r\n");
      out.write("  \t\t<tr><td align=\"right\"><font><b>Role</b></font></td><td> <input type=\"text\" name=\"role\"></td></tr>\r\n");
      out.write("   \t\t\r\n");
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
