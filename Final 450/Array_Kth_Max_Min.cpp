#include <iostream>
using namespace std;

//Using Quicksort because it is considered fastest
//anyother sorting techinque can also be used

void swap(int *i, int *j){
    int temp = *i;
    *i = *j;
    *j = temp;
}

int partition(int arr[], int l, int r){
    int pivot = arr[r];
    int i = l-1;

    for(int j=l;j<r;j++){
        if(arr[j] < pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
        swap(&arr[i+1], &arr[r]);
        return i+1;
}

void QuickSort(int arr[], int l, int r){
    if(l<r){
        int pi = partition(arr, l, r);

        QuickSort(arr, l, pi-1);
        QuickSort(arr, pi+1, r);
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    int k;
    cout<<"Enter value of K ";
    cin>>k;
    
    QuickSort(arr, 0, n-1);

    cout<<"Kth maximum "<<arr[n-k]<<endl;    
    cout<<"Kth minimum "<<arr[k-1]<<endl;    

    return 0;
}