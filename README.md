# c-logger
Simple logger and test package for debugging c projects.

## One way to include in your project
wget https://raw.githubusercontent.com/davidbeesley/c-logger/master/Logger.c
wget https://raw.githubusercontent.com/davidbeesley/c-logger/master/Logger.h

## Usage
logging functions take same format as printf and automatically print a new line.
```c
l_debug(char * format, ...)
l_info(char * format, ...)
l_warning(char * format, ...)
l_error(char * format, ...)
l_println(char * format, ...)
// The only one that doesn't print an automatic newline.
l_print(char * format, ...)
```

testing functions
