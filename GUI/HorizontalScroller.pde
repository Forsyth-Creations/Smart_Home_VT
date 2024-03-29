class HScrollbar {
  int swidth, sheight;    // width and height of bar
  float xpos, ypos;       // x and y position of bar
  float spos, newspos;    // x position of slider
  float sposMin, sposMax; // max and min values of slider
  int loose;              // how loose/heavy
  boolean over;           // is the mouse over the slider?
  boolean locked = false;
  boolean holding = false;
  float ratio;

  HScrollbar (float xp, float yp, int sw, int sh, int l) {
    swidth = sw;
    sheight = sh;
    int widthtoheight = sw - sh;
    ratio = (float)sw / (float)widthtoheight;
    xpos = xp;
    ypos = yp-sheight/2;
    spos = xpos + swidth/2 - sheight/2;
    newspos = spos;
    sposMin = xpos;
    sposMax = xpos + swidth - sheight;
    loose = l;
  }

  void update() {
    if (!locked)
    {
      if (overEvent()) {
        over = true;
      } 
      else {
        over = false;
      }
      if (mousePressed && over) {
        holding = true;
      }
      if (!mousePressed) {
        holding = false;
      }
      if (holding) {
        newspos = constrain(mouseX-sheight/2, sposMin, sposMax);
      }
      if (abs(newspos - spos) > 1) {
        spos = spos + (newspos-spos)/loose;
      }
    }
  }

  float constrain(float val, float minv, float maxv) {
    return min(max(val, minv), maxv);
  }

  boolean overEvent() {
    if (mouseX > xpos && mouseX < xpos+swidth &&
      mouseY > ypos && mouseY < ypos+sheight) {
      return true;
    } else {
      return false;
    }
  }

  void display() {
    if (!locked)
    {
      noStroke();
      stroke(color(255, 255, 255));
      strokeWeight(10);
      line(xpos, ypos, xpos + swidth, ypos);
      if (over || locked) {
        fill(100, 100, 100);
      } else {
        fill(255, 255, 255);
      }
      noStroke();
      rect(spos, ypos - 25, sheight, 50, 10);
    }
  }

  float getPos() {
    // Convert spos to be values between
    // 0 and the total width of the scrollbar
    return spos * ratio;
  }

  void setLock(boolean state)
  {
    locked = state;
  }
}
