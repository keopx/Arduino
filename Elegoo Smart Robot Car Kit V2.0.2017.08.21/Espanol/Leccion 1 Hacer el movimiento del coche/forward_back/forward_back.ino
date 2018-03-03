//www.elegoo.com
//2016.09.23
int ENA=5; 
int IN1=6;
int IN2=7;
int ENB=11; 
int IN3=8;
int IN4=9;
void setup()
{
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  pinMode(ENA,OUTPUT);
  pinMode(ENB,OUTPUT);
  digitalWrite(ENA,HIGH);  
  digitalWrite(ENB,HIGH);      

}
void loop()
{
  digitalWrite(IN1,HIGH);      
  digitalWrite(IN2,LOW);         // left wheel goes forward
  digitalWrite(IN3,LOW);      
  digitalWrite(IN4,HIGH);         // right wheel goes forward
  delay(500);
  digitalWrite(IN1,LOW);      
  digitalWrite(IN2,LOW);         //left wheel holds still
  digitalWrite(IN3,LOW);      
  digitalWrite(IN4,LOW);         // right wheel holds still
  delay(500);
  digitalWrite(IN1,LOW);      
  digitalWrite(IN2,HIGH);        //left wheel is back up
  digitalWrite(IN3,HIGH);      
  digitalWrite(IN4,LOW);        // right wheel is back up
  delay(500);
  digitalWrite(IN1,LOW);      
  digitalWrite(IN2,LOW);         // left wheel holds still
  digitalWrite(IN3,LOW);      
  digitalWrite(IN4,LOW);         // right wheel holds still
  delay(500);
}

