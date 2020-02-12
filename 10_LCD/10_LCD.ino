// https://i.imgur.com/P7u1Fna.png

#include <LiquidCrystal.h>

LiquidCrystal lcd(1, 2, 4, 5, 6, 7);

void setup(){
  lcd.begin(16, 2);
}

void loop(){
  lcd.setCursor(0, 0);
  lcd.print("Watersensor");
  lcd.setCursor(1, 1);
  lcd.print("Raw Value");


// Hygrosensor Read
/* 
  int val = analogRead(0);

  if ((val / 10) < 1){
    lcd.setCursor(15, 1);
  }
  else if ((val / 10) < 10){
    lcd.setCursor(14, 1);
  }
  else if((val / 10) < 100){
    lcd.setCursor(13, 1);
  }
  else{
    lcd.setCursor(12, 1);
  }
  lcd.print(val);  

*/
  for (int i = 0; i < 1000; i++){
    if ((i / 10) < 1){
      lcd.setCursor(15, 1);  
    }
    else if((i / 10) < 10){
      lcd.setCursor(14, 1);
    }
    else{
      lcd.setCursor(13, 1);
    }
    
    lcd.print(i);
    delay(1000);
  }
}
