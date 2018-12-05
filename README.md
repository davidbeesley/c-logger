# c-logger
Simple logger and test package for debugging c projects.

## One way to include in your project
```
wget https://raw.githubusercontent.com/davidbeesley/c-logger/master/Logger.c
wget https://raw.githubusercontent.com/davidbeesley/c-logger/master/Logger.h
```
## Usage

### Logging functions
logging functions take same format as printf and automatically print a new line.
set logging level with `l_setLogLevel`
```c

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

```
### Testing functions
```c
// Testing functions
bool l_test(bool passed, char * message);
bool l_testInt(long actual, long expected, char * message);
bool l_testHex(long actual, long expected, char * message);
bool l_testBits(long actual, long expected, char * message);
bool l_testFloat(double actual, double expected, char * message);
bool l_testString(char * actual, char * expected, char * message);
```
