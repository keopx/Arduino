//www.elegoo.com
//2016.09.23

int in1=6;
int in2=7;
int in3=8;
int in4=9;
int ENA=5;
int ENB=11;
 int ABS=115;
 void _mForward()
{
  analogWrite(ENA,ABS);
  analogWrite(ENB,ABS);
  digitalWrite(in1,HIGH);//digital output
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
  Serial.println("go forward!");
}

void _mBack()
{
  analogWrite(ENA,ABS);
  analogWrite(ENB,ABS);
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  Serial.println("go back!");
}

void _mleft()
{
   analogWrite(ENA,ABS);
   analogWrite(ENB,ABS);
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW); 
   Serial.println("go left!");
}

void _mright()
{
   analogWrite(ENA,ABS);
   analogWrite(ENB,ABS);
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
   Serial.println("go right!");
} 
void _mStop()
{
   digitalWrite(ENA,LOW);
   digitalWrite(ENB,LOW);
   Serial.println("Stop!");
} 

void setup() 
{
  Serial.begin(9600);
}

void loop() {
  int num1,num2,num3;
  num1=digitalRead(10);    
  num2=digitalRead(4);
  num3=digitalRead(2); 
   if((num1==0)&&num2&&num3) 
   {
    _mleft();          //The sensor detected that right car turn left immediately when it meets black line 
    delay(2);
    while(1){
    num2=digitalRead(2);         //Cycle to judge degree of intermediate sensor,
    if(num2==1)
    {  _mleft();                     //If num2==1 does not go to the middle position, continue to turn left.
     delay(2);}
     else
     break;                      //Detection of num2==0 instructions turned over, out of the loop, detection of three sensors’ statusand then make appropriate action
   }                                       //The following and so on
   }    

  else if(num2&&num1&&(num3==0))
   {
    _mright();
    delay(2);
    while(1)
    {
     num2=digitalRead(2);
    if(num2==1){
      _mright();  
     delay(2);}
     else
      break;
    }
   }
  else
  {
    _mForward(); 
    delay(2);
  } 
}

