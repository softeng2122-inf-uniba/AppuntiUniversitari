<html>
<%
String msg=null;

msg=request.getParameter("msg");

 %>
<head>
<script type="text/javascript">
function check()
{
<%
if(request.getParameter("msg")!=null)
{
%>
var msg='Please Check your userid and password';
alert(msg);
<%
}


if(request.getParameter("msg1")!=null)
{
%>
var msg1='Permission not granted';
alert(msg1);
<%
}

%>
}

//}
</script>
</head>
<body onload="return check()"><center>
<table width="100%">
	<tr>
	<td align=""><img src="./Images/header.jpeg" height="120"></img></td>
	<td align=""><font face="arial narrow" size="5px" color="orange"><b> Defect Tracking System</b></font></td>
	</tr>
</table>
<hr>
<br><br>
<table width="80%" border=0 cellpadding=12>
<tr><td>
<p align="justify"> <font face="arial narrow"><b>
	The Project entitled DEFECT TRACKING SYSTEM is a web based and intranet application aimed for the tracking 
and resolution of bugs. All businesses have issues that need to be tracked and managed to resolution. Resolution 
of these issues requires the coordination of multiple individuals within and perhaps even outside the company.
This application can be used by all team members to coordinate their work and to make sure that reported bugs can 
use this application and enhancement requests wont be forgotten. In this way Tester delivers up to the minute 
project information and status to the team members everywhere to foster better communication and collaboration.
 The Online handling of reporting ensure that the project working hours will be prompt.
This also ensures well-disciplined authorization of users according to the project specification. 
Usage of this application increases the productivity and quality of the project.
</font></b></p>
<td><jsp:include page="./Login.html" /></td>
</tr>
</table>
<br><br><br>
</center>
</body>
<jsp:include page="./footer.jsp" />   

</html>