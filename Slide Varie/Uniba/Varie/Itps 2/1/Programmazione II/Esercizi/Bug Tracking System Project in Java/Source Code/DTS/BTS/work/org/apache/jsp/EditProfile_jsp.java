package org.apache.jsp;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.jsp.*;
import java.sql.*;

public final class EditProfile_jsp extends org.apache.jasper.runtime.HttpJspBase
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

      out.write("<HTML>\r\n");
      out.write("\r\n");

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
      out.write("\r\n");
      out.write("\r\n");
      out.write("\r\n");
      out.write("<br>\r\n");
      out.write("<script LANGUAGE=\"Javascript\" >\r\n");
      out.write("\t\tfunction ChkMandatoryField(F,T){\r\n");
      out.write("\t\t\tvar val= F.value;\r\n");
      out.write("\t\t\tif(val==\"\"){alert(T+\" is mandatory\");return false;}\r\n");
      out.write("\t\t}\r\n");
      out.write("\t\t\r\n");
      out.write("\t\tfunction validate()\r\n");
      out.write("\t\t{\r\n");
      out.write("\t\t\talert(\"hai\");\r\n");
      out.write("\t\t\t\r\n");
      out.write("            if(ChkMandatoryField(editform.fname,'FirstName')==false) return false;\r\n");
      out.write("            alert(\"hai\")\r\n");
      out.write("            if(ChkMandatoryField(editform.lname,'LastName')==false) return false;\r\n");
      out.write("            if(editform.gender.value==\"select\")\r\n");
      out.write("    \t\t{\r\n");
      out.write("    \t\t\twindow.alert(\"Select Gender !\");\r\n");
      out.write("    \t\t\treturn false;\r\n");
      out.write("    \t\t}\r\n");
      out.write("    \t\talert(\"hai1\")\r\n");
      out.write("            if(ChkMandatoryField(editform.dob,'Date of Birth')==false) return false;\r\n");
      out.write("            if(ChkMandatoryField(editform.qualification,'Qualification')==false) return false;\r\n");
      out.write("            if(ChkMandatoryField(editform.address,'Address')==false) return false;\r\n");
      out.write("            if(ChkMandatoryField(editform.phoneno,'PhoneNo')==false) return false;\r\n");
      out.write("             if(ChkMandatoryField(editform.mobileno,'MobileNo')==false) return false;\r\n");
      out.write("             if(ChkMandatoryField(editform.emailid,'EmailID')==false) return false;\r\n");
      out.write("             if(ChkMandatoryField(editform.doj,'Date Of Joining')==false) return false;\r\n");
      out.write("             \r\n");
      out.write("             if(editform.role.value==\"select\")\r\n");
      out.write("    \t\t{\r\n");
      out.write("    \t\t\twindow.alert(\"Select Designation !\");\r\n");
      out.write("    \t\t\treturn false;\r\n");
      out.write("    \t\t}\r\n");
      out.write("    \t\t\r\n");
      out.write("    \t\tif(editform.maritalstatus.value==\"select\")\r\n");
      out.write("    \t\t{\r\n");
      out.write("    \t\t\twindow.alert(\"Select MaritalStatus !\");\r\n");
      out.write("    \t\t\treturn false;\r\n");
      out.write("    \t\t}\r\n");
      out.write("    \t\tif(editform.HintQuestion.value==\"select\")\r\n");
      out.write("    \t\t{\r\n");
      out.write("    \t\t\twindow.alert(\"Select HintQuestion !\");\r\n");
      out.write("    \t\t\treturn false;\r\n");
      out.write("    \t\t}\r\n");
      out.write("             \r\n");
      out.write("             if(ChkMandatoryField(editform.hintanswer,'HintAnswer')==false) return false;\r\n");
      out.write("             \r\n");
      out.write("\t\t   \r\n");
      out.write("\t\r\n");
      out.write("\r\n");
      out.write("}\r\n");
      out.write("\r\n");
      out.write("\r\n");
      out.write("\r\n");
      out.write("</script>\r\n");
      out.write("\r\n");
      out.write("<body bgcolor=\"silver\">\r\n");
      out.write("<form  name=\"editform\" action=\"UpdateProfile?cat=");
      out.print(request.getParameter("cat"));
      out.write("\" method=\"post\" >\r\n");
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
      out.write("<center><h3><font face=\"arial narrow\" >Edit Profile</font></h3></center>\r\n");
      out.write("<center>\r\n");
      out.write("<table>\r\n");

		ServletContext sc=getServletContext();
		String driver=sc.getInitParameter("drivername");
		String url=sc.getInitParameter("url");
		String uname=sc.getInitParameter("username");
		String pwd=sc.getInitParameter("password");
