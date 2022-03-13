#include <iostream>
#include <exception>
#include "kdbx.h"
#include "key.h"
#include "kdb.h"

int main()
{
    keepass::Key key("password");


    try {
        keepass::KdbxFile file;
        std::unique_ptr<keepass::Database> db = file.Import("./Database.kdbx", key);

        auto groups = db->root()->Groups();
        for(auto group : groups){
            std::cout << "\nGroup " << group->name() << group->notes() << ", entries: " << group->Entries().size();
        }

        auto entries = db->root()->Entries();
        for(auto entry : entries){
            std::cout << "\nEntry " << entry->title().value() << entry->username().value() << entry->password().value();
        }

    }
    catch(std::exception& e){
        std::cout << "Exception" << e.what();
    }

    //file.Export("out.kdbx", *db.get(), key);

    return 0;
}