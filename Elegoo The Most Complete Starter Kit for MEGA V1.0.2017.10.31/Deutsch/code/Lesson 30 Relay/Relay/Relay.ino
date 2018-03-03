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
  //---Stellt die Pinrichtung ein
  pinMode(ENABLE,OUTPUT);
  pinMode(DIRA,OUTPUT);
  pinMode(DIRB,OUTPUT);
  Serial.begin(9600);
}

void loop() {
 
//---vor zurück Beispiel
    Serial.println("One way, then reverse");
    digitalWrite(ENABLE,HIGH); // an
    for (i=0;i<5;i++) {
    digitalWrite(DIRA,HIGH); //eine richtung
    digitalWrite(DIRB,LOW);
    delay(750);
    digitalWrite(DIRA,LOW);  //rückwärts
    digitalWrite(DIRB,HIGH);
    delay(750);
  }
  digitalWrite(ENABLE,LOW); // aus
    delay(3000);
      for (i=0;i<5;i++) {
    digitalWrite(DIRA,HIGH); /eine richtung
    digitalWrite(DIRB,LOW);
    delay(750);
    digitalWrite(DIRA,LOW);  //rückwärts
    digitalWrite(DIRB,HIGH);
    delay(750);
  }
    digitalWrite(ENABLE,LOW); // aus
    delay(3000);
}
   
