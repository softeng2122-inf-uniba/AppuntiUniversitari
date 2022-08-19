import java.io.*;
import java.sql.*;
import javax.servlet.*;
import javax.servlet.http.*;

public class UpdateProject extends HttpServlet
{

    public void doPost(HttpServletRequest request, HttpServletResponse response)
    throws IOException, ServletException
    {
    	String pid=request.getParameter("pid");
    	String pname=request.getParameter("pname");
    	
    	String description=request.getParameter("description");
        String date=request.getParameter("date");
        String duration=request.getParameter("duration");
        String name=request.getParameter("name");
        String address=request.getParameter("address");
        String phoneno=request.getParameter("phoneno");
        String emailid=request.getParameter("emailid");
       
        String deptname=request.getParameter("deptname");
        String plead=request.getParameter("plead");
        
        System.out.println("ecode"+pname);
    	Connection con;
    	PreparedStatement pstmt;
    	ServletContext sc=getServletContext();
		String driver=sc.getInitParameter("drivername");
    	String url=sc.getInitParameter("url");
    	String dbpassword=sc.getInitParameter("password");
    	String user=sc.getInitParameter("username");
	    response.setContentType("text/html");
	    System.out.println("pname"+pname);
		
		try
		{
			System.out.println(".......1........");
    	  Class.forName(driver);
    	  
    	  con=DriverManager.getConnection(url,user,dbpassword);
    	  System.out.println(".......2........");
    	  System.out.println(pname);
    	  pstmt=con.prepareStatement("update project_details set project_name=?,project_description=?,sdate=?,duration=?,clientname=?,clientaddress=?,clientphone=?,clientemail=?,projectlead=?,deptname=? where project_no=?");
    	  System.out.println(".......3........");
    	  pstmt.setString(1,pname );
    	  pstmt.setString(2,description);
    	  pstmt.setString(3,date);
    	  pstmt.setString(4,duration);
    	  pstmt.setString(5,name);
    	  pstmt.setString(6,address);
    	  pstmt.setString(7,phoneno );
    	  pstmt.setString(8,emailid);
    	  pstmt.setString(9,plead);
    	  pstmt.setString(10,deptname);
    	  pstmt.setString(11,pid);
    	
    	 
    	 
   	  	 int n=pstmt.executeUpdate();
   	  	 System.out.println("pid"+pid);
   	  	System.out.println(".......4........"+n);
    	  response.sendRedirect("UpdateProject.jsp");
    	  System.out.println(".......5........");
		}
		catch(Exception e)
		{System.out.println(".......6........");
			e.printStackTrace();
		}
		
    }
}