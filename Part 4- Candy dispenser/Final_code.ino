
#include <Keypad.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(0,1, 10, 11 , 12,13);
#include <Servo.h>

Servo myservo;  // create servo object to control a servo
byte sad[8] = {
  B00000,
  B01010,
  B01010,
  B00000,
  B00000,
  B01110,
  B10001,
};

unsigned long time=0;
unsigned long start=0;
int m, mu=0,md=0;             
int s, su=0,sd=0;
int c,cu,cd=0;
byte attempt=0;

char level;
boolean modePlay=false;
int randomNum;
int firstNum=0;
int secondNum=0;
int thirdNum=0;
int temp=0;
int result;
String operand="";
String sresult;
String sLevel;
int len=0;
boolean activate=false;
boolean wait = false;


char player_num[4]; //Stores the number of the player

String numOfPlayer = String(); 
String snumOfPlayer;


int counter=0;
int i,j,x;

int attempts=0;
int max_attempt=5;

const byte ROWS=4;
const byte COLS=4;
char keys[ROWS][COLS] = {
 {'1','2','3','A'},
 {'4','5','6','B'},
 {'7','8','9','C'},
 {'*','0','#','D'}
};
byte rowPins[ROWS] = {9,8,7,6}; //rows(pins 9 and 6)
byte colPins[COLS] = {5,4,3,2}; //Columns (pins 5 and 2)
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );



void game_over()
{
  wait=false;
  modePlay=false;
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Enjoy your candy");
  lcd.setCursor(0,1);
  lcd.print("Time: ");
  lcd.print(md);
  lcd.print(mu);
  lcd.print(":");
  lcd.print(sd);
  lcd.print(su); 
  lcd.print(":");
  lcd.print(cd);
  lcd.print(cu); 
  myservo.write(180);                  // sets the servo position according to the scaled value
  delay(1000);
}

void generate_random()
{
    lcd.clear();
    counter=0;
    sresult="";
    snumOfPlayer="";
   
    randomSeed(analogRead(analogRead(0)));
    
    switch(level)
    {
      case '1':
  
       firstNum=random(1,11);  //Generates a number between 1 and 10
       secondNum=random(1,11);  //Generates a number between 1 and 10     
       break;

      case '2':
      
       firstNum=random(50,100);  //Generates a number between 50 and 99
       secondNum=random(1,11);  //Generates a number between 1 and 10
       break;

        
      case '3':
        
       firstNum=random(50,100);  //Generates a number between 1 and 99
       secondNum=random(50,100);  //Generates a number between 1 and 10     
       break;

      case '4':

       firstNum=random(1,100);  //Generates a number between 1 and 100
       secondNum=random(1,100);  //Generates a number between 1 and 100     
       break;

      
    }    
    
    thirdNum=random(1,5);  //Generates a number between 1 and 4
    

    switch(thirdNum)
    {
      case 1:
        operand="+";
        result=firstNum+secondNum;
        break;
      case 2:
        operand="-";
          if(firstNum<secondNum)
          {
            temp=firstNum;
            firstNum=secondNum;
            secondNum=temp;
          }
        result=firstNum-secondNum;    
    
        break;
       case 3:
        operand="*";
        result=firstNum*secondNum;       
        break;
       case 4:
         operand="/";
         result=firstNum%secondNum;
         if(result!=0)  //If not is zero the mod
         {
           operand="*";
           result=firstNum*secondNum;       
         }
         else  //The mod is zero
         {
           result=firstNum/secondNum;
         }
    }
          
    sresult=  String(result);
    
    lcd.setCursor(0,0);
    lcd.print(firstNum);
    lcd.setCursor(2,0);
    lcd.print(operand);
    lcd.setCursor(3,0);
    lcd.print(secondNum); 
    lcd.setCursor(12,1);
    lcd.print(counter);   

    lcd.setCursor(0,1);  
    lcd.print("    ");
    lcd.setCursor(0,1);  

     
}

