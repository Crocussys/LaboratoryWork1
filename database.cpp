#include <iostream>
#include <fstream>
#include "database.h"

using namespace std;

DataBase::DataBase(char* fname)
{
    FileName = fname;
    file.open(FileName, ios::binary|ios::in);
    file >> size;
}
DataBase::~DataBase(){
    file.close();
    delete [] main;
}
int DataBase::FileIsOpen(){
    if(file) return 1;
    else return 0;
}
void DataBase::Load(){
    main = new Product[size];
    for (int i = 0; i < size; i ++){
        file >> main[i];
    }
}
void DataBase::Save(){
    file.close();
    file.open(FileName, ios::binary|ofstream::out|ofstream::trunc);
    file << size;
    for (int i = 0; i < size; i++){
        file << main[i];
    }
    file.close();
    file.open(FileName, ios::binary|ios::in);
}
void DataBase::Add(Product pr){
    Product* cash = new Product[size];
    for (int i = 0; i < size; i++){
        cash[i] = main[i];
    }
    delete [] main;
    size++;
    main = new Product[size];
    for (int i = 0; i < size - 1; i++){
        main[i] = cash[i];
    }
    main[size - 1] = pr;
    delete [] cash;
    Save();
}
void DataBase::Delete(int ind){
    Product* cash = new Product[size];
    for (int i = 0; i < size; i++){
        cash[i] = main[i];
    }
    delete [] main;
    size--;
    main = new Product[size];
    for (int i = 0; i < size; i++){
        if (i < ind){
            main[i] = cash[i];
        }else{
            main[i] = cash[i + 1];
        }
    }
    delete [] cash;
    Save();
}
void DataBase::Search(int flag){
    if (flag < 0 || flag > 3){
        cout << "Error flag!" << endl;
        return;
    }
    string inp;
    int inpi;

    Product a;
    int *ans = new int[size];
    int count = 0;

    string t;
    string m;
    string s;

    if (flag){
        cout << "Search> ";
        cin >> inp;
    }
    for (int i = 1; i <= size; i++){
        a = main[i - 1];
        t = a.getType();
        m = a.getManufacturer();
        s = a.getSerie();
        if (flag == 0 || (flag == 1 && !t.find(inp)) || (flag == 2 && !m.find(inp)) || (flag == 3 && !s.find(inp))){
            ans[count] = i - 1;
            count++;
            cout << count << ". " << t << " " << m << " " << s << " " << a.getPrice() << "$" << endl;
        }
    }
    while (true) {
        cin >> inpi;
        if (inpi == 0){
            break;
        }else if (inpi > 0 && inpi <= count) {
            Change(ans[inpi - 1]);
            break;
        }else{
            cout << "Specify a number from the menu or 0 for exit" << endl;
            continue;
        }
    }
    delete [] ans;
    return;
}
void DataBase::Change(int ind){
    if (ind < 0 || ind > size - 1){
        cout << "Error index" << endl;
        return;
    }
    const string changemenu = "0 Accept\n1 Delete\nChange:\n2 Type\n3 Manufacturer\n4 Serie\n5 Model\n6 Colour\n7 Price\n8 Quantity\n9 Space in the warehouse\n10 Size\n11 Mark 'NEW'\n12 Mark 'DISCOUNT'";
    const string miss = "Specify a number from the menu!";

    Product a = main[ind];
    string input;
    int inpi;
    float inpf;

    while (true) {
        cout << a.getType() << " " << a.getManufacturer()<< " " << a.getSerie() << endl <<
                a.getModel() << endl <<
                "Color " << a.getColor() << endl <<
                "Price " << a.getPrice() << "$" << endl <<
                a.getQuantity() << "items left in stock" << endl <<
                "Place in the warehouse:" << endl <<
                "Row " << a.getRow() << endl <<
                "Place " << a.getPlace() << endl <<
                "Size :" << endl <<
                "Width " << a.getWidth() << endl <<
                "Height " << a.getHeight() << endl <<
                "Depth " << a.getDepth() << endl;
        if (a.getNEW()) cout << "NEW" << endl;
        if (a.getSALE()) cout << "DISCONT" << endl <<
                                 "Old price" << a.getOldPrice() << endl;
        cout << changemenu << endl;
        cin >> input;
        if (input == "0"){
            main[ind] = a;
            Save();
            cout << "Saved" << endl;
            break;
        }
        else if (input == "1"){
            Delete(ind);
            break;
        }
        else if (input == "2"){
            cout << "test> " << endl;
            cin >> input;
            a.setType(input);
        }
        else if (input == "3"){
            cout << "test> " << endl;
            cin >> input;
            a.setManufacturer(input);
        }
        else if (input == "4"){
            cout << "test> " << endl;
            cin >> input;
            a.setSerie(input);
        }
        else if (input == "5"){
            cout << "test> " << endl;
            cin >> input;
            a.setModel(input);
        }
        else if (input == "6"){
            cout << "test> " << endl;
            cin >> input;
            a.setColor(input);
        }
        else if (input == "7"){
            cout << "test> " << endl;
            cin >> inpf;
            a.setPrice(inpf);
        }
        else if (input == "8"){
            cout << "test> " << endl;
            cin >> inpi;
            a.setQuantity(inpi);
        }
        else if (input == "9"){
            cout << "test> " << endl;
            cin >> inpi;
            a.setRow(inpi);
            cin >> inpi;
            a.setPlace(inpi);
        }
        else if (input == "10"){
            cout << "test> " << endl;
            cin >> inpf;
            a.setWidth(inpf);
            cin >> inpf;
            a.setHeight(inpf);
            cin >> inpf;
            a.setDepth(inpf);
        }
        else if (input == "11"){
            while (true) {
                cout << "1. Mark 'NEW'" << endl << "2. Unmark 'NEW'" << endl;
                cin >> input;
                if (input == "1") {
                    a.setNEW(true);
                    break;
                }else if (input == "2") {
                    a.setNEW(false);
                    break;
                }else{
                    cout << miss << endl;
                    continue;
                }
            }
        }
        else if (input == "12"){
            while (true) {
                cout << "1. Mark 'DISCONT'" << endl << "2. Unmark 'DISCONT'" << endl;
                cin >> input;
                if (input == "1") {
                    cout << "Enter a new price" << endl;
                    cin >> inpf;
                    a.setNEW(true);
                    a.setOldPrice(a.getPrice());
                    a.setPrice(inpf);
                    break;
                }else if (input == "2") {
                    a.setSALE(false);
                    a.setPrice(a.getOldPrice());
                    a.setOldPrice(-1);
                    break;
                }else{
                    cout << miss << endl;
                    continue;
                }
            }
        }
        else {
            cout << miss << endl;
            continue;
        }
    }
}
