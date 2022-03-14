#include<iostream>
using namespace std;

int main(){

  int n;
  cin>>n;
  int arr[n];

  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  
  for(int i=1;i<n;i++){
    int current=arr[i];
    int j=i-1;
    while(arr[j]>current && j>=0){
      arr[j+1]=arr[j];
      j--;
    }
    arr[j+1]=current;
  
  }
  for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
  
  return 0;
}

// 8 5 3 4 7-step:1   i=1, j=0
// 5 8 3 4 7-step:1   i=1, j=0

// 5 8 8 4 7-step:2   i=2, j=1
// 5 5 8 4 7-step:2   i=2, j=0
// 3 5 8 4 7-step:2   i=2, j=-1

//3 5 8 8 7-step:3    i=3,j=2
//3 5 5 8 7-step:3    i=3,j=1
//3 4 5 8 7-step:3    i=3,j=0

//3 4 5 8 8-step:4    i=4,j=3
//3 4 5 7 8-step:4    i=4,j=2