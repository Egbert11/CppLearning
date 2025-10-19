#include <string>
#include "common.h"

void variable()
{
    bool b = true;
    std::string msg = std::string("bool: ") + (b ? "true" : "false") + ", sizeof bool: " + std::to_string(sizeof(b));
    Log(msg.c_str());
    char ch = 'A';
    msg = std::string("char: ") + ch + ", sizeof char: " + std::to_string(sizeof(ch));
    Log(msg.c_str());
    short sh = 12345;
    msg = std::string("short: ") + std::to_string(sh) + ", sizeof short: " + std::to_string(sizeof(sh));
    Log(msg.c_str());
    int i = 123456789;
    msg = std::string("int: ") + std::to_string(i) + ", sizeof int: " + std::to_string(sizeof(i));
    Log(msg.c_str());
    long l = 1234567890L;
    msg = std::string("long: ") + std::to_string(l) + ", sizeof long: " + std::to_string(sizeof(l));
    Log(msg.c_str());
    float f = 3.14f;
    msg = std::string("float: ") + std::to_string(f) + ", sizeof float: " + std::to_string(sizeof(f));
    Log(msg.c_str());
    double d = 3.141592653589793;
    msg = std::string("double: ") + std::to_string(d) + ", sizeof double: " + std::to_string(sizeof(d));
    Log(msg.c_str());
}