class Toggle
{
  final int size = 60;
  final int offset = round(size/3.7);
  boolean state = false;
  int x, y;
  Toggle(int _x, int _y)
  {
    x = _x;
    y = _y;
  }
  void display()
  {
    isClicked();
    if (state)
    {
      strokeWeight(.5);
      noStroke();
      fill(21, 23, 21);
      ellipse(x - offset, y, size, size); 
      fill(104, 205, 96);  
      ellipse(x + offset, y, size, size);
    }
    else
    {
      strokeWeight(.5);
      noStroke();
      fill(21, 23, 21);
      ellipse(x + offset, y, size, size);
      fill(204, 23, 21);  
      ellipse(x - offset, y, size, size);
    }
  }
  void isClicked()
  {
    if (isMouseOn() && mousePressed)
    {
      state = !state;
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
    super.display();
    writeTextLeft(text, x + 100, y - 10, 49, color(255, 255, 255));
   }
}
