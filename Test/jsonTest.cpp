#include "Json/json.h"
#include <iostream>

int main()
{
    Json::Value data;
    data["name"] = "zhang";
    data["value"] = 27;

    std::cout << data["name"].asString() << std::endl;
    return 0;
}
