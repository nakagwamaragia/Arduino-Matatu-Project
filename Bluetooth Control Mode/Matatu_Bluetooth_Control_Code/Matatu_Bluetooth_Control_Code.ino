// for serial communication with Arduino via Software 
#include <SoftwareSerial.h> 

// Create a SoftwareSerial object named mySerial using pins 12 and 13
SoftwareSerial mySerial(12, 13);

// Define constant values for pin numbers
#define frontLED 2
#define rearLED 3
#define in1 4
#define in2 5
#define in3 6
#define in4 7
#define buzz 8

// Define variables for motor speed control
int enA = 9;
int enB = 10;


void setup() {
// Initialize the serial communication for debugging
  Serial.begin(9600);
// Initialize the SoftwareSerial communication for the Bluetooth module
  mySerial.begin(9600);

// Set pin modes for various components
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  
  pinMode(buzz, OUTPUT);
  pinMode(frontLED, OUTPUT);
  pinMode(rearLED, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

// Set initial motor speeds
  analogWrite(enA, 255);
  analogWrite(enB, 255);

}

void loop() {
// Check if data is available on the Bluetooth serial connection
  if (mySerial.available() > 0) {
// Read a character from the Bluetooth serial connection
    char ctrlVal = char(mySerial.read()); 
    Serial.println(ctrlVal); // Print the received character on serial monitor for debugging

 // Motor control based on received character
 
    //****Reverse****
  if (ctrlVal == 'B' || ctrlVal == 'b') {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  
  // Start ReverseTone for 2.5 seconds 
    digitalWrite(buzz, HIGH);
    delay(2500);
    digitalWrite(buzz, LOW);
    delay(500);
    }
  
    //****Forward****
    else if (ctrlVal == 'F' || ctrlVal == 'f') {
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
    }
    
    //****Right****
    else if (ctrlVal == 'R' || ctrlVal == 'r') {
      digitalWrite(in1, HIGH);//L
      digitalWrite(in2, HIGH);//L
      digitalWrite(in3, LOW);//H
      digitalWrite(in4, HIGH);//L
    }
    
   //****Left****
    else if (ctrlVal == 'L' || ctrlVal == 'l') {
      digitalWrite(in1, LOW);//H
      digitalWrite(in2, HIGH);//L
      digitalWrite(in3, HIGH);//L
      digitalWrite(in4, HIGH);//L
    }
    
    //****Tail chase mode****
    else if (ctrlVal == 'C' || ctrlVal == 'c') {
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
    }
    
    //****Tail chase mode****
    else if (ctrlVal == 'A' || ctrlVal == 'a') {
      digitalWrite(in1, HIGH);//H
      digitalWrite(in2, LOW);
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);//H
    }
    
    //****Brake****
     else if (ctrlVal == 'S' || ctrlVal == 's') {
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);
      digitalWrite(in3, LOW);
      digitalWrite(in4, LOW);
    }
    
   //****Turn ON/OFF FRONT LEDs****
    else if (ctrlVal == 'X' || ctrlVal == 'x') {
      digitalWrite(frontLED, HIGH);
    }
    else if (ctrlVal == 'Z' || ctrlVal == 'z') {
      digitalWrite(frontLED, LOW);
    }
    
   //****Turn ON/OFF REAR LEDs****
    else if (ctrlVal == 'Y' || ctrlVal == 'y') {
      digitalWrite(rearLED, HIGH);
    }
    else if (ctrlVal == 'U' || ctrlVal == 'u') {
      digitalWrite(rearLED, LOW);
    }
    //****Horn****
    else if (ctrlVal == 'H' || ctrlVal == 'h') {
      digitalWrite(buzz, HIGH);
      delay(2000);
      digitalWrite(buzz, LOW);
      delay(500);
    }

  }
}
