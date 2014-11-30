// Keypad class (C++) that monitors a matrix circuit of x rows and y columns.
/*
Example usage:
 
 	keypad = new Keypad(4, 3, true);
 	unsigned short int row_index = 1;
 	unsigned short int col_index = 1;
 	while(1){
 		keypad.Check( row_index, col_index );
 		switch( row_index ){
 			case 1:
 				switch( col_index ){
 					case 1:
 						// "1" button pressed
 					case 2:
 						// "2" button pressed
 					case 3:
 						// "3" button pressed
 				}
 			case 2:
 				switch ( col_index ){
 					case 1:
 						// "4"  button pressed
 					case 2: 
 						// "5" button pressed
 					case 3:
 						// "6" button pressed
 				}
 			case 3:
 				<...>
 			<...>
 		}
 	}
 */
 
#ifndef keypad_h
#define keypad_h

#include "pin.h"

class keypad
{
  /////////////////////////////////////////////////////////////////////////////
  //Members:
  ////////////////////////////////////////////////////////////////////////////
private:
  // Number of rows and columns in keypad.
  unsigned short int num_rows;
  unsigned short int num_cols;

  // List of row and column pins.
  // User is responsible for adding pin numbers to this list.
  pin * row_pins;
  pin * col_pins;

  // How many pins have been added so far. These are used as indexes when adding new pins.
  unsigned short int num_row_pins_added;
  unsigned short int num_col_pins_added;

  // 1-based row/col index of current key to check.
  unsigned short int cur_row_index; 
  unsigned short int cur_col_index; 

  // Whether or not a key is pressed. Defined here so it doesn't have to be defined in the check() function,
  // because the check() function needs to do work after setting the value, i.e. it can't just return 
  // true or false.
  bool key_is_pressed;

  // Amount of time to wait before scanning again (milliseconds).
  unsigned long debounce_time_ms;

  // Time of last keypress.
  unsigned long time_of_last_keypress;

  ////////////////////////////////////////////////////////////////////////////
  // Methods 
  //   (See .cpp file for method documentation):
  ////////////////////////////////////////////////////////////////////////////
public:

  keypad(unsigned short int in_num_rows, unsigned short int in_num_cols);
  ~keypad();
  bool check(unsigned short int & out_row_index, unsigned short int & out_col_index);
  void add_row_pin(uint8_t in_pin_num);
  void add_col_pin(uint8_t in_pin_num);
};

#endif

















