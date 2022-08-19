import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;
import java.sql.*;
public class Login extends HttpServlet
{
	public void service(HttpServletRequest request,HttpServletResponse response)throws IOException,ServletException
	{
        
		ServletContext sc=getServletContext();
		String driver=sc.getInitParameter("drivername");
		String url=sc.getInitParameter("url");
		String uname=sc.getInitParameter("username");
		String pwd=sc.getInitParameter("password");
		String userid=request.getParameter("userid");
		
		String password=request.getParameter("password");
		System.out.println(".......10........");
				try
				{
			Class.forName(driver);
			Connection  con=DriverManager.getConnection(url,uname,pwd);
			System.out.println(".......11........");
			PreparedStatement pstmt=con.prepareStatement("select role,permission from employee_details where loginid=? and password=?");
			pstmt.setString(1,userid);
			pstmt.setString(2,password);
			ResultSet rs=pstmt.executeQuery();
			System.out.println(".......13........");
			HttpSession hs=request.getSession();
			int i=0;
			if(userid.equals("admin") && password.equals("12345"))
			{
				System.out.println(".......14a........");
				hs.setAttribute("role","admin");
				response.sendRedirect("./AdminHome.jsp");
			}
		
			while(rs.next())
			{
				i++;
				System.out.println(".......14........");
				if(rs.getString("role").equals("Tester"))
				{
					 System.out.println("--permission--"+rs.getString("permission"));
						if(rs.getString("permission").equals("n"))
						{
						response.sendRedirect("./Home.jsp?msg1=Permission not Granted");
							
					     }
						else
						{	
					         System.out.println(".......14a........");
					         hs.setAttribute("userid",userid);
					         hs.setAttribute("role", rs.getString("role"));
					         response.sendRedirect("./TesterHome.jsp");
						}
				}
				
				if(rs.getString("role").equals("Manager"))
				{
					 System.out.println("--permission--"+rs.getString("permission"));
						if(rs.getString("permission").equals("n"))
						{
						response.sendRedirect("./Home.jsp?msg1=Permission not Granted");
							
					     }
						else
						{
							System.out.println(".......14c........");
							hs.setAttribute("userid",userid);
							hs.setAttribute("role", rs.getString("role"));
							response.sendRedirect("./ManagerHome.jsp");
						}
				}
				if(rs.getString("role").equals("Developer"))
				{
					 System.out.println("--permission--"+rs.getString("permission"));
						if(rs.getString("permission").equals("n"))
						{
						response.sendRedirect("./Home.jsp?msg1=Permission not Granted");
							
					     }
						else
						{
					
					     System.out.println(".......14b........");
					     hs.setAttribute("userid",userid);
					     hs.setAttribute("role", rs.getString("role"));
					     response.sendRedirect("./DeveloperHome.jsp");
						}
				}
					
			
			
			}//while
		
		
			
			if(i==0)
			{
				System.out.println(".......17........");
				response.sendRedirect("./Home.jsp?msg=Check your userid and password.");
			}
			
			System.out.println(".......18........");
			}catch(Exception e)
			{
				e.printStackTrace();
				}
			
		
	}
}