try{
			Class.forName(driver);
			Connection  con=DriverManager.getConnection(url,uname,pwd);
			System.out.println(".......11........");
			ResultSet rs;
			HttpSession hs=request.getSession();
			String userid=(String)hs.getAttribute("userid");
			System.out.println("userid"+userid);
			PreparedStatement pstmt=con.prepareStatement("select * from employee_details where loginid=?");
			pstmt.setString(1,userid);
			rs=pstmt.executeQuery();
	while(rs.next())
	{			
	

      out.write("\r\n");
      out.write("\r\n");
      out.write("<tr><td><b>UserID*</td><td><input type=\"text\" name=\"userid\" value=\"");
      out.print(rs.getString("loginid"));
      out.write("\" readonly></tc></td></tr>\r\n");
      out.write("<tr><td><b>Fname*</td><td><input type=\"text\" name=\"fname\" value=\"");
      out.print(rs.getString("fname"));
      out.write("\"></td></tr>\r\n");
      out.write("<tr><td><b>Lname*</td><td><input type=\"text\" name=\"lname\" value=\"");
      out.print(rs.getString("lname"));
      out.write("\"></td></tr>\r\n");
      out.write("<tr>\r\n");
      out.write("<td><b>Gender:</td>\r\n");
      out.write("<td><select name=\"gender\">\r\n");
      out.write("<option value=\"select\">----select----</option>\r\n");
      out.write("<option>Male</option>\r\n");
      out.write("<option>FeMale</option>\r\n");
      out.write("</td>\r\n");
      out.write("</tr>\r\n");
      out.write("<tr>\r\n");
      out.write("<td><B>DOB</td>\r\n");
      out.write("<td><input type=\"text\" name=\"dob\" value=\"");
      out.print(rs.getString("dob"));
      out.write("\"></td>\r\n");
      out.write("</tr>\r\n");
      out.write("\r\n");
      out.write("<tr>\r\n");
      out.write("<td><b>Qualification</b></td>\r\n");
      out.write("<td><input type=\"text\" name=\"qualification\" value=\"");
      out.print(rs.getString("qualification"));
      out.write("\"></td>\r\n");
      out.write("</tr>\r\n");
      out.write("\r\n");
      out.write("<tr>\r\n");
      out.write("<td><b>Address</b></td>\r\n");
      out.write("<td><input type=\"text\" name=\"address\" value=\"");
      out.print(rs.getString("address"));
      out.write("\"></td>\r\n");
      out.write("</tr>\r\n");
      out.write("\r\n");
      out.write("<tr>\r\n");
      out.write("<td><b>PhoneNo</b></td>\r\n");
      out.write("<td><input type=\"text\" name=\"phoneno\" value=\"");
      out.print(rs.getString("phoneno"));
      out.write("\"></td>\r\n");
      out.write("</tr>\r\n");
      out.write("\r\n");
      out.write("<tr>\r\n");
      out.write("<td><b>MobileNo</b></td>\r\n");
      out.write("<td><input type=\"text\" name=\"mobileno\" value=\"");
      out.print(rs.getString("mobileno"));
      out.write("\"></td>\r\n");
      out.write("</tr>\r\n");
      out.write("\r\n");
      out.write("<tr>\r\n");
      out.write("<td><b>EmailID</b></td>\r\n");
      out.write("<td><input type=\"text\" name=\"mailid\" value=\"");
      out.print(rs.getString("emailid"));
      out.write("\"></td>\r\n");
      out.write("</tr>\r\n");
      out.write("\r\n");
      out.write("<tr>\r\n");
      out.write("<td><b>DOJ</b></td>\r\n");
      out.write("<td><input type=\"text\" name=\"doj\" value=\"");
      out.print(rs.getString("doj"));
      out.write("\"></td>\r\n");
      out.write("</tr>\r\n");
      out.write("<tr>\r\n");
      out.write("<td><b>Designation</b></td>\r\n");
      out.write("<td>\r\n");
      out.write("<select name=\"role\"><option>Developer\r\n");
      out.write("<option>");
      out.print(rs.getString("role"));
      out.write("</option>\r\n");
      out.write("<option value=\"select\">----select----</option>\r\n");
      out.write("<option>Tester</option>\r\n");
      out.write("<option>Manager</option>\r\n");
      out.write("</td>\r\n");
      out.write("</tr>\r\n");
      out.write("\r\n");
      out.write("<tr>\r\n");
      out.write("<td><b>MaritalStatus</b></td>\r\n");
      out.write("<td>\r\n");
      out.write("<select name=\"maritalstatus\">\r\n");
      out.write("<option>");
      out.print(rs.getString("maritalstatus") );
      out.write("</option>\r\n");
      out.write("<option value=\"select\">----select----</option>\r\n");
      out.write("<option>Married</option>\r\n");
      out.write("<option>Unmarried<option></td>\r\n");
      out.write("</tr>\r\n");
      out.write("\r\n");
      out.write("\r\n");
      out.write("<tr>\r\n");
      out.write("           <td class=\"text1\"><div align=\"right\" class=\"style2\"><b>Hint Question<b></div></td>\r\n");
      out.write("           <td><div align=\"left\">\r\n");
      out.write("             <select name=\"HintQuestion\" class=\"borderBlue\">\r\n");
      out.write("\t\t       <OPTION value=\"select\">[Select One]\r\n");
      out.write("               <OPTION value=\"What is the name of your first school?\">What is the name of your first school?\r\n");
      out.write("               <OPTION value=\"What is your favourite pass-time?\">What is your favourite pass-time?\r\n");
      out.write("               <OPTION value=\"What is your mother maiden name?\">What is your mother's maiden name?\r\n");
      out.write("               <OPTION value=\"What is your favourite food?\">What is your favourite food?\r\n");
      out.write("             </select>\r\n");
      out.write("           </div></td>\r\n");
      out.write("         </tr>\r\n");
      out.write("        \r\n");
      out.write("\r\n");
      out.write("<tr>\r\n");
      out.write("<td><b>HintAnswer</b></td>\r\n");
      out.write("<td><input type=\"text\" name=\"hintanswer\" value=\"");
      out.print(rs.getString("hintanswer"));
      out.write("\"></td>\r\n");
      out.write("</tr>\r\n");
 
}
}
catch(Exception e)
{
e.printStackTrace();
}


      out.write("\r\n");
      out.write("</table><br><br>\r\n");
      out.write("&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp\r\n");
      out.write("&nbsp&nbsp&nbsp&nbsp&nbsp\r\n");
      out.write("<tr><td><b><input type=\"submit\" name=\"sub\" value=\"Edit\" onclick=\"return validate()\">\r\n");
      out.write("<b><input type=\"Reset\" name=\"reset\" value=\"Reset\"></td></tr>\r\n");
      out.write("</center>\r\n");
      out.write("</form>\r\n");
      out.write("</body>\r\n");
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
