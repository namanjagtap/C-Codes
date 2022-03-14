//Euclid Algorithm
#include<iostream>
using namespace std;

long long gcd(long long int a, long long int b){
    if(b==0)
        return a;
    return gcd(b, a%b);
}

long long LCM(long long int a,long long int b){
    return (a*b)/gcd(a,b);
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        cout<<gcd(a,b)<<" "<<LCM(a,b)<<endl;
    }
    return 0;
}