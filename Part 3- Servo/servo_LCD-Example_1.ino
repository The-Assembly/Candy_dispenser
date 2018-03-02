#include <Servo.h>
#include <LiquidCrystal.h>
Servo myservo;
int servo  
LiquidCrystal lcd(0,1,10,11,12,13);

Servo myservo;  // create servo object to control a servo  

void setup()
{
  servo1.attach(2); 
  lcd.begin(16, 2);
  lcd.print("position="); 
}

void loop() 
{     
  servo = 90;
  myservo.write(servo);                  // sets the servo position according to the scaled value
  lcd.setCursor(9, 0);
  lcd.print(servo);
  lcd.print("degree");
  delay(1000); 
  
  servo = 180;
  myservo.write(servo);                  // sets the servo position according to the scaled value
  delay(1000); 
  lcd.setCursor(9, 0);
  lcd.print(servo);
  lcd.print("degree");
  delay(1000); 
} 
