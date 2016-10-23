//
//  Die.hpp
//

#pragma once

#include <stdlib.h>     /* rand */
#include <random> /* for mindstd_rand0 */

class Die {
public:
   Die() { roll(); }
   void roll() {
      faceValue = rand() % MAX_FACE_VALUE + 1;
   }
   
   // copy constructor
   Die(Die& die) { faceValue = die.getFaceValue(); }
   
   // assignment operator
   Die& operator=(const Die& d) {
      if (this != &d) { // avoid self-assignment
         faceValue = d.faceValue;
      }
      return *this;
   }
   
   // accessor
   int getFaceValue() {
      return faceValue;
   }
private:
   const int MAX_FACE_VALUE = 6;
   int faceValue;
};