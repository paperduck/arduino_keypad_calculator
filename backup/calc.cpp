// calc.cpp

#include "Arduino.h"
#include "calc.h"

//Members:
/*
	char * msg;
 	enum operator
 	{
 		add,
 		subtract,
 		multiply,
 		divide,
 		none
 	};
 	enum operator current_operator;
 	float operand_1;
 	float operand_2;
 	enum state
 	{
 		editing_first_operand,
 		editing_additional_operand,
 		editing_operator,
 		just_performed_calculation
 	};
 	enum state current_state;
 */

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
    return -0;
    break;
  default:
    return -0;
    break;
  }
}

void calculator::update_msg(float f)
{
  //sprintf(msg, "sup");
  //sprintf(msg, dtostrf(3.2, 16, 2, "World%f!\0"));
  //dtostrf(floatVar, minStringWidthIncDecimalPoint, numVarsAfterDecimal, charBuf);
  sprintf(msg, dtostrf(f, 16, 2, "%f\0"));
}

void calculator::update_msg(const char * s)
{
  sprintf(msg, "%15s%c", s, '\0');
}

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
    break;
  default:
    update_msg("ERROR");
    break;
  }
}

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
    break;
  default:
    update_msg("ERROR");
    break;
  }
}

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
    break;
  default:
    update_msg("ERROR");
    break;
  }
}

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
    break;
  default:
    update_msg("ERROR");
    break;
  }
}

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
    break;
  default:
    update_msg("ERROR");
    break;
  }
}

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
    break;
  default:
    update_msg("ERROR");
    break;
  }
}

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
    break;
  default:
    update_msg("ERROR");
    break;
  }
}

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
    break;
  default:
    update_msg("ERROR");
    break;
  }
}

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
    break;
  default:
    update_msg("ERROR");
    break;
  }
}

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
    break;
  default:
    update_msg("ERROR");
    break;
  }
}

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
    operand_1 = do_calculation();
    // start at beginning of cycle
    current_operator = none;
    break;
  default:
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
    update_msg("ERROR");
    current_state = editing_first_operand;
    current_operator = none;
    break;
  }

  current_state = just_performed_calculation;
}













