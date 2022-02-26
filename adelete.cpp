#include "adelete.hpp"

namespace action {

    filesystem::Node* ADelete::action(filesystem::Node* context, std::string arg)
    {
        filesystem::Directory* currentDirectory = dynamic_cast<filesystem::Directory*>(context);
        if (!currentDirectory)
        {
            std::cout << "[ADelete::action] Cast failed!";
            return context;
        }
        return currentDirectory->deleteChild(arg);
    }
}
