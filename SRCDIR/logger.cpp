#include <stdarg.h> 
#include <stdio.h>
#include "logger.h"
#include <string>
#include <iostream>
using namespace std;

   #include <wx/wx.h>


Logger::Logger()
{
}

Logger::~Logger()
{
}

void Logger::log(const char *formatstring, ...) 
{
   int nSize = 0;
   char buff[4096];
   memset(buff, 0, sizeof(buff));
   va_list args;
   va_start(args, formatstring);
   nSize = vsnprintf( buff, sizeof(buff) - 1, formatstring, args);

   wxLogMessage(buff);
}
