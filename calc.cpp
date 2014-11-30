// calc.cpp

#include "Arduino.h"
#include "calc.h"


///////////////////////////////////////////////////////////////////////
// Purpose:
//   Constructor.
///////////////////////////////////////////////////////////////////////
calculator::calculator()
{
  sprintf(msg, "CALCULATOR\0");
  operand_1 = 0;
  operand_2 = 0;
  current_operator = none;
  current_state = editing_first_operand;
}

char * calculator::get_output()
{
  return msg;	
}

float calculator::do_calculation()
{
  switch(current_operator)
  {
  case add:
    return (operand_1 + operand_2);
    break;
  case subtract:
    return (operand_1 - operand_2);
    break;
  case multiply:
    return (operand_1 * operand_2);
    break;
  case divide:
    return (operand_1 / operand_2);
    break;
  case none:
    return operand_1;
    break;
  default:
    return -1;
    break;
  }
}


///////////////////////////////////////////////////////////////////////
// Purpose:
//   Take a number and store it as the string that will appear on-screen.
///////////////////////////////////////////////////////////////////////
void calculator::update_msg(float f)
{
  // The Arduino (AVR compiler) can't convert a float to string using the 
  // standard library sprintf() function, so use the AVR-specific dtostrf()
  // function to convert and format. 
  // Might be able to remove sprintf() and just use dtostrf by itself.
  sprintf(msg, dtostrf(f, 16, 2, "%f\0"));
}

///////////////////////////////////////////////////////////////////////
// Purpose:
//   Update string value that will appear on-screen.
///////////////////////////////////////////////////////////////////////
void calculator::update_msg(const char * s)
{
  sprintf(msg, "%15s%c", s, '\0');
}

///////////////////////////////////////////////////////////////////////
// Purpose:
//   Button 0 is being pressed.
///////////////////////////////////////////////////////////////////////
void calculator::btn_0()
{
  switch(current_state)
  {
  case editing_first_operand:
    operand_1 = (operand_1 * 10);
    update_msg(operand_1);
    break;
  case editing_additional_operand:
    operand_2 = (operand_2 * 10);
    update_msg(operand_2);
    break;
  case editing_operator:
    operand_2 = 0;
    update_msg(operand_2);
    current_state = editing_additional_operand;
    break;
  case just_performed_calculation:
    operand_1 = 0;
    update_msg(operand_1);
    current_state = editing_first_operand;
    current_operator = none;
    break;
  default:
    update_msg("ERROR:calc0");
    break;
  }
}

///////////////////////////////////////////////////////////////////////
// Purpose:
//   Button 1 is being pressed.
///////////////////////////////////////////////////////////////////////
void calculator::btn_1()
{
  switch(current_state)
  {
  case editing_first_operand:
    operand_1 = (operand_1 * 10) + 1;
    update_msg(operand_1);
    break;
  case editing_additional_operand:
    operand_2 = (operand_2 * 10) + 1;
    update_msg(operand_2);
    break;
  case editing_operator:
    operand_2 = 1;
    update_msg(operand_2);
    current_state = editing_additional_operand;
    break;
  case just_performed_calculation:
    operand_1 = 1;
    update_msg(operand_1);
    current_state = editing_first_operand;
    current_operator = none;
    break;
  default:
    update_msg("ERROR:calc1");
    break;
  }
}

///////////////////////////////////////////////////////////////////////
// Purpose:
//   Button 2 is being pressed.
///////////////////////////////////////////////////////////////////////
void calculator::btn_2()
{
  switch(current_state)
  {
  case editing_first_operand:
    operand_1 = (operand_1 * 10) + 2;
    update_msg(operand_1);
    break;
  case editing_additional_operand:
    operand_2 = (operand_2 * 10) + 2;
    update_msg(operand_2);
    break;
  case editing_operator:
    operand_2 = 2;
    update_msg(operand_2);
    current_state = editing_additional_operand;
    break;
  case just_performed_calculation:
    operand_1 = 2;
    update_msg(operand_1);
    current_state = editing_first_operand;
    current_operator = none;
    break;
  default:
    update_msg("ERROR:calc2");
    break;
  }
}

