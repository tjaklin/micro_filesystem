#include "file.hpp"

namespace filesystem {

    File::File(std::string name)
        : File(name, nullptr)
    {
    }

    File::File(std::string name, Node* parent)
        : Node{name, parent}
    {
    }

    File::~File() {
        m_parent = nullptr;
        m_self = nullptr;
    }

    void File::print() {
        std::cout << "File: " << m_name << "\n";
    }

}
