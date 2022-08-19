import javax.servlet.*;
import javax.servlet.http.*;
import java.sql.*;
import java.io.*;


public class employeepermission extends HttpServlet
{
	public void doGet(HttpServletRequest req,HttpServletResponse res)throws ServletException,IOException
	{
		PrintWriter out = res.getWriter();
		res.setContentType("text/html");
		//String username =	req.getParameter("login");
		//String salutation =	req.getParameter("salutation");
		try
		{
		Connection con;
		Statement st;
		Class.forName("com.mysql.jdbc.Driver");
		String s="jdbc:mysql://localhost:3306/bts";
		con=DriverManager.getConnection(s,"root","igen");
		st=con.createStatement();		
	
		System.out.println("--size---"+req.getParameter("size"));
		String query=null;	
        String userid=null;
        String a[]=new String [Integer.parseInt(req.getParameter("size"))];
        int size=Integer.parseInt(req.getParameter("size"));
        int i=0,j=0;
        for(i=0;i<size;i++)
        {
        	System.out.println("--executed--"+req.getParameter("list-"+i));
        	a[i]=req.getParameter("list-"+i);
        	System.out.println("a[i]"+a[i]+"<br>");
        	userid=a[i];
        	if(a[i]!=null)
        	{
        		j++;
        		query="update employee_details set permission='y'where e_code='"+userid+"'";
        		
        		st.executeUpdate(query);
	      	}
        }
        if(j>0)
        {
        	res.sendRedirect("./EmployeePermission.jsp");
        	//out.println("<center> "+j+" Records Updated !  Click <a href='./html/RecruiterFilter.jsp'>here</a> to go Back</center>");
        }
		}//try
		catch(Exception e)
		{
			e.printStackTrace();
		}
		
	}
}
