/*
* Disposición de pines
* LCD RS pin to digital pin 12
* LCD Enable pin to digital pin 11
* LCD D4 pin to digital pin 5
* LCD D5 pin to digital pin 4
* LCD D6 pin to digital pin 3
* LCD D7 pin to digital pin 2
*/
#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

int screenWidth = 16;
int screenHeight = 2;

// líneas impares - scroll
// líneas pares - no scroll
String line1 = " Si buscas resultados distintos, no hagas siempre lo mismo";
String line2 = " Einstein";
String line3 = " Si quieres tener exito, promete todo y no cumplas nada";
String line4 = " Napoleon";
String line5 = " El saber es la parte principal de la felicidad";
String line6 = " Socrates";

int stringStart, stringStop, stringStart2, stringStop2, stringStart3, stringStop3 = 0;
int scrollCursor = screenWidth;
int scrollCursor2 = screenWidth;
int scrollCursor3 = screenWidth;

void setup() {
  lcd.begin(screenWidth,screenHeight);
}

void loop() {
  lcd.setCursor(scrollCursor, 0);
  lcd.print(line1.substring(stringStart,stringStop));
  delay(100);
  if(stringStart == 0 && scrollCursor > 0){
      scrollCursor--;
      stringStop++;
  }
  else if (stringStop == line1.length() && scrollCursor == 0) {
      stringStart++;
  } 
  else {
      stringStart++;
      stringStop++;
  }
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
    lcd.print(line3.substring(stringStart2,stringStop2));
// delay(0);
    if(stringStart2 == 0 && scrollCursor2 > 0){
      scrollCursor2--;
      stringStop2++;
    }
    else if (stringStop2 == line3.length() && scrollCursor2 == 0) {
      stringStart2++;
    }
    else {
      stringStart2++;
      stringStop2++;
    }
    if(stringStart2 <= stringStop2){
      lcd.setCursor(0,1);
      lcd.print(line4);
    }
  }
  
  ///Tercera Frase
  if(stringStart2 > stringStop2){
    lcd.clear();
    lcd.setCursor(scrollCursor3, 0);
    lcd.print(line5.substring(stringStart3,stringStop3));
    if(stringStart3 == 0 && scrollCursor3 > 0){
      scrollCursor3--;
      stringStop3++;
    }
    else if (stringStop3 == line5.length() && scrollCursor3 == 0) {
      stringStart3++;
    }
    else {
      stringStart3++;
      stringStop3++;
    }
    if(stringStart3 <= stringStop3){
      lcd.setCursor(0,1);
      lcd.print(line6);
    }
  }
}

