#include "commandfactory.hpp"
#include "directory.hpp"

// Akcije
#include "acreatedirectory.hpp"
#include "acreatefile.hpp"
#include "adelete.hpp"
#include "aprint.hpp"

int main()
{

    filesystem::Directory root("Root");
    root.print();
    root.addChild(new filesystem::File("foo.txt"));
    root.addChild(new filesystem::File("bar.txt"));
    root.addChild(new filesystem::File("foobar.txt"));
    root.addChild(new filesystem::Directory("folder1"));
    root.print();

    filesystem::Directory* folder2 = new filesystem::Directory("folder2");
    folder2->addChild(new filesystem::File("d_foo.txt"));
    folder2->addChild(new filesystem::File("d_bar.txt"));
    folder2->addChild(new filesystem::File("d_foobar.txt"));
    folder2->print();

    root.addChild(folder2);
    root.print();

    root.deleteChild("folder1");
    root.deleteChild("folder2");
    root.print();

    parser::CommandFactory commandFactory(&root);

    commandFactory.registerAction("ls", new action::APrint());
    commandFactory.registerAction("mkdir", new action::ACreateDirectory());
    commandFactory.registerAction("mkfile", new action::ACreateFile());
    commandFactory.registerAction("rm", new action::ADelete());

    parser::Command c1("mkdir testni_folder");
    parser::Command c2("ls");
    parser::Command c3("mkfile oh_mene.png");
    parser::Command c4("mkfile oh_nas.mkv");
    parser::Command c5("ls");
    parser::Command c6("rm oh_nas.mkv");
    parser::Command c7("ls");

    commandFactory.executeCommand(&c1);
    commandFactory.executeCommand(&c2);
    commandFactory.executeCommand(&c3);
    commandFactory.executeCommand(&c4);
    commandFactory.executeCommand(&c5);
    commandFactory.executeCommand(&c6);
    commandFactory.executeCommand(&c7);

    return 0;
}
