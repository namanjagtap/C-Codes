#include<iostream>
using namespace std;

int main(){
    int n,m,r,c;
    cout<<"Enter order of matrix: ";
    cin>>n>>m;
    int target;
    cout<<"Enter no. to be found: ";
    cin>>target;
    int arr[n][m];
    cout<<"Enter matrix"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    r=0,c=m-1;
    bool flag =false;
    while(r<n && c>=0){
        if(arr[r][c]==target)
            flag = true;
        if(arr[r][c]>target)
            c--;
        else
            r++;
    }
    if(flag==true){
        cout<<"Element Found!"<<endl;
    }
    else
        cout<<"Element not found."<<endl;
    
    return 0;
    
}