// MAINTAINER keopx <keopx@keopx.net>
// LICENSE GPLv3

// Define Proximity Pins
#include "SR04.h"
#define TRIG_PIN 12
#define ECHO_PIN 11
SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);
long a;

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

// main loop
void loop()
{

  a = sr04.Distance();
  Serial.print(a);
  Serial.println("cm");

  // Block.
  if (a > 5) {
    red();
  }

  // Access.
  if (a < 5) {
    orange();
    delay(2000);
    green();
    delay(2000);
  }
  // Delay time in milliseconds.
  delay(1000);
}

