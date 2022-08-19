import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;
import java.sql.*;
public class AddProject extends HttpServlet
{
	public void service(HttpServletRequest request,HttpServletResponse response)throws IOException,ServletException
	{
        
		ServletContext sc=getServletContext();
		String driver=sc.getInitParameter("drivername");
		String url=sc.getInitParameter("url");
		String uname=sc.getInitParameter("username");
		String pwd=sc.getInitParameter("password");
		String pname=request.getParameter("pname");
        String description=request.getParameter("description");
        String sdate=request.getParameter("sdate");
        String cname=request.getParameter("cname");
        String caddress=request.getParameter("caddress");
        String phoneno=request.getParameter("phoneno");
        String mailid=request.getParameter("mailid");
        String deptname=request.getParameter("deptname");
        System.out.println(deptname);
        String duration=request.getParameter("duration");
        String plead=request.getParameter("plead");
        
        
		System.out.println(".......10........");
				try
				{
			Class.forName(driver);
			Connection  con=DriverManager.getConnection(url,uname,pwd);
			System.out.println(".......11........");
			PreparedStatement pstmt=con.prepareStatement("insert into project_details(project_name,project_description,sdate,duration,clientname,clientaddress,clientphone,clientemail,projectlead,deptname) values(?,?,?,?,?,?,?,?,?,?)");
			pstmt.setString(1,pname);
			pstmt.setString(2,description);
			pstmt.setString(3,sdate);
			pstmt.setString(4,duration);
			pstmt.setString(5,cname);
			pstmt.setString(6,caddress);
			pstmt.setString(7,phoneno);
			pstmt.setString(8,mailid);
			pstmt.setString(9,plead);
			pstmt.setString(10,deptname);
			
			
			
			int n=pstmt.executeUpdate();
			System.out.println(".......13........");
			if(n==1)
			{
				response.sendRedirect("./AddProject.jsp?msg=Successfully saved");
				}
				
			System.out.println(".......18........");
			}catch(Exception e)
			{
				e.printStackTrace();
		}
			
			 
	}
}