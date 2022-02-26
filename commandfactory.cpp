#include "commandfactory.hpp"

namespace parser {

    CommandFactory::CommandFactory(filesystem::Node* workingDirectory)
        : m_workingDirectory{workingDirectory}
    {
    }

    filesystem::Node* CommandFactory::executeCommand(Command* cmd)
    {
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
