#include <iostream>
using namespace std;

void swap(int *i, int *j){
    int temp = *i;
    *i = *j;
    *j = temp;
}

void sortNegative(int arr[], int l, int r){
    while(l<r){
        if(arr[l]<0){
            swap(&arr[l], &arr[r]);
            l++, r--;
        }
        else{
            l++;
        }
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    sortNegative(arr, 0, n-1);

    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}