#ifndef MENU_H
#define MENU_H
#include <iostream>
#include "database.h"

using namespace std;

class menu
{
private:
    string input;
public:
    menu();

    const string main = "Menu:\n1 Display the entire database\n2 Search by type\n3 Search by manufacturer\n4 Search by series\n5 Add\n6 Exit";
    const string addmenu = "Do you want to indicate something else?\n1.Model\n2.Color\n3.Quantity\n4.Space in the warehouse\n5.Size\n6.New mark\n7.Marked DISCOUNT and old price\n8.No";
    const string miss = "Specify a number from the menu!";

    void start(DataBase &db);
    void add(DataBase &db);
};

#endif // MENU_H
