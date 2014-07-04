/*
 Will help scroll just one line in LCD
 The other will be static.
 
 In this case 1st line: scrolling and 2nd line: static
 
 Reference: http://arduino.cc/en/Tutorial/LiquidCrystal
 
 The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)
*/

// include the library
#include <LiquidCrystal.h>

// init the lcd display according to the circuit
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

// it's a 16x2 LCD so...
int screenWidth = 16;
int screenHeight = 2;

// the two lines
// line1 = scrolling
String line1 = " Si buscas resultados distintos, no hagas siempre lo mismo";
// line2 = static
String line2 = " Albert Einstein";
String line3 = " Si quieres tener éxito, promete todo y no cumplas nada";
String line4 = " Napoleón Bonaparte";
String line5 = " El saber es la parte principal de la felicidad";
String line6 = " Socrates";

// just some reference flags
int stringStart, stringStop = 0;
int scrollCursor = screenWidth;

// most of the part is pretty basic
void setup() {
  lcd.begin(screenWidth,screenHeight);
}

void loop() {
  lcd.setCursor(scrollCursor, 0);
  lcd.print(line1.substring(stringStart,stringStop));
  lcd.setCursor(0, 1);
  lcd.print(line2);
  delay(100);
  lcd.clear();
  if(stringStart == 0 && scrollCursor > 0){
    scrollCursor--;
    stringStop++;
  } else if (stringStart == stringStop){
    stringStart = stringStop = 0;
    scrollCursor = screenWidth;
  } else if (stringStop == line1.length() && scrollCursor == 0) {
    stringStart++;
  } else {
    stringStart++;
    stringStop++;
  }
  lcd.clear();
 }
