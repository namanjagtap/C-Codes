#include <iostream>
#include <climits>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    int maX = INT_MIN;
    for(int i=0;i<n;i++){
        maX=max(maX, arr[i]);
        cout<<maX<<" ";
    }
    cout<<endl;

    return 0;
}