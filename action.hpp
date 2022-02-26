#ifndef ACTION_HPP
#define ACTION_HPP

#include "node.hpp"

namespace action {

    class Action
    {
    public:
        Action() = default;
        virtual ~Action();

        virtual filesystem::Node* action(filesystem::Node* context, std::string arg) = 0;
    };
}

#endif // ACTION_HPP
