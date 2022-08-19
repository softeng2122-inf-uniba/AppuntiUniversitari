package org.apache.jsp;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.jsp.*;
import java.sql.*;
import java.io.*;
import java.util.Random;

public final class UpdateProject1_jsp extends org.apache.jasper.runtime.HttpJspBase
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
      out.write("<head>\r\n");
      out.write("<script language=\"javascript\">\r\n");
      out.write("function ChkMandatoryField(F,T){\r\n");
      out.write("\t\t\tvar val= F.value;\r\n");
      out.write("\t\t\tif(val==\"\"){alert(T+\" is mandatory\");return false;}\r\n");
      out.write("\t\t}\r\n");
      out.write("\t\t\r\n");
      out.write("\t\tfunction validate()\r\n");
      out.write("\t\t{\r\n");
      out.write("\t\t\t\r\n");
      out.write("\t\t\tif(ChkMandatoryField(proj.pname,'ProjectName')==false) return false;\r\n");
      out.write("            if(ChkMandatoryField(proj.description,'Description')==false) return false;\r\n");
      out.write("             if(ChkMandatoryField(proj.date,'date')==false) return false;\r\n");
      out.write("            if(ChkMandatoryField(proj.duration,'Duration')==false) return false;\r\n");
      out.write("            if(ChkMandatoryField(proj.name,'Name')==false) return false;\r\n");
      out.write("            if(ChkMandatoryField(proj.address,'Address')==false) return false;\r\n");
      out.write("            if(ChkMandatoryField(proj.phone,'Phone')==false) return false;\r\n");
      out.write("             if(ChkMandatoryField(proj.mailid,'Mailid')==false) return false;\r\n");
      out.write("             \r\n");
      out.write("              \r\n");
      out.write("            \r\n");
      out.write("            \r\n");
      out.write("            \r\n");
      out.write("            \r\n");
      out.write("\t\t}\r\n");
      out.write("\t\t\r\n");
      out.write("\t</script>\r\n");
      out.write("\r\n");
      out.write("\r\n");
      out.write("\r\n");
      out.write("</head>\r\n");
      out.write("\r\n");
      out.write("<title>Edir Requests</title>\r\n");
      out.write("\r\n");
      out.write("\r\n");
      out.write("\r\n");
      out.write("<form action=\"./UpdProj\" method=\"post\" name=\"frm\">\r\n");
      out.write("<h3 align=center>Update Project</h3>\r\n");

/*Declaration of variables*/

Connection con;
PreparedStatement pstmt,pstmt1;
ResultSet rs=null,rs1=null;

String pname,description,date,duration,name,address,phone,email,plead,deptname;
 String pid=request.getParameter("pid");

try
{	
	      Class.forName("com.mysql.jdbc.Driver");
       	  con=DriverManager.getConnection("jdbc:mysql://localhost:3306/bts", "root", "igen");
       	  pstmt=con.prepareStatement("select * from project_details where project_no=?");
       	  pstmt.setString(1,pid);
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
      out.write("\t\r\n");
      out.write("\t    <tr><td align=\"center\"></td><td><input type=\"hidden\" value=");
      out.print(pid);
      out.write(" name=\"pid\"></td></tr>\r\n");
      out.write("\t\t<tr><td align=\"center\">ProjectName:</td><td><input type=\"text\" value=");
      out.print(pname);
      out.write(" name=\"pname\"></td></tr>\r\n");
      out.write("\t\t<tr><td align=\"center\">Description:</td><td><textarea cols=\"30\" rows=\"3\" name=description>");
      out.print(description);
      out.write(" </textarea></td></tr>\r\n");
      out.write("\t\t<tr><td align=\"center\">Submission Date</td><td><input type=\"text\"value=");
      out.print(date);
      out.write(" name=\"date\" ></td></tr>\r\n");
      out.write("\t\t<tr><td align=\"center\">Duration:</td><td><input type=\"text\"value=");
      out.print(duration);
      out.write(" name=\"duration\" ></td></tr>\r\n");
      out.write("\t\t<tr><td align=\"center\">Client Name:</td><td><input type=\"text\"value=");
      out.print(name);
      out.write(" name=\"name\" ></td></tr>\r\n");
      out.write("\t\t<tr><td align=\"center\">Address</td><td><input type=\"text\"value=");
      out.print(address);
      out.write(" name=\"address\" ></td></tr>\r\n");
      out.write("\t\t<tr><td align=\"center\">phoneNo:</td><td><input type=\"text\"value=");
      out.print(phone);
      out.write(" name=\"phoneno\" ></td></tr>\r\n");
      out.write("\t\t<tr><td align=\"center\">EmailId:</td><td><input type=\"text\"value=");
      out.print(email);
      out.write(" name=\"emailid\" ></td></tr>\r\n");
      out.write("\t\t<tr><td>Department Name:</td>\r\n");
      out.write("<td><select name=\"deptname\">\r\n");
      out.write("<option>deptname</option>\r\n");

		pstmt=con.prepareStatement("select * from department_details");
         
    	   rs=pstmt.executeQuery();
    	   while(rs.next())
    	   {
    	   
      out.write("\r\n");
      out.write("    \t   <option>");
      out.print(rs.getString("dept_name") );
      out.write("</option>\r\n");
      out.write("    \t   ");

    	   }
    	    
      out.write("\r\n");
      out.write("    \t    </select>\r\n");
      out.write("    \t    </td></tr>\r\n");
      out.write("\t\t\r\n");
      out.write("\t\t\r\n");
      out.write("\t\t\r\n");
      out.write("\t\t\r\n");
      out.write("\t\t<tr><td>Project Lead:</td>\r\n");
      out.write("    \t   <td><select name=\"plead\">\r\n");
      out.write("    \t   <option>plead</option>\r\n");
      out.write("    \t   ");

    	   pstmt=con.prepareStatement("select * from employee_details");
    	   rs=pstmt.executeQuery();
    	   while(rs.next())
    	   {
    	   
      out.write("\r\n");
      out.write("    \t   <option>");
      out.print(rs.getString("loginid"));
      out.write("</option>\r\n");
      out.write("    \t   ");

    	   }
    	    
      out.write("\r\n");
      out.write("    \t    \r\n");
      out.write("    \t    </select>\r\n");
      out.write("    \t    </td>\r\n");
      out.write("    \t    </tr>\r\n");
      out.write("    \t  \t\r\n");
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
      out.write("<center><input type=\"submit\"value=\"Update\"></center>\r\n");
      out.write("</form>\r\n");
      out.write("<br><br>\r\n");
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
