/*
Main program
 */

#include "calc.h"
#include "keypad.h"
#include <LiquidCrystal.h>

// Global stuff *********************
//Create LCD screen instance
LiquidCrystal lcd(8, 9, 10, 11, 12, 13);

// Calculator instance
calculator calc;

// Keypad instance
keypad * k = new keypad(4, 3, true);

// These are output from the keypad class, and indicate which key is currently pressed.
unsigned short int row_index;
unsigned short int col_index;


void setup()
{
  //Set pins as output/input for hardware as needed
  // xxx


  //Configure keypad class to use pins that have been wired
  // xxx
  k->add_row_pin(1, true);
  k->add_row_pin(2, false);
  k->add_row_pin(3, true);
  k->add_row_pin(4, false);


  // Configure lcd
  lcd.begin(16,2);

  // Startup fanfare
  lcd.print(calc.get_output());
  delay(1000);
}


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
      case 0:
        calc.btn_1();        
        break;
      case 1:
        calc.btn_2();
        break;
      case 2:
        calc.btn_3();
        break;
      default:
        break; 
      }
      break;
    case 2:
      switch(col_index)
      {
      case 0:
        calc.btn_4();
        break;
      case 1:
        calc.btn_5();
        break;
      case 2:
        calc.btn_6();
        break;
      default:
        break; 
      }
      break;
    case 3:
      switch(col_index)
      {
      case 0:
        calc.btn_7();
        break;
      case 1:
        calc.btn_8();
        break;
      case 2:
        calc.btn_9();
        break;
      default:
        break; 
      }
      break;
    case 4:
      switch(col_index)
      {
      case 0:
        calc.btn_cycle_operator();
        break;
      case 1:
        calc.btn_0();
        break;
      case 2:
        calc.btn_equals();
        break;
      default:
        break; 
      }
      break;
    default:
      break;
    }
  }

  //Feed keypress data into calculator class
  calc.btn_0();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(calc.get_output());
  delay(500);

  //Send calculator class output to LCD screen.
}






