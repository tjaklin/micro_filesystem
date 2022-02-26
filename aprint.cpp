#include "aprint.hpp"

namespace action {

    filesystem::Node* APrint::action(filesystem::Node* context, std::string arg)
    {
        context->print();
        return context;
    }

}
