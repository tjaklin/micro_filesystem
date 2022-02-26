#ifndef APRINT_HPP
#define APRINT_HPP

#include "action.hpp"

namespace action {

    class APrint : public Action
    {
    public:
        APrint() = default;

        virtual filesystem::Node* action(filesystem::Node* context, std::string arg) override;

    };
}
#endif // APRINT_HPP
