#include <stdarg.h>
#include <stdio.h>

#ifndef LOGGER_H_
#define LOGGER_H_



typedef enum {DEBUG, INFO, WARNING, ERROR, NONE}  LogLevel;





void l_setLogLevel(LogLevel newLogLevel);


// log functions
void l_debug( char *format, ...);
void l_info( char *format, ...);
void l_warning( char *format, ...);
void l_error( char *format, ...);
void l_log(LogLevel stringLogLevel,  char *format, va_list args);




// Output to stdout and keep record in log
void l_print( char *format, ...);
void l_printLine( char *format, ...);



LogLevel logLevel;









#endif // LOGGER_H_
