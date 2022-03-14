#include <iostream>
using namespace std;

int main(){
    int n, m;
    cin>>n>>m;
    int arr[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    int sum = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==0||i==n-1||j==n-1-i){
                sum+=arr[i][j];
            }
        }
    }
    cout<<sum<<endl;
    return 0;
}