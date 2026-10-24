#ifndef __LOGGERH__
#define __LOGGERH__

#include <string>
using namespace std;

class Logger
{
public:
   Logger();
   ~Logger();

   //void log(const char *str);
   void log(const char *formatstring, ...);

private:

};

#endif
