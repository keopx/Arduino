//www.elegoo.com
#include <Servo.h>
Servo myservo;

void setup(){
  myservo.attach(3);
  myservo.write(90);// move servos to center position -> 90°
} 
void loop(){

}
