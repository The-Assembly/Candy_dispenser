/*

   Demonstrates the use a 16x2 LCD display and
  4x4 LCD display. 

  -- The  Arduino circuit connection for LCD --

   * LCD RS  pin to digital pin D0

   * LCD  Enable pin to digital pin D1

   * LCD D4  pin to digital pin D10

   * LCD D5  pin to digital pin D11

   * LCD D6  pin to digital pin D12

   * LCD D7  pin to digital pin D13

  -- The  Arduino circuit connection for MAtrix Key Pad --

   * ROW1 pin  to digital pin 9

   * ROW2 pin  to digital pin 8

   * ROW3 pin  to digital pin 7

   * ROW4 pin  to digital pin 6

   * COLUMN1  pin to digital pin 5

   * COLUMN2  pin to digital pin 4

   * COLUMN3  pin to digital pin 3

   * COLUMN4  pin to digital pin 2
   
   */

  // include the library code:

  #include <Keypad.h>

  #include <LiquidCrystal.h>

  //initialize the library with the numbers of the interface pins

  LiquidCrystal lcd(A0,A1,A2,A3,A4,A5);

  //4x4 Matrix key pad

  const byte ROWS = 4; // Four rows
  const byte COLS = 4; // Four columns

  // Define the Keymap

  char keys[ROWS][COLS] = 
  {
    
  {'7','8','9','/'},
  {'4','5','6','X'},
  {'1','2','3','-'},
  {'#','0','=','+'}
 
  };

  byte rowPins[numRows] = {9,8,7,6}; //Rows 0 to 3 
  byte colPins[numCols]= {5,4,3,2}; //Columns 0 to 3

  // Create the Keypad

  Keypad kpd = Keypad( makeKeymap(keys), rowPins,
  colPins, ROWS, COLS );

  void setup() 

  { 
    // set up the LCD's number of columns and rows:
    lcd.begin(16, 2);
    // Print a message to the LCD.
    lcd.print("KEYPAD LCD TEST"); 
  }

  void loop() 

  {
    char key = kpd.getKey();
    // set the cursor to column 0, line 1
    // (note:line 1 is the second row, since counting begins with 0):
    
    lcd.setCursor(0, 1);

    // print the number of seconds since reset:

    lcd.print("SEC= ");
    lcd.print(millis() / 1000);

    // Check for a valid key

    if(key)  
   {
     // set the cursor to column 9, line 1
     //(note: line 1 is the second row, since counting begins with 0):
    
     lcd.setCursor(9, 1);

     //Print the detected key

     lcd.print("KEY= ");
     lcd.print(key);

    }  

  }
