#include "commandfactory.hpp"
#include "directory.hpp"

// Akcije
#include "acreatedirectory.hpp"
#include "acreatefile.hpp"
#include "adelete.hpp"
#include "aprint.hpp"

#include <memory>

int main()
{

    // Izrada Root direktorija - prvog cvora u stablu.
    filesystem::Directory root("Root");
    root.print();
    // Dodajem mu neku djecu, samo za test.
    root.addChild(new filesystem::File("foo.txt"));
    root.addChild(new filesystem::File("bar.txt"));
    root.addChild(new filesystem::File("foobar.txt"));
    root.addChild(new filesystem::Directory("folder1"));
    root.print();

    // Ovo isto za test, ak radi sve kak treba.
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

    // Izrada objekta CommandFactory klase.
    // S tim objektom mozemo registrirati akcije (registerAction(...)),
    // koje se kasnije mogu pozivati prek terminala - kroz upis naredbe
    parser::CommandFactory commandFactory(&root);

    // Stvori po jedan objekt za svaku mogucu akciju i spremi ga u
    // mapu od commandFactory objekta.
    // S ovim pristupom, uvijek imamo spremne objekte, samo ih treba
    // pronaci u mapi i pozvati njihovu metodu action(...)
    commandFactory.registerAction("ls", new action::APrint());
    commandFactory.registerAction("mkdir", new action::ACreateDirectory());
    commandFactory.registerAction("mkfile", new action::ACreateFile());
    commandFactory.registerAction("rm", new action::ADelete());

    // Tu izradujemo komande, samo za potrebe testiranja.
    // Zapravo se ovo radi automatikom, kad korisnik, kroz terminal
    // upise naredbu.
    parser::Command c1("mkdir testni_folder");
    parser::Command c2("ls");
    parser::Command c3("mkfile oh_mene.png");
    parser::Command c4("mkfile oh_nas.mkv");
    parser::Command c5("ls");
    parser::Command c6("rm oh_nas.mkv");
    parser::Command c7("ls");

    // Stvorenu komandu izvrsimo prek ove metode.
    commandFactory.executeCommand(&c1);
    commandFactory.executeCommand(&c2);
    commandFactory.executeCommand(&c3);
    commandFactory.executeCommand(&c4);
    commandFactory.executeCommand(&c5);
    commandFactory.executeCommand(&c6);
    commandFactory.executeCommand(&c7);

    // Tu sad postavljam teren za automatiku:
    // imamo jedan string (terminalInput) u kojeg bude korisnik upisival naredbe.
    // ovaj shared_ptr od Command je 'pametni' pointer koji bude cuval adresu
    // zadnje stvorene komande. Ta komanda je stvorena odma nakon korisnikovog
    // upisivanja komande.
    std::string terminalInput;
    std::shared_ptr<parser::Command> command = nullptr;

    // Ovo se vrti ukrug, sve dok se ne upise naredba "exit".
    do
    {
        // Procitaj korisnikovu naredbu i spremi ju u terminalInput.
        std::getline(std::cin, terminalInput);
        // stvori Command objekt na temelju teksta u terminalInput i iz nje napravi
        // shared_ptr, prek std::make_shared naredbe. Adresu tog objekta spremi u
        // command.
        command = std::make_shared<parser::Command>( parser::Command(terminalInput) );
        // Sad imamo sve kaj nam treba, mozemo probati izvrsiti command naredbu.
        commandFactory.executeCommand(command);
    } while (terminalInput != "exit");

    return 0;
}
