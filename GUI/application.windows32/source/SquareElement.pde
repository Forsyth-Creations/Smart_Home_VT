/**
class Button {

  int x, y;
  int size;
  color basecolor, highlightcolor;
  color currentcolor;
  boolean over = false;
  boolean pressed = false;   
  void update() 
  {
    if(over()) {
      currentcolor = highlightcolor;
    } else {
      currentcolor = basecolor;
    }
  }
  boolean pressed() 
  {
    if(over) {
      locked = true;
      return true;
    } else {
      locked = false;
      return false;
    }    
  }
  boolean over() 
  { 
    return true; 
  }
  void display() 
  { 
  }
}

class RectButton extends Button {

  RectButton(int ix, int iy, int isize, color icolor, color ihighlight) 
  {
    x = ix;
    y = iy;
    size = isize;
    basecolor = icolor;
    highlightcolor = ihighlight;
    currentcolor = basecolor;
  }
  boolean over() 
  {
    if( overRect(x, y, size, size) ) {
      over = true;
      return true;
    } else {
      over = false;
      return false;
    }
  }
  void display() 
  {
    stroke(255);
    fill(currentcolor);
    rect(x, y, size, size);
  }
  void update(int x, int y) {
  if(locked == false) {
  //  rect1.update();
  //} else {
  //  locked = false;
  //}
  //Turn LED on and off if buttons pressed where
  //H = on (high) and L = off (low)
  //if(mousePressed) {
  //  if(rect1.pressed()) {            //ON button
  //    currentcolor = rect1.basecolor;
  //    //port.write('H');
  //  } 
    //else if(rect2.pressed()) {    //OFF button
    //  currentcolor = rect2.basecolor;
    //  //port.write('L');
    //}
  }
}
}*/
