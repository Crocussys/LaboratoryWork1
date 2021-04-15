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
void DataBase::Search(){
    Product a;
    for (int i = 1; i <= size; i++){
        a = main[i - 1];
        cout << i << "." << a.getType() << " " << a.getManufacturer() << " " << a.getSerie() << endl;
    }
}
