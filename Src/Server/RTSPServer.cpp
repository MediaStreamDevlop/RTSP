#include <RTSPServer.h>

int main(int argc, char** argv)
{
    Log log = new Log(LOG_INFO);
    log.append("Server init~");

    //Common init
    
    //ENV init

    //Start
    RTSPServer Server = new RTSPServer(args);
    Server.start();
}
