#ifndef DATABASE_H
#define DATABASE_H
#include <fstream>
#include "product.h"

using namespace std;


class DataBase
{
private:
    fstream file;
    char* FileName;

    int size;
    Product* main;
public:
    DataBase(char* fname);
    ~DataBase();

    bool FileIsOpen();
    void Load();
    void Save();
    void PrintP(Product pr);
    void Add(Product pr);
    void Search(int flag);
    void Change(int ind);
    void Delete(int ind);
};

#endif // DATABASE_H
