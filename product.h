#ifndef PRODUCT_H
#define PRODUCT_H
#include <iostream>

using namespace std;

class Product
{
private:
    string type;
    string manufacturer;
    string serie;
    string model;
    string color;
    float price;
    int quantity;
    int row;
    int place;
    float width;
    float height;
    float depth;
    bool NEW;
    bool SALE;
    float OldPrice;
public:
    Product();

    void setType(string inp);
    string getType();
    void setManufacturer(string inp);
    string getManufacturer();
    void setSerie(string inp);
    string getSerie();
    void setModel(string inp);
    string getModel();
    void setColor(string inp);
    string getColor();
    void setPrice(float inp);
    float getPrice();
    void setQuantity(int inp);
    int getQuantity();
    void setRow(int inp);
    int getRow();
    void setPlace(int inp);
    int getPlace();
    void setWidth(float inp);
    float getWidth();
    void setHeight(float inp);
    float getHeight();
    void setDepth(float inp);
    float getDepth();
    void setNEW(bool inp);
    bool getNEW();
    void setSALE(bool inp);
    bool getSALE();
    void setOldPrice(float inp);
    float getOldPrice();

    friend ostream& operator << (ostream &out, Product &pr){
        out << pr.getType() << "|";
        out << pr.getManufacturer() << "|";
        out << pr.getSerie() << "|";
        out << pr.getModel() << "|";
        out << pr.getColor() << "|";
        out << pr.getPrice() << "|";
        out << pr.getQuantity() << "|";
        out << pr.getRow() << "|";
        out << pr.getPlace() << "|";
        out << pr.getWidth() << "|";
        out << pr.getHeight() << "|";
        out << pr.getDepth() << "|";
        out << pr.getNEW() << "|";
        out << pr.getSALE() << "|";
        out << pr.getOldPrice() << "\n";
        return out;
    }
    friend istream& operator >> (istream &in, Product &pr){
        string ins;
        string ans[15];
        int j = 0;
        in >> ins;
        for (unsigned long i = 0; i < ins.size(); i++){
            if (ins[i] == '|'){
                j++;
            }else{
                ans[j] += ins[i];
            }
            if (j == 15) break;
        }
        pr.setType(ans[0]);
        pr.setManufacturer(ans[1]);
        pr.setSerie(ans[2]);
        pr.setModel(ans[3]);
        pr.setColor(ans[4]);
        pr.setPrice(stof(ans[5]));
        pr.setQuantity(stoi(ans[6]));
        pr.setRow(stoi(ans[7]));
        pr.setPlace(stoi(ans[8]));
        pr.setWidth(stof(ans[9]));
        pr.setHeight(stof(ans[10]));
        pr.setDepth(stof(ans[11]));
        stoi(ans[12])?pr.setNEW(true):pr.setNEW(false);
        stoi(ans[13])?pr.setSALE(true):pr.setSALE(false);
        pr.setOldPrice(stof(ans[14]));
        return in;
    }
};

#endif // PRODUCT_H
