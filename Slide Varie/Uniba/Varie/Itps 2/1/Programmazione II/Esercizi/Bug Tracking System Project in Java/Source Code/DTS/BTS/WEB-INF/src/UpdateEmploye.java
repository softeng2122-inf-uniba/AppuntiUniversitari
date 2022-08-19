import java.io.*;
import java.sql.*;
import javax.servlet.*;
import javax.servlet.http.*;

public class UpdateEmploye extends HttpServlet
{

    public void doPost(HttpServletRequest request, HttpServletResponse response)
    throws IOException, ServletException
    {
    	String deptname=request.getParameter("deptname");
    	
    	String bsalary=request.getParameter("bsalary");
        String ecode=request.getParameter("ecode");
        System.out.println("ecode"+ecode);
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
    	  System.out.println(ecode);
    	  pstmt=con.prepareStatement("update employee_details set basicsalary=?,dno=? where e_code=?");
    	  System.out.println(".......3........");
    	  
    	  
    	  pstmt.setString(1,bsalary );
    	  pstmt.setString(2,deptname);
    	  pstmt.setString(3,ecode);
    	 
   	  	  pstmt.execute();
   	  	System.out.println(".......4........");
    	  response.sendRedirect("UpdateEmployee.jsp");
    	  System.out.println(".......5........");
		}
		catch(Exception e)
		{System.out.println(".......6........");
			e.printStackTrace();
		}
		
    }
}