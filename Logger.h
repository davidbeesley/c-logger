#include <stdarg.h>
#include <stdio.h>
#include <stdbool.h>

#ifndef LOGGER_H_
#define LOGGER_H_



typedef enum {L_DEBUG, L_INFO, L_WARNING, L_ERROR, L_NONE}  LogLevel;





void l_setLogLevel(LogLevel newLogLevel);


// log functions
void l_debug( char *format, ...);
void l_info( char *format, ...);
void l_warning( char *format, ...);
void l_error( char *format, ...);
void l_out(LogLevel stringLogLevel,  char *format, va_list args);


// Output to stdout and keep record in log
void l_print( char *format, ...);
void l_printLine( char *format, ...);

// Testing functions
bool l_test(bool passed, char * message);
bool l_testInt(long actual, long expected, char * message);
bool l_testHex(long actual, long expected, char * message);
bool l_testBits(long actual, long expected, char * message);
bool l_testFloat(double actual, double expected, char * message);
bool l_testString(char * actual, char * expected, char * message);
LogLevel logLevel;









#endif // LOGGER_H_
