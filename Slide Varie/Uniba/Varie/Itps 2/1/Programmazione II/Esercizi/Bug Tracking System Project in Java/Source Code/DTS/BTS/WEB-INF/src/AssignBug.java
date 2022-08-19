import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;
import java.sql.*;
public class AssignBug extends HttpServlet
{
	public void service(HttpServletRequest request,HttpServletResponse response)throws IOException,ServletException
	{
        
		ServletContext sc=getServletContext();
		String driver=sc.getInitParameter("drivername");
		String url=sc.getInitParameter("url");
		String uname=sc.getInitParameter("username");
		String pwd=sc.getInitParameter("password");
        String bug_name=request.getParameter("bug_name");
		String bug_type=request.getParameter("bug_type");
		String bug_level=request.getParameter("bug_level");
        int priority=Integer.parseInt(request.getParameter("priority"));
        String pname=request.getParameter("pname");
        String tester_code=request.getParameter("tester_code");
        String bug_date=request.getParameter("bug_date");
        String e_code=request.getParameter("e_code");
        String status=request.getParameter("status");
        
		System.out.println(".......10........");
				try
				{
			Class.forName(driver);
			Connection  con=DriverManager.getConnection(url,uname,pwd);
			System.out.println(".......11........");
			PreparedStatement pstmt=con.prepareStatement("insert into bug_report(bug_name,bug_type,bug_level,priority,pname,testercode,bugdate,e_code,status) values(?,?,?,?,?,?,?,?,?)");
			pstmt.setString(1,bug_name);
			pstmt.setString(2,bug_type);
			pstmt.setString(3,bug_level);
			pstmt.setInt(4,priority);
			pstmt.setString(5,pname);
			pstmt.setString(6,tester_code);
			pstmt.setString(7,bug_date);
			pstmt.setString(8,e_code);
			pstmt.setString(9,status);
			
			int n=pstmt.executeUpdate();
			System.out.println(".......13........");
			if(n==1)
			{
				response.sendRedirect("./AssignBug.jsp?msg=Successfully saved");
				}
				
			System.out.println(".......18........");
			}catch(Exception e)
			{
				e.printStackTrace();
		}
			
			 
	}
}