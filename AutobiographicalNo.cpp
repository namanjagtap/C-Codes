#include <iostream>
using namespace std;

int main(){
    string s = "42101000";
    int c=0;
    int n = stoi(s);
    int arr[s.size()];
    for(int i=s.size()-1;i>=0;i--){
        arr[i]=n%10;
        n=n/10;
    }
    bool flag=true;
    for(int i=0;i<s.size();i++){
        int count=0;
        for(int j=0;j<s.size();j++){
            if(i==arr[j])
                count++;
        }
        if(count!=arr[i]){
            flag=false;
            break;
        }
    }
    for(int i=0;i<s.size();i++){
        if(arr[i]>0)
        c++;
    }
    if(flag==true){
        cout<<"Autobiographical Number"<<endl;
        cout<<c<<endl;
    }
    else{
        cout<<"Na na na!"<<endl;
    }
    return 0;
}