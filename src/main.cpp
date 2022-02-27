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

        std::cout << db->root()->Entries().front().get()->ToJson();

    }
    catch(std::exception& e){
        std::cout << "Exception" << e.what();
    }

    //file.Export("out.kdbx", *db.get(), key);

    return 0;
}