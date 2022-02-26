#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <iostream>
#include <string>

namespace parser {

    class Command
    {
    public:
        Command(std::string cmd);

    public:
        std::string action;
        std::string argument;
    };

}
#endif // COMMAND_HPP
