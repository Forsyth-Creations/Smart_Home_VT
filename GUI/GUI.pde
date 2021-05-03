//import class to set up serial connection with wiring board
import processing.serial.*;
Serial port;
PImage img;

//RectButton rect1, rect2;
MenuButton menuButton;
TextCircle humidity;
TemperatureCircle temp;
ToggleWithText nightLightToggle, tempToggle, humidToggle, secSysToggle;
HScrollbar hs1;
MasterEnable enableButton;
boolean locked = false;
int Y_AXIS = 1;
int X_AXIS = 2;
color b1, b2, c1, c2;
final int screenSizeX = 800;
final int screenSizeY = 1500;
int startTime = 0;
int tempVal = 0; 
int humVal  = 0;
boolean isLedOn = false;

void setup() {
  frameRate(60);
  port = new Serial(this, "COM19", 9600); // Initializing the serial port.
  //---------------- set up window ----------------------
  size(800, 1500);
  setLinearGradient(0, 0, 800, 1500, color(151, 200, 218), color(255, 255, 255), Y_AXIS);
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
  menuButton = new MenuButton(20, 20);
  //------------------------- Setting Toggle Element Commands ---------------------------
  secSysToggle.setCommand("G1 A2");
  nightLightToggle.setCommand("G1 A3");
  tempToggle.setCommand("G1 A5");
  
  port.write("G0 A5;");
  delay(100);
  tempVal = port.read();
  delay(150);
  port.clear();
  delay(150);
  port.write("G0 A6;");
  delay(100);
  humVal = port.read();
  print(humVal);
  
}

void draw() {
  //background(255, 255, 255);
  //setLinearGradient(0, 0, 800, 1500, color(151, 200, 240), color(255, 255, 255), Y_AXIS); 
  //--------------------------------- Grab All Necessary Data from Device -------------------------------
  //updateWeatherStation();
    
  image(img, 0, 0);
  //----------------------- Menu Button ------------------------------------
  menuButton.display();
  locked = menuButton.getState();
  //----------------------- Draw the title ---------------------------------
  writeTextCenter("SMART HOME 2021", (int)(width * .61), 40, 60, color(255, 255, 255)); //Title in Tmed Font
  writeTextLeft("By R. Forsyth and J. Michaud", 20, height - 30, 25, color(255, 255, 255)); //FWD
  //----------------------- Update the Sensor Data -------------------------

   
  temp.update(tempVal);
  delay(50);
  humidity.update(humVal, color(255, 255, 255), color(0, 0, 255), humVal + "%");
  //------------------------ Show Slider -----------------------------------
  if (!locked)
  {
    if (tempToggle.getState())
    {
      hs1.update();
      hs1.display();
    //------------------------ Show Text Next To Slider ----------------------
    writeTextCenter("Set Temp:", 650, 530, 40, color(255, 255, 255));
    writeTextCenter(str(round(map(hs1.getPos(), 75, 525, 50, 90))) + "°", 650, 580, 40, color(255, 255, 255));
    }
    //------------------------ Write Header Text -----------------------------
    writeTextLeft("Active Elements", 50, 650, 60, color(255, 255, 255)); //Title in Tmed Font
    stroke(255, 255, 255);
    strokeWeight(10);
    line(40, 700, 600, 700);
  }
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
  } else if (!nightLightToggle.getState() && !tempToggle.getState() && !humidToggle.getState() && !secSysToggle.getState())
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
  //------------------------- Change the LED on the AC Unit Appliance ---------------
  if (tempVal > round(map(hs1.getPos(), 75, 525, 50, 90)) && !isLedOn)
  {
    println("It's too hot");
    port.write("G1 A7 1;");
    isLedOn = true;
  }
  else if (tempVal < round(map(hs1.getPos(), 75, 525, 50, 90)) && isLedOn)
  { 
    println("All good");
    port.write("G1 A7 0;");
    isLedOn = false;

  }
}

void updateWeatherStation()
{
  println(millis());
  if (millis() > startTime + 3000)
  {
  startTime = millis();
  println("in loop");
  port.write("G0 A5;");
  delay(50);
  while (port.available() > 0) {
     tempVal = port.read();
     print("Temp is ");
     println(tempVal);
  }
  delay(1000);
  port.write("G0 A6;");
  delay(100);
  if (port.available() > 0) {
     humVal = port.read();
     print("Hum is: ");
     println(humVal);
  }
  //port.clear();
  }
  
}
