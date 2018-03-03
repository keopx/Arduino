#include <LiquidCrystal.h>

// Pin, an dem der Thermistor angeschlossen ist
#define PINOTERMISTOR A0
// Nenntemperaturwert für den Thermistor
#define TERMISTORNOMINAL 10000
// Nenntemperatur auf dem Datenblatt
#define TEMPERATURENOMINAL 25
// Anzahl der Proben
#define NUMAMOSTRAS 5
// Beta-Wert für unseren Thermistor
#define BCOEFFICIENT 3977
// Wert des Serienwiderstandes
#define SERIESRESISTOR 10000


int tempPin = 0;
//                BS  E  D4 D5  D6 D7
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

int amostra[NUMAMOSTRAS];
int i;

void setup() {
Serial.begin(9600);
lcd.begin(16, 2);
analogReference(EXTERNAL);
}

void loop(void) {
float media;

for (i=0; i< NUMAMOSTRAS; i++) {
amostra[i] = analogRead(PINOTERMISTOR);
delay(10);
}

media = 0;
for (i=0; i< NUMAMOSTRAS; i++) {
media += amostra[i];
}
media /= NUMAMOSTRAS;
// Umwandlung des thermischen Spannungswertes in Widerstand
media = 1023 / media - 1;
media = SERIESRESISTOR / media;

//Berechnen Sie die Temperatur mit der Beta-Faktor-Gleichung weiteres zur Gleichung bei google
float temperatura;
temperatura = media / TERMISTORNOMINAL;     // (R/Ro)
temperatura = log(temperatura); // ln(R/Ro)
temperatura /= BCOEFFICIENT;                   // 1/B * ln(R/Ro)
temperatura += 1.0 / (TEMPERATURENOMINAL + 273.15); // + (1/To)
temperatura = 1.0 / temperatura;                 // Invertiert den Wert
temperatura -= 273.15;                         // Umwandeln nach Celsius

//Serial.print("The sensor temperature is: ");
//Serial.print(temperatura);
//Serial.println(" *C");


lcd.setCursor(0, 0);
  lcd.print("Temp         C  ");
 
  lcd.setCursor(6, 0);
  // Anzeige Temperatur in C
  lcd.print(temperatura);
  
  
delay(1000);
}
