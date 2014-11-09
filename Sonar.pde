// Project          : Sonar GUI
// Language         : Processing 2
// Version          : ALPHA v0.2
// Author           : Batuhan Gayretli
// Commencement Date: 11.09.2014
// Last Update      : 25.09.2014

/*
DESCRIPTION:
The Program takes distance data from HC-SR04 Ultrasonic Range Finder,process and indicates in a graphical way.
Actually, it works like sea sonar. However, the display is similar to a land radar.
*/

// Imports
import processing.serial.*;

// Properties
Serial port;
Serial port2;
String data = "";
String Radius = "";
String Theta = "";
int index = 0;
float distance = 0;
float angle = 0;
float pi = 22.0/7;


void setup() 
{
 // The Radar Shape
  size(1000,1000);
  background(255);
  fill(200);
  ellipse(500,500,1000,1000);
  line(500,0,500,1000);
  line(0,500,1000,500);
  line(500,500,1000,0);
  line(500,500,0,0);

  // Port 
  port = new Serial(this, "COM4", 9600); // Because, Arduino UNO is on COM4.
  port.bufferUntil('.');
}

void draw()
{
  // NULL
}

void serialEvent(Serial port)
{
  // Data Processing
  data = port.readStringUntil('n');
  data = data.substring(0, data.length() - 1);  
  index = data.indexOf(",");
  Radius = data.substring(0, index);
  Theta = data.substring (index+1 , data.length());
  
  // Draw
  translate(500,500); // Specifies an amount to displace objects within the display window
  point (0,0);
   
  distance = float(Radius); // Parsing
  angle = float(Theta) /180 * pi; // Parsing
  fill(30,200,30);
  ellipse(distance * cos(angle) ,  -1 * distance * sin(angle) , 5,5); // Fills the Scanner with data

}
