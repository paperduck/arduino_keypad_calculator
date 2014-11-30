/*
Main program
 */

#include "pin.h"
#include "calc.h"
#include "keypad.h"
#include <inttypes.h>
#include <LiquidCrystal.h>

// Global stuff *********************
//Create LCD screen instance
LiquidCrystal lcd(8, 9, 10, 11, 12, 13);

// Calculator instance
calculator calc;

// Keypad instance
keypad * k = new keypad(4, 3);

// These are output from the keypad class, and indicate which key is currently pressed.
unsigned short int row_index;
unsigned short int col_index;

// Timing
unsigned long time_of_last_print = 0;
unsigned long print_delay_ms = 100;


///////////////////////////////////////////////////////////////////////
void setup()
{
  //Serial.begin(9600);

  //Set pins as output/input for hardware as needed.
  // Row pins will output voltage into the keypad
  pinMode(2, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(4, OUTPUT);
  
  // Voltage needs to be read from the pins wired to the columns of the keypad.
  pinMode(3, INPUT_PULLUP);
  pinMode(1, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  
  // COMMON wire
  //pinMode(0, OUTPUT);
  //digitalWrite(0, LOW);

  //Configure keypad class to use pins that have been wired.
  // Add row pins.
  k->add_row_pin(2);
  k->add_row_pin(7);
  k->add_row_pin(6);
  k->add_row_pin(4);
  // Add column pins
  k->add_col_pin(3);
  k->add_col_pin(1);
  k->add_col_pin(5);

  // Configure lcd
  lcd.begin(16,2);

  // Startup fanfare
  lcd.print(calc.get_output());
  delay(1000);
  lcd.clear();
}


///////////////////////////////////////////////////////////////////////
void loop()
{
  //Uses keypad class above to get keypresses
  if (k->check(row_index, col_index))
  {
    // this key is pressed
    switch(row_index)
    {
    case 1:
      switch(col_index)
      {
      case 1:
        calc.btn_1();        
        break;
      case 2:
        calc.btn_2();
        break;
      case 3:
        calc.btn_3();
        break;
      default:
        lcd.print("ERROR:row1");
        break; 
      }
      break;
    case 2:
      switch(col_index)
      {
      case 1:
        calc.btn_4();
        break;
      case 2:
        calc.btn_5();
        break;
      case 3:
        calc.btn_6();
        break;
      default:
        lcd.print("ERROR:row2");
        break; 
      }
      break;
    case 3:
      switch(col_index)
      {
      case 1:
        calc.btn_7();
        break;
      case 2:
        calc.btn_8();
        break;
      case 3:
        calc.btn_9();
        break;
      default:
        lcd.print("ERROR:row3");
        break; 
      }
      break;
    case 4:
      switch(col_index)
      {
      case 1:
        calc.btn_cycle_operator();
        break;
      case 2:
        calc.btn_0();
        break;
      case 3:
        calc.btn_equals();
        break;
      default:
        lcd.print("ERROR:row4");
        break; 
      }
      break;
    default:
      lcd.print("ERROR:row!");
      break;
    }
  }

  // Delay printing to LCD, to avoid flickering screen.
  if ( (millis() - time_of_last_print) > print_delay_ms )
  {
    time_of_last_print = millis();
    //Send calculator class output to LCD screen.
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(calc.get_output());
  }
}














