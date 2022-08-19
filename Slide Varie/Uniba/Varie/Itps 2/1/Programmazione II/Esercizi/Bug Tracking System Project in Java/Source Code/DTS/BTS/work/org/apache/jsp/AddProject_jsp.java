package org.apache.jsp;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.jsp.*;
import java.sql.*;
import java.io.*;
import java.util.Random;

public final class AddProject_jsp extends org.apache.jasper.runtime.HttpJspBase
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
      out.write("<html>\r\n");
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
      out.write("\t\t\tif(ChkMandatoryField(proj.pname,'ProjectName')==false) return false;\r\n");
      out.write("            if(ChkMandatoryField(proj.description,'Description')==false) return false;\r\n");
      out.write("             if(ChkMandatoryField(proj.sdate,'date')==false) return false;\r\n");
      out.write("            if(ChkMandatoryField(proj.duration,'Duration')==false) return false;\r\n");
      out.write("            if(ChkMandatoryField(proj.cname,'Name')==false) return false;\r\n");
      out.write("            if(ChkMandatoryField(proj.caddress,'Address')==false) return false;\r\n");
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
      out.write("</head>\r\n");
      out.write("\r\n");
      out.write("<body bgcolor=\"silver\">\r\n");
      out.write("<form  name=\"proj\" action=\"./AddProj\">\r\n");
      out.write("<center>\r\n");
      out.write("<h3>Add Project</h3></center>\r\n");
      out.write("<center><table>\r\n");
      out.write("<tr>\r\n");
      out.write("  <td>&nbsp;Project Name:</td>\r\n");
      out.write("  <td><input type=\"text\" name=\"pname\" value=\"\"></td>\r\n");
      out.write("</tr>\r\n");
      out.write("<tr>\r\n");
      out.write("  <td>Project Description</td>\r\n");
      out.write("  <td><textarea name=\"description\" cols=\"20\" rows=\"3\" name=\"description\"></textarea></td>\r\n");
      out.write("  </tr>\r\n");
      out.write("   \r\n");
      out.write("<tr>\r\n");
      out.write("  <td>&nbsp;Submission Date</td>\r\n");
      out.write("  <td><input type=\"text\" name=\"sdate\" value=\"\"></td>\r\n");
      out.write("</tr>\r\n");
      out.write("\r\n");
      out.write("\r\n");
      out.write("<tr>\r\n");
      out.write("  <td>&nbsp;Duration:</td>\r\n");
      out.write("  <td><input type=\"text\" name=\"duration\" value=\"\"></td>\r\n");
      out.write("</tr>\r\n");
      out.write("\r\n");
      out.write("<tr>\r\n");
      out.write("  <td>&nbsp;Client Name:</td>\r\n");
      out.write("  <td><input type=\"text\" name=\"cname\" value=\"\"></td>\r\n");
      out.write("</tr>\r\n");
      out.write("\r\n");
      out.write("\r\n");
      out.write("<tr>\r\n");
      out.write("  <td>Client Address</td>\r\n");
      out.write("  <td><textarea name=\"caddress\" name=\"caddress\" cols=\"20\" rows=\"3\"></textarea></td>\r\n");
      out.write("  </tr>\r\n");
      out.write("   \r\n");
      out.write("<tr>\r\n");
      out.write("  <td>&nbsp;Phone No:</td>\r\n");
      out.write("  <td><input type=\"text\" name=\"phoneno\" value=\"\"></td>\r\n");
      out.write("</tr>\r\n");
      out.write("\r\n");
      out.write("<tr>\r\n");
      out.write("  <td>&nbsp;EmailId:</td>\r\n");
      out.write("  <td><input type=\"text\" name=\"mailid\" value=\"\"></td>\r\n");
      out.write("</tr>\r\n");
      out.write("\r\n");
      out.write("\r\n");
      out.write("<tr><td>Department Name:</td>\r\n");
      out.write("<td><select name=\"deptname\">\r\n");

Connection con;
PreparedStatement pstmt,pstmt1;
ResultSet rs=null,rs1=null;




try

{	
	      Class.forName("com.mysql.jdbc.Driver");
       	  con=DriverManager.getConnection("jdbc:mysql://localhost:3306/bts", "root", "igen");
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
      out.write("    \t   <tr><td>Project Lead:</td>\r\n");
      out.write("    \t   <td><select name=\"plead\">\r\n");
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
      out.write("    \t  \r\n");
      out.write("\r\n");
      out.write("  ");
  	   
}
catch(Exception e)
{
e.printStackTrace();

}


      out.write("\r\n");
      out.write("</table><br>\r\n");
      out.write("&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;\r\n");
      out.write("<tr><td><input type=\"submit\" name=\"login\" value=\"login\" onClick=\"return validate()\"></td></tr>\r\n");
      out.write("</center>\r\n");
      out.write("</body>\r\n");
      org.apache.jasper.runtime.JspRuntimeLibrary.include(request, response, "footer.jsp", out, true);
      out.write("\r\n");
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
