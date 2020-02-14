#include "Log/log.h"
#include <iostream>

int main()
{
    Log* l = new Log("test.log", 2560, 4);
    for (int i=1; i<5; i++) {
        l->log("Test log~~", LOG_LEVEL(i));
    }
    l->logDump();
    return 0;
}
