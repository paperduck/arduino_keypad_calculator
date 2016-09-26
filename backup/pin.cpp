// Matrix keypad class

#include "Arduino.h"
#include "keypad.h"

/*
Purpose:
 Constructor
 */
keypad::keypad(unsigned short int in_num_rows, unsigned short int in_num_cols, boolean in_use_row_input)
{
  // Set numRows to value passed in
  num_rows = in_num_rows;

  // Set numCols to value passed in
  num_cols = in_num_cols;

  // Set useRowInput to value passed in
  use_row_input = in_use_row_input;

  // Initialize current row and column indexes
  cur_row_index = 1;
  cur_col_index = 1;

  // Initialize array of keypad_pin structs
  row_pins = (keypad_pin*)malloc(sizeof(keypad_pin) * num_rows);
  col_pins = (keypad_pin*)malloc(sizeof(keypad_pin) * num_cols);
  
  
}


keypad::~keypad()
{
  free(row_pins);
  free(col_pins); 
}


/*
Params:
 - (output) unsigned short int & rowIndex
 Row index (1-based) of key pressed, if any
 - (output) unsigned short int & colIndex
 Column index (1-based) of key pressed, if any
 Purpose:
 Check if the current key is pressed and returns its row and col indexes.
 The program that uses this class is responsible for calling this function over and over,
 to continuously scan the keyspad.
 Returns:
 bool
 false if no key pressed
 true if any key pressed
 Outline:
 If (UseRowInput)
 {
 Turn voltage on to pin with number RowPins[rowIndex]
 Read voltage on ColPins[colIndex]
 }
 else
 { 
 (same as above, but use reverse inputs & outputs)
 }
 */
boolean keypad::check(unsigned short int & row_index, unsigned short int & col_index)
{


  // Increment row and/or column indexes
  if (cur_row_index >= num_rows)
  {
    cur_row_index++;
  }
  else
  {
    cur_row_index = 1;
    if(cur_col_index >= num_cols)
    {
      cur_col_index++;
    } 
    else
    {
      cur_col_index = 1; 
    }
  }

  return true;
} 


/*
Params:
 hex pin name (e.g. A0, 4, 0, etc.)
 Purpose:
 Create a new pin struct and add it to the list of row pins.
 Outline:
 Create new pin struct using arguments passed in.
 Add this struct to the existing list of row pins.
 Params:
 hex pin name (e.g. A0, 4, 0, etc.)
 */
void keypad::add_row_pin(unsigned short int in_pin_num, boolean in_is_digital, )
{
  row_pins[num_row_pins_added]->pin_num = in_pin_num;
  row_pins[num_row_pins_added]->is_digital = in_is_digital;
  num_row_pins_added++;
  return; 
}


//Params:
//hex pin name (e.g. A0, 4, 0, etc.)
void keypad::add_col_pin(unsigned short int pin_num, boolean is_digital)
{
  return; 
}


/*
Purpose:
 Attempts to increase row index by one. If at max, reset to 1 and increment column index.
 If column index is also at max, reset both indexes to 1.
 */
//void keypad::increment_key_indexes()
//{
//  return;  
//}


//boolean keypad::is_analog()
//{
//  return true;;
//}




