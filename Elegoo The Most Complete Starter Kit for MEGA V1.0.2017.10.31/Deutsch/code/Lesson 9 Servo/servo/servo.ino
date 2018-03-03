//www.elegoo.com
//2016.12.08
#include <Servo.h>

Servo myservo;  // Erstellen Sie objekt vom typ Servo, um ein Servo zu steuern   -- 
// sollte dies unklar sein was ein Objekt sein soll, 
//bitte etwas schlau lesen zum Thema Objektorientierte Programmierung
// Zwölf Servoobjekte können auf den meisten Boards erstellt werden

int pos = 0;    // Variable zum Speichern der Servoposition

void setup() {
  myservo.attach(9);  // deklariert den Servo auf pin 9 mit dem Servo Objekt
}

void loop() {
  for (pos = 0; pos <= 180; pos += 1) { // geht von 0 grad bis 180grad
    // in steps of 1 degree
    myservo.write(pos);              // sagt dem Servo in die Position  'pos' zu gehen
    delay(15);                       // wartet 15ms damit der servo zeit hat zum drehen
  }
  for (pos = 180; pos >= 0; pos -= 1) { // geht von 180 grad auf 0 grad
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}

