// Matrix keypad class

#include "Arduino.h"
#include "keypad.h"

///////////////////////////////////////////////////////////////////////
// Purpose:
//   Constructor
///////////////////////////////////////////////////////////////////////
keypad::keypad(unsigned short int in_num_rows, unsigned short int in_num_cols)
{
  // Record number of rows and columns
  num_rows = in_num_rows;
  num_cols = in_num_cols;

  // Initialize current row and column indexes.
  cur_row_index = 1;
  cur_col_index = 1;

  // Track number of rows and columns configured.
  num_row_pins_added = 0;
  num_col_pins_added = 0;

  // Initialize arrays of pins.
  //row_pins = (pin*)malloc(sizeof(pin) * in_num_rows);
  row_pins = new pin[in_num_rows];
  col_pins = new pin[in_num_cols];

  // Whether or not key being scanned is pressed.
  key_is_pressed = false;

  // Initiazize debounce.
  debounce_time_ms = 200;
  time_of_last_keypress = 0;

  //Serial.begin(9600);
}


///////////////////////////////////////////////////////////////////////
// Purpose:
//   Deconstructor
///////////////////////////////////////////////////////////////////////
keypad::~keypad()
{
  free(row_pins);
  free(col_pins); 
}


///////////////////////////////////////////////////////////////////////
/*
 Purpose:
 
 Check if the current key is pressed and returns its row and col indexes.
 The program that uses this class is responsible for calling this function over and over,
 to continuously scan the keypad.
 
 Returns:
 
 bool:
 false if no key pressed
 true if any key pressed
 
 Remarks: 
 
 It is assumed that the calling program has configured the appropriate pins
 so they are ready to be read from or written to.
 */
///////////////////////////////////////////////////////////////////////
bool keypad::check(unsigned short int & out_row_index, unsigned short int & out_col_index)
{
  // No keys pressed, by default.
  key_is_pressed = false;
    
  // Send signal into keypad (row)
  digitalWrite(row_pins[cur_row_index - 1].get_pin_num(), LOW);

  // See if signal comes out (column)
  if (digitalRead(col_pins[cur_col_index - 1].get_pin_num()) == LOW)
  {
    // A key is pressed, so do a debounce check.
    if ( (millis() - time_of_last_keypress) > debounce_time_ms )
    {
      // Debounce check cleared, so record key as being pressed.
      key_is_pressed = true;
      time_of_last_keypress = millis();
    }
  }
  
  // Reset signal
  digitalWrite(row_pins[cur_row_index - 1].get_pin_num(), HIGH);

  // Send row and col indexes of key just checked back to calling program
  out_row_index = cur_row_index;
  out_col_index = cur_col_index;

  // Increment current row and/or column indexes 
  if(cur_col_index < num_cols)
  {
    cur_col_index++;
  } 
  else
  {
    cur_col_index = 1; 
    // increment row index
    if (cur_row_index < num_rows)
    {
      cur_row_index++;
    }
    else
    {
      cur_row_index = 1; 
    }
  }

  // Inform the calling program whether or not the current key being checked is pressed.
  return key_is_pressed;
} 


///////////////////////////////////////////////////////////////////////
/*
Params:
 hex pin number (e.g. A0, 4, 0, etc.).
 
 Purpose:
 Create a new pin struct and add it to the list of row pins.
 
 Outline:
   Create new pin struct using arguments passed in.
   Add this struct to the existing list of row pins.
   
 Remarks:
   The uint8_t data type is used in the LiquidCrystal class constructor
   to specify pin numbers. So it is also used here.
 */
///////////////////////////////////////////////////////////////////////
void keypad::add_row_pin(uint8_t in_pin_num)
{
  // Check if max number of pins reached
  if (num_row_pins_added >= num_rows)
  {
    // Error.
    return;
  }  
  row_pins[num_row_pins_added].set_pin_num(in_pin_num);
  num_row_pins_added++;
  return;
}

///////////////////////////////////////////////////////////////////////
// Purpose:
//   Add column pin.
///////////////////////////////////////////////////////////////////////
void keypad::add_col_pin ( uint8_t in_pin_num )
{
  // Check if max number of pins reached
  if (num_col_pins_added >= num_cols)
  {
    // Error.
    return;
  }  
  col_pins[num_col_pins_added].set_pin_num(in_pin_num);
  num_col_pins_added++;
  return;
}




















