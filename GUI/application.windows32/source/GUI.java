import processing.core.*; 
import processing.data.*; 
import processing.event.*; 
import processing.opengl.*; 

import processing.serial.*; 

import java.util.HashMap; 
import java.util.ArrayList; 
import java.io.File; 
import java.io.BufferedReader; 
import java.io.PrintWriter; 
import java.io.InputStream; 
import java.io.OutputStream; 
import java.io.IOException; 

public class GUI extends PApplet {

//import class to set up serial connection with wiring board


Serial port;

//RectButton rect1, rect2;
TextCircle humidity;
TemperatureCircle temp;
ToggleWithText nightLightToggle, tempToggle, humidToggle, secSysToggle;
boolean locked = false;
int Y_AXIS = 1;
int X_AXIS = 2;
int b1, b2, c1, c2;
int i = 190;

public void setup() {
  frameRate(60);
  //---------------- set up window ----------------------
  
  setLinearGradient(0, 0, 800, 1500, color(151, 200, 218), color(255, 255, 255), Y_AXIS);
  //port = new Serial(this, Serial.list()[4], 9600);

  int x = 60;
  int y = 60;
  //-------------------------- Circular Elements --------------------------------------
  temp = new TemperatureCircle(225, 330, 500, color(255, 255, 255), color(0, 0, 255), color(0, 100, 100), color(255, 0, 0));
  humidity = new TextCircle(575, 330, 500, color(0, 0, 255), color(255, 255, 255));
  //------------------------- Toggle Elements ------------------------------------------
  humidity.setTextFormat(60, color(255, 255, 255));
  temp.setTextFormat(60, color(255, 255, 255));
  nightLightToggle = new ToggleWithText(120, 800, "NIGHT LIGHT");
  tempToggle = new ToggleWithText(120, 900, "TEMP");
  humidToggle = new ToggleWithText(120, 1000, "HUMIDITY");
  secSysToggle = new ToggleWithText(120, 1100, "SECURITY SYSTEM");
}



public void draw() {
  //background(255, 255, 255);
  setLinearGradient(0, 0, 800, 1500, color(151, 200, 240), color(255, 255, 255), Y_AXIS);  
  //----------------------- Draw the title ---------------------------------
  writeTextCenter("SMART HOME 2021", (int)(width * .61f), 40, 60, color(255, 255, 255)); //Title in Tmed Font
  writeTextCenter("By R. Forsyth and J. Michaud", width - 200, height - 30, 25, color(0, 200, 200)); //FWD
  //----------------------- Update the Sensor Data -------------------------
  temp.update(50);
  humidity.update(50, color(255, 255, 255), color(0, 0, 255), "Testing");
  //------------------------ Write Header Text -----------------------------
  writeTextLeft("Active Elements", 50, 650, 60, color(255, 255, 255)); //Title in Tmed Font
  stroke(255, 255, 255);
  line(40, 700, 600, 700);

  //----------------------- Display User Elements --------------------------
  nightLightToggle.display();
  tempToggle.display();
  humidToggle.display();
  secSysToggle.display();
 
}
class Circle {

  int x, y, size, input;
  int basecolor, loadingColor;
  
  Circle(int ix, int iy, int isize, int icolor, int iloading)
  {
    basecolor = icolor;
    loadingColor = iloading;
    x = ix;
    y = iy;
    size = isize;
  }
  public void update(int percentage, int icolor, int iloading) 
  {
    //get new temp, create new circle
    input = percentage;
    noFill();
    stroke(icolor);
    this.display(); 
    strokeWeight(12);
    stroke(iloading);
    arc(x, y, size/2, size/2, (5 * PI)/4, ((5 * PI)/4) + (2*percentage*PI)/(100));

  }
  public void display() 
  { 
    noFill();
    strokeWeight(10);
    ellipse(x, y, size/2, size/2);
  }
}

/**
The TextCircle class has three new methods: constructor, update, and setText
The constructor behaves the same has a normal circle. However, when you update it,
there will be a default word placed at the center of the circle. Change the parameters
of "update" to change the word (see String _txt of the update function). You must also set your prefered
font specs using setTextFormat
**/
class TextCircle extends Circle
{
  String txt = "Default";
  int fontSize = 40;
  int fontColor = color(255, 0, 0);
  TextCircle(int ix, int iy, int isize, int icolor, int iloading)
  {
    super(ix, iy, isize, icolor, iloading);
  }
  public void update(int percentage, int icolor, int iloading, String _txt)
  {
    super.update(percentage, icolor, iloading);
    txt = _txt;
    writeTextCenter(txt, x, y - 10, fontSize, fontColor);
  }
  public void setTextFormat(int _fontSize, int _fontColor)
  {
    fontSize = _fontSize;
    fontColor = _fontColor;
  }
}
/**
This class must be constructed with three loading colors. Their designation is as follows:
loading1 = high temp, considered out of range but still worth tracking. Ex: 100->200 degrees
loading2 = normal temp, considered within range. Ex: 0->100 degrees
loading3 = low temp, considered below range but still worth tracking. Ex: -100->0 degrees
*/
class TemperatureCircle extends TextCircle
{
  final int lowestBound = -100;
  final int middleLowBound = 0;
  final int middleHighBound = 100;
  final int highestBound = 200;
  int x, y;
  int loading1, loading2, loading3;
  
