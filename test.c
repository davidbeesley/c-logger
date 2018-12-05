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
