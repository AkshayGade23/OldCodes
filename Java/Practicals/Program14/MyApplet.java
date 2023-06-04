// package Program14;

import java.applet.*;
import java.awt.*;

public class MyApplet extends Applet{ 
    public void paint(Graphics g){

        // vertical and horizontal line
        g.drawLine(10,60,110,60);
        g.drawLine(60,10,60,110);

        // square inside circle
        g.drawRect(1130,85,80,80);
        g.drawOval(1090,40,160,160);

        //circle inside square 
        g.drawRect(890,40,160,160);
        g.drawOval(890,40,160,160);

        // cone
        g.drawOval(200,80,200,50);
        g.drawLine(200,105,300,300);
        g.drawLine(400,105,300,300);

        // cyclinder
        g.drawOval(500,60,200,50);
        g.drawLine(500,80,500,300);
        g.drawLine(700,80,700,300);
        g.drawOval(500,280,200,50);

        // cube
        g.drawRect(500,400,100,100);
        g.drawRect(550,450,100,100);
        g.drawLine(500,400,550,450);
        g.drawLine(500,500,550,550);
        g.drawLine(600,400,650,450);
        g.drawLine(650,550,600,500);

        //retrive font 
        Font currentFont = g.getFont();
 
        String fontName = currentFont.getName();
        
        int size = currentFont.getSize();
        
        int style = currentFont.getStyle();
        String fontStyle = "";
        
        if( (style & Font.BOLD) == Font.BOLD)
            fontStyle = "Bold";
        
        if( (style & Font.ITALIC) == Font.ITALIC)
            fontStyle = "Italic";
        
        if( (style & Font.PLAIN) == Font.PLAIN)
            fontStyle = "Plain";
        
        
        String family = currentFont.getFamily();
        
        g.drawString("Font Name   : " + fontName, 60, 330);
        g.drawString("Font size   : " + size, 60, 350);
        g.drawString("Font Family : " + family, 60, 370);
        g.drawString("Font Style  : " + fontStyle, 60, 390);
    }
}

/*
<applet code="MyApplet" width="1000" height="1000">
</applet>
*/
