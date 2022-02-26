#ifndef FILE_HPP
#define FILE_HPP

#include "node.hpp"

namespace filesystem {

    class File : public Node
    {
    public:
        File(std::string name);
        File(std::string name, Node* parent);
        virtual ~File();

        virtual void print() override;
    };
}
#endif // FILE_HPP