///////////////////////////////////////////////////////////////////////
// Purpose:
//   Button 3 is being pressed.
///////////////////////////////////////////////////////////////////////
void calculator::btn_3()
{
  switch(current_state)
  {
  case editing_first_operand:
    operand_1 = (operand_1 * 10) + 3;
    update_msg(operand_1);
    break;
  case editing_additional_operand:
    operand_2 = (operand_2 * 10) + 3;
    update_msg(operand_2);
    break;
  case editing_operator:
    operand_2 = 3;
    update_msg(operand_2);
    current_state = editing_additional_operand;
    break;
  case just_performed_calculation:
    operand_1 = 3;
    update_msg(operand_1);
    current_state = editing_first_operand;
    current_operator = none;
    break;
  default:
    update_msg("ERROR:calc3");
    break;
  }
}

///////////////////////////////////////////////////////////////////////
// Purpose:
//   Button 4 is being pressed.
///////////////////////////////////////////////////////////////////////
void calculator::btn_4()
{
  switch(current_state)
  {
  case editing_first_operand:
    operand_1 = (operand_1 * 10) + 4;
    update_msg(operand_1);
    break;
  case editing_additional_operand:
    operand_2 = (operand_2 * 10) + 4;
    update_msg(operand_2);
    break;
  case editing_operator:
    operand_2 = 4;
    update_msg(operand_2);
    current_state = editing_additional_operand;
    break;
  case just_performed_calculation:
    operand_1 = 4;
    update_msg(operand_1);
    current_state = editing_first_operand;
    current_operator = none;
    break;
  default:
    update_msg("ERROR:calc4");
    break;
  }
}

///////////////////////////////////////////////////////////////////////
// Purpose:
//   Button 5 is being pressed.
///////////////////////////////////////////////////////////////////////
void calculator::btn_5()
{
  switch(current_state)
  {
  case editing_first_operand:
    operand_1 = (operand_1 * 10) + 5;
    update_msg(operand_1);
    break;
  case editing_additional_operand:
    operand_2 = (operand_2 * 10) + 5;
    update_msg(operand_2);
    break;
  case editing_operator:
    operand_2 = 5;
    update_msg(operand_2);
    current_state = editing_additional_operand;
    break;
  case just_performed_calculation:
    operand_1 = 5;
    update_msg(operand_1);
    current_state = editing_first_operand;
    current_operator = none;
    break;
  default:
    update_msg("ERROR:calc5");
    break;
  }
}

///////////////////////////////////////////////////////////////////////
// Purpose:
//   Button 6 is being pressed.
///////////////////////////////////////////////////////////////////////
void calculator::btn_6()
{
  switch(current_state)
  {
  case editing_first_operand:
    operand_1 = (operand_1 * 10) + 6;
    update_msg(operand_1);
    break;
  case editing_additional_operand:
    operand_2 = (operand_2 * 10) + 6;
    update_msg(operand_2);
    break;
  case editing_operator:
    operand_2 = 6;
    update_msg(operand_2);
    current_state = editing_additional_operand;
    break;
  case just_performed_calculation:
    operand_1 = 6;
    update_msg(operand_1);
    current_state = editing_first_operand;
    current_operator = none;
    break;
  default:
    update_msg("ERROR:calc6");
    break;
  }
}

///////////////////////////////////////////////////////////////////////
// Purpose:
//   Button 7 is being pressed.
///////////////////////////////////////////////////////////////////////
void calculator::btn_7()
{
  switch(current_state)
  {
  case editing_first_operand:
    operand_1 = (operand_1 * 10) + 7;
    update_msg(operand_1);
    break;
  case editing_additional_operand:
    operand_2 = (operand_2 * 10) + 7;
    update_msg(operand_2);
    break;
  case editing_operator:
    operand_2 = 7;
    update_msg(operand_2);
    current_state = editing_additional_operand;
    break;
  case just_performed_calculation:
    operand_1 = 7;
    update_msg(operand_1);
    current_state = editing_first_operand;
    current_operator = none;
    break;
  default:
    update_msg("ERROR:calc7");
    break;
  }
}

