// Uses a PIR sensor to detect movement
//based upon: 
// PIR sensor tester by Limor Fried of Adafruit 

int ledPin = 13;                // choose the pin for the LED 
int Sensor1Pin = 2;               // choose the input pin (for PIR sensor) 
int Sensor2Pin = 4;
int pirState = LOW;             // we start, assuming no motion detected 
int val1 = 0;                    // variable for reading the pin status 
int val2 = 0;

void setup() { 
  pinMode(ledPin, OUTPUT);      // declare LED as output 
  pinMode(Sensor1Pin, INPUT);     // declare sensor as input 
  pinMode(Sensor2Pin, INPUT);
  Serial.begin(9600); 
} 
void loop(){ 
  val1 = digitalRead(Sensor1Pin);
  val2 = digitalRead(Sensor2Pin);  // read input values
  if (val1 == HIGH || val2 == HIGH) { // check if the input is HIGH 
    digitalWrite(ledPin, HIGH);  // turn LED ON 
    delay(150); 
    
    if (pirState == LOW) { 
      Serial.println("Motion detected!"); 
      pirState = HIGH; 
    } 
  } else { 
    digitalWrite(ledPin, LOW); // turn LED OFF 
    delay(300);     
    if (pirState == HIGH){ 
      Serial.println("Motion ended!"); 
      pirState = LOW;     } 
  } 
}

