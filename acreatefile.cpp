#include "acreatefile.hpp"

namespace action {

    filesystem::Node* ACreateFile::action(filesystem::Node* context, std::string arg)
    {
        // Try casting ...
        filesystem::Directory* currentDirectory = dynamic_cast<filesystem::Directory*>(context);
        if (!currentDirectory)
        {
            std::cout << "[ACreateFile::action] Cast failed!";
            return context;
        }

        currentDirectory->addChild(new filesystem::File(arg));
        return context;
    }

}
