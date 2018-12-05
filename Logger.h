#include <stdarg.h>
#include <stdio.h>
#include <stdbool.h>

#ifndef LOGGER_H_
#define LOGGER_H_



// Possible logging levels
typedef enum {L_DEBUG, L_INFO, L_WARNING, L_ERROR, L_NONE}  LogLevel;




// Default value is L_WARNING
void l_setLogLevel(LogLevel newLogLevel);


// log functions
void l_debug( char *format, ...);
void l_info( char *format, ...);
void l_warning( char *format, ...);
void l_error( char *format, ...);
void l_out(char *format, va_list args);

// Print functions
void l_print( char *format, ...);
// The only one that doesn't print an automatic newline.
void l_println( char *format, ...);

// Testing functions
bool l_test(bool passed, char * message);
bool l_testInt(long actual, long expected, char * message);
bool l_testHex(long actual, long expected, char * message);
bool l_testBits(long actual, long expected, char * message);
bool l_testFloat(double actual, double expected, char * message);
bool l_testString(char * actual, char * expected, char * message);

// Keeps track of the current logging level. default is L_WARNING
LogLevel logLevel;









#endif // LOGGER_H_
