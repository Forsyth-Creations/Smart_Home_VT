class MenuButton
{
  final int size = 60;
  final int offset = round(size/3.7);
  boolean state = false;
  int x, y;
  boolean locked = false;
  color color1 = color(0, 100, 100);
  color color2 = color(0, 255, 255);

  MenuButton(int _x, int _y)
  {
    x = _x;
    y = _y;
  }
  void display()
  {
    isClicked();
    if (!state)
    {
      strokeWeight(.5);
      noStroke();
      if (isMouseOn())
        fill(dim(color1));  
      else
        fill(color1);          
        drawIcon();
        lockAll(false);
    }
    else
    { 
        strokeWeight(.5);
        noStroke();
      if (isMouseOn())
        fill(dim(color2));  
      else
        fill(color2);       
      drawIcon();
      fill(0, 0, 0, 200);
      rect(0, 0, screenSizeX, screenSizeY);
      lockAll(true);
      //println("Hello");
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
    if (mouseX < x + size && mouseX > x - size && mouseY < y + size && mouseY > x - size)
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
  
  void drawIcon()
  {
     rect(x, y,      size, size/5, 5);
     rect(x, y + size*2/5, size, size/5, 5);
     rect(x, y + size*4/5, size, size/5, 5);
  }
}
