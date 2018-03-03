//www.elegoo.com
//2016.12.12

#include "Stepper.h"
#define STEPS  32   // Anzahl der Schritte für eine Umdrehung der Innenwelle
                    // 2048 Schritte für eine Umdrehung der Außenwelle

volatile boolean TurnDetected;  // Muss für unterbrechungen flüchtig sein
volatile boolean rotationdirection;  // CW- oder CCW-Drehung

const int PinCLK=2;   // Erzeugen von unterbrechungen mit CLK-Signal
const int PinDT=3;    // DT-Signal lesen
const int PinSW=4;    // Lesen Push Button Schalter

int RotaryPosition=0;    // Um die Position des Schrittmotors zu speichern

int PrevPosition;     // Vorherige Drehposition Wert zur Prüfung der Genauigkeit
int StepsToTake;      // Wie viel der Stepper sich bewegen muss

// Einrichten der richtigen Sequenzierung für Motor Driver Pins
// In1, In2, In3, In4 in the sequence 1-3-2-4
Stepper small_stepper(STEPS, 8, 10, 9, 11);

// Interrupt-Routine läuft, wenn CLK von HIGH zu LOW geht
void isr ()  {
  delay(4);  // Verzögerung für Entprellung
  if (digitalRead(PinCLK))
    rotationdirection= digitalRead(PinDT);
  else
    rotationdirection= !digitalRead(PinDT);
  TurnDetected = true;
}

void setup ()  {
  
pinMode(PinCLK,INPUT);
pinMode(PinDT,INPUT);  
pinMode(PinSW,INPUT);
digitalWrite(PinSW, HIGH); // Pull-Up-Widerstand für Schalter
attachInterrupt (0,isr,FALLING); // Interrupt 0 immer mit Pin 2 auf Arduino UNO verbunden
}

void loop ()  {
  small_stepper.setSpeed(700); // Max scheint 700 zu sein
  if (!(digitalRead(PinSW))) {   // Überprüfen Sie, ob die Taste gedrückt wird
    if (RotaryPosition == 0) {  // Überprüfen Sie, ob die Taste bereits gedrückt wurde
    } else {
        small_stepper.step(-(RotaryPosition*50));
        RotaryPosition=0; // Position auf NULL zurücksetzen
      }
    }

  //Läuft, wenn Rotation erkannt wurde
  if (TurnDetected)  {
    PrevPosition = RotaryPosition; // Vorherige Position in Variable speichern
    if (rotationdirection) {
      RotaryPosition=RotaryPosition-1;} // Senkt die Position um 1
    else {
      RotaryPosition=RotaryPosition+1;} // Erhöht die Position um 1

    TurnDetected = false;  //NICHT wiederholen IF-Schleife, bis neue Rotation erkannt wird
    // Welche Richtung Schrittmotor bewegen
    if ((PrevPosition + 1) == RotaryPosition) { // Motor CW bewegen
      StepsToTake=50; 
      small_stepper.step(StepsToTake);
    }

    if ((RotaryPosition + 1) == PrevPosition) { //Motor CCW verschieben
      StepsToTake=-50;
      small_stepper.step(StepsToTake);
    }
  }
     digitalWrite(8, LOW);
     digitalWrite(9, LOW);
     digitalWrite(10, LOW);
     digitalWrite(11, LOW);     
}
