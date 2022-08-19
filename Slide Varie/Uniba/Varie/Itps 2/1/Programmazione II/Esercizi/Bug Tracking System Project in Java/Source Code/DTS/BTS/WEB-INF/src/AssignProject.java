import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;
import java.sql.*;
public class AssignProject extends HttpServlet
{
	public void service(HttpServletRequest request,HttpServletResponse response)throws IOException,ServletException
	{
        
		ServletContext sc=getServletContext();
		String driver=sc.getInitParameter("drivername");
		String url=sc.getInitParameter("url");
		String uname=sc.getInitParameter("username");
		String pwd=sc.getInitParameter("password");
		String pname=request.getParameter("pname");
        String e_code=request.getParameter("e_code");
        String role=request.getParameter("role");
		System.out.println(".......10........");
				try
				{
			Class.forName(driver);
			Connection  con=DriverManager.getConnection(url,uname,pwd);
			System.out.println(".......11........");
			PreparedStatement pstmt=con.prepareStatement("insert into assign_project(project_name,userid,role)values(?,?,?)");
			pstmt.setString(1,pname);
			pstmt.setString(2,e_code);
			pstmt.setString(3,role);
			int n=pstmt.executeUpdate();
			System.out.println(".......13........");
			if(n==1)
			{
				response.sendRedirect("./AssignProject.jsp?msg=Successfully saved");
				}
				
			System.out.println(".......18........");
			}catch(Exception e)
			{
				e.printStackTrace();
		}
			
			 
	}
}