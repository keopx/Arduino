//www.elegoo.com
//2016.12.12

/************************
Exercise the motor using
the L293D chip
************************/

#define ENABLE 5
#define DIRA 3
#define DIRB 4

int i;
 
void setup() {
  //---Stellen Sie die Pinrichtung ein
  pinMode(ENABLE,OUTPUT);
  pinMode(DIRA,OUTPUT);
  pinMode(DIRB,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  //---Hin und her Beispiel
    Serial.println("One way, then reverse");
    digitalWrite(ENABLE,HIGH); // Aktivieren
    for (i=0;i<5;i++) {
    digitalWrite(DIRA,HIGH); //eine Richtung
    digitalWrite(DIRB,LOW);
    delay(500);
    digitalWrite(DIRA,LOW);  //andersrum
    digitalWrite(DIRB,HIGH);
    delay(500);
  }
  digitalWrite(ENABLE,LOW); // aus
  delay(2000);

  Serial.println("fast Slow example");
  //---Schnell / langsam stoppen Beispiel
  digitalWrite(ENABLE,HIGH); //Aktivieren
  digitalWrite(DIRA,HIGH); //eine richtung
  digitalWrite(DIRB,LOW);
  delay(3000);
  digitalWrite(ENABLE,LOW); //langsam stop
  delay(1000);
  digitalWrite(ENABLE,HIGH); //wieder an
  digitalWrite(DIRA,LOW); //eine richtung
  digitalWrite(DIRB,HIGH);
  delay(3000);
  digitalWrite(DIRA,LOW); //schnell aus
  delay(2000);

  Serial.println("PWM full then slow");
  //---PWM Beispiel, volle Geschwindigkeit dann langsam
  analogWrite(ENABLE,255); //an
  digitalWrite(DIRA,HIGH); //eine richtung
  digitalWrite(DIRB,LOW);
  delay(2000);
  analogWrite(ENABLE,180); //halbe geschwindigkeit
  delay(2000);
  analogWrite(ENABLE,128); //davon halbe geschwindigkeit
  delay(2000);
  analogWrite(ENABLE,50); //und nochmal halbiert
  delay(2000);
  analogWrite(ENABLE,128); //vorige geschwindigkeit
  delay(2000);
  analogWrite(ENABLE,180); //wieder schneller
  delay(2000);
  analogWrite(ENABLE,255); //vollgas
  delay(2000);
  digitalWrite(ENABLE,LOW); //fertig
  delay(10000);
}
   
