//www.elegoo.com
//2016.12.12

// Definieren die LED-Ziffernmuster von 0 - 9
// 1 = LED an, 0 = LED aus, in dieser Reihenfolge:
//                74HC595 pin     Q0,Q1,Q2,Q3,Q4,Q5,Q6,Q7 
//                Mapping to      a,b,c,d,e,f,g of Seven-Segment LED
byte seven_seg_digits[10] = { B11111100,  // = 0
                              B01100000,  // = 1
                              B11011010,  // = 2
                              B11110010,  // = 3
                              B01100110,  // = 4
                              B10110110,  // = 5
                              B10111110,  // = 6
                              B11100000,  // = 7
                              B11111110,  // = 8
                              B11100110   // = 9
                             };
 
// Verbindung zum ST_CP von 74HC595 (Pin 3, Latch Pin)
int latchPin = 3;
// Verbindung zum SH_CP von 74HC595 (Pin 4, Taktgeber)
int clockPin = 4;
// Verbindung zum DS von 74HC595 (Pin 2)
int dataPin = 2;
 
void setup() {
  // Set latchPin, clockPin, dataPin als Ausgabe
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}
 
// Zeigt eine Nummer auf der digitalen Segmentanzeige an
void sevenSegWrite(byte digit) {
  // Setzen Sie den LatchPin auf niedriges Potential, bevor Sie Daten senden
  digitalWrite(latchPin, LOW);
     
  // Die ursprünglichen Daten (Bitmuster)
  shiftOut(dataPin, clockPin, LSBFIRST, seven_seg_digits[digit]);  
 
  // Setzen Sie den LatchPin auf das hohe Potential, nachdem Sie Daten gesendet haben
  digitalWrite(latchPin, HIGH);
}
 
void loop() {       
  // Von 9 auf 0 zählen
  for (byte digit = 10; digit > 0; --digit) {
    delay(1000);
    sevenSegWrite(digit - 1); 
  }
   
  // 4 Sekunden aussetzen
  delay(3000);
}
