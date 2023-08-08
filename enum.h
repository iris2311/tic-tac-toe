#include <string>

enum player{O=0,X=1, e=2};

static const char *enum_string[] = { "O", "X", "e" };

std::string convert_to_enum (int tmp){

    std::string MyStr(enum_string[tmp]);
    return MyStr;
}
