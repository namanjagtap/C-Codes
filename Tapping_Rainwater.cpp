#include <bits/stdc++.h>
using namespace std;

int rainWater(vector<int> a){
    stack<int> st;
    int n = a.size(), ans = 0;
    for(int i=0;i<n;i++){
        while(!st.empty() && a[st.top()]<a[i]){
            int curr = st.top();
            st.pop();
            if(st.empty())
                break;
            int diff = i-st.top()-1;
            ans += (min(a[st.top()], a[i]) - a[curr])*diff;
        }
        st.push(i);
    }
    return ans;
}

int main(){
    vector<int> a = {3, 0, 0, 2, 0, 4};
    cout<<rainWater(a)<<endl;

    return 0;
}