#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>

namespace filesystem {

    class Node
    {
    public:
        Node(std::string name);
        Node(std::string name, Node* parent);
        virtual ~Node();

        virtual void print();
        std::string& getName();
        Node* getParent();

        void setName(std::string name);
        void setParent(Node* parent);

    protected:
        std::string m_name;
        Node* m_parent;
        Node* m_self;
    };

}

#endif // NODE_HPP
