import java.io.*;
import java.sql.*;
import javax.servlet.*;
import javax.servlet.http.*;

public class UpdateDepartment extends HttpServlet
{

    public void doPost(HttpServletRequest request, HttpServletResponse response)
    throws IOException, ServletException
    {
    	String deptname=request.getParameter("deptname");
    	
    	String loc=request.getParameter("location");
        String deptno=request.getParameter("deptno");
    	Connection con;
    	PreparedStatement pstmt;
    	ServletContext sc=getServletContext();
		String driver=sc.getInitParameter("drivername");
    	String url=sc.getInitParameter("url");
    	String dbpassword=sc.getInitParameter("password");
    	String user=sc.getInitParameter("username");
	    response.setContentType("text/html");
		
		try
		{
			System.out.println(".......1........");
    	  Class.forName(driver);
    	  
    	  con=DriverManager.getConnection(url,user,dbpassword);
    	  System.out.println(".......2........");
    	  System.out.println(deptno);
    	  pstmt=con.prepareStatement("update department_details set dept_name=?,dept_loc=? where dept_no=?");
    	  System.out.println(".......3........");
    	  
    	  
    	  pstmt.setString(1,deptname);
    	  pstmt.setString(2,loc);
    	  pstmt.setString(3,deptno);
    	 
   	  	  pstmt.execute();
   	  	System.out.println(".......4........");
    	  response.sendRedirect("UpdateDepartment.jsp");
    	  System.out.println(".......5........");
		}
		catch(Exception e)
		{System.out.println(".......6........");
			e.printStackTrace();
		}
		
    }
}