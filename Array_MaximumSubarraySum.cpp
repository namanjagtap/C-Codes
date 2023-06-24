#include <iostream>
#include <climits>
using namespace std;

//My Approach
void maxSumMy(int arr[], int n){
    int maxSum = INT_MIN;
    for(int i=0;i<n;i++){
        int sum = 0;
        for(int j=i;j<n;j++)
            sum += arr[j];
        maxSum = max(maxSum, sum);
    }
    cout<<maxSum<<endl;
}

//With complexity of O(n^3)
void maxSumI(int arr[], int n){
    int maxSum  = INT_MIN;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int sum = 0;
            for(int k=i;k<=j;k++)
                sum += arr[k];
            maxSum = max(maxSum, sum);
        }
    }
    cout<<maxSum<<endl;
}

//Cumulatice Sum Approach with complexity O(n^2)
void maxSumII(int arr[], int n){
    int currsum[n+1];
    currsum[0] = 0;
    for(int i=1;i<=n;i++)
        currsum[i] = currsum[i-1] + arr[i-1];
    
    int maxSum = INT_MIN;
    for(int i=1;i<=n;i++){
        int sum = 0;
        for(int j=0;j<i;j++){
            sum = currsum[i] - currsum[j];
            maxSum = max(maxSum, sum);
        }
    }
    cout<<maxSum<<endl;
}

//Optimized Approach:- Kadane's Theorem with complexity O(n)
void maxSumIII(int arr[], int n){
    int currSum = 0;
    int maxSum = INT_MIN;
    for(int i=0;i<n;i++){
        currSum += arr[i];
        if(currSum < 0)
            currSum = 0;
        maxSum = max(maxSum, currSum);
    }
    cout<<maxSum<<endl;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    maxSumMy(arr, n);
    maxSumI(arr, n);
    maxSumII(arr, n);
    maxSumIII(arr, n);

    return 0;
}