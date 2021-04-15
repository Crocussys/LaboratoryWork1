#include "product.h"

Product::Product()
{
    type = "";
    manufacturer = "";
    serie = "";
    model = "";
    color = "";
    price = -1;
    quantity = 0;
    row = -1;
    place = -1;
    width = -1;
    height = -1;
    depth = -1;
    NEW = false;
    SALE = false;
    OldPrice = -1;
}
void Product::setType(string inp){
    type = inp;
}
string Product::getType(){
    return type;
}
void Product::setManufacturer(string inp){
    manufacturer = inp;
}
string Product::getManufacturer(){
    return manufacturer;
}
void Product::setSerie(string inp){
    serie = inp;
}
string Product::getSerie(){
    return serie;
}
void Product::setModel(string inp){
    model = inp;
}
string Product::getModel(){
    return model;
}
void Product::setColor(string inp){
    color = inp;
}
string Product::getColor(){
    return color;
}
void Product::setPrice(float inp){
    price = inp;
}
float Product::getPrice(){
    return price;
}
void Product::setQuantity(int inp){
    quantity = inp;
}
int Product::getQuantity(){
    return quantity;
}
void Product::setRow(int inp){
    row = inp;
}
int Product::getRow(){
    return row;
}
void Product::setPlace(int inp){
    place = inp;
}
int Product::getPlace(){
    return place;
}
void Product::setWidth(float inp){
    width = inp;
}
float Product::getWidth(){
    return width;
}
void Product::setHeight(float inp){
    height = inp;
}
float Product::getHeight(){
    return height;
}
void Product::setDepth(float inp){
    depth = inp;
}
float Product::getDepth(){
    return depth;
}
void Product::setNEW(bool inp){
    NEW = inp;
}
bool Product::getNEW(){
    return NEW;
}
void Product::setSALE(bool inp){
    SALE = inp;
}
bool Product::getSALE(){
    return SALE;
}
void Product::setOldPrice(float inp){
    OldPrice = inp;
}
float Product::getOldPrice(){
    return OldPrice;
}
