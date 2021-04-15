#include <QCoreApplication>
#include <iostream>
#include "database.h"
#include "menu.h"

using namespace std;

int main(int argc, char *argv[])
{
    if(argc < 2){
        cout << "Not enough arguments: "<< argc << " args out of 2 specified." << endl;
        return 1;
    }
    DataBase db(argv[1]);
    if(!db.FileIsOpen()){
        cout << "Failed to connect to database: File opening error." << endl;
        return 2;
    }
    db.Load();
    menu Menu;
    Menu.start(db);
    return 0;
}
