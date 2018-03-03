//www.elegoo.com
//2016.09.19

#include <IRremote.h>//Infrared Library
int receiverpin = 12;//Infrared signal receiving pin
int LED=13;                //define LED pin
volatile int state = LOW;  //define default input mode
unsigned long RED;
#define L 16738455
IRrecv irrecv(receiverpin);//initialization
decode_results results;//Define structure type
void setup() {
pinMode(LED, OUTPUT);     //initialize LED as an output
Serial.begin(9600);       // debug output at 9600 baud
 irrecv.enableIRIn();// Start receiving
}
void stateChange()      
{
  state = !state;          
  digitalWrite(LED, state);
}
void loop() {
if (irrecv.decode(&results))
    { 
      RED=results.value;
       Serial.println(RED);
       irrecv.resume(); // Receive the next value
    delay(150);
     if(RED==L)
  {  
     stateChange();
   }
  }
     }

