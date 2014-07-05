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
String line1 = " Not TOday le ganara a union gaymin";
// line2 = static
String line2 = " Einstein";
String linea3 = " Esta es la segunda linea largaaa";
String linea4 = " Pronto";

// just some reference flags
int stringStart, stringStop, stringStart2, stringStop2, stringStart3, stringStop3  = 0;
int scrollCursor = screenWidth;
int scrollCursor2 = screenWidth;
int scrollCursor3 = screenWidth;

// most of the part is pretty basic
void setup() {
  lcd.begin(screenWidth,screenHeight);
}

void loop() {
  lcd.setCursor(scrollCursor, 0);
  lcd.print(line1.substring(stringStart,stringStop));
  delay(100);
  Casa();
  if(stringStart2==0){
    lcd.clear();
  }
  lcd.clear();
  if(stringStart <= stringStop){
    lcd.setCursor(0,1);
    lcd.print(line2);
  }
  if(stringStart >= stringStop){
    lcd.clear();
    lcd.setCursor(scrollCursor2, 0);
    lcd.print(linea3.substring(stringStart2,stringStop2));
//    delay(0);
    if(stringStart2 == 0 && scrollCursor2 > 0){
      scrollCursor2--;
      stringStop2++;
    } 
    else if (stringStop2 == linea3.length() && scrollCursor2 == 0) {
      stringStart2++;
    }
    else {
      stringStart2++;
      stringStop2++;
    }
    if(stringStart2 <= stringStop2){
      lcd.setCursor(0,1);
      lcd.print(linea4);
    }
  }
}

boolean Casa(){
    if(stringStart == 0 && scrollCursor > 0){
      scrollCursor--;
      stringStop++;
    } 
    else if (stringStop == line1.length() && scrollCursor == 0) {
      stringStart++;
    } //Codigo
    /*else if (stringStart == stringStop){
       
      
    //Codigo  
    }*/
    else {
      stringStart++;
      stringStop++;
    }
}