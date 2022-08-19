package org.apache.jsp;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.jsp.*;

public final class ManagerHeader_jsp extends org.apache.jasper.runtime.HttpJspBase
    implements org.apache.jasper.runtime.JspSourceDependent {

  private static java.util.Vector _jspx_dependants;

  public java.util.List getDependants() {
    return _jspx_dependants;
  }

  public void _jspService(HttpServletRequest request, HttpServletResponse response)
        throws java.io.IOException, ServletException {

    JspFactory _jspxFactory = null;
    PageContext pageContext = null;
    HttpSession session = null;
    ServletContext application = null;
    ServletConfig config = null;
    JspWriter out = null;
    Object page = this;
    JspWriter _jspx_out = null;
    PageContext _jspx_page_context = null;


    try {
      _jspxFactory = JspFactory.getDefaultFactory();
      response.setContentType("text/html");
      pageContext = _jspxFactory.getPageContext(this, request, response,
      			null, true, 8192, true);
      _jspx_page_context = pageContext;
      application = pageContext.getServletContext();
      config = pageContext.getServletConfig();
      session = pageContext.getSession();
      out = pageContext.getOut();
      _jspx_out = out;

      out.write("<html>\r\n");

HttpSession hs=request.getSession();

 
      out.write("\r\n");
      out.write("<body bgcolor=\"white\">\r\n");
      out.write("<form>\r\n");
      out.write("\t<table width=\"100%\">\r\n");
      out.write("\t<tr>\r\n");
      out.write("\t<td align=\"\"><img src=\"./Images/header.jpeg\" height=\"120\"></img></td>\r\n");
      out.write("\t<td align=\"\"><font face=\"arial narrow\" size=\"5px\" color=\"orange\"><b> Defect Tracking System</b></font></td>\r\n");
      out.write("\t</tr>\r\n");
      out.write("\t<tr>\r\n");
      out.write("\t");

	String uname=(String)hs.getAttribute("userid");
	String role=(String)hs.getAttribute("role");
	 
      out.write("\r\n");
      out.write("\t   <td align=\"right\" valign=\"bottom\" colspan=2>\r\n");
      out.write("                <b>  ");
if(role.equals("admin")){
      out.write("Welcome,&nbsp;&nbsp; Admin");
} else {
      out.write("Welcome,&nbsp;&nbsp;");
      out.print(uname);
      out.write(' ');
} 
      out.write(" </b>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;    \r\n");
      out.write("                <b>[ ");
if(role.equals("admin")){
      out.write("<a href=\"./AdminHome.jsp\">");
} else if(role.equals("Tester")){
      out.write("<a href=\"./TesterHome.jsp?cat=Tester\">");
} else if(role.equals("Developer")){
      out.write("<a href=\"./DeveloperHome.jsp?cat=Developer\">");
}else if(role.equals("Manager")){
      out.write("<a href=\"./ManagerHome.jsp?cat=HrManager\">");
} 
      out.write("<font color=\"#FBC61\">home</font></a> ]</b>&nbsp;\r\n");
      out.write("                ");
if(role!="user"){
      out.write("<b>[ <a href=\"./logout.jsp\"><font color=\"#FBC61\" size=\"3px\">logout</font></a> ]</b>");
} 
      out.write("\r\n");
      out.write("            </td>\r\n");
      out.write("\t\r\n");
      out.write("\r\n");
      out.write("\t</tr>\r\n");
      out.write("\t</table>\r\n");
      out.write("\t\r\n");
      out.write("\t<script type=\"text/javascript\">\r\n");
      out.write("sfHover = function() {\r\n");
      out.write("   var sfEls = document.getElementById(\"nav\").getElementsByTagName(\"LI\");\r\n");
      out.write("   for (var i=0; i<sfEls.length; i++) {\r\n");
      out.write("      sfEls[i].onmouseover=function() {\r\n");
      out.write("         this.className+=\" over\";\r\n");
      out.write("      }\r\n");
      out.write("      sfEls[i].onmouseout=function() {\r\n");
      out.write("         this.className=this.className.replace(new RegExp(\" over\\\\b\"), \"\");\r\n");
      out.write("      }\r\n");
      out.write("   }\r\n");
      out.write("}\r\n");
      out.write("if (window.attachEvent) window.attachEvent(\"onload\", sfHover);\r\n");
      out.write("\r\n");
      out.write("</script>\r\n");
      out.write("\r\n");
      out.write("\r\n");
      out.write("<style type=\"text/css\">\r\n");
      out.write("\r\n");
      out.write("ul#nav, ul#nav ul {\r\n");
      out.write("   margin: 0;\r\n");
      out.write("   padding: 0px;\r\n");
      out.write("   list-style: none;\r\n");
      out.write("   \r\n");
      out.write("   }\r\n");
      out.write("\r\n");
      out.write("ul#nav  li {\r\n");
      out.write("   position: relative;\r\n");
      out.write("   float: left;\r\n");
      out.write("   width:140px;\r\n");
      out.write("   font-size: 12px;\r\n");
      out.write("  \r\n");
      out.write("   \r\n");
      out.write("  \r\n");
      out.write("}\r\n");
      out.write("   \r\n");
      out.write("#nav li ul {\r\n");
      out.write("   position: absolute;\r\n");
      out.write("   margin-left: -999em; /* hide menu from view */\r\n");
      out.write("   top: 20;\r\n");
      out.write("   left:0;\r\n");
      out.write("}\r\n");
      out.write("\r\n");
      out.write("/* Styles for Menu Items */\r\n");
      out.write("ul#nav  li a {\r\n");
      out.write("   display: block;\r\n");
      out.write("   text-decoration: none;\r\n");
      out.write("   color:\"black\";\r\n");
      out.write("   padding: 2px;\r\n");
      out.write("   border: 1px solid #ccc;\r\n");
      out.write("   \r\n");
      out.write("   min-height:0;\r\n");
      out.write("   }\r\n");
      out.write("/* commented backslash mac hiding hack \\*/\r\n");
      out.write("* html ul#nav  li a {height:1%;   position:relative;}\r\n");
      out.write("/* end hack */\r\n");
      out.write("\r\n");
      out.write("/* this sets all hovered lists to black */\r\n");
      out.write("#nav li:hover a,#nav  li.over a,\r\n");
      out.write("#nav li:hover li a:hover,#nav li.over li a:hover {\r\n");
      out.write("   color: #fff;\r\n");
      out.write("   background-color: black;}\r\n");
      out.write("    \r\n");
      out.write("/* set dropdown to default */\r\n");
      out.write("#nav li:hover li a,#nav li.over li a {\r\n");
      out.write("   color: black;\r\n");
      out.write("   background-color:silver; */\r\n");
      out.write("}\r\n");
      out.write("#nav li ul li a { padding: 2px 2px; } /* Sub Menu Styles */\r\n");
      out.write("#nav li:hover ul,#nav li.over ul {margin-left:0; } /* show menu*/\r\n");
      out.write("\r\n");
      out.write("</style>\r\n");
      out.write("\r\n");
      out.write("<body bgcolor=\"white\">\r\n");
      out.write("<form>\r\n");
      out.write("<hr>\r\n");
      out.write("\r\n");
      out.write("<table border=0 align=right>\r\n");
      out.write("        <tr><td>\r\n");
      out.write("<font size=\"3px\">\r\n");
      out.write("  <ul id=\"nav\">\r\n");
      out.write("  <li><a href=\"#\">Open</a>\r\n");
      out.write("  <ul id=\"nav\">\r\n");
      out.write("       \r\n");
      out.write("       <li><a href=\"./AssignProject.jsp\">Assign Project</a></li>\r\n");
      out.write("       <li><a href=\"./EditProfile.jsp?cat=HrManager\"\">Edit Profile</a></li> \r\n");
      out.write("       <li><a href=\"./Recchange_pass.jsp?cat=HrManager&userid=");
      out.print((String)hs.getAttribute("userid"));
      out.write("\">Change Password</a></li>        \r\n");
      out.write("    </ul>\r\n");
      out.write("  </li>\r\n");
      out.write("  </ul>\r\n");
      out.write("  </font>\r\n");
      out.write("        \r\n");
      out.write("        </td></tr>\r\n");
      out.write("        \r\n");
      out.write("    </table>\r\n");
      out.write(" <br>\r\n");
      out.write("\r\n");
      out.write("\t\r\n");
      out.write("\t\r\n");
      out.write("\r\n");
      out.write("</form>\r\n");
      out.write("</body>\r\n");
      out.write("</html>");
    } catch (Throwable t) {
      if (!(t instanceof SkipPageException)){
        out = _jspx_out;
        if (out != null && out.getBufferSize() != 0)
          out.clearBuffer();
        if (_jspx_page_context != null) _jspx_page_context.handlePageException(t);
      }
    } finally {
      if (_jspxFactory != null) _jspxFactory.releasePageContext(_jspx_page_context);
    }
  }
}
