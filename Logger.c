
#include "Logger.h"
#include <string.h>

/* Our color wheel */
#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m" // Error
#define KGRN  "\x1B[32m" // Passed
#define KYEL  "\x1B[33m" // Warning
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m" // Info
#define KCYN  "\x1B[36m" // Debug
#define KWHT  "\x1B[37m"

LogLevel logLevel = L_WARNING;

void l_setLogLevel(LogLevel newLogLevel){
	logLevel = newLogLevel;
	//debug("Changed log level");
}

/* Printing Functions */

void l_out(char *format, va_list args){

	vprintf(format, args);
	printf("\n");


}


void l_debug( char *format, ...){
	if (logLevel <= L_DEBUG) {
		va_list args;
		va_start(args, format);
		printf(KCYN);
		printf("[DEBUG]   ");
		l_out(format, args);
		printf(KNRM);

		va_end(args);
	}
}

void l_info( char *format, ...){
	if (logLevel <= L_INFO) {

		va_list args;
		va_start(args, format);
		printf(KMAG);
		printf("[INFO]    ");
		l_out(format, args);
		printf(KNRM);
		va_end(args);
	}
}

void l_warning( char *format, ...){
	if (logLevel <= L_WARNING) {

		va_list args;
		va_start(args, format);
		printf(KYEL);
		printf("[WARNING] ");
		l_out(format, args);
		printf(KNRM);
		va_end(args);
	}
}

void l_error( char *format, ...){
	if (logLevel <= L_ERROR) {

		va_list args;
		va_start(args, format);
		printf(KRED);
		printf("[ERROR]   ");
		l_out(format, args);
		printf(KNRM);
		va_end(args);
	}
}

void l_print( char *format, ...){


	va_list args;
	va_start(args, format);
	vprintf(format,args);
	//format = "Printed: \"" + format + "\" to stdout";
	//debug("Printed to stdout: \"%.20s...\"", format);
	va_end(args);
}

void l_println( char *format, ...){


	va_list args;
	va_start(args, format);
	vprintf(format,args);
	printf("\n");
	//format = "Printed Line: \"" + format + "\" to stdout";
	//debug("Printed line to stdout: \"%.20s...\"", format);
	va_end(args);
}

// Testing functions

bool l_test(bool passed, char * message){

	if (passed == false) {
		l_warning("%sTest \"%s\" %s", KRED, message, " failed.", KNRM);

	}
	else
	{
		l_debug("%sTest \"%s\" %s%s",KGRN, message, " passed.", KNRM);

	}
	return passed;
}

bool l_testInt(long actual, long expected, char * message){
	bool passed = (actual == expected);
	if (passed == false) {
		l_warning("%sTest \"%s\" %s\n\t\tActual:   %10ld\n\t\tExpected: %10ld%s", KRED, message, " failed.",actual, expected, KNRM);

	}
	else
	{
		l_debug("%sTest \"%s\" %s%s", KGRN, message, " passed.", KNRM);

	}
	return passed;

}

bool l_testHex(long actual, long expected, char * message){
	bool passed = (actual == expected);
	if (passed == false) {
		l_warning("%sTest \"%s\" %s\n\t\tActual:   0x%015lx\n\t\tExpected: 0x%016lx%s", KRED, message, " failed.",actual, expected, KNRM);

	}
	else
	{
		l_debug("%sTest \"%s\" %s%s", KGRN, message, " passed.", KNRM);

	}
	return passed;

}

bool l_testBits(long actual, long expected, char * message){
	bool passed = (actual == expected);

	if (passed == false) {
		char bitsActual[64+8];
		char bitsExpected[64+8];

		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 9; j++) {
				int index = 9 * i + j;
				if (j == 8) {
					if (i != 7) {
						bitsActual[index] = ' ';
						bitsExpected[index] = ' ';
					}
					else {
						bitsActual[index] = 0;
						bitsExpected[index] = 0;
					}
				}
				else {
					int shift = 63 - (8 * i + j);
					int actualBit = (actual >> shift) & 1;
					int expectedBit = (expected >> shift) & 1;
					bitsActual[index] = actualBit ? '1' : '0';
					bitsExpected[index] = expectedBit ? '1' : '0';
				}
			}

		}
		//snprintf(c, MAX_BUF, "%s\n\t\tActual:   %s\n\t\tExpected: %10s", message.c_str(), bitsActual, bitsExpected);
		l_warning("%sTest \"%s\" %s\n\t\tActual:   %s\n\t\tExpected: %10s",KRED, message, " failed.", bitsActual, bitsExpected, KNRM);


	}
	else
	{
		l_debug("%sTest \"%s\" %s%s", KGRN, message, " passed.", KNRM);

	}
	return passed;

}

bool l_testFloat(double actual, double expected, char * message){
	bool passed = (actual == expected);



	if (passed == false) {
		l_warning("%sTest \"%s\" %s\n\t\tActual:   %21.10F\n\t\tExpected: %21.10F", KRED, message, " failed.",actual, expected, KNRM);

	}
	else
	{
		l_debug("%sTest \"%s\" %s%s", KGRN, message, " passed.", KNRM);

	}
	return passed;

}

bool l_testString(char * actual, char * expected, char * message){
	int compare = strcmp(actual, expected);
	bool passed = (compare == 0);


	if (passed == false) {
		//snprintf(c, MAX_BUF, "%s\n\t\tActual:    \"%s\"\n\t\tExpected:  \"%s\"", message.c_str(), actual.c_str(), expected.c_str());
		l_warning("%sTest \"%s\" %s\n\t\tActual:    \"%s\"\n\t\tExpected:  \"%s\"%s", KRED, message, " failed.", actual, expected,KNRM);


	}
	else
	{
		l_debug("%sTest \"%s\" %s%s", KGRN, message, " passed.", KNRM);

	}
	return passed;

}
