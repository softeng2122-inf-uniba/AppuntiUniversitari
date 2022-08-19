import java.io.*;
import java.sql.*;
import javax.servlet.*;
import javax.servlet.http.*;
public class Employee extends HttpServlet
{
public void service(HttpServletRequest request,HttpServletResponse response)throws ServletException,IOException
{
	Connection con;
	PreparedStatement pstmt;
	PrintWriter out=response.getWriter();
	ServletContext sc=getServletContext();
	String driver=sc.getInitParameter("drivername");
	String url=sc.getInitParameter("url");
	String uname=sc.getInitParameter("username");
	String pwd=sc.getInitParameter("password");
	response.setContentType("text/html");
	String f1=request.getParameter("f1");
    String to=request.getParameter("to");
    String from=request.getParameter("from");
    String subject=request.getParameter("subject");
    String message=request.getParameter("message");
    String tested=request.getParameter("tested");
        System.out.println("...........1.......");
 try{
	Class.forName(driver);
	 con=DriverManager.getConnection(url,uname,pwd);
	 System.out.println("...........2.......");
	 pstmt=con.prepareStatement("insert into employeerequest values(?,?,?,?,?,?)");
	 System.out.println("...........3.......");
 	pstmt.setString(1,f1);
	pstmt.setString(2,to);
	pstmt.setString(3,from);
	pstmt.setString(4,subject);
	pstmt.setString(5,message);
	pstmt.setString(6,tested);
	System.out.println("...........4.......");
	pstmt.executeUpdate();
	System.out.println("rows updated");
	pstmt.close();
     con.close();
     {
		 
	    out.print("<html>");
	     out.print("<body bgcolor=\"cyan\">");
	     out.print("<a href=Employeerequest.html>Sucessfully forward one request</a>");		
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