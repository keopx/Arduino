// MAINTAINER keopx <keopx@keopx.net>
// LICENSE GPLv3

// Define Servo.
#include <Servo.h>
Servo myservo;  // create servo object to control a servo
#define SERVO_PIN 9
int pos = 0;    // variable to store the servo position

// Define Proximity Pins
#include "SR04.h"
#define TRIG_PIN 6
#define ECHO_PIN 7
SR04 sr04 = SR04(ECHO_PIN, TRIG_PIN);
long distance;

// Define LED Pins
#define RED    11
#define YELLOW 12
#define GREEN  13

// LED color intensity.
#define MIN 0
#define MAX 255

// Barrier status
#define OPEN 0
#define CLOSE 90

// Distance
#define DISTANCE 10

void setup()
{
  // LED.
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  digitalWrite(RED, HIGH);
  digitalWrite(GREEN, LOW);
  digitalWrite(YELLOW, LOW);

  // Proximity.
  Serial.begin(9600);
  delay(1000);

  int pos = CLOSE;
  myservo.attach(SERVO_PIN);  // attaches the servo on pin 9 to the servo object
}

void red()
{
  analogWrite(RED, MAX);
  analogWrite(YELLOW, MIN);
  analogWrite(GREEN, MIN);
}

void yellow()
{
  analogWrite(RED, MIN);
  analogWrite(YELLOW, MAX);
  analogWrite(GREEN, MIN);
}

void green()
{
  analogWrite(RED, MIN);
  analogWrite(YELLOW, MIN);
  analogWrite(GREEN, MAX);
}

int closeServo() {
  Serial.print("Close start: ");
  Serial.println(pos);
  for (pos = OPEN; pos < CLOSE; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}

int openServo() {
  Serial.print("Open start: ");
  Serial.println(pos);
  int pos_new = OPEN + 1;
  for (pos = CLOSE; pos >= pos_new; pos -= 1) { // goes from 0 degrees to 180 degrees
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

  // Close.
  if (distance > DISTANCE && pos >= CLOSE) {
    red();
  }

  // Warning and open.
  if (distance <= DISTANCE && pos >= CLOSE) {
    yellow();
    openServo();
  }

  // Warning and Close.
  if (distance > DISTANCE && pos <= OPEN) {
    yellow();
    delay(2000);
    closeServo();
  }

  // Access granted and opened.
  if (distance <= DISTANCE && pos <= OPEN) {
    green();
  }

  delay(1000);
}

