//www.elegoo.com
//2016.12.9

/*
  LiquidCrystal Library - Hello World

 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.

 This sketch prints "Hello World!" to the LCD
 and shows the time.

  The circuit:
 * LCD RS pin to digital pin 7
 * LCD Enable pin to digital pin 8
 * LCD D4 pin to digital pin 9
 * LCD D5 pin to digital pin 10
 * LCD D6 pin to digital pin 11
 * LCD D7 pin to digital pin 12
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/LiquidCrystal
 */

// Bibliothek einbinden
#include <LiquidCrystal.h>

// Initialisiere die Bibliothek mit den Nummern der Schnittstellenpins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

String s = "Dieser Text ist etwas länger und wird als Lauftext angezeigt";
// Spalten und Zeilen des lcd
int lcdsize[] = {16, 2};

void setup() {
// Richtet die Anzahl der Spalten und Zeilen der LCD ein:
lcd.begin(lcdsize[0], lcdsize[1]);
// Drucket eine Nachricht an das LCD.
lcd.print("hello, world!");
}

void loop() {
// Setzt den Cursor auf Spalte 0, Zeile 1
// (Anmerkung: Zeile 1 ist die zweite Zeile, da das Zählen mit 0 beginnt):
lcd.setCursor(0, 1);
for (int i = 0; i < s.length(); i++) {
if (i > lcdsize[0] - 1) {
// lcd.print(" ");
lcd.setCursor(0, 1);
// Den String starten
String s1 = "";
for (int j = lcdsize[0] - 1; j >= 0; j--) {
// Fügt char zum string hinzu
s1.concat(s.charAt(i - j));
}
// print string
lcd.print(s1);
delay(80);
}
lcd.print(s.charAt(i));
delay(150);
}
delay(500);
lcd.setCursor(0, 1);
lcd.print(" ");
delay(1000);
}
