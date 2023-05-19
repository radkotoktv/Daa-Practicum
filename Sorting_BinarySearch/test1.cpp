#include <iostream>
#include <cstring>

class Baloon {
private:
    char* color;
    double price;

    void copyString(char*& destination, const char* source);
    void deallocate();

public:
    Baloon() : Baloon("", 0) {};
    Baloon(const char* color, const double price);
    
    void print();

    void setColor(const char* color);
    void setPrice(const double price);
    const char* getColor() const;
    const double getPrice() const;

    ~Baloon();
};

void Baloon::copyString(char*& destination, const char* source){
    if(destination) delete[] destination;
    
    destination = new (std::nothrow) char[strlen(destination) + 1];
    if(!destination){
        throw "maika ti";
        this->deallocate();
        exit(0);
    }

    strcpy(destination, source);
}

void Baloon::deallocate(){
    delete[] this->color;
}

Baloon::Baloon(const char* color, const double price){
    copyString(this->color, color);
    this->price = price;
}    

void Baloon::print(){
    std::cout << "Balloon color: " << this->color << std::endl;
    std::cout << "Balloon price: " << this->price << std::endl;
}

void Baloon::setColor(const char* color){
    copyString(this->color, color);
}

void Baloon::setPrice(const double price){
    this->price = price;
}

const char* Baloon::getColor() const{
    return this->color;
}

const double Baloon::getPrice() const{
    return this->price;
}

Baloon::~Baloon(){
    this->deallocate();
}

int main() {
    Baloon balloon("Red", 10.2);
    balloon.print();
}