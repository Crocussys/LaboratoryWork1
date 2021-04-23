#include <iostream>
#include "menu.h"
#include "product.h"
#include "database.h"

using namespace std;;

menu::menu()
{
    cout << "Welcome!" << endl;
}
void menu::start(DataBase &db){
    while (true){
        cout << main << endl << "> ";
        cin >> input;
        cout << endl;
        if (input == "1"){
            db.Search(0);
        }
        else if (input == "2"){
            db.Search(1);
        }
        else if (input == "3"){
            db.Search(2);
        }
        else if (input == "4"){
            db.Search(3);
        }
        else if (input == "5"){
            add(db);
        }
        else if (input == "6"){
            cout << "Bye" << endl;
            break;
        }
        else {
            cout << miss << endl;
        }
        cout << endl;
    }
}
void menu::add(DataBase &db){
    Product in;
    float inpf;
    int inpi;
    cout << "What do you want to add?" << endl << "> ";
    cin >> input;
    in.setType(input);
    cout << "Enter manufacturer." << endl << "> ";
    cin >> input;
    in.setManufacturer(input);
    cout << "Enter product series(name)." << endl << "> ";
    cin >> input;
    in.setSerie(input);
    cout << "What`s the price?" << endl << "> ";
    cin >> inpf;
    in.setPrice(inpf);
    while (true){
        db.PrintP(in);
        cout << addmenu << endl << "> ";
        cin >> input;
        if (input == "1"){
            cout << "Enter model or feature." << endl << "> ";
            cin >> input;
            in.setModel(input);
        }
        else if (input == "2"){
            cout << "Enter color." << endl << "> ";
            cin >> input;
            in.setColor(input);
        }
        else if (input == "3"){
            cout << "Enter the quantity of goods." << endl << "> ";
            cin >> inpi;
            in.setQuantity(inpi);
        }
        else if (input == "4"){
            cout << "Enter a place in the warehouse. Format: [row place]." << endl << "> ";
            cin >> inpi;
            in.setRow(inpi);
            cin >> inpi;
            in.setPlace(inpi);
        }
        else if (input == "5"){
            cout << "Enter the dimensions. Format: [width height depth]." << endl << "> ";
            cin >> inpf;
            in.setWidth(inpf);
            cin >> inpf;
            in.setHeight(inpf);
            cin >> inpf;
            in.setDepth(inpf);
        }
        else if (input == "6"){
            while (true) {
                cout << "1.Check NEW\n2.Uncheck NEW" << endl << "> ";
                cin >> input;
                if (input == "1"){
                    in.setNEW(true);
                    break;
                }else if (input == "2"){
                    in.setNEW(false);
                    break;
                }else{
                    cout << miss;
                }
                cout << endl;
            }
        }
        else if (input == "7"){
            while (true) {
                cout << "1.Check DISCOUNT\n2.Uncheck DISCOUNT" << endl << "> ";
                cin >> input;
                if (input == "1"){
                    in.setSALE(true);
                    cout << "Enter the old price." << endl << "> ";
                    cin >> inpf;
                    in.setOldPrice(inpf);
                    break;
                }else if (input == "2"){
                    in.setSALE(false);
                    in.setOldPrice(-1);
                    break;
                }else{
                    cout << miss;
                }
                cout << endl;
            }
        }
        else if (input == "0"){
            break;
        }
        else {
            cout << miss;
        }
        cout << endl;
    }
    db.Add(in);
    cout << "Added" << endl;
}
