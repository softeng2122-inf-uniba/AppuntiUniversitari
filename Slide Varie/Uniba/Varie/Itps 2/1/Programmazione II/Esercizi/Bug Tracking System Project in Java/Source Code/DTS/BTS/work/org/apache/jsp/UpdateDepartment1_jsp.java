package org.apache.jsp;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.jsp.*;
import java.sql.*;
import java.io.*;
import java.util.Random;

public final class UpdateDepartment1_jsp extends org.apache.jasper.runtime.HttpJspBase
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

      org.apache.jasper.runtime.JspRuntimeLibrary.include(request, response, "./Header.jsp", out, true);
      out.write("\r\n");
      out.write("\r\n");
      out.write("\r\n");
      out.write("\r\n");
      out.write("<HTML>\r\n");
      out.write("\r\n");
      out.write("<title>Edir Requests</title>\r\n");
      out.write("<script LANGUAGE=\"Javascript\" >\r\n");
      out.write("\t\tfunction ChkMandatoryField(F,T){\r\n");
      out.write("\t\t\tvar val= F.value;\r\n");
      out.write("\t\t\tif(val==\"\"){alert(T+\" is mandatory\");return false;}\r\n");
      out.write("\t\t}\r\n");
      out.write("\t\t\r\n");
      out.write("\t\tfunction validate()\r\n");
      out.write("\t\t{\r\n");
      out.write("\t\t\t\r\n");
      out.write("\t\t\t\r\n");
      out.write("            if(ChkMandatoryField(frm.deptname,'DepartmentName')==false) return false;\r\n");
      out.write("            if(ChkMandatoryField(frm.location,'Location')==false) return false;\r\n");
      out.write("            \r\n");
      out.write("            \r\n");
      out.write("\t\t}\r\n");
      out.write("\t\t\r\n");
      out.write("\t</script>\r\n");
      out.write("\r\n");
      out.write("</head>\r\n");
      out.write("<form action=\"./UpdateDept\" method=\"post\" name=\"frm\">\r\n");
      out.write("<h3 align=center>Update Department</h3>\r\n");

/*Declaration of variables*/

Connection con;
PreparedStatement pstmt;
ResultSet rs=null;

String deptname,location;
String deptno=request.getParameter("deptno");

try
{	
	      Class.forName("com.mysql.jdbc.Driver");
       	  con=DriverManager.getConnection("jdbc:mysql://localhost:3306/bts", "root", "igen");
       	  pstmt=con.prepareStatement("select * from department_details where dept_no=?");
       	  pstmt.setString(1,deptno);
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
      out.write("\t<table align=center>\r\n");
      out.write("\t\t\t\t\r\n");

int DisRow=0;
	/*Getting the values from the database*/

	while(rs.next())
	{
	   deptno=rs.getString(1);
	   deptname=rs.getString(2);
	   location=rs.getString(3);
	   
	   DisRow++;
	
      out.write("\r\n");
      out.write("\t<tr class= ");
      out.print((DisRow%2!=0)? "row_even" : "row_odd");
      out.write(">\r\n");
      out.write("\t    <tr><td align=\"center\"></td><td><input type=\"hidden\"value=");
      out.print(deptno);
      out.write(" name=\"deptno\"></td></tr>\r\n");
      out.write("\t\t<tr><td align=\"center\">Department Name:</td><td><input type=\"text\"value=");
      out.print(deptname);
      out.write(" name=\"deptname\"></td></tr>\r\n");
      out.write("\t\t<tr><td align=\"center\">Location:</td><td><input type=\"text\"value=\"");
      out.print(location);
      out.write("\" name=\"location\" ></td></tr>\r\n");
      out.write("\t\t\r\n");
      out.write("\t\t\r\n");
      out.write("\t");

	}
	rs.close();		
if(DisRow==0)
{	
	
      out.write("\t\t\r\n");
      out.write("\t  <tr><th colspan=6>No Jobs found</th></tr>\r\n");
      out.write("\t");

}
}

      out.write("\r\n");
      out.write("</table>\r\n");
      out.write("<br>\r\n");
      out.write("<br>\r\n");
      out.write("<center><input type=\"submit\"value=\"Update\" onClick=\"return validate()\"></center>\r\n");
      out.write("</form>\r\n");
      out.write("</BODY>\r\n");
      org.apache.jasper.runtime.JspRuntimeLibrary.include(request, response, "footer.jsp", out, true);
      out.write("\r\n");
      out.write("</HTML>\r\n");
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
