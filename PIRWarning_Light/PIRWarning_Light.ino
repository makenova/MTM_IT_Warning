#include "HT1632.h"

#define DATA 2
#define WR   3
#define CS   4

// use this line for single matrix
HT1632LEDMatrix matrix = HT1632LEDMatrix(DATA, WR, CS);

void setup() {
  Serial.begin(9600);
  matrix.begin(HT1632_COMMON_16NMOS);  
  matrix.fillScreen();
  delay(500);

}

void loop() {
 matrix.clearScreen();
 delay(500); 
  // draw some text!
  matrix.setTextSize(1);    // size 1 == 8 pixels high
  matrix.setTextColor(1);   // 'lit' LEDs
  
  matrix.setCursor(0, 0);   // start at top left, with one pixel of spacing
  matrix.print("STOP ");
  matrix.setCursor(0, 8);   // next line, 8 pixels down
  matrix.print("STOP");
  matrix.writeScreen();
  
  delay(2000);
}
