#include <iostream>
using namespace std;

bool pairSum(int arr[], int n, int k){
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
            if(arr[i]+arr[j]==k){
                cout<<i<<" "<<j<<endl;
                return true;
            }
    return false;
}

bool pairSumOptimized(int arr[], int n, int k){
    int low = 0;
    int high = n-1;
    for(int i=0;i<n;i++){
        if(arr[low] + arr[high] == k){
            cout<<low<<" "<<high<<endl;
            return true;
        }
        else if(arr[low] + arr[high] < k)
            low++;
        else
            high++;
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    int desiredSum;
    cin>>desiredSum;
    
    pairSumOptimized(arr, n, desiredSum);

    return 0;    
}