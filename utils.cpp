#include <string>
#include "utils.h"

// UTIL METHODS //
// Returns true if s is a number else false 
bool isNumber(std::string s) 
{ 
    for (int i = 0; (unsigned)i < s.length(); i++) 
        if (isdigit(s[i]) == false) 
            return false; 
  
    return true; 
} 