#ifndef DIRECTORY_HPP
#define DIRECTORY_HPP

#include "file.hpp"
#include <vector>

namespace filesystem {

    class Directory : public Node
    {
    public:
        Directory(std::string name);
        Directory(std::string name, Node* parent);
        virtual ~Directory();

        virtual void print() override;
        Node* addChild(Node* child);
        Node* deleteChild(std::string childName);

    protected:
        std::vector<Node*> m_children;
    };

}

#endif // DIRECTORY_HPP
