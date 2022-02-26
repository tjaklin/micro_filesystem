#include "directory.hpp"

namespace filesystem {

    Directory::Directory(std::string name)
        : Directory{name, nullptr}
    {
    }

    Directory::Directory(std::string name, Node* parent)
        : Node{name, parent}
    {
    }

    Directory::~Directory() {
        for (auto& c : m_children)
            delete c;
        m_parent = nullptr;
        m_self = nullptr;
    }

    void Directory::print()
    {
        std::cout << "Directory: " << m_name << "\n";
        for (auto& c : m_children)
        {
            std::cout << "\t";
            c->print();
        }
    }

    Node* Directory::addChild(Node* child)
    {
        if (!child) { return this; }
        child->setParent(this);
        m_children.push_back(child);
        return child;
    }

    Node* Directory::deleteChild(std::string childName)
    {
        for (auto it = m_children.begin(); it != m_children.end(); ) {
            auto* p = *it;

            if (p->getName() == childName) {
                delete p;
                it = m_children.erase(it);
                return this;
            } else {
                ++it;
            }
        }

        return this;
    }
}
