#include<iostream>
using namespace std;

int fact(int n){
  int factorial=1;
  for(int i=1;i<=n;i++){
    factorial*=i;
  }
  return factorial;
}

int main(){

// #ifndef ONLINE_JUDGE
//   freopen("input.txt", "r", stdin);
//   freopen("output.txt", "w", stdout);
// #endif

int n;
cin>>n;

for(int i=0;i<n;i++){
  for(int j=n-i;j>=1;j--){
    cout<<" ";
  }
  for(int j=0;j<=i;j++){
    cout<<fact(i)/(fact(j)*fact(i-j))<<" ";
  }
  cout<<endl;
}
  return 0;
}
