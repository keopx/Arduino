//www.elegoo.com

#define LT1 digitalRead(10)
#define LT2 digitalRead(4)
#define LT3 digitalRead(2)

#define ENA 5
#define ENB 11
#define IN1 6
#define IN2 7
#define IN3 8
#define IN4 9

#define ABS 115

void forward(){
  analogWrite(ENA, ABS);
  analogWrite(ENB, ABS);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  Serial.println("go forward!");
}

void back(){
  analogWrite(ENA, ABS);
  analogWrite(ENB, ABS);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  Serial.println("go back!");
}

void left(){
  analogWrite(ENA, ABS);
  analogWrite(ENB, ABS);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW); 
  Serial.println("go left!");
}

void right(){
  analogWrite(ENA, ABS);
  analogWrite(ENB, ABS);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  Serial.println("go right!");
} 

void stop(){
   digitalWrite(ENA, LOW);
   digitalWrite(ENB, LOW);
   Serial.println("Stop!");
} 

void setup(){
  Serial.begin(9600);
}

void loop() {
  if(LT2){
    forward();
  }
  else if(LT1) { 
    left();
    while(LT1);                             
  }   
  else if(LT3) {
    right();
    while(LT3);  
  }
}

