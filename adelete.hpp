#ifndef ADELETE_HPP
#define ADELETE_HPP

#include "action.hpp"
#include "directory.hpp"

namespace action {

    class ADelete : public Action
    {
    public:
        ADelete() = default;

        virtual filesystem::Node* action(filesystem::Node* context, std::string arg) override;
    };

}

#endif // ADELETE_HPP
