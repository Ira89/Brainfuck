#include "BrainfuckInterpreter.h"

int main(){

    std::cout << "Example 1:" << std::endl;
    std::string str = ";+:"; // increment
    BrainfuckInterpreter simpleStr(str);
    simpleStr.parseCommand();

    std::cout << std::endl << "Example 2:" << std::endl;
    str = ";>;<[->+<]>:"; // sum
    BrainfuckInterpreter middlingStr(str);
    middlingStr.parseCommand();

    std::cout << std::endl << "Example 3:" << std::endl;
    str = ";[>+>>+<<<-]>>>[>+<<++>--]<<[>-<-]>[>>->+<<<-]>>:>:"; // division by 2 with a remainder
    BrainfuckInterpreter hardStr(str);
    hardStr.parseCommand();

    return 0;
}
