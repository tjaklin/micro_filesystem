#ifndef ACREATEFILE_HPP
#define ACREATEFILE_HPP

#include "action.hpp"
#include "directory.hpp"

namespace action {

    class ACreateFile : public Action
    {
    public:
        ACreateFile() = default;

        virtual filesystem::Node* action(filesystem::Node* context, std::string arg) override;
    };

}

#endif // ACREATEFILE_HPP
