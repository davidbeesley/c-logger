#include "Logger.h"


int main()
{
	l_setLogLevel(L_DEBUG);
	l_debug("Sample Debug: %d", 5);
	l_info("Sample Info: %d", 5);
	l_warning("Sample Warning: %d", 5);
	l_error("Sample Error: %d", 5);



}
