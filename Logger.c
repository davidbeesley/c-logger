
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
 #define DEBUG LogLevel::DEBUG
 #define INFO LogLevel::INFO
 #define WARNING LogLevel::WARNING
 #define ERROR LogLevel::ERROR
 #define NONE LogLevel::NONE
 */




void l_setLogLevel(LogLevel newLogLevel){
	logLevel = newLogLevel;
	//debug("Changed log level");
}


/*


   void l_newTestSuite(){
    newTestSuite("Unnamed Test Suite");
   }
   void l_newTestSuite(std:: string testSuiteName){
    if (totalTests > 0) {
        debug("Ending Previous Test Suite: %s", this->testSuiteName);
        endTestSuite();
    }
    std::transform(testSuiteName.begin(), testSuiteName.end(), testSuiteName.begin(), ::toupper);
    this->testSuiteName = testSuiteName;
   }

   void l_endTestSuite(){
    std::string color;
    if (passedTests == totalTests && passedTests > 0)
        color = KGRN;
    else
        color = KRED;

    info("%sTest Results for Test Suite: %s", color,testSuiteName);
    if (totalTests > 0) {
        info("%s%d / %d tests passed", color, passedTests, totalTests);
        if (passedTests != totalTests) {
            info("%sFailed Tests:",KRED);
            while(failedTestsQueue.empty() == false) {
                info("  - %s%s", KRED, failedTestsQueue.front());
                failedTestsQueue.pop();
            }
        }
        if (passedTests > 0)
            debug("%sPassed Tests:",KGRN);
        while(passedTestsQueue.empty() == false) {
            debug("  - %s%s", KGRN, passedTestsQueue.front());
            passedTestsQueue.pop();
        }
    }
    else {
        info("%sNo Tests Provided", color);
    }
    totalTests = 0;
    passedTests = 0;


   }

   bool l_test(bool l_passed, std::string message)
   {
    totalTests++;
    char c[MAX_BUF];
    std::string s;
    if (passed == false) {
        snprintf(c, MAX_BUF, "%s", message);
        warning("Test \"%s\" %s", message, " failed.");
        s = c;
        failedTestsQueue.push(s);

    }
    else
    {
        snprintf(c, MAX_BUF, "%s", message);
        debug("Test \"%s\" %s", message, " passed.");
        s = c;
        passedTestsQueue.push(s);
        passedTests++;
    }
    return passed;
   }

   bool l_test(bool l_passed)
   {
    return test(passed, "No Message Provided");
   }

   bool l_testInt(long actual, long expected){
    return testInt(actual, expected,  "No Message Provided");
   }
   bool l_testInt(long actual, long expected, std:: string message){
    bool l_passed = (actual == expected);
    totalTests++;
    char c[MAX_BUF];
    std::string s;
    if (passed == false) {
        snprintf(c, MAX_BUF, "%s\n\t\tActual:   %10ld\n\t\tExpected: %10ld", message, actual, expected);
        warning("Test \"%s\" %s", message, " failed.");
        s = c;
        failedTestsQueue.push(s);

    }
    else
    {
        snprintf(c, MAX_BUF, "%s", message);
        debug("Test \"%s\" %s", message, " passed.");
        s = c;
        passedTestsQueue.push(s);
        passedTests++;
    }
    return passed;

   }

   bool l_testHex(long actual, long expected){
    return testHex(actual, expected,  "No Message Provided");
   }
   bool l_testHex(long actual, long expected, std:: string message){
    bool l_passed = (actual == expected);
    totalTests++;
    char c[MAX_BUF];
    std::string s;
    if (passed == false) {
        snprintf(c, MAX_BUF, "%s\n\t\tActual:   0x%08lx\n\t\tExpected: 0x%08lx", message, actual, expected);
        warning("Test \"%s\" %s", message, " failed.");
        s = c;
        failedTestsQueue.push(s);

    }
    else
    {
        snprintf(c, MAX_BUF, "%s", message);
        debug("Test \"%s\" %s", message, " passed.");
        s = c;
        passedTestsQueue.push(s);
        passedTests++;
    }
    return passed;

   }
   bool l_testBits(long actual, long expected){
    return testBits(actual, expected,  "No Message Provided");
   }
   bool l_testBits(long actual, long expected, std:: string message){
    bool l_passed = (actual == expected);
    totalTests++;
    char c[MAX_BUF];
    std::string s;
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
        snprintf(c, MAX_BUF, "%s\n\t\tActual:   %s\n\t\tExpected: %10s", message, bitsActual, bitsExpected);
        warning("Test \"%s\" %s", message, " failed.");
        s = c;
        failedTestsQueue.push(s);

    }
    else
    {
        snprintf(c, MAX_BUF, "%s", message);
        debug("Test \"%s\" %s", message, " passed.");
        s = c;
        passedTests++;
        passedTestsQueue.push(s);
    }
    return passed;

   }


   bool l_testFloat(double actual, double expected){
    return testFloat(actual, expected,  "No Message Provided");

   }
   bool l_testFloat(double actual, double expected, std:: string message){
    bool l_passed = (actual == expected);
    totalTests++;
    char c[MAX_BUF];
    std::string s;
    if (passed == false) {
        snprintf(c, MAX_BUF, "%s\n\t\tActual:   %21.10F\n\t\tExpected: %21.10F", message, actual, expected);
        warning("Test \"%s\" %s", message, " failed.");
        s = c;
        failedTestsQueue.push(s);

    }
    else
    {
        snprintf(c, MAX_BUF, "%s", message);
        debug("Test \"%s\" %s", message, " passed.");
        s = c;
        passedTests++;
        passedTestsQueue.push(s);
    }
    return passed;


   }
   bool l_testString(std::string actual, std::string expected){
    return testString(actual, expected,  "No Message Provided");

   }
   bool l_testString(std::string actual, std::string expected, std:: string message){
    bool l_passed = (actual == expected);
    totalTests++;
    char c[MAX_BUF];
    std::string s;
    if (passed == false) {
        snprintf(c, MAX_BUF, "%s\n\t\tActual:    \"%s\"\n\t\tExpected:  \"%s\"", message, actual, expected);
        warning("Test \"%s\" %s", message, " failed.");
        s = c;
        failedTestsQueue.push(s);

    }
    else
    {
        snprintf(c, MAX_BUF, "%s", message);
        debug("Test \"%s\" %s", message, " passed.");
        s = c;
        passedTests++;
        passedTestsQueue.push(s);
    }
    return passed;

   }

 */

/* Printing Functions */

void l_log(LogLevel stringLogLevel, char *format, va_list args){


	switch (stringLogLevel) {

	case DEBUG:
		l_debug(format, args);
		break;
	case INFO:
		l_info(format, args);
		break;
	case WARNING:
		l_warning(format,args);
		break;
	case ERROR:
		l_error(format,args);
		break;
	default:
		l_error("Invalid logLevel");
	}

}


void l_debug( char *format, ...){
	va_list args;
	va_start(args, format);
	l_log(DEBUG,format, args);
	va_end(args);
}

void l_info( char *format, ...){
	va_list args;
	va_start(args, format);
	l_log(INFO,format, args);
	va_end(args);
}

void l_warning( char *format, ...){
	va_list args;
	va_start(args, format);

	l_log(WARNING,format, args);
	va_end(args);
}

void l_error( char *format, ...){
	va_list args;
	va_start(args, format);
	l_log(ERROR,format, args);
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
