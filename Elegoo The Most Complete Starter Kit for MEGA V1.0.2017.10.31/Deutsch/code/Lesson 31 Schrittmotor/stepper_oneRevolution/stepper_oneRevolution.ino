//www.elegoo.com
//2016.12.12

/*
 Schrittmotorsteuerung - eine Umdrehung

 Dieses Programm fährt einen unipolaren oder bipolaren Schrittmotor.
 Der Motor ist an den digitalen Stiften 8 - 11 des Arduino befestigt.

Der Motor sollte dann eine Umdrehung in eine Richtung drehen
Eine Umdrehung in die andere Richtung.

 */

#include <Stepper.h>

const int stepsPerRevolution = 1500;  // Ändern Sie dies, um die Anzahl der Schritte pro Umdrehung zu passen

// Initialisierung der Stepper-Bibliothek auf den Pins 8 bis 11:
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);

void setup() {
  // Stellt die Geschwindigkeit bei 20 U / min ein:
  myStepper.setSpeed(20);
  // Initialisierung der seriellen Schnittstelle:
  Serial.begin(9600);
}

void loop() {
  // Schritt eine Umdrehung in eine Richtung:
  Serial.println("clockwise");
  myStepper.step(stepsPerRevolution);
  delay(500);

  // Schritt eine Umdrehung in die andere Richtung:
  Serial.println("counterclockwise");
  myStepper.step(-stepsPerRevolution);
  delay(500);
}

