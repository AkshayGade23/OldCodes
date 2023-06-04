package Program13;
import java.applet.*;
import java.awt.*;

public class CheckUserApplet extends Applet
 {
     String username;
     String password;

    public void init()
    {
        username = getParameter("uname");
        password = getParameter("pass");
    }

    public void paint(Graphics g)
    {
        if(username.equals("abc") && password.equals("123"))
        {
            g.drawString("Welcome User", 25, 70);
        }
        else
        {
            g.drawString("Invalid User", 25, 70);
        }
    }
}
/*
<applet code="CheckUserApplet" width=100 height=300>
<param name="uname" value="abc">
<param name="pass" value="123">
</applet>
*/