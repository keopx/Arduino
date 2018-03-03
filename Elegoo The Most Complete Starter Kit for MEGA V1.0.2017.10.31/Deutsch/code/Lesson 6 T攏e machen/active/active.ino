//www.elegoo.com
//2016.12.08

int buzzer = 12;//der Pins des angesteckten Summers
void setup()
{
 pinMode(buzzer,OUTPUT);// initialsiert den buzzer als Output
}
void loop()
{
 unsigned char i;
 while(1)
 {
   //gibt eine frequenz aus
   for(i=0;i<80;i++)
   {
    digitalWrite(buzzer,HIGH);
    delay(15);//wartet 1ms
    digitalWrite(buzzer,LOW);
    delay(5);//wartet 1ms
    }
    //gibt wieder eine frequenz aus
    
  }
} 
