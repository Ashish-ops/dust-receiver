#include <LiquidCrystal.h>
#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); // RX, TX

const int rs=2, en=3, d4=4, d5=5, d6=6, d7=7 ;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
  lcd.begin(16, 2);
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
 
  

}

void loop() {
  while (Serial.available()){
    lcd.home();
    float mm = Serial.readStringUntil(59).toFloat();
    lcd.print(mm);
    lcd.println(" mg/m3");
    if(mm>0.05){
      digitalWrite(13,HIGH);
      digitalWrite(12,HIGH);
    }
    else{
      digitalWrite(13,LOW);
      digitalWrite(12,LOW);
    }
    mySerial.print(mm);
   
  }
}
