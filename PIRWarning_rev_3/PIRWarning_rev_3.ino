// Uses a PIR sensor to detect movement
//based upon: 
// PIR sensor tester by Limor Fried of Adafruit 

#include "HT1632.h"

#define DATA 2
#define WR   3
#define CS   4

// use this line for single matrix
HT1632LEDMatrix matrix = HT1632LEDMatrix(DATA, WR, CS);

int Sensor1Pin = 7; 
int Sensor2Pin = 8;  // assign pins for PIR sensors
int val1 = 0;
int val2 = 0;  // variables for reading the sensor status 

void setup() {
  Serial.begin(9600);
  matrix.begin(HT1632_COMMON_16NMOS);  
  matrix.fillScreen();
  pinMode(Sensor1Pin, INPUT);  // declare sensor as input 
  pinMode(Sensor2Pin, INPUT);
}
void loop(){
  val1 = digitalRead(Sensor1Pin);
  val2 = digitalRead(Sensor2Pin);  // read input values
  if (val1 == HIGH || val2 == HIGH) {  // check if the input is HIGH 
    stop();
  } else {
    matrix.clearScreen();
  }
}

void stop(){
 matrix.clearScreen();
 delay(500); 
  // draw some text!
  matrix.setTextSize(1);    // size 1 == 8 pixels high
  matrix.setTextColor(1);   // 'lit' LEDs
  
  trigger(4);
}

void trigger( int count){
  for(int i = count; i > 0; i--){
      warning();
      matrix.blink(true);
      delay(1000);
      matrix.fillScreen();
      delay(1000);
      matrix.blink(false);
      matrix.clearScreen();
  }
}

void warning(){
  matrix.setCursor(0, 0);   // start at top left, with one pixel of spacing
  matrix.print("STOP ");
  matrix.setCursor(0, 8);   // next line, 8 pixels down
  matrix.print("STOP");
  matrix.writeScreen();
}
