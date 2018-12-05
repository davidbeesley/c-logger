# c-logger
Simple logger and test package for debugging c projects.

## Easest way to include in your project
```
wget https://raw.githubusercontent.com/davidbeesley/c-logger/master/Logger.c
wget https://raw.githubusercontent.com/davidbeesley/c-logger/master/Logger.h
```
## Usage

### Logging functions
logging functions take same format as printf and automatically print a new line.

set logging level with `l_setLogLevel`

output uses terminal colors, so it won't look very good using a program like less (unless you use the -R flag)
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

### Example
```c
#include "Logger.h"

int main()
{
	l_setLogLevel(L_DEBUG);
	l_debug("Sample Debug: %d", 5);
	l_info("Sample Info: %d", 5);
	l_warning("Sample Warning: %d", 5);
	l_error("Sample Error: %d", 5);
	l_test(true, "Passed test example");
	l_test(false, "Failed test example");
	l_testInt(1,2, "Failed int test example");
	l_testInt(2,2, "Passed int test example");
	l_testHex(-11,2, "Failed hex test example");
	l_testHex(-11,-11, "Passed hex test example");
	l_testBits(-11,2, "Failed bits test example");
	l_testBits(-11,-11, "Passed bits test example");
	l_testFloat(-11,-11.3, "Failed float test example");
	l_testFloat(-11.2,-11.2, "Passed float test example");
	l_testString("hi", "hi", "Passed string test example");
	l_testString("hi", "hi five", "Failed string test example");
}
```
