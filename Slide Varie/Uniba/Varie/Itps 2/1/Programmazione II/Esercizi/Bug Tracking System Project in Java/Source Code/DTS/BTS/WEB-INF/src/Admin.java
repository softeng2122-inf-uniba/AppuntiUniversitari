import java.io.*;
import java.sql.*;
import javax.servlet.*;
import javax.servlet.http.*;
public class Admin extends HttpServlet
{
public void service(HttpServletRequest request,HttpServletResponse response)throws ServletException,IOException
{
	Connection con;
	PreparedStatement pstmt;
	ServletContext sc=getServletContext();
	String driver=sc.getInitParameter("drivername");
	String url=sc.getInitParameter("url");
	String uname=sc.getInitParameter("username");
	String pwd=sc.getInitParameter("password");
	PrintWriter out=response.getWriter();
	response.setContentType("text/html");
	String f1=request.getParameter("f1");
    String message=request.getParameter("message");
    String reassignto=request.getParameter("reassignto");
    String newstatus=request.getParameter("newstatus");
    String tested=request.getParameter("tested");
    System.out.println("...........1.......");
 try{
	Class.forName(driver);
	 con=DriverManager.getConnection(url,uname,pwd);
	 System.out.println("...........2.......");
	 pstmt=con.prepareStatement("insert into adminresponse values(?,?,?,?,?)");
	 System.out.println("...........3.......");
 	pstmt.setString(1,f1);
	pstmt.setString(2,message);
	pstmt.setString(3,reassignto);
	pstmt.setString(4,newstatus);
	pstmt.setString(5,tested);
	System.out.println("...........4.......");
	pstmt.executeUpdate();
	System.out.println("rows updated");
	pstmt.close();
     con.close();
     {
		 
	    out.print("<html>");
	     out.print("<body bgcolor=\"cyan\">");
	     out.print("<a href=Status.html>Sucessfully forward one response</a>");		
	     out.println("</body>"); 
	     out.println("</html>");	 
		
	}
	
      }
catch(Exception e)
{
	e.printStackTrace();

    }
 }
}