import java.io.*;
import java.sql.*;
import javax.servlet.*;
import javax.servlet.http.*;

public class solution extends HttpServlet
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
	    HttpSession hs=request.getSession();
	    String userid=(String)hs.getAttribute("userid");
	    
	    String status=request.getParameter("status");
	    String bug_rectified=request.getParameter("bug_rectified");
	    int bugid=Integer.parseInt(request.getParameter("bugid"));

		try
		{
		  System.out.println(".......1........"+request.getParameter("solution"));
    	  Class.forName(driver);
    	  con=DriverManager.getConnection(url,user,dbpassword);
    	  System.out.println(".......2........");
     	
    	  //pstmt=con.prepareStatement("insert into bug_solution set status1=?,bug_rectifieddate=? where bugno=?");
    	  pstmt=con.prepareStatement("insert into bug_solution values(?,?,?,?)");
    	  System.out.println(".......3........");
    	  
    	  
    	  pstmt.setInt(1,bugid);
    	  pstmt.setString(2,userid);
    	  pstmt.setString(3,request.getParameter("solution"));
    	  pstmt.setString(4,request.getParameter("pdate"));
    	
    	 
    	 
    	 int i=0;
   	  	  i=pstmt.executeUpdate();
   	  	System.out.println(".......4........");
   	  	 if(i>0)
   	  	 {
   	     	System.out.println(".......5........");
    	    response.sendRedirect("ViewBugs.jsp?msg=Successfully Updated&bugid="+bugid);
   	  	 }
   	  System.out.println(".......6........");
    	  
		}
		catch(Exception e)
		{System.out.println(".......6........");
			e.printStackTrace();
		}
		
    }
}