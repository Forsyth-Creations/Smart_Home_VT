//import class to set up serial connection with wiring board
import processing.serial.*;

Serial port;

//RectButton rect1, rect2;
TextCircle humidity;
TemperatureCircle temp;
ToggleWithText nightLightToggle, tempToggle, humidToggle, secSysToggle;
boolean locked = false;
int Y_AXIS = 1;
int X_AXIS = 2;
color b1, b2, c1, c2;
int i = 190;

void setup() {
  frameRate(60);
  //---------------- set up window ----------------------
  size(800, 1500);
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



void draw() {
  //background(255, 255, 255);
  setLinearGradient(0, 0, 800, 1500, color(151, 200, 240), color(255, 255, 255), Y_AXIS);  
  //----------------------- Draw the title ---------------------------------
  writeTextCenter("SMART HOME 2021", (int)(width * .61), 40, 60, color(255, 255, 255)); //Title in Tmed Font
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
