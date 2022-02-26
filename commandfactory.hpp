#ifndef COMMANDFACTORY_HPP
#define COMMANDFACTORY_HPP

#include <map>
#include "command.hpp"
#include "action.hpp"
#include <memory>

namespace parser {

    class CommandFactory
    {

    public:
        CommandFactory(filesystem::Node*);
        ~CommandFactory();

        filesystem::Node* executeCommand(Command* cmd);
        filesystem::Node* executeCommand(std::shared_ptr<Command> cmd);
        void registerAction(std::string key, action::Action* value);

    private:
        action::Action* findAction(std::string action);

    private:
        std::map<std::string, action::Action*> m_map;
        filesystem::Node* m_workingDirectory;
    };

}
#endif // COMMANDFACTORY_HPP
