#ifndef pin_h
#define pin_h

#include <inttypes.h>

///////////////////////////////////////////////////////////////////////
// Class pin
//   
// Remarks:
//   This was going to be a struct, but it's easier to maintain an array of classes
///////////////////////////////////////////////////////////////////////
class pin
{
  ///////////////////////////////////////////////////////////////////////
  // Members
  ///////////////////////////////////////////////////////////////////////
private: 
  // Pin number.
  // Example: A1, A0, 4.
  uint8_t pin_num; 

  ///////////////////////////////////////////////////////////////////////
  //Methods
  ///////////////////////////////////////////////////////////////////////
public:
  pin();
  pin(uint8_t in_pin_num);
  ~pin();

  uint8_t get_pin_num();
  void set_pin_num(uint8_t);
};

#endif







