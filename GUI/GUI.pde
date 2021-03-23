//import class to set up serial connection with wiring board
import processing.serial.*;

Serial port;

//button setup
color currentcolor;
RectButton rect1, rect2;
boolean locked = false;
int Y_AXIS = 1;
int X_AXIS = 2;
color b1, b2, c1, c2;
  
void setup() {

  //---------------- set up window ----------------------
  size(800, 1500);
  color baseColor = color(0, 0, 255);
  color c1 = color(204, 102, 0);
  color c2 = color(0, 102, 153);
  currentcolor = baseColor;
  // List all the available serial ports in the output pane. 
  // You will need to choose the port that the Wiring board is 
  // connected to from this list. The first port in the list is 
  // port #0 and the third port in the list is port #2. 
  println(Serial.list()); 
  // Open the port that the Wiring board is connected to (in this case 1
  // which is the second open port in the array) 
  // Make sure to open the port at the same speed Wiring is using (9600bps) 
  
  //port = new Serial(this, Serial.list()[4], 9600);
  
  // Define and create rectangle button #1
 
  int x = 60;
  int y = 60;
  int size = 50;
  color buttoncolor = color(153, 102, 102);
  color highlight = color(102, 51, 51); 
  rect1 = new RectButton(x, y, size, buttoncolor, highlight);
  // Define and create rectangle button #2
  x = 90;
  y = 100; 
  size = 50;
  buttoncolor = color(153, 153, 153);
  highlight = color(102, 102, 102); 
  rect2 = new RectButton(x, y, size, buttoncolor, highlight);
  //-------------- Show a List of All Fonts -----------------
  String[] fontList = PFont.list();
  printArray(fontList);
}

void draw() {
  setGradient(50, 190, 540, 80, c2, c1, X_AXIS);
  //background();

  
  //----------------------- Draw the title ---------------------------------
  //textSize (25); // The arrow keys text size- 20
  fill (255,255,255); // painting it green.
  textFont(createFont("Optimus Bold", 50));
  textAlign(CENTER, CENTER);
  text("SMART HOME 2021", width/2, 40); //FWD
  textFont(createFont("Optimus Bold", 25));
  text("By R. Forsyth and J. Michaud", width - 200, height - 30); //FWD
  stroke(255);
  update(mouseX, mouseY);
  rect1.display();
  rect2.display();
}

void update(int x, int y) {

  if(locked == false) {
    rect1.update();
    rect2.update();
  } else {
    locked = false;
  }
  //Turn LED on and off if buttons pressed where
  //H = on (high) and L = off (low)
  if(mousePressed) {
    if(rect1.pressed()) {            //ON button
      currentcolor = rect1.basecolor;
      //port.write('H');
    } else if(rect2.pressed()) {    //OFF button
      currentcolor = rect2.basecolor;
      //port.write('L');
    }
  }
}

boolean overRect(int x, int y, int width, int height) {
  if (mouseX >= x && mouseX <= x+width && 
      mouseY >= y && mouseY <= y+height) {
    return true;
  } else {
    return false;
  }
}
