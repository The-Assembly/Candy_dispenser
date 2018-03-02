/*
 In this example you will controlling a servo motor by pressing a button on th keypad
 Each button signifies a particular angle at which the servo moves when pressed
 */
 
#include <Keypad.h>
#include <Servo.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(0 ,1, 10, 11 , 12,13);

const byte rows = 4; //four rows since the keypad is full
const byte columns = 4; //four columns, same as above

char buttons[rows][columns] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowP[rows] = {9,8,7,6}; //row pins of the keypad
byte columnsP[columns] = {5,4,3,2}; //column pins of the keypad

Keypad pad = Keypad( makeKeymap(buttons), rowP, columnsP, rows, columns );    //create keypad

Servo myServo;  

void setup(){
   lcd.begin(16, 2);
   myServo.attach(2);  // attaches the servo on pin 2 to the servo object
}
void loop(){
  char key = pad.getKey();  //get the char from the keypad
      if(key == '0')
      {
        lcd.setCursor(0,0)
        myServo.write(15);
        lcd.print("0");
        lcd.setCursor(2,0)
        lcd.print("degree")
        delay(15);
      }
      if(key == '1')
      {
        lcd.setCursor(0,0)
        myServo.write(30);
        lcd.print("1");
        lcd.setCursor(2,0)
        lcd.print("degree")
        delay(15);
      }
      if(key == '2')
      {
        lcd.setCursor(0,0)
        myServo.write(45);
        lcd.print("2");
        lcd.setCursor(2,0)
        lcd.print("degree")
        delay(15);
      }
      if(key == '3')
      {
        lcd.setCursor(0,0)
        myServo.write(60);
        lcd.print("3");
        lcd.setCursor(2,0)
        lcd.print("degree")
        delay(15);
      }
      if(key == '4')
      {
        lcd.setCursor(0,0)
        myServo.write(75);
        lcd.print("4");
        lcd.setCursor(2,0)
        lcd.print("degree")
        delay(15);
      }
      if(key == '5')
      {
        lcd.setCursor(0,0)
        myServo.write(90);
        lcd.print("5");
        lcd.setCursor(2,0)
        lcd.print("degree")
        delay(15);
      }
      if(key == '6')
      {
        lcd.setCursor(0,0)
        myServo.write(105);
        lcd.print("6");
        lcd.setCursor(2,0)
        lcd.print("degree")
        delay(15);
      }
      if(key == '7')
      {
        lcd.setCursor(0,0)
        myServo.write(120);
        lcd.print("7");
        lcd.setCursor(2,0)
        lcd.print("degree")
        delay(15);
      }
      if(key == '8')
      {
        lcd.setCursor(0,0)
        myServo.write(135);
        lcd.print("8");
        lcd.setCursor(2,0)
        lcd.print("degree")
        delay(15);
      }
      if(key == '9')
      {
        lcd.setCursor(0,0)
        myServo.write(150);
        lcd.print("9");
        lcd.setCursor(2,0)
        lcd.print("degree")
        delay(15);
      }
      if(key == '*')
      {
        lcd.setCursor(0,0)
        myServo.write(165);
        lcd.print("*");
        lcd.setCursor(2,0)
        lcd.print("degree")
        delay(15);
      }
      if(key == '#')
      {
        lcd.setCursor(0,0)
        myServo.write(180);
        lcd.print("#");
        lcd.setCursor(2,0)
        lcd.print("degree")
        delay(15);
      }     
}
