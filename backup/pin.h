
// Keypad class (C++) that monitors a matrix circuit of x rows and y columns.
/*
Example usage:
 
 	keypad = new Keypad(4, 3, true);
 	unsigned short int row_index;
 	unsigned short int col_index;
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

// Struct that contains information about each pin
struct keypad_pin
{
  unsigned short int pin_num; // e.g. A1
  boolean isAnalog;
  //boolean isRow;
};


class keypad
{
  //Members:
private:
  // Number of rows and columns in keypad.
  unsigned short int num_rows;
  unsigned short int num_cols;

  // If true, voltage is sent into rows and columns are read as output.
  // Otherwise, cols are input and rows are output.
  boolean use_row_input;

  // List of row and column pins.
  // Allows user to treat digital pins and analog pins the same (as digital).
  //  User is responsible for adding pin numbers to this list.
  keypad_pin row_pins[];
  keypad_pin col_pins[];

  // How many pins have been "initialized" so far.
  // These are also used as indexes when adding new pins.
  int num_row_pins_added;
  int num_col_pins_added;

  // 1-based row/col index of current key to check.
  unsigned short int cur_row_index; 
  unsigned short int cur_col_index; 

  // Methods (See implementation code file for documentation notes):
public:

  keypad(unsigned short int in_num_rows, unsigned short int in_num_cols, boolean in_use_row_input);
  ~keypad();
  boolean check(unsigned short int & rowIndex, unsigned short int & colIndex);
  void add_row_pin(unsigned short int pin_num, boolean is_digital);
  void add_col_pin(unsigned short int pin_num, boolean is_digital);
  //  void increment_key_indexes();
  //  boolean is_analog();


};



















