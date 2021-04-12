class Circle {

  int x, y, size, input;
  color basecolor, loadingColor;
  boolean locked = false;
  boolean disabled = false;
  boolean hide = false;

  Circle(int ix, int iy, int isize, color icolor, color iloading)
  {
    basecolor = icolor;
    loadingColor = iloading;
    x = ix;
    y = iy;
    size = isize;
  }
  void update(int percentage, color icolor, color iloading) 
  {
    //get new temp, create new circle
    if (!locked)
    {
      input = percentage;
      noFill();
      stroke(icolor);
      this.display(); 
      strokeWeight(16);
      stroke(iloading);
      arc(x, y, size/2, size/2, (5 * PI)/4, ((5 * PI)/4) + (2*percentage*PI)/(100));
    }
  }
  void display() 
  { 
    if (!locked)
    {
      noFill();
      strokeWeight(16);
      ellipse(x, y, size/2, size/2);
    }
  }
  void disable()
  {
    disabled = true;
  }
  void enable()
  {
    disabled = false;
  }

  void setLock(boolean state)
  {
    locked = state;
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
  color fontColor = color(255, 0, 0);
  TextCircle(int ix, int iy, int isize, color icolor, color iloading)
  {
    super(ix, iy, isize, icolor, iloading);
  }
  void update(int percentage, color icolor, color iloading, String _txt)
  {
    if (!locked && !disabled)
    {
      super.update(percentage, icolor, iloading);
      txt = _txt;
      writeTextCenter(txt, x, y - 10, fontSize, fontColor);
    }
  }
  void setTextFormat(int _fontSize, color _fontColor)
  {
    fontSize = _fontSize;
    fontColor = _fontColor;
  }
  void disable()
  {
    if (!locked)
    {
      disabled = true;
      writeTextCenter("Disabled", x, y - 10, fontSize, fontColor);
    }
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
  color loading1, loading2, loading3;

  TemperatureCircle(int ix, int iy, int isize, color icolor, color iloading1, color iloading2, color iloading3)
  {
    super(ix, iy, isize, icolor, iloading2);
    loading1 = iloading1;
    loading2 = iloading2;
    loading3 = iloading3;
    basecolor = icolor;
  }

  void update(int degrees)
  {
    if (!locked)
    {
      if (degrees > lowestBound && degrees <= middleLowBound) //first condition satisifed
      {
        super.update((int)(abs(degrees)), basecolor, loading1, str(degrees)+  "°");
      } else if (degrees > middleLowBound && degrees <= middleHighBound) //second condition satisifed
      {
        super.update((int)(abs(degrees)), basecolor, loading2, str(degrees)+  "°");
      } else if (degrees > middleHighBound && degrees <= highestBound) //third condition satisifed
      {
        super.update((int)(abs(degrees - 100)), basecolor, loading3, str(degrees) +  "°");
      } else 
      {
        writeTextCenter("Unknown\nTemp", super.x, super.y, fontSize, fontColor);
      }
    }
  }
}
//temp = new TemperatureCircle(225, 330, 500, color(255, 0, 0), color(0, 255, 0), color(0, 0, 255), color(255, 255, 255));
