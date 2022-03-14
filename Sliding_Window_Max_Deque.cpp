#include <bits/stdc++.h>
using namespace std;

//Time Complexity- O(nlogn)

int main(){
    int n, k;
    cin>>n>>k;
    vector<int> a(n);
    for(auto &i: a)
        cin>>i;
    multiset<int, greater<int>> m;
    vector<int> ans;
    for(int i=0;i<k;i++)
        m.insert(a[i]);
    ans.push_back(*m.begin());
    for(int i=k;i<n;i++){
        m.erase(m.lower_bound(a[i-k]));
        m.insert(a[i]);
        ans.push_back(*m.begin());
    }
    for(auto i: ans){
        cout<<i<<' ';
    }
}

//Time Complexity- O(n)

// int main(){
//     int n, k;
//     cin>>n>>k;
//     vector<int> a(n);
//     for(auto &i: a)
//         cin>>i;
//     deque<int> q;
//     vector<int> ans;
//     for(int i=0;i<k;i++){
//         while(!q.empty() && a[q.back()]<a[i]){
//             q.pop_back();
//         }
//         q.push_back(i);
//     }
//     ans.push_back(a[q.front()]);
//     for(int i=k;i<n;i++){
//         if(q.front()==i-k)
//             q.pop_front();
//         while(!q.empty() && a[q.back()]<a[i]){
//             q.pop_back();
//         q.push_back(i);
//         ans.push_back(a[q.front()]);
//         }
//         for(auto i: a)
//             cout<<i<<" ";
//         cout<<endl;
//     }
// }