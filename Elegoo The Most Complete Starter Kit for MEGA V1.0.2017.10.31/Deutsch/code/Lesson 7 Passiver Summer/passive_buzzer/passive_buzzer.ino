int buzzer = 8 ;// Einstellung steuert den digitalen IO-Fußsummer
void setup ()
{
  pinMode (buzzer, OUTPUT) ;// Setze den digitalen IO-Pin-Modus, OUTPUT

}
void loop ()
{
  unsigned char i, j ;// Definieren von Variablen
  while (1)
  {
    for (i = 0; i <80; i++) // Wen a frequency sound
    {
      digitalWrite (buzzer, HIGH) ;// Sende geräusch
      delay (1) ;// warte 1ms
      digitalWrite (buzzer, LOW) ;// sende kein geräusch
      delay (1) ;// warte 1ms
    }
    for (i = 0; i <100; i++) // Wen Qie out another frequency sound
    {
      digitalWrite (buzzer, HIGH) ;// Sende geräusch
      delay (2) ;// delay 2ms
      digitalWrite (buzzer, LOW) ;// sende kein geräusch
      delay (2) ;// delay 2ms
    }
  }
}
