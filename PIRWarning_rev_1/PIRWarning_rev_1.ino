// Uses a PIR sensor to detect movement
//based upon: 
// PIR sensor tester by Limor Fried of Adafruit 

int ledPin1 = 13;
//int ledPin2 = 8;  // assign pins for the indicator lights
int Sensor1Pin = 2; 
int Sensor2Pin = 4;  // assign pins for PIR sensors
int pirState = LOW;  // we start, assuming no motion detected 
int val1 = 0;
int val2 = 0;  // variables for reading the sensor status 

void setup() {
  pinMode(ledPin1, OUTPUT);  // declare LED as output
  //pinMode(ledPin2, OUTPUT);  // declare LED as output 
  pinMode(Sensor1Pin, INPUT);  // declare sensor as input 
  pinMode(Sensor2Pin, INPUT);
  Serial.begin(9600);
}
void loop(){
  val1 = digitalRead(Sensor1Pin);
  val2 = digitalRead(Sensor2Pin);  // read input values
  if (val1 == HIGH || val2 == HIGH) {  // check if the input is HIGH 
    digitalWrite(ledPin, HIGH);
    //digitalWrite(ledPin2, HIGH); // turn ON both LEDs
    delay(150);
    
    if (pirState == LOW) {
      Serial.println("Motion detected!");
      pirState = HIGH;
    }
  } else {
    digitalWrite(ledPin, LOW);  // turn LED OFF 
    delay(300);
    if (pirState == HIGH){
      Serial.println("Motion ended!");
      pirState = LOW;     }
  }
}

