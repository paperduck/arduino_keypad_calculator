/*
Calculator class
 
 Purpose:
 	Takes in keystrokes and outputs a string to display
 	Functions as a simple calculator that takes a maximum of two operands and one operator.
 	Several operands can be entered, stringed together, but will be processed as soon as
 	a pair is entered, left-to-right, with
 	no order or operations. 
 
 
 */

#include "Arduino.h"

class calculator
{
  //Members:
private:
  //text to show on-screen
  char msg[17];

  // mathematical operator to perform
  enum math_operator
  {
    add,
    subtract,
    multiply,
    divide,
    none
  };
  // current operator to use in calculations
  enum math_operator current_operator;

  // left-side operand
  // When chaining operations, previous results are stored here.
  float operand_1;

  // Right-hand operand
  float operand_2;

  // State
  enum state
  {
    editing_first_operand,
    editing_additional_operand,
    editing_operator,
    just_performed_calculation
  };

  enum state current_state;

  //Methods:
private:
public:
  // Constructor
  calculator();

  // Call this function to get the text to show on-screen.
  char * get_output();

  // return result of (operand 1 [operation] operand 2)
  float do_calculation();

  // edit the internal string msg
  void update_msg(float);
  void update_msg(const char *);

  // Button functions
  // These should be called whenever a button is pressed in the calling program.
  void btn_0();
  void btn_1();
  void btn_2();
  void btn_3();
  void btn_4();
  void btn_5();
  void btn_6();
  void btn_7();
  void btn_8();
  void btn_9();
  void btn_cycle_operator();
  void btn_equals();

};

