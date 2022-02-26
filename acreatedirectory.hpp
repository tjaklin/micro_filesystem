#ifndef ACREATEDIRECTORY_HPP
#define ACREATEDIRECTORY_HPP

#include "action.hpp"
#include "directory.hpp"

namespace action {

    class ACreateDirectory : public Action
    {
    public:
        ACreateDirectory() = default;

        virtual filesystem::Node* action(filesystem::Node* context, std::string arg) override;
    };
}

#endif // ACREATEDIRECTORY_HPP
