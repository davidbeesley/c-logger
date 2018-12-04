
#include "Logger.h"


/* Our color wheel */
#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m" // Error
#define KGRN  "\x1B[32m" // Passed
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m" // Debug
#define KMAG  "\x1B[35m" // Info
#define KCYN  "\x1B[36m" // Warning
#define KWHT  "\x1B[37m"

/* LogLevel shortcuts */
/*
 #define L_DEBUG LogLevel::L_DEBUG
 #define L_INFO LogLevel::L_INFO
 #define L_WARNING LogLevel::L_WARNING
 #define L_ERROR LogLevel::L_ERROR
 #define L_NONE LogLevel::L_NONE
 */




void l_setLogLevel(LogLevel newLogLevel){
	logLevel = newLogLevel;
	//debug("Changed log level");
}


/* Printing Functions */

void l_out(LogLevel stringLogLevel, char *format, va_list args){

	if (stringLogLevel >= logLevel) {
		vprintf(format, args);
		printf("\n");
	}

}


void l_debug( char *format, ...){
	va_list args;
	va_start(args, format);
	printf(KBLU);
	l_out(L_DEBUG,format, args);
	printf(KNRM);

	va_end(args);
}

void l_info( char *format, ...){
	va_list args;
	va_start(args, format);
	l_out(L_INFO,format, args);
	va_end(args);
}

void l_warning( char *format, ...){
	va_list args;
	va_start(args, format);

	l_out(L_WARNING,format, args);
	va_end(args);
}

void l_error( char *format, ...){
	va_list args;
	va_start(args, format);
	l_out(L_ERROR,format, args);
	va_end(args);
}




void l_print( char *format, ...){


	va_list args;
	va_start(args, format);
	vprintf(format,args);
	//format = "Printed: \"" + format + "\" to stdout";
	//debug("Printed to stdout: \"%.20s...\"", format);
	va_end(args);
}

void l_printLine( char *format, ...){


	va_list args;
	va_start(args, format);
	vprintf(format,args);
	printf("\n");
	//format = "Printed Line: \"" + format + "\" to stdout";
	//debug("Printed line to stdout: \"%.20s...\"", format);
	va_end(args);
}
