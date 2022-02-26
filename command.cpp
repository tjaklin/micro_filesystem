#include "command.hpp"

namespace parser {

    Command::Command(std::string cmd)
    {
        for (std::string::size_type i = 0; i < cmd.size(); i++)
        {
            if (cmd[i] == ' ')
            {
                // split
                action = cmd.substr(0, i);
                argument = cmd.substr(i+1, cmd.size()-i+1);

                // debug print
                return;
            }
        }
        action = cmd;
    }
}
