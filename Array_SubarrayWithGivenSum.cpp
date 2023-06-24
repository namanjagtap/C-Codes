#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int requiredSum;
    cin>>requiredSum;

    int i = 0, j = 0, sum = 0, st = -1, end = -1;

    while(j<n && sum+arr[j]<=requiredSum){
        sum+=arr[j];
        j++;
    }
    if(sum == requiredSum){
        cout<<i+1<<" "<<j<<endl;
        return 0;
    }

    while(j<n){
        sum+=arr[j];
        while(sum > requiredSum){
            sum -= arr[i];
            i++;
        }
        if(sum==requiredSum){
            st = i+1;
            end = j+1;
            break;
        }
        j++;
    }
    cout<<st<<" "<<end<<endl;

    return 0;
}