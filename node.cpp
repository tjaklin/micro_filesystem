#include "node.hpp"

namespace filesystem {

    Node::Node(std::string name)
        : Node(name, nullptr)
    {
    }

    Node::Node(std::string name, Node* parent)
        : m_name{name}, m_parent{parent}, m_self{this}
    {
    }

    Node::~Node()
    {
        m_parent = nullptr;
        m_self = nullptr;
    }

    void Node::print()
    {
        std::cout << "Node: " << m_name << "\n";
    }

    std::string& Node::getName() { return m_name; }
    Node* Node::getParent() { return m_parent; }

    void Node::setName(std::string name)
    {
        m_name = name;
    }

    void Node::setParent(Node* parent)
    {
        if (!parent) return;
        m_parent = parent;
    }
}
