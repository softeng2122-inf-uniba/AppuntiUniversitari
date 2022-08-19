/* program for changing password of the recruiter*/

import javax.servlet.*;
import javax.servlet.http.*;
import java.io.*;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;

public class RecChngPwdServ extends HttpServlet 
{
	public void doPost(HttpServletRequest req,HttpServletResponse res) throws ServletException,IOException
	{   
		HttpSession hs=req.getSession(false);

		String userid=(String)hs.getAttribute("userid");
		String msg="";
		
		String npass=req.getParameter("npass");
		
		ServletContext sc=getServletContext();
		
		String driver=sc.getInitParameter("drivername");
		String url=sc.getInitParameter("url");
		String uname=sc.getInitParameter("username");
		String pwd=sc.getInitParameter("password");
		
	try
	{
	Class.forName(driver);
	Connection  con=DriverManager.getConnection(url,uname,pwd);
	System.out.println(".......11........");
	PreparedStatement pstmt=con.prepareStatement("update employee_details set password=? where loginid=?");
	pstmt.setString(1,npass);
	pstmt.setString(2,userid);
	System.out.println("userid is "+userid);
	int n=0;
	n=pstmt.executeUpdate();
	if(n>0)
	{
		res.sendRedirect("./Recchange_pass.jsp?cat="+req.getParameter("cat")+"&msg=Password changed successfully");
	}
	}//try
	catch(Exception e)
	{
		e.printStackTrace();
	}
	}//post
}
