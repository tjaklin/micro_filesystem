#include "acreatedirectory.hpp"

namespace action {

    filesystem::Node* ACreateDirectory::action(filesystem::Node* context, std::string arg)
    {
        // Try casting context to Directory*, as only a Directory* can
        // execute this action!

        filesystem::Directory* currentDirectory = dynamic_cast<filesystem::Directory*>(context);
        if (!currentDirectory)
        {
            std::cout << "[ACreateDirectory::action] Cast failed!";
            return context;
        }

        return currentDirectory->addChild(new filesystem::Directory(arg));
    }
}
