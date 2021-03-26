class MasterEnable
{
  int x, y, w, h;
  MasterEnable(int _x, int _y, int _w, int _h)
  {
    x = _x;
    y = _y;
    w = _w;
    h = _h;
  }
  void display()
  {
    fill(255, 255, 255);
    rect(x - w/2, y - h/2, w, h, 40);
    writeTextCenter("ENABLE ALL", x, y - 10, 60, color(0,0,0));
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
}
