class Toggle
{
  final int size = 60;
  final int offset = round(size/3.7);
  boolean state = false;
  int x, y;
  boolean locked = false;
  color greenColor = color(104, 205, 96);
  color redColor = color(204, 23, 21);
  color blackColor = color(21, 23, 21);
  color setColor = color(0, 0, 0);
  Toggle(int _x, int _y)
  {
    x = _x;
    y = _y;
  }
  void display()
  {
    isClicked();
    if (state && !locked)
    { //should be green
      strokeWeight(.5);
      noStroke();
      fill(blackColor);
      ellipse(x - offset, y, size, size); 

      if (isMouseOn()) {  
        setColor = dim(greenColor);
      } else { 
        setColor = greenColor;
      }

      fill(setColor);
      ellipse(x + offset, y, size, size);
    } else if (!locked)
    { //should be red
      strokeWeight(.5);
      noStroke();
      fill(blackColor);
      ellipse(x + offset, y, size, size);
      if (isMouseOn()) {  
        setColor = dim(redColor);
      } else { 
        setColor = redColor;
      }
      fill(setColor); 
      ellipse(x - offset, y, size, size);
    } 
    else
    {
      
    }
  }
  void isClicked()
  {
    if (isMouseOn() && mousePressed)
    {
      state = !state;
      delay(50);
    }
  }

  boolean isMouseOn()
  {
    if (dist(x + offset, y, mouseX, mouseY) < size/2 || dist(x - offset, y, mouseX, mouseY) < size/2)
    {
      return true;
    }
    return false;
  }
  void setState(boolean input)
  {
    state = input;
  }
  boolean getState()
  {
    return state;
  }

  void setLock(boolean state)
  {
    locked = state;
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
  void display()
  {
    if (!locked)
    {
    super.display();
    writeTextLeft(text, x + 100, y - 10, 49, color(255, 255, 255));
    }
  }
}