void timer()
{
    
   if(modePlay==true)
   {
    time = millis()-start;  
    
    m=(time/1000)/60;                 //Minutes
    mu=m%10;                            
    md=(m-mu)/10;                       
       
    s=(time/1000)%60;                 //Seconds
    su=s%10;                            
    sd=(s-su)/10;
    
    c=(time/100)%60;
    cu=c%10;
    cd=(c-cu)/10;
    
    lcd.setCursor(8,0);
    lcd.print(md);
    lcd.print(mu);
    lcd.print(":");
    lcd.print(sd);
    lcd.print(su); 
    lcd.print(":");
    lcd.print(cd);
    lcd.print(cu); 
    
    
   }
   
}

void setup() 
  {
    // put your setup code here, to run once:
      lcd.createChar(1,sad); 
      lcd.begin(16, 2);    
      choose();    //Displays the select level mode
      myservo.attach(2);  // attaches the servo on pin 9 to the servo object
  
  }
  
//********************************************************
void check()
{
  if(snumOfPlayer==sresult)
  {  
    
    lcd.setCursor(6,0);
    lcd.print("G");

    attempt=attempt+1;    
    
    generate_random();
 
  }
 
  else
 
  {
   
    
    lcd.setCursor(0,1);   
    
    counter=0;
    
    snumOfPlayer="";
    
    lcd.setCursor(6,1);
    lcd.write(byte(1));  //this writes the sad face
   
   
  
  }
 

  
  lcd.setCursor(8,1);
  lcd.print("Try:");
  lcd.print(attempt);
  lcd.print("/5");
  
  if(attempt==max_attempt)
  {
    game_over();  // Ends the game
  }

}

void choose()
{ myservo.write(10);                  // sets the servo position according to the scaled value
  delay(10000);
  modePlay=false;
  attempt=0;
  lcd.clear();
  lcd.setCursor(2,0);
  lcd.print("Select level");
  lcd.setCursor(0,1);
  lcd.print("1-E 2-M 3-H 4-R");

}

void countdown()
{
  lcd.clear();
  
  lcd.setCursor(4,0);
  
  lcd.print(sLevel);
  
  delay(300);
  
  lcd.clear();

  for(int x=3;x>=1;x--)
  {
  lcd.setCursor(8,0);
  
  lcd.print(x);
  
  delay(300);
  
  
  }
  
lcd.clear();

lcd.setCursor(7,0);
  
lcd.print("Go");

delay(600);


generate_random();
  
modePlay=true;
  
  if(activate==false)
    {
      start=millis();
      activate=true;
    }

}


void loop()
{ 
  timer();
  
  // put your main code here, to run repeatedly:
  
  
  char key = keypad.getKey();
  
  if(key)
  


  {   
    //If is the select level display
    if(modePlay==false)    
      {
        if(key=='1' || key=='2' || key=='3' || key=='4')
      {
          level=key;
          
          lcd.clear();
         
          lcd.setCursor(5,1);
  
          switch(level)
          {
            case '1':
              sLevel="Easy Level";              
              break;
            case '2':
              sLevel="Medium Level";
              break;
            case '3':
              sLevel="Hard Level";
              break;
            case '4':
              sLevel = "Random Level";
              break;
            
          } //end switch
   
          countdown();       

        } // end IF key select level
          
      } //end IF mode play off
      
      else
      //Mode player
      
      {
        
           wait=true;
        
           if(activate==false)
          {
            start=millis();
            activate=true;
            lcd.clear();
          }        
          
        
        if(key!='A' && key!='B' && key!='C' && key!='D' && key!='#')
       {
         
        player_num[counter] = key;
        
        numOfPlayer = String(key);
        
        snumOfPlayer=snumOfPlayer+numOfPlayer;
      
        lcd.setCursor(0+counter,1);
        
        lcd.print(player_num[counter]);
        
        counter++;                     
        
       len=sresult.length();
       
       if(counter==len)
        {
  //        lcd.setCursor(10,1);
          check();
        }

         
       } //End if key!=   
      
        
      } // End else mode player
      
      
        if(key=='#')
        {  
          modePlay=false;
          start=millis();
          activate=false; 
          choose(); 

        }
   
  }    //End if Key main
 


} //End loop

