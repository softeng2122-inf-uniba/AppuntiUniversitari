import java.io.*;
import java.sql.*;
import javax.servlet.*;
import javax.servlet.http.*;

public class UpdateBugReport1 extends HttpServlet
{

    /**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	public void doPost(HttpServletRequest request, HttpServletResponse response)
    throws IOException, ServletException
    {
    	Connection con;
    	PreparedStatement pstmt;
    	ServletContext sc=getServletContext();
		String driver=sc.getInitParameter("drivername");
    	String url=sc.getInitParameter("url");
    	String dbpassword=sc.getInitParameter("password");
    	String user=sc.getInitParameter("username");
	    response.setContentType("text/html");
	    
	    String status=request.getParameter("status");
	    String bug_rectified=request.getParameter("bug_rectified");
	    int bugid=Integer.parseInt(request.getParameter("bugid"));
	    int i=0;
		try
		{
			System.out.println(".......1........");
    	  Class.forName(driver);
    	  con=DriverManager.getConnection(url,user,dbpassword);
    	  System.out.println(".......2........");
     	  if(status.equals("close"))
     	  {
    	   pstmt=con.prepareStatement("update bug_report set status1=? where bugno=?");
    	   System.out.println(".......3........");
    	   pstmt.setString(1,status);
    	   System.out.println("bug rect"+bug_rectified);
    	   pstmt.setInt(2,bugid);
    	   i=pstmt.executeUpdate();
     	 }
     	  else
     	  {
     		 pstmt=con.prepareStatement("update bug_report set status=?,bugdate=?,status1=?,bug_rectifieddate=? where bugno=?");
      	   System.out.println(".......3........");
      	   pstmt.setString(1,status);
      	   pstmt.setString(2,bug_rectified);
      	   System.out.println("bug rect"+bug_rectified);
      	   pstmt.setString(3,"");
      	   pstmt.setString(4,"");
      	   pstmt.setInt(5,bugid);
      	   i=pstmt.executeUpdate();
     		  
     	  }
   	  	System.out.println(".......4........");
   	  	 if(i>0)
   	  	 {
   	  	System.out.println(".......5........");
    	  response.sendRedirect("ViewBugs1.jsp?msg=Successfully Updated&bugid="+bugid);
   	  	 }
   	  System.out.println(".......6........");
    	  
		}
		catch(Exception e)
		{System.out.println(".......6........");
			e.printStackTrace();
		}
		
    }
}