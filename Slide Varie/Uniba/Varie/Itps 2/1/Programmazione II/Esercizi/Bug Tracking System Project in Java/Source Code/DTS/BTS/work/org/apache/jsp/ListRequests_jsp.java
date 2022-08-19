package org.apache.jsp;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.jsp.*;
import java.sql.*;
import java.io.*;
import java.util.Random;

public final class ListRequests_jsp extends org.apache.jasper.runtime.HttpJspBase
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

      out.write("\r\n");
      out.write("\r\n");
      out.write("\r\n");
      out.write("<HTML>\r\n");
      out.write("<HEAD>\r\n");
      out.write("\r\n");
      out.write("\t<LINK href=\"styles.css\" type=\"text/css\" rel=\"stylesheet\">\r\n");
      out.write("<script LANGUAGE=\"Javascript\" SRC=\"Images/validate.js\"></script>\r\n");
      out.write("<title>List Requests</title>\r\n");
      out.write("\r\n");
      out.write("</HEAD>\r\n");
      out.write("<a href=\"Administration.jsp\"><img border=0 src=\"Images2/CalLeft.gif\"></a>\r\n");
      out.write("<body class=\"SC\">\r\n");
      out.write("<form action=\"Login.html\">\r\n");
      out.write("<h3 align=center>Employee List</h3>\r\n");

/*Declaration of variables*/

Connection con;
PreparedStatement pstmt;
ResultSet rs=null;

String username,userid,password,email,address,phno,status;

try
{	
	      Class.forName("com.mysql.jdbc.Driver");
       	  con=DriverManager.getConnection("jdbc:mysql://localhost:3306/test", "root", "igen");
       	  pstmt=con.prepareStatement("select * from employee");
    	   rs=pstmt.executeQuery();
}
catch(Exception e)
{
	e.printStackTrace();
}
if(rs!=null)
{

      out.write("\r\n");
      out.write("\t<br>\r\n");
      out.write("\t<table class=notebook align=center>\r\n");
      out.write("\t<tr class=row_title>\r\n");
      out.write("        <th align=\"center\">username</th>\r\n");
      out.write("\t\t<th align=\"center\">userid</th>\r\n");
      out.write("\t\t<th align=\"center\">password</th>\r\n");
      out.write("\t\t<th align=\"center\">email</th>\r\n");
      out.write("\t\t<th align=\"center\">address</th>\r\n");
      out.write("\t\t<th align=\"center\">phno</th>\r\n");
      out.write("\t\t<th align=\"center\">status</th>\t\t\t\t\r\n");

int DisRow=0;
	/*Getting the values from the database*/

	while(rs.next())
	{
	   username=rs.getString(1);
	   userid=rs.getString(2);
	   password=rs.getString(3);
	   email=rs.getString(4);
	   address=rs.getString(5);
	   phno=rs.getString(6);
	   status=rs.getString(7);
	   DisRow++;
	
      out.write("\r\n");
      out.write("\t<tr class= ");
      out.print((DisRow%2!=0)? "row_even" : "row_odd");
      out.write(">\r\n");
      out.write("\t\t<td><a href=\"\">");
      out.print(username);
      out.write("</a></td>\t\t\r\n");
      out.write("\t\t<td align=\"center\">");
      out.print(userid);
      out.write("</td>\r\n");
      out.write("\t\t<td align=\"center\">");
      out.print(password);
      out.write("</td>\r\n");
      out.write("\t\t<td align=\"center\">");
      out.print(email);
      out.write("</td>\r\n");
      out.write("\t\t<td align=\"center\">");
      out.print(address);
      out.write("</td>\r\n");
      out.write("\t\t<td align=\"center\">");
      out.print(phno);
      out.write("</td>\r\n");
      out.write("\t\t<td align=\"center\">");
      out.print(status);
      out.write("</td>\t\t\t\t\r\n");
      out.write("\t");

	}
	rs.close();		
if(DisRow==0)
{	
	
      out.write("\t\t\r\n");
      out.write("\t\t\t<tr><th colspan=6>No Records found</th></tr>\r\n");
      out.write("\t");

}
}

      out.write("\r\n");
      out.write("</table><table align=\"right\">\r\n");
      out.write(" <tr><td><input type=\"submit\" name=\"logout\" value=\"Logout\"></td></tr></table>\r\n");
      out.write("</form>\r\n");
      out.write("</BODY>\r\n");
      out.write("</HTML>");
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
