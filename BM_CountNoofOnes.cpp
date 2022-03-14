#include<bits/stdc++.h>
using namespace std;

int countOne(int n){
    int count = 0;
    for( int i=2;i<n;i++){
        while(i){
        i = i & (i-1);
        count++;
        }
    }

    return count;
}

int main(){
    cout<<countOne(5)<<endl;
}