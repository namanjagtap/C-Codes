#include<iostream>
#include<math.h>
using namespace std;

    int t1=0;
void fib(int n){
    int t2=1;
    int nextTerm;
    for(int i=1;i<=n;i++){
        cout<<t1<<endl;
        nextTerm=t1+t2;
        t1=t2;
        t2=nextTerm;
    }
    return;
}

int main(){

  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif

int n;
cin>>n;

    fib(n);
  return 0;
}     