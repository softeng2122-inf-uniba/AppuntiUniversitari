package org.apache.jsp;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.jsp.*;
import java.sql.*;
import java.io.*;
import java.util.Random;

public final class ViewProject_jsp extends org.apache.jasper.runtime.HttpJspBase
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

      org.apache.jasper.runtime.JspRuntimeLibrary.include(request, response, "Header.jsp", out, true);
      out.write("\r\n");
      out.write("\r\n");
      out.write("\r\n");
      out.write("\r\n");
      out.write("<HTML>\r\n");
      out.write("<HEAD>\r\n");
      out.write("\r\n");
      out.write("\t<LINK href=\"styles.css\" type=\"text/css\" rel=\"stylesheet\">\r\n");
      out.write("<script LANGUAGE=\"Javascript\" SRC=\"Images/validate.js\"></script>\r\n");
      out.write("<title>Adminresponse</title>\r\n");
      out.write("<script language=\"javascript\">\r\n");
      out.write("function Checkfiles()\r\n");
      out.write("{\r\n");
      out.write("\t\r\n");
      out.write("     var fup = document.getElementById('my_file_element').value;\r\n");
      out.write("     alert(fup);\r\n");
      out.write("\t if(fup==\"\")\r\n");
      out.write("\t {\r\n");
      out.write("\t alert(\"Upload at least one file\");\r\n");
      out.write("\t document.getElementById('my_file_element').focus();\r\n");
      out.write("\t return false;\r\n");
      out.write("\t }\r\n");
      out.write("\t else if(fup!=\"\")\r\n");
      out.write("\t {\r\n");
      out.write("\t alert(\"Not null\");\r\n");
      out.write("     var fileName = fup;\r\n");
      out.write("\r\n");
      out.write("     var ext = fileName.substring(fileName.lastIndexOf('.') + 1);\r\n");
      out.write("\t alert(ext);\r\n");
      out.write("     if(ext == \"gif\" || ext == \"GIF\" || ext == \"JPEG\" || ext == \"jpeg\" || ext == \"jpg\" || ext == \"JPG\")\r\n");
      out.write("\r\n");
      out.write("      {\r\n");
      out.write("\t\t\t\talert(\"correct format\");\r\n");
      out.write("                return true;\r\n");
      out.write("\r\n");
      out.write("      }         \r\n");
      out.write("\r\n");
      out.write("      else\r\n");
      out.write("\r\n");
      out.write("      {\r\n");
      out.write("\r\n");
      out.write("                alert(\"Upload Gif or Jpg images only\");\r\n");
      out.write("                document.getElementById('my_file_element').focus();\r\n");
      out.write("                return false;\r\n");
      out.write("\r\n");
      out.write("       }\r\n");
      out.write("       return false;\r\n");
      out.write("\t}\r\n");
      out.write("}</script>\r\n");
      out.write("</HEAD>\r\n");
      out.write("\r\n");
      out.write("<body class=\"SC\">\r\n");
      out.write("<form name=\"get ElementById\">\r\n");
      out.write("<h3 align=center>View Project</h3>\r\n");

/*Declaration of variables*/

Connection con;
PreparedStatement pstmt;
ResultSet rs=null;

String pid,pname,description,date,duration,name,address,phone,email,plead,deptname;

try
{	
	      Class.forName("com.mysql.jdbc.Driver");
       	  con=DriverManager.getConnection("jdbc:mysql://localhost:3306/bts", "root", "igen");
       	  pstmt=con.prepareStatement("select * from project_details");
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
      out.write("        <th align=\"center\">ProjectName</th>\r\n");
      out.write("\t\t<th align=\"center\">Submission Date</th>\r\n");
      out.write("\t\t<th align=\"center\">Duration</th>\r\n");
      out.write("\t\t<th align=\"center\">ClientName</th>\r\n");
      out.write("\t\t<th align=\"center\">ClientAddress</th>\r\n");
      out.write("\t\t<th align=\"center\">PhoneNo</th>\r\n");
      out.write("\t\t<th align=\"center\">EmailId</th>\r\n");
      out.write("\t\t<th align=\"center\">ProjectLead</th>\r\n");
      out.write("\t\t<th align=\"center\">DeptName</th>\r\n");
      out.write("\t\t<th align=\"center\">Delete</th>\r\n");
      out.write("\t\t");

int DisRow=0;
	/*Getting the values from the database*/

	while(rs.next())
	{
	   pid=rs.getString("project_no");
	   pname=rs.getString("project_name");
	   description=rs.getString("project_description");
	   date=rs.getString("sdate");
	   duration=rs.getString("duration");
	   name=rs.getString("clientname");
	   address=rs.getString("clientaddress");
	   phone=rs.getString("clientphone");
	   email=rs.getString("clientemail");
	   plead=rs.getString("projectlead");
	   deptname=rs.getString("deptname");
	   DisRow++;
	
      out.write("\r\n");
      out.write("\t<tr class= ");
      out.print((DisRow%2!=0)? "row_even" : "row_odd");
      out.write(">\r\n");
      out.write("\t\t\r\n");
      out.write("\t\t<td align=\"center\">");
      out.print(pname);
      out.write("</td>\r\n");
      out.write("\t\t<td align=\"center\">");
      out.print(date);
      out.write("</td>\r\n");
      out.write("\t\t<td align=\"center\">");
      out.print(duration);
      out.write("</td>\r\n");
      out.write("\t\t<td align=\"center\">");
      out.print(name);
      out.write("</td>\r\n");
      out.write("\t\t<td align=\"center\">");
      out.print(address);
      out.write("</td>\r\n");
      out.write("\t\t<td align=\"center\">");
      out.print(phone);
      out.write("</td>\r\n");
      out.write("\t\t<td align=\"center\">");
      out.print(email);
      out.write("</td>\r\n");
      out.write("\t\t<td align=\"center\">");
      out.print(plead);
      out.write("</td>\r\n");
      out.write("\t\t<td align=\"center\">");
      out.print(deptname);
      out.write("</td>\r\n");
      out.write("\t\t<td align=\"center\"><a href=\"DelProj?pid=");
      out.print(pid);
      out.write("\">Delete</a></td>\r\n");
      out.write("\t\t");

	}
	rs.close();		
if(DisRow==0)
{	
	
      out.write("\t\t\r\n");
      out.write("\t\t\t<tr><th colspan=5>No Records found</th></tr>\r\n");
      out.write("\t");

}
}

      out.write("\r\n");
      out.write("</table>\r\n");
      out.write("<br><br><br>\r\n");
      out.write("</BODY>\r\n");
      org.apache.jasper.runtime.JspRuntimeLibrary.include(request, response, "footer.jsp", out, true);
      out.write("\r\n");
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