///////////////////////////////////////////////////////////////////////
// Purpose:
//   Button 8 is being pressed.
///////////////////////////////////////////////////////////////////////
void calculator::btn_8()
{
  switch(current_state)
  {
  case editing_first_operand:
    operand_1 = (operand_1 * 10) + 8;
    update_msg(operand_1);
    break;
  case editing_additional_operand:
    operand_2 = (operand_2 * 10) + 8;
    update_msg(operand_2);
    break;
  case editing_operator:
    operand_2 = 8;
    update_msg(operand_2);
    current_state = editing_additional_operand;
    break;
  case just_performed_calculation:
    operand_1 = 8;
    update_msg(operand_1);
    current_state = editing_first_operand;
    current_operator = none;
    break;
  default:
    update_msg("ERROR:calc8");
    break;
  }
}

///////////////////////////////////////////////////////////////////////
// Purpose:
//   Button 9 is being pressed.
///////////////////////////////////////////////////////////////////////
void calculator::btn_9()
{
  switch(current_state)
  {
  case editing_first_operand:
    operand_1 = (operand_1 * 10) + 9;
    update_msg(operand_1);
    break;
  case editing_additional_operand:
    operand_2 = (operand_2 * 10) + 9;
    update_msg(operand_2);
    break;
  case editing_operator:
    operand_2 = 9;
    update_msg(operand_2);
    current_state = editing_additional_operand;
    break;
  case just_performed_calculation:
    operand_1 = 9;
    update_msg(operand_1);
    current_state = editing_first_operand;
    current_operator = none;
    break;
  default:
    update_msg("ERROR:calc9");
    break;
  }
}

///////////////////////////////////////////////////////////////////////
// Purpose:
//   Button "cycle operator" is being pressed.
///////////////////////////////////////////////////////////////////////
void calculator::btn_cycle_operator()
{
  switch(current_state)
  {
  case editing_first_operand:
    // start at beginning of cycle
    current_operator = none;
    break;
  case editing_additional_operand:
    // Chain calculations together; store running result in operand_1
    operand_1 = do_calculation();
    // start at beginning of cycle
    current_operator = none;
    break;
  case editing_operator:
    // Do nothing; continue cycling the operator
    break;
  case just_performed_calculation:
    // Chain calculations together; store running result in operand_1
    // start at beginning of cycle
    current_operator = none;
    break;
  default:
    update_msg("ERROR:calcOP");
    break;
  }   

  switch(current_operator)
  {
  case add:
    current_operator = subtract;
    update_msg("-");
    break;
  case subtract:
    current_operator = multiply;
    update_msg("x");
    break;
  case multiply:
    current_operator = divide;
    update_msg("/");
    break;
  case divide:
    current_operator = add;
    update_msg("+");
    break;
  case none:
    current_operator = add;
    update_msg("+");
    break;
  default:
    current_operator = divide;
    update_msg("!!!");
    break;
  }

  // Set state
  current_state = editing_operator;
}


///////////////////////////////////////////////////////////////////////
// Purpose:
//   Button "equals" is being pressed.
///////////////////////////////////////////////////////////////////////
void calculator::btn_equals()
{
  switch(current_state)
  {
  case editing_first_operand:
    update_msg(operand_1);
    current_state = just_performed_calculation;
    break;
  case editing_additional_operand:
    operand_1 = do_calculation();
    update_msg(operand_1);
    current_state = just_performed_calculation;
    break;
  case editing_operator:
    current_state = just_performed_calculation;
    update_msg(operand_1);
    break;
  case just_performed_calculation:
    operand_1 = do_calculation();
    update_msg(operand_1);
    break;
  default:
    update_msg("ERROR:calcEQ");
    current_state = editing_first_operand;
    current_operator = none;
    break;
  }

  current_state = just_performed_calculation;
}













