#include <iostream>
#include <vector>
using namespace std;

void rotate(vector<int> nums, int k){
    int n = nums.size();
    k = k % n;
    if(k==0 || n==0 || k==n)
        return;
    int count = 0;
    int start = 0;
    int current = start;
    int prev = nums[start];

    while(count < n){
        current = (current + k) % n;
        int temp = nums[current];
        nums[current] = prev;
        prev = temp;
        count++;

        if(current==start){
            start++;
            current = start;
            prev = nums[start];
        }
    }
    for(auto i: nums)
        cout<<i<<" ";
    cout<<endl;
}

int main(){

    // int arr[5] = {1,2,3,4,5};
    // int temp1 = 0, temp2 = 0;
    // int count = 3;
    // while(count){
    //     for(int i=0;i<5;i++){
    //         temp2 = arr[i];
    //         arr[i] = temp1;
    //         temp1 = temp2;
    //     }
    //     arr[0] = temp2;
    //     count--;
    // }
    // for(auto t: arr)
    //     cout<<t<<" ";
    // cout<<endl;


    vector<int> nums = {-1,-100,3,99};
    rotate(nums, 2);
    for(auto i: nums)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}