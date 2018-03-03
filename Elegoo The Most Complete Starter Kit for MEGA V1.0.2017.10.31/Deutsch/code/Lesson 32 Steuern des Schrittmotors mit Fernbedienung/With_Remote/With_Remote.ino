//www.elegoo.com
//2016.12.12

#include "Stepper.h"
#include "IRremote.h"

/*----- Variables, Pins -----*/
#define STEPS  32   // Anzahl der Schritte pro Umdrehung der Innenwelle
int  Steps2Take;  // 2048 = 1 umdrehung
int receiver = 12; // Signal Pin des IR-Empfängers an Arduino Digital Pin 6

/*-----( Declare objects )-----*/
// Einrichten der richtigen Sequenzierung für Motor Driver Pins
// In1, In2, In3, In4 In der Reihenfolge 1-3-2-4

Stepper small_stepper(STEPS, 8, 10, 9, 11);
IRrecv irrecv(receiver);    // Erstellen Instanz von 'irrecv'
decode_results results;     // Erstellen Instanz von 'decode_results'

void setup()
{ 
  irrecv.enableIRIn(); // Startet den Empfänger
}

void loop()
{
if (irrecv.decode(&results)) //Haben wir ein IR-Signal erhalten?

  {
    switch(results.value)

    {

      case 0xFFA857: // VOL + Taste gedrückt
                      small_stepper.setSpeed(500); //Max scheint 500 zu sein
                      Steps2Take  =  2048;  // CW drehen
                      small_stepper.step(Steps2Take);
                      delay(2000); 
                      break;

      case 0xFF629D: // VOL- Taste gedrückt
                      small_stepper.setSpeed(500);
                      Steps2Take  =  -2048;  // CCW drehen
                      small_stepper.step(Steps2Take);
                      delay(2000); 
                      break;
                
    }
    
      irrecv.resume(); // Erhalten den nächsten Wert
                 digitalWrite(8, LOW);
                 digitalWrite(9, LOW);
                 digitalWrite(10, LOW);
                 digitalWrite(11, LOW);       
  }  


}/* --end main loop -- */
