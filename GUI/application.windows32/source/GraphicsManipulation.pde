void setLinearGradient(int x, int y, float w, float h, color c1, color c2, int axis ) {

  noFill();

  if (axis == Y_AXIS) {  // Top to bottom gradient
    for (int i = y; i <= y+h; i++) {
      float inter = map(i, y, y+h, 0, 1);
      color c = lerpColor(c1, c2, inter);
      stroke(c);
      line(x, i, x+w, i);
    }
  }  
  else if (axis == X_AXIS) {  // Left to right gradient
    for (int i = x; i <= x+w; i++) {
      float inter = map(i, x, x+w, 0, 1);
      color c = lerpColor(c1, c2, inter);
      stroke(c);
      line(i, y, i, y+h);
    }
  }
}

void setRadialGradient(int xPos, int yPos, int w, int h, color c1, color c2) {
  for(int y = 0; y < height; y++){
    
    for(int x = 0; x < width; x++){
      
      float distanceFromCenter = dist(xPos, yPos, w/2, h/2);
      float maxDistance = sqrt((w * w) + (h * h));
      float percentage = distanceFromCenter/maxDistance;
      
      float redPart = (red(c1) * (1 - percentage)) + (red(c2) * (percentage));
      float greenPart = (green(c1) * (1 - percentage)) + (green(c2) * (percentage));
      float bluePart = (blue(c1) * (1 - percentage)) + (blue(c2) * (percentage));
      
      stroke(redPart, greenPart, bluePart);
      
      point(x, y);
    }
  }
}

void writeTextCenter(String txt, int x, int y, int fontSize, color fontColor)
{
  fill (fontColor);
  textFont(createFont("Optimus Bold", fontSize));
  textAlign(CENTER, CENTER);
  text(txt, x, y); 
}

void writeTextLeft(String txt, int x, int y, int fontSize, color fontColor)
{
  fill (fontColor);
  textFont(createFont("Optimus Bold", fontSize));
  textAlign(LEFT, CENTER);
  text(txt, x, y); 
}
