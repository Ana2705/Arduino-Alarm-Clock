#include <DS3231.h>
#include <Wire.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
DS3231 rtc(SDA, SCL);
Time t;
int H;
int Min;
int Sec;
#define buz 11

void setup(){
  
  Wire.begin();
  rtc.begin();
  Serial.begin(9600);
  //rtc.setTime(10, 5, 0);
  //rtc.setDate(25, 5, 2021);
  pinMode(buz, OUTPUT);
  lcd.begin(16,2);
  lcd.print("Alarm Clock");
  delay(2000);

}

void loop(){
  
  t = rtc.getTime();
  H = t.hour;
  Min = t.min;
  Sec = t.sec;
  lcd.setCursor(0,0);
  lcd.print("Time: ");
  lcd.print(rtc.getTimeStr());
  lcd.setCursor(0,1);
  lcd.print("Date: ");
  lcd.print(rtc.getDateStr());

  if(H == 19 && Min == 53){
    
    Buzzer();
    Buzzer();
    lcd.clear();
    lcd.print("Alarm active");
    Buzzer();
    Buzzer();
  
  } 

  delay(1000); 

}

void Buzzer(){

  digitalWrite(buz,HIGH);
  delay(500);
  digitalWrite(buz, LOW);
  delay(500);

}
