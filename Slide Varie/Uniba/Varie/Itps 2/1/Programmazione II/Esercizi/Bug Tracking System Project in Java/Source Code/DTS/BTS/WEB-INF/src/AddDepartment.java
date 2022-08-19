import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;
import java.sql.*;
public class AddDepartment extends HttpServlet
{
	public void service(HttpServletRequest request,HttpServletResponse response)throws IOException,ServletException
	{
        
		ServletContext sc=getServletContext();
		String driver=sc.getInitParameter("drivername");
		String url=sc.getInitParameter("url");
		String uname=sc.getInitParameter("username");
		String pwd=sc.getInitParameter("password");
		String deptname=request.getParameter("dname");
        String loc=request.getParameter("location");
		System.out.println(".......10........");
				try
				{
			Class.forName(driver);
			Connection  con=DriverManager.getConnection(url,uname,pwd);
			System.out.println(".......11........");
			PreparedStatement pstmt=con.prepareStatement("insert into department_details(dept_name,dept_loc)values(?,?)");
			pstmt.setString(1,deptname);
			pstmt.setString(2,loc);
			int n=pstmt.executeUpdate();
			System.out.println(".......13........");
			if(n==1)
			{
				response.sendRedirect("./AddDepartment.jsp?msg=Successfully saved");
				}
				
			System.out.println(".......18........");
			}catch(Exception e)
			{
				e.printStackTrace();
		}
			
			 
	}
}