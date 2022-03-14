#include <iostream>
using namespace std;

class student{
    string name;
    public:
    int age;
    bool gender;

    void getName();
    void setName(string s){
        name = s;
    }
    // Default Constructor
    student(){
        cout<<"Default Constructor"<<endl;
    }
    // Parameterised Constructor
    student (string s, int i, bool b){
        cout<<"Parameterised Constructor"<<endl;
        name = s;
        age = i;
        gender = b;
    }

    // Copy Constructor
    student (student &a){
        cout<<"Copy Constructor"<<endl;
        name = a.name;
        age = a.age;
        gender = a.gender;
    }

    ~student(){
        cout<<"Destructor"<<endl;
    }

    bool operator == (student &a){
        if(name==a.name && age==a.age && gender==a.gender){
            return true;
        }
        else{
            return false;
        }
    }
    // Inner Function
    void printInfo(){
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
        cout<<"Gender: "<<gender<<endl;
    }
};

// Outer Function
void student :: getName(){
        cout<<name<<endl;
        cout<<age<<endl;
        cout<<gender<<endl;
    }

int main(){
    // student arr[3];
    // for(int i=0;i<3;i++){
    //     string s;
    //     cout<<"Name: ";
    //     cin>>s;
    //     arr[i].setName(s);
    //     cout<<"Age: ";
    //     cin>>arr[i].age;
    //     cout<<"Gender: ";
    //     cin>>arr[i].gender;
    // }
    // for(int i=0;i<3;i++){
    //     arr[i].printInfo();
    // }
    student a("Naman", 19, 0);
    // a.getName();
    student b;
    student c = a;

    if(c==a){
        cout<<"Same"<<endl;
    }
    else{
        cout<<"Not Same"<<endl;
    }
    return 0;
}