  TemperatureCircle(int ix, int iy, int isize, int icolor, int iloading1, int iloading2, int iloading3)
  {
    super(ix, iy, isize, icolor, iloading2);
    loading1 = iloading1;
    loading2 = iloading2;
    loading3 = iloading3;
    basecolor = icolor;
  }

   public void update(int degrees)
   {
     
     if (degrees > lowestBound && degrees <= middleLowBound) //first condition satisifed
     {
       super.update((int)(abs(degrees)), basecolor, loading1, str(degrees));
     }
     else if (degrees > middleLowBound && degrees <= middleHighBound) //second condition satisifed
     {
       super.update((int)(abs(degrees)), basecolor, loading2, str(degrees));
     }
     else if (degrees > middleHighBound && degrees <= highestBound) //third condition satisifed
     {
       super.update((int)(abs(degrees - 100)), basecolor, loading3, str(degrees));
     }
     else 
     {
       writeTextCenter("Unknown\nTemp", super.x, super.y, fontSize, fontColor);
     }
   }
}
//temp = new TemperatureCircle(225, 330, 500, color(255, 0, 0), color(0, 255, 0), color(0, 0, 255), color(255, 255, 255));
/*



  // List all the available serial ports in the output pane. 
  // You will need to choose the port that the Wiring board is 
  // connected to from this list. The first port in the list is 
  // port #0 and the third port in the list is port #2. 
  println(Serial.list()); 
  // Open the port that the Wiring board is connected to (in this case 1
  // which is the second open port in the array) 
  // Make sure to open the port at the same speed Wiring is using (9600bps) 










 

  // Define and create rectangle button #2
  //x = 90;
  //y = 100; 
  //size = 50;


*/
public void setLinearGradient(int x, int y, float w, float h, int c1, int c2, int axis ) {

  noFill();

  if (axis == Y_AXIS) {  // Top to bottom gradient
    for (int i = y; i <= y+h; i++) {
      float inter = map(i, y, y+h, 0, 1);
      int c = lerpColor(c1, c2, inter);
      stroke(c);
      line(x, i, x+w, i);
    }
  }  
  else if (axis == X_AXIS) {  // Left to right gradient
    for (int i = x; i <= x+w; i++) {
      float inter = map(i, x, x+w, 0, 1);
      int c = lerpColor(c1, c2, inter);
      stroke(c);
      line(i, y, i, y+h);
    }
  }
}

public void setRadialGradient(int xPos, int yPos, int w, int h, int c1, int c2) {
  for(int y = 0; y < height; y++){
    
    for(int x = 0; x < width; x++){
      
      float distanceFromCenter = dist(xPos, yPos, w/2, h/2);
      float maxDistance = sqrt((w * w) + (h * h));
      float percentage = distanceFromCenter/maxDistance;
      
      float redPart = (red(c1) * (1 - percentage)) + (red(c2) * (percentage));
      float greenPart = (green(c1) * (1 - percentage)) + (green(c2) * (percentage));
      float bluePart = (blue(c1) * (1 - percentage)) + (blue(c2) * (percentage));
      
      stroke(redPart, greenPart, bluePart);
      
      point(x, y);
    }
  }
}

public void writeTextCenter(String txt, int x, int y, int fontSize, int fontColor)
{
  fill (fontColor);
  textFont(createFont("Optimus Bold", fontSize));
  textAlign(CENTER, CENTER);
  text(txt, x, y); 
}

public void writeTextLeft(String txt, int x, int y, int fontSize, int fontColor)
{
  fill (fontColor);
  textFont(createFont("Optimus Bold", fontSize));
  textAlign(LEFT, CENTER);
  text(txt, x, y); 
}
// SLIDER 
class Slider {

