#ifndef COMMANDFACTORY_HPP
#define COMMANDFACTORY_HPP

#include <map>
#include "command.hpp"
#include "action.hpp"

namespace parser {

    class CommandFactory
    {

    public:
        CommandFactory(filesystem::Node*);

        filesystem::Node* executeCommand(Command* cmd);
        void registerAction(std::string key, action::Action* value);

    private:
        action::Action* findAction(std::string action);

    private:
        std::map<std::string, action::Action*> m_map;
        filesystem::Node* m_workingDirectory;
    };

}
#endif // COMMANDFACTORY_HPP
