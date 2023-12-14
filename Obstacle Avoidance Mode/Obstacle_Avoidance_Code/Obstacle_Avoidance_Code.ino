#include <Servo.h>         
#include <NewPing.h>

#define in1 4
#define in2 5
#define in3 6
#define in4 7

int enA = 9;
int enB = 10;

#define trig_pin A1 
#define echo_pin A2 


#define maximum_distance 200
boolean goesForward = false;
int distance = 100;
 int distanceRight = 0;
  int distanceLeft = 0;

NewPing sonar(trig_pin, echo_pin, maximum_distance); //sensor function
Servo servo_motor;

void setup(){
Serial.begin(9600);
Serial.println("hello");

pinMode(enA, OUTPUT);//enable RearMotors
pinMode(enB, OUTPUT);//enable FrontMotors
analogWrite(enA, 255);
analogWrite(enB, 255);

  servo_motor.attach(11); //our servo pin

 servo_motor.write(90);
  delay(1000);
  distance = readPing();
   Serial.println("Forwarddistance");
     Serial.println(distance);
     
    distanceRight = lookRight();
     Serial.println("InitStartdistanceRight");
     Serial.println(distanceRight);
     
    //delay(300);
    distanceLeft = lookLeft();
    Serial.println("InitdistanceLeft");
     Serial.println(distanceLeft);
servo_motor.write(90);
  delay(1000);
}
void loop(){
  delay(50);
 distance = readPing();
  delay(10);

  if (distance <= 20){
   // Serial.println("movinmg..");
    Stop();
    delay(500);
    Backwards();
    delay(500);
     Stop();
    delay(500);
    
    distanceRight = lookRight();
     Serial.println("distanceRight");
     Serial.println(distanceRight);
    //delay(300);
    distanceLeft = lookLeft();
    Serial.println("distanceLeft");
     Serial.println(distanceLeft);
    //delay(300);

     if (distanceRight >= distanceLeft){
      Right();
       delay(700);
      Forward();
    }
    else{
      Left();
        delay(7600);
      Forward();
    }
   distance = readPing(); 
  }
  {
    // If no obstacle detected, move forward
    Forward();
  }
  
}

int lookRight(){  
  servo_motor.write(40);
  delay(500);
  int distance = readPing();
  delay(100);
  servo_motor.write(90);
  return distance;
}

int lookLeft(){
  servo_motor.write(150);
  delay(500);
  int distance = readPing();
  delay(100);
  servo_motor.write(90);
  return distance;
  delay(100);
}


int readPing(){
  delay(70);
  int cm = sonar.ping_cm();
  if (cm==0){
    cm=250;
  }
  return cm;
}


//****Stop****
void Stop() {
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);
      digitalWrite(in3, LOW);
      digitalWrite(in4, LOW);
    }

//****Forward****
    void Forward() {
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
    }
      
 //****Backwards****
  void Backwards() {
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
    }

  //****Right****
     void Right()  {
      digitalWrite(in1, HIGH);//L
      digitalWrite(in2, HIGH);//L
      digitalWrite(in3, LOW);//H
      digitalWrite(in4, HIGH);//L
    }
    
   //****Left****
     void Left()  {
      digitalWrite(in1, LOW);//H
      digitalWrite(in2, HIGH);//L
      digitalWrite(in3, HIGH);//L
      digitalWrite(in4, HIGH);//L
    }
