#include "server/TSCachedServer.h"


int main() {
    std::string addr("127.0.0.1:50000");
    TSCached::TSCachedServer server(addr);
    server.Run();
}