  float slider_width = 50;
  float slider_height = 10;
  float posx, posy;
  boolean over = false;
  boolean locked = false;
  float xoff;
  float fundo;

  public void create() {
    size(500, 500, P2D);
    posx = width/2;
    posy = height/2;
    rectMode(CENTER);
    line (posx, posy, posx+100, posy);
  }
  public void display() {
    fundo = posx;
    background(200);
    line (150, posy, 350, posy);
    println (posx);
    if (dist(mouseX, mouseY, posx, posy) < slider_height) {
      fill(200);
      over = true;
    } else {
      fill(255);
      over = false;
    }
    if (posx < 175) {
      println ("ERRO");
      posx = 175;
    }
    if (posx > 325) {
      println ("ERRO");
      posx = 325;
    }
    rect(posx, posy, slider_width, slider_height);
  }
  public void mousePressed() {
    if (over) {
      locked = true;
      xoff = mouseX-posx;
    }
  }
  public void mouseDragged() {
    if (locked) {
      posx = mouseX-xoff;
    }
  }
  public void mouseReleased() {
    locked = false;
  }
}
/**
class Button {

  int x, y;
  int size;
  color basecolor, highlightcolor;
  color currentcolor;
  boolean over = false;
  boolean pressed = false;   
  void update() 
  {
    if(over()) {
      currentcolor = highlightcolor;
    } else {
      currentcolor = basecolor;
    }
  }
  boolean pressed() 
  {
    if(over) {
      locked = true;
      return true;
    } else {
      locked = false;
      return false;
    }    
  }
  boolean over() 
  { 
    return true; 
  }
  void display() 
  { 
  }
}

class RectButton extends Button {

  RectButton(int ix, int iy, int isize, color icolor, color ihighlight) 
  {
    x = ix;
    y = iy;
    size = isize;
    basecolor = icolor;
    highlightcolor = ihighlight;
    currentcolor = basecolor;
  }
  boolean over() 
  {
    if( overRect(x, y, size, size) ) {
      over = true;
      return true;
    } else {
      over = false;
      return false;
    }
  }
  void display() 
  {
    stroke(255);
    fill(currentcolor);
    rect(x, y, size, size);
  }
  void update(int x, int y) {
  if(locked == false) {
  //  rect1.update();
  //} else {
  //  locked = false;
  //}
  //Turn LED on and off if buttons pressed where
  //H = on (high) and L = off (low)
  //if(mousePressed) {
  //  if(rect1.pressed()) {            //ON button
  //    currentcolor = rect1.basecolor;
  //    //port.write('H');
  //  } 
    //else if(rect2.pressed()) {    //OFF button
    //  currentcolor = rect2.basecolor;
    //  //port.write('L');
    //}
  }
}
}*/
class Toggle
{
  final int size = 60;
  final int offset = round(size/3.7f);
  boolean state = false;
  int x, y;
  Toggle(int _x, int _y)
  {
    x = _x;
    y = _y;
  }
  public void display()
  {
    isClicked();
    if (state)
    {
      strokeWeight(.5f);
      noStroke();
      fill(21, 23, 21);
      ellipse(x - offset, y, size, size); 
      fill(104, 205, 96);  
      ellipse(x + offset, y, size, size);
    }
    else
    {
      strokeWeight(.5f);
      noStroke();
      fill(21, 23, 21);
      ellipse(x + offset, y, size, size);
      fill(204, 23, 21);  
      ellipse(x - offset, y, size, size);
    }
  }
  public void isClicked()
  {
    if (isMouseOn() && mousePressed)
    {
      state = !state;
    }
  }
  public boolean isMouseOn()
  {
    if (dist(x + offset, y, mouseX, mouseY) < size/2 || dist(x - offset, y, mouseX, mouseY) < size/2)
    {
      return true;
    }
    return false;
  }
}

class ToggleWithText extends Toggle
{
  String text = "unset";
  ToggleWithText(int _x, int _y, String _text)
  {
    super(_x, _y);
    text = _text;
  }
  public void display()
  {
    super.display();
    writeTextLeft(text, x + 100, y - 10, 49, color(255, 255, 255));
   }
}

  public void settings() {  size(800, 1500); }
  static public void main(String[] passedArgs) {
    String[] appletArgs = new String[] { "GUI" };
    if (passedArgs != null) {
      PApplet.main(concat(appletArgs, passedArgs));
    } else {
      PApplet.main(appletArgs);
    }
  }
}
