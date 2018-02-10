// MAINTAINER keopx <keopx@keopx.net>
// LICENSE GPLv3

// Define Servo.
#include <Servo.h>
Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards
#define SERVO_PIN 9

int pos = 0;    // variable to store the servo position

// Define Proximity Pins
#include "SR04.h"
#define TRIG_PIN 12
#define ECHO_PIN 11
SR04 sr04 = SR04(ECHO_PIN, TRIG_PIN);
long distance;

// Define LED Pins
#define BLUE 3
#define GREEN 5
#define RED 6

// LED color intensity.
#define MIN 0
#define MAX 255

void setup()
{
  // LED.
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  digitalWrite(RED, HIGH);
  digitalWrite(GREEN, LOW);
  digitalWrite(BLUE, LOW);

  // Proximity.
  Serial.begin(9600);
  delay(1000);

  int pos = 0;
  myservo.attach(SERVO_PIN);  // attaches the servo on pin 9 to the servo object
}

void red()
{
  analogWrite(RED, MAX);
  analogWrite(BLUE, MIN);
  analogWrite(GREEN, MIN);
}

void orange()
{
  analogWrite(RED, MAX);
  analogWrite(BLUE, MIN);
  analogWrite(GREEN, 50);
}

void blue()
{
  analogWrite(RED, MIN);
  analogWrite(BLUE, MAX);
  analogWrite(GREEN, MIN);
}

void green()
{
  analogWrite(RED, MIN);
  analogWrite(BLUE, MIN);
  analogWrite(GREEN, MAX);
}

int openServo() {
  Serial.print("Open start: ");
  Serial.println(pos);
  for (pos = 0; pos < 90; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}

int closeServo() {
  Serial.print("Close start: ");
  Serial.println(pos);
  for (pos = 90; pos >= 1; pos -= 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  myservo.write(0);              // tell servo to go to position in variable 'pos'
  delay(15);                       // waits 15ms for the servo to reach the position
}

// main loop
void loop()
{
  distance = sr04.Distance();
  Serial.print(distance);
  Serial.println(" cm");

  Serial.print("Position: ");
  Serial.println(pos);

  // Block.
  if (distance > 10 && pos <= 0) {
    red();
  }

  // Warning and open.
  if (distance <= 10 && pos <= 0) {
    orange();
    openServo();
  }

  // Warning and Close.
  if (distance > 10 && pos >= 90) {
    orange();
    delay(2000);
    closeServo();
  }

  // Access granted and opened.
  if (distance <= 10 && pos >= 90) {
    green();
  }

  delay(1000);
}
