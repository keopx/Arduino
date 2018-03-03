//www.elegoo.com
//2016.09.19

int LED=13;//Define 13 pin for LED
volatile int state = LOW;//The initial state of the function is defined as a low level
char getstr;    //Defines a function that receives the Bluetooth character
void setup() {
 pinMode(LED, OUTPUT);
Serial.begin(9600);
}
/*Control LED sub function*/
void stateChange()
{
  state = !state;
  digitalWrite(LED, state);  
}
void loop() {
    getstr=Serial.read();//The Bluetooth serial port to receive the data in the function
    if(getstr=='A'){
    stateChange();
  }
}
