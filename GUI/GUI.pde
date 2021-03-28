//import class to set up serial connection with wiring board
import processing.serial.*;
Serial port;
PImage img;

//RectButton rect1, rect2;
TextCircle humidity;
TemperatureCircle temp;
ToggleWithText nightLightToggle, tempToggle, humidToggle, secSysToggle;
HScrollbar hs1;
MasterEnable enableButton;
boolean locked = false;
int Y_AXIS = 1;
int X_AXIS = 2;
color b1, b2, c1, c2;

void setup() {
  frameRate(60);
  //---------------- set up window ----------------------
  size(800, 1500);
  setLinearGradient(0, 0, 800, 1500, color(151, 200, 218), color(255, 255, 255), Y_AXIS);
  //port = new Serial(this, Serial.list()[4], 9600);
  //-------------------------- Load Background Image ----------------------------------
  img = loadImage("background.png");
  //-------------------------- Circular Elements --------------------------------------
  temp = new TemperatureCircle(225, 330, 500, color(255, 255, 255), color(0, 0, 255), color(0, 100, 100), color(255, 0, 0));
  humidity = new TextCircle(575, 330, 500, color(0, 0, 255), color(255, 255, 255));
  //------------------------- Create Slider --------------------------------------------
  hs1 = new HScrollbar(70, 570, 450, 30, 2);
  //------------------------- Toggle Elements ------------------------------------------
  humidity.setTextFormat(60, color(255, 255, 255));
  temp.setTextFormat(60, color(255, 255, 255));
  nightLightToggle = new ToggleWithText(120, 800, "NIGHT LIGHT");
  tempToggle = new ToggleWithText(120, 900, "TEMP");
  humidToggle = new ToggleWithText(120, 1000, "HUMIDITY");
  secSysToggle = new ToggleWithText(120, 1100, "SECURITY SYSTEM");
  enableButton = new MasterEnable(400, 1300, 700, 150);
}

void draw() {
  //background(255, 255, 255);
  //setLinearGradient(0, 0, 800, 1500, color(151, 200, 240), color(255, 255, 255), Y_AXIS);  
  image(img, 0, 0);
  //----------------------- Draw the title ---------------------------------
  writeTextCenter("SMART HOME 2021", (int)(width * .61), 40, 60, color(255, 255, 255)); //Title in Tmed Font
  writeTextLeft("By R. Forsyth and J. Michaud", 20, height - 30, 25, color(255, 255, 255)); //FWD
  //----------------------- Update the Sensor Data -------------------------
  temp.update(80);
  delay(50);
  humidity.update(50, color(255, 255, 255), color(0, 0, 255), "33%");
  //------------------------ Show Slider -----------------------------------
  hs1.update();
  hs1.display();
  //------------------------ Show Text Next To Slider ----------------------
  writeTextCenter("Set Temp:", 650, 530, 40, color(255, 255, 255));
  writeTextCenter(str(round(map(hs1.getPos(), 75, 525, 50, 90))) + "°", 650, 580, 40, color(255, 255, 255));
  //------------------------ Write Header Text -----------------------------
  writeTextLeft("Active Elements", 50, 650, 60, color(255, 255, 255)); //Title in Tmed Font
  stroke(255, 255, 255);
  line(40, 700, 600, 700);
  //----------------------- Display User Elements --------------------------
  nightLightToggle.display();
  tempToggle.display();
  humidToggle.display();
  secSysToggle.display();
  //------------------------ enable button ---------------------------------
  enableButton.display();
  
  //------------ use master enabing button to change all states ------------
  if (enableButton.getChangedState())
  {
    nightLightToggle.setState(enableButton.getState());
    tempToggle.setState(enableButton.getState());
    humidToggle.setState(enableButton.getState());
    secSysToggle.setState(enableButton.getState());
  }
  if (nightLightToggle.getState() && tempToggle.getState() && humidToggle.getState() && secSysToggle.getState())
  {
    enableButton.setState(true);
  }
  else if (!nightLightToggle.getState() && !tempToggle.getState() && !humidToggle.getState() && !secSysToggle.getState())
  {
    enableButton.setState(false);
  }
  //----------------------- Disable Functionalities -----------------------
  if (!tempToggle.getState())
    temp.disable();
  else
    temp.enable();
  
  if (!humidToggle.getState())
    humidity.disable();
  else
    humidity.enable();
}
