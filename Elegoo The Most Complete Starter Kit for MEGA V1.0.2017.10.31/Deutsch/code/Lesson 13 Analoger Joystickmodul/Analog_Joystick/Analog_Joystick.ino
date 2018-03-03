//www.elegoo.com
//2016.12.09

// Arduino-PIN- Nummern
const int SW_pin = 2; // Digitaler Pin zum Schaltausgang angeschlossen
const int X_pin = 0; // Analog-Pin an X-Ausgang angeschlossen
const int Y_pin = 1; // Analog-Pin an Y-Ausgang angeschlossen

void setup() {
  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);
  Serial.begin(9600);
}

void loop() {
  Serial.print("Switch:  ");
  Serial.print(digitalRead(SW_pin));
  Serial.print("\n");
  Serial.print("X-axis: ");
  Serial.print(analogRead(X_pin));
  Serial.print("\n");
  Serial.print("Y-axis: ");
  Serial.println(analogRead(Y_pin));
  Serial.print("\n\n");
  delay(500);
}
