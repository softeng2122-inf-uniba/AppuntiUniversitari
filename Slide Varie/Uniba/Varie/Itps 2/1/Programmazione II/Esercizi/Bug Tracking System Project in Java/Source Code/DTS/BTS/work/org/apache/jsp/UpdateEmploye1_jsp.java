package org.apache.jsp;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.jsp.*;
import java.sql.*;
import java.io.*;
import java.util.Random;

public final class UpdateEmploye1_jsp extends org.apache.jasper.runtime.HttpJspBase
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
      out.write("\r\n");
      out.write("<title>Edir Requests</title>\r\n");
      out.write("<head>\r\n");
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
      out.write("            if(ChkMandatoryField(frm.bsalary,'BasicSalary')==false) return false;\r\n");
      out.write("            \r\n");
      out.write("            \r\n");
      out.write("            \r\n");
      out.write("\t\t}\r\n");
      out.write("\t\t\r\n");
      out.write("\t</script>\r\n");
      out.write("\r\n");
      out.write("\r\n");
      out.write("</head>\r\n");
      out.write("<form action=\"./UpdateEmp\" method=\"post\" name=\"frm\">\r\n");
      out.write("<h3 align=center>UPDATE EMPLOYEE</h3>\r\n");

/*Declaration of variables*/

Connection con;
PreparedStatement pstmt,pstmt1;
ResultSet rs=null,rs1=null;

String ecode,fname,lname,gender,dob,qualification,address,phoneno,mobileno,emailid,doj,role,salary,dno;
ecode=request.getParameter("ecode");

try
{	
	      Class.forName("com.mysql.jdbc.Driver");
       	  con=DriverManager.getConnection("jdbc:mysql://localhost:3306/bts", "root", "igen");
       	  pstmt=con.prepareStatement("select * from employee_details where e_code=?");
       	  pstmt.setString(1,ecode);
    	   rs=pstmt.executeQuery();


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
	   ecode=rs.getString("e_code");
	   fname=rs.getString("fname");
	   lname=rs.getString("lname");
	   gender=rs.getString("gender");
	   dob=rs.getString("dob");
	   qualification=rs.getString("qualification");
	   address=rs.getString("address");
	   phoneno=rs.getString("phoneno");
	   mobileno=rs.getString("mobileno");
	   emailid=rs.getString("emailid");
	   doj=rs.getString("doj");
	   role=rs.getString("role");
	   salary=rs.getString("basicsalary");
	   dno=rs.getString("dno");
	   
	   DisRow++;
	
      out.write("\r\n");
      out.write("\t<tr class= ");
      out.print((DisRow%2!=0)? "row_even" : "row_odd");
      out.write(">\r\n");
      out.write("\t    <tr><td align=\"center\"></td><td><input type=\"hidden\" value=");
      out.print(ecode);
      out.write(" name=\"ecode\"  ></td></tr>\r\n");
      out.write("\t\t<tr><td align=\"center\">Employee Name:</td><td><input type=\"text\"value=");
      out.print(fname);
      out.print(lname );
      out.write(" name=\"empname\" disabled=\"true\"></td></tr>\r\n");
      out.write("\t\t<tr><td align=\"center\">Gender:</td><td><input type=\"text\"value=");
      out.print(gender);
      out.write(" name=\"gender\" disabled=\"true\"></td></tr>\r\n");
      out.write("\t\t<tr><td align=\"center\">Date of Birth</td><td><input type=\"text\"value=");
      out.print(dob);
      out.write(" name=\"dob\" disabled=\"true\"></td></tr>\r\n");
      out.write("\t\t<tr><td align=\"center\">Qualification:</td><td><input type=\"text\"value=");
      out.print(qualification);
      out.write(" name=\"qualification\" disabled=\"true\"></td></tr>\r\n");
      out.write("\t\t<tr><td align=\"center\">Address:</td><td><input type=\"text\"value=");
      out.print(address);
      out.write(" name=\"address\" disabled=\"true\"></td></tr>\r\n");
      out.write("\t\t<tr><td align=\"center\">PhoneNo</td><td><input type=\"text\"value=");
      out.print(phoneno);
      out.write(" name=\"phoneno\" disabled=\"true\"></td></tr>\r\n");
      out.write("\t\t<tr><td align=\"center\">MobileNo:</td><td><input type=\"text\"value=");
      out.print(mobileno);
      out.write(" name=\"mobileno\" disabled=\"true\"></td></tr>\r\n");
      out.write("\t\t<tr><td align=\"center\">EmailId:</td><td><input type=\"text\"value=");
      out.print(emailid);
      out.write(" name=\"emailid\" disabled=\"true\"></td></tr>\r\n");
      out.write("\t\t<tr><td align=\"center\">Date Of Joining:</td><td><input type=\"text\"value=");
      out.print(doj);
      out.write(" name=\"doj\" disabled=\"true\"></td></tr>\r\n");
      out.write("\t\t<tr><td align=\"center\">Role:</td><td><input type=\"text\"value=");
      out.print(role);
      out.write(" name=\"role\" disabled=\"true\"></td></tr>\r\n");
      out.write("\t\t<tr><td align=\"center\">Basic Salary:</td><td><input type=\"text\" name=\"bsalary\" value=");
      out.print(salary );
      out.write("></td></tr>\r\n");
      out.write("\t\t<tr>\r\n");
      out.write("\t\t<td align=\"center\">Department Name</td>\r\n");
      out.write("\t\t<td><select name=\"deptname\">\r\n");
      out.write("\t\t  ");
pstmt=con.prepareStatement("select * from department_details");
       	  rs=pstmt.executeQuery();
       	  while(rs.next())
       	  {
       	  
      out.write("\r\n");
      out.write("       \t  <option>");
      out.print(rs.getString("dept_name") );
      out.write("</option>\r\n");
      out.write("       \t  ");
 
       	      	  }
       	  
      out.write("\r\n");
      out.write("   \r\n");
      out.write("       \t \r\n");
      out.write("\t\t\r\n");
      out.write("\t\t</select>\r\n");
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

}
catch(Exception e)
{
	e.printStackTrace();
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
      out.write("\r\n");
      out.write("\r\n");
      out.write("\r\n");
      out.write("\r\n");
      out.write("\r\n");
      out.write("\r\n");
      out.write("\r\n");
      out.write("\r\n");
      out.write("\r\n");
      out.write("\r\n");
      out.write("\r\n");
      out.write("\r\n");
      out.write("\r\n");
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
