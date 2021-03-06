/*
Class: pin
*/

#include "Arduino.h"
#include "pin.h"

///////////////////////////////////////////////////////////////////////
// Constructor
///////////////////////////////////////////////////////////////////////
pin::pin()
{
  return; 
}

///////////////////////////////////////////////////////////////////////
// Constructor
///////////////////////////////////////////////////////////////////////
pin::pin(uint8_t in_pin_num)
{
  pin_num = in_pin_num;
  //is_digital = in_is_digital;
  return;
}

///////////////////////////////////////////////////////////////////////
// Deconstructor
///////////////////////////////////////////////////////////////////////
pin::~pin()
{
  return;
}

///////////////////////////////////////////////////////////////////////
// Purpose:
//   Get pin number 
//////////////////////////////////////////////////////////////////////
uint8_t pin::get_pin_num()
{
  return pin_num;
}

///////////////////////////////////////////////////////////////////////
// Purpose:
//   Set pin number 
//////////////////////////////////////////////////////////////////////
void pin::set_pin_num(uint8_t in_pin_num)
{
  pin_num = in_pin_num;
  return;
}



