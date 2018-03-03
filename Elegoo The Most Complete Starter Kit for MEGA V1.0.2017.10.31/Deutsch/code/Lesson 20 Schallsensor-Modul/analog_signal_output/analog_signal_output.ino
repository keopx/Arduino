int Led = 11 ;// define LED Interface
int buttonpin = 2; // define D0 Sensor Interface
int val = 0;// define numeric variables val
 
void setup ()
{
  pinMode (Led, OUTPUT) ;// define LED as output interface
  pinMode (buttonpin, INPUT) ;// Ausgangsschnittstelle D0 ist unser definierter Sensor
  Serial.begin(9600);
}
 
void loop ()
{
  val = digitalRead(buttonpin);// Digitale Schnittstelle wird ein Wert von Pin 3 zugeordnet, um "val" zu lesen
  Serial.println(val);
  if (val == HIGH) // Wenn der Sensor ein Signal erkennt, blinkt die LED
  {
    digitalWrite (Led, HIGH);
  }
  else
  {
    digitalWrite (Led, LOW);
  }
}
