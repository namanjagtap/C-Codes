#include <bits/stdc++.h>
using namespace std;

void print2largest(int arr[], int n){
    int i, first, second;
    if(n<2){
        cout<<"Invalid Output"<<endl;
        return;
    }
    sort(arr, arr+n);

    for(i=n-2;i>=0;i--){
        if(arr[i]!=arr[n-1]){
            cout<<"The second largest element is "<<arr[i]<<endl;
            return;
        }
    }
    cout<<"There is no second largest element"<<endl;
}

int main(){
    int arr[]={12, 5 ,6, 10, 11, 2, 3};
    int n=sizeof(arr)/sizeof(arr[0]);
    print2largest(arr, n);
    return 0;
}