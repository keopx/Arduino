// MAINTAINER keopx <keopx@keopx.net>
// LICENSE GPLv3

// Define Pins
#define BLUE 3
#define GREEN 5
#define RED 6

// Delay time in milliseconds.
#define delayTime 1000 

// LED color intensity.
#define MIN 0 
#define MAX 255

void setup()
{
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  digitalWrite(RED, HIGH);
  digitalWrite(GREEN, LOW);
  digitalWrite(BLUE, LOW);
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

  red();
  delay(delayTime);

  orange();
  delay(delayTime);

  blue();
  delay(delayTime);

  green();
  delay(delayTime);
}

