#include "commandfactory.hpp"

namespace parser {

    CommandFactory::CommandFactory(filesystem::Node* workingDirectory)
        : m_workingDirectory{workingDirectory}
    {
    }

    CommandFactory::~CommandFactory()
    {

        for (auto it = m_map.begin(); it != m_map.end(); it++)
        {
            // delete all Action* fom map.
            delete it->second;
        }
        m_workingDirectory = nullptr;

    }

    filesystem::Node* CommandFactory::executeCommand(Command* cmd)
    {
        return executeCommand(std::make_shared<Command>(*cmd));
    }

    filesystem::Node* CommandFactory::executeCommand(std::shared_ptr<Command> cmd)
    {
        if (!cmd)
        {
            return m_workingDirectory;
        }

        action::Action* a = findAction(cmd->action);
        if (a)
            m_workingDirectory= a->action(m_workingDirectory, cmd->argument);

        return m_workingDirectory;
    }

    void CommandFactory::registerAction(std::string key, action::Action* value)
    {
        m_map[key] = value;
    }

    action::Action* CommandFactory::findAction(std::string action)
    {
        auto registeredAction = m_map.find(action);
        if (registeredAction == m_map.end())
        {
            std::cout << "[CommandFactory::findAction] Action not registered!\n";
            return nullptr;
        }
            return registeredAction->second;
    }

    /* Tipovi akcija:
     * dir      -> samo primi Node* i na njemu zovi print()
     * rm x     -> primi trenutni Node*, napravi delete njega
     * mkdir x  -> primi trenutni, napravi Directory s imenom x
     * mkfil x  -> primi trenutni, napravi File s imenom x
     * cd x     -> primi trenutni, pronadi ako ima dijete s imenom x i pomakni context u njega.
     */
}
