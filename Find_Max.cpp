#include<iostream>
using namespace std;

int main() {

  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif
int num1;
int num2;
int num3;
cin>>num1>>num2>>num3;

if(num1 > num2) {
  if(num1 > num3){
    cout<<num1;
  }
  else{
    cout<<num3;
  }
}
else if(num2 > num3){
  if(num2 > num1){
    cout<<num2;
  }
  else{
    cout<<num1;
  }
}
else{
  cout<<num3;
}

  return 0;
}