class MasterEnable
{
  int x, y, w, h;
  boolean state;
  boolean hasChanged = false;
  color fillColor = color(255, 255, 255);
  boolean locked = false;

  MasterEnable(int _x, int _y, int _w, int _h)
  {
    x = _x;
    y = _y;
    w = _w;
    h = _h;
  }

  void display()
  {
    if (!locked)
    {
      isMouseOn();
      fill(fillColor);
      if (!state)
      { //should be on
        rect(x - w/2, y - h/2, w, h, 40);
        writeTextCenter("ENABLE ALL", x, y - 10, 60, color(0, 0, 0));
      } else 
      {
        rect(x - w/2, y - h/2, w, h, 40);
        writeTextCenter("DISABLE ALL", x, y - 10, 60, color(0, 0, 0));
      }
    }
  }

  boolean isMouseOn()
  {
    if ((mouseX > x - w/2) && (mouseX < x + w/2) && (mouseY > y - h/2) && (mouseY < y + h/2))
    {
      fillColor = color(230, 230, 230);
      if (mousePressed)
      {
        state = !state;
        hasChanged = true;
        //println("changed");
        delay(50);
      }
      return true;
    } else
    {
      fillColor = color(255, 255, 255);
      return false;
    }
  }

  boolean getChangedState()
  {
    if (hasChanged)
    {
      hasChanged = false;
      return true;
    }
    return false;
  }

  boolean getState()
  {
    return state;
  }

  void setState(boolean input)
  {
    state = input;
  }

  void setLock(boolean state)
  {
    locked = state;
  }
}
