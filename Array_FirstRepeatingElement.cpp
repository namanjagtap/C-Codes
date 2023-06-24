#include <iostream>
#include <climits>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int count[n+1];
    for(int i=0;i<=n;i++)
        count[i] = -1;
    
    int minIndex = INT_MAX;
    for(int i=0;i<n;i++){
        if(count[arr[i]] != -1)
            minIndex = min(minIndex, count[arr[i]]);
        else
            count[arr[i]] = i;
    }
    if(minIndex == INT_MAX)
        cout<<"-1"<<endl;
    else
        cout<<minIndex+1<<"   "<<arr[minIndex]<<endl;

    return 0;
}