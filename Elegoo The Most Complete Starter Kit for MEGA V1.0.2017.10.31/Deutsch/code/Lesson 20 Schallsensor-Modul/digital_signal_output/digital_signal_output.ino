//www.elegoo.com
//2016.06.13

int Led=11;//define LED port
int buttonpin=3; //define switch port
;int  val;//define digital variable val
void  setup()
{
pinMode(Led,OUTPUT);//define LED as a output port
pinMode(buttonpin,INPUT);//define switch as a output port
}
void  loop()

{ val=digitalRead(buttonpin);//read the value of the digital interface 3 assigned to val 
if(val==HIGH)//Wenn der Schalter Sensor ein Signal hat, blinkt die LED
{
digitalWrite(Led,HIGH);
}
else
{
digitalWrite(Led,LOW);
}
}

