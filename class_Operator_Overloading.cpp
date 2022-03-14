#include "bits/stdc++.h"
using namespace std;

class Complex{
    private:
    int real, img;
    public:
    Complex(int r, int i){
        real = r;
        img = i;
    }
    Complex(){
        
    }
    Complex operator + (Complex const &obj){
        Complex res;
        res.real = real + obj.real;
        res.img = img + obj.img;
        return res;
    }
    void display(){
        cout<<real<<" + i"<<img<<endl;
    }
};

int main(){
        Complex c1(5, 3);
        Complex c2(4, 5);
        Complex c3;

        c3=c1+c2;
        c3.display();
}