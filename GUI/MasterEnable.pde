class MasterEnable
{
  int x, y, w, h;
  boolean state;
  color fillColor = color(255, 255, 255);
  MasterEnable(int _x, int _y, int _w, int _h)
  {
    x = _x;
    y = _y;
    w = _w;
    h = _h;
  }
  void display()
  {
    isMouseOn();
    fill(fillColor);
    rect(x - w/2, y - h/2, w, h, 40);
    writeTextCenter("ENABLE ALL", x, y - 10, 60, color(0,0,0));
  }
  
   boolean isMouseOn()
  {
    if ((mouseX > x - w/2) && (mouseX < x + w/2) && (mouseY > y + h/2) && (mouseY < y - h/2))
    {
      fillColor = color(0, 0, 200);
      return true;
    }
    else
    {
      fillColor = color(0, 0, 255);
      return false;
    }
  }
  
  void setState(boolean input)
  {
   state = input; 
  }
}
