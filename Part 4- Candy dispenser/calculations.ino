

const byte numRows= 4; //number of rows on the keypad
const byte numCols= 4; //number of columns on the keypad
long randNumber;

//keymap defines the key pressed according to the row and columns just as appears on the keypad
char keymap[numRows][numCols]=
{
{'1', '2', '3', 'A'},
{'4', '5', '6', 'B'},
{'7', '8', '9', 'C'},
{'*', '0', '#', 'D'}
};

//Code that shows the the keypad connections to the arduino terminals
byte rowPins[numRows] = {9,8,7,6}; //Rows 0 to 3
byte colPins[numCols]= {5,4,3,2}; //Columns 0 to 3

//initializes an instance of the Keypad class
//Keypad myKeypad= Keypad(makeKeymap(keymap), rowPins, colPins, numRows, numCols);

long int a = 0;

void setup()
{
  Serial.begin(9600);
  randomSeed(analogRead(0));
  Serial.println("start ");

  Serial.println("Please select the difficulty: E for Easy, M for Medium, or H for Hard");
   
}

void loop()
{ 
  char diff = Serial.read();
//  char keypressed = myKeypad.getKey();
   int w = random(4);
   int x1 = random(100);
   int y1 = random(100);
   
   long int x2 = random(100);
   long int y2 = random(100);
   long int z2 = random(100);
   
   long int x3 = random(1000);
   long int y3 = random(1000);
   long int z3 = random(1000);

   
  
   //////////////////////////////////////       If they select the 1st difficulty ie. Easy        /////////////////////////////////////////////////////
  if(diff == 'E' || diff == 'e')
{
  switch(w)
  {
    case 1: Serial.print(x1);
            Serial.print(" + ");
            Serial.print(y1);
            Serial.println(" = ");
           // delay(150);
            
            do {if(Serial.available() > 0){
              a = Serial.parseInt();
              Serial.println(a);}}
            while (a != ( x1 + y1));
            Serial.println("Loop Broken");
            
    break;
    case 2: 
            //delay(150);
            if( x1 > y1 )
           {Serial.print(x1);
            Serial.print(" - ");
            Serial.print(y1);
            Serial.println(" = ");}

            else
                { Serial.print(y1);
            Serial.print(" - ");
            Serial.print(x1);
            Serial.println(" = ");}
            
            do {if(Serial.available() > 0){
              a = Serial.parseInt();
              Serial.println(a);}}
            while (a != ( x1 - y1) && a != ( y1 - x1));
            Serial.println("Loop Broken");
            
    break;

    case 3:
            Serial.print(x1);
            Serial.print(" * ");
            Serial.print(y1);
            Serial.println(" = ");
           // delay(150);
            
            do {if(Serial.available() > 0){
              a = Serial.parseInt();
              Serial.println(a);}}
            while (a != ( x1 * y1));
            Serial.println("Loop Broken");
  }
}
 //////////////////////////////////////        If they select the 2nd difficulty ie. Medium       ////////////////////////////////////////////////////////
if(diff == 'M' || diff == 'm')
{
  switch(w)
  {
    case 1: Serial.print(x2);
            Serial.print(" + ");
            Serial.print(y2);
            Serial.print(" + ");
            Serial.print(z2);
            Serial.println(" = ");
           // delay(150);
            
            do {if(Serial.available() > 0){
              a = Serial.parseInt();
              Serial.println(a);}}
            while (a != ( x2 + y2 + z2));
            Serial.println("Loop Broken");
            
    break;
    case 2: 
            //delay(150);
            if( x2 > y2 > z2)
              { Serial.print(x2);
            Serial.print(" - ");
            Serial.print(y2);
            Serial.print(" - ");
            Serial.print(z2);
            Serial.println(" = ");}

            else
                { Serial.print(z2);
            Serial.print(" - ");
            Serial.print(y2);
            Serial.print(" - ");
            Serial.print(x2);
            Serial.println(" = ");}
            
            do {if(Serial.available() > 0){
              a = Serial.parseInt();
              Serial.println(a);}}
            while (a != ( x2 - y2 - z2) && a != ( z2 - y2 - x2));
            Serial.println("Loop Broken");
            
    break;

    case 3:
            Serial.print(x2);
            Serial.print(" * ");
            Serial.print(y2);
            Serial.print(" * ");
            Serial.print(z2);
            Serial.println(" = ");
           // delay(150);
            
            do {if(Serial.available() > 0){
              a = Serial.parseInt();
              Serial.println(a);}}
            while (a != ( x2 * y2 * z2));
            Serial.println("Loop Broken");
     break;

    case 4:
            Serial.print(x2);
            Serial.print(" * ");
            Serial.print(y2);
            Serial.print(" + ");
            Serial.print(z2);
            Serial.println(" = ");
           // delay(150);
            
            do {if(Serial.available() > 0){
              a = Serial.parseInt();
              Serial.println(a);}}
            while (a != ( (x2 * y2) + z2));
            Serial.println("Loop Broken");
     break;
     
     
  }
}

 //////////////////////////////////////        If they select the 3rd difficulty ie. Hard       ////////////////////////////////////////////////////////
if(diff == 'H' || diff == 'h')
{
  switch(w)
  {
    case 1: Serial.print(x3);
            Serial.print(" + ");
            Serial.print(y3);
            Serial.print(" + ");
            Serial.print(z3);
            Serial.println(" = ");
           // delay(150);
            
            do {if(Serial.available() > 0){
              a = Serial.parseInt();
              Serial.println(a);}}
            while (a != ( x3 + y3 + z3));
            Serial.println("Loop Broken");
            
    break;
    case 2: 
            //delay(150);
            if( x3 > y3 > z3)
              { Serial.print(x3);
            Serial.print(" - ");
            Serial.print(y3);
            Serial.print(" - ");
            Serial.print(z3);
            Serial.println(" = ");}

            else
                { Serial.print(z3);
            Serial.print(" - ");
            Serial.print(y3);
            Serial.print(" - ");
            Serial.print(x3);
            Serial.println(" = ");}
            
            do {if(Serial.available() > 0){
              a = Serial.parseInt();
              Serial.println(a);}}
            while (a != ( x3 - y3 - z3) && a != ( z3 - y3 - x3));
            Serial.println("Loop Broken");
            
    break;

    case 3:
            Serial.print(x3);
            Serial.print(" * ");
            Serial.print(y3);
            Serial.print(" * ");
            Serial.print(z3);
            Serial.println(" = ");
           // delay(150);
            
            do {if(Serial.available() > 0){
              a = Serial.parseInt();
              Serial.println(a);}}
            while (a != ( x3 * y3 * z3));
            Serial.println("Loop Broken");
     break;

    case 4:
            Serial.print(x3);
            Serial.print(" * ");
            Serial.print(y3);
            Serial.print(" + ");
            Serial.print(z3);
            Serial.println(" = ");
           // delay(150);
            
            do {if(Serial.available() > 0){
              a = Serial.parseInt();
              Serial.println(a);}}
            while (a != ( (x3 * y3) + z3));
            Serial.println("Loop Broken");
     break;

     case 5:
            Serial.print(x3);
            Serial.print(" * ");
            Serial.print(y3);
            Serial.print(" - ");
            Serial.print(z3);
            Serial.println(" = ");
           // delay(150);
            
            do {if(Serial.available() > 0){
              a = Serial.parseInt();
              Serial.println(a);}}
            while (a != ( (x3 * y3) - z3));
            Serial.println("Loop Broken");
     break;
     
     case 6: 
            //delay(150);
            if( (x3 + y3) > z3)
              { Serial.print(x3);
            Serial.print(" + ");
            Serial.print(y3);
            Serial.print(" - ");
            Serial.print(z3);
            Serial.println(" = ");}

            else
                { Serial.print(x3);
            Serial.print(" - ");
            Serial.print(y3);
            Serial.print(" + ");
            Serial.print(z3);
            Serial.println(" = ");}
            
            do {if(Serial.available() > 0){
              a = Serial.parseInt();
              Serial.println(a);}}
            while (a != ( x3 + y3 - z3) && a != ( x3 - y3 - z3));
            Serial.println("Loop Broken");
            
    break;
    
  }
}

}

