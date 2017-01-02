// Final Project Milestone 4
// ErrorMessage class
// File ErrorMessage.h
// Version 1.0
// Date 2015/08/07
// Author Fardad Soleimanloo
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
// Fardad             2015/08/07           Preliminary release
/////////////////////////////////////////////////////////////////
#ifndef __244_ERRORMESSAGE_H__
#define __244_ERRORMESSAGE_H__
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class ErrorMessage {

  char _message[81];

public:
  ErrorMessage();
  virtual ~ErrorMessage();
  void clear();
  bool isClear()const;
  void message(const char* value);
  const char* message()const;
};

std::ostream& operator<<(std::ostream& os, const ErrorMessage& M);

#endif

