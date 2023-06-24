#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main(){
    vector<int> a1 = {1,2,2,1};
    vector<int> a2 = {2,2};

    set<int> st;
    for(auto i=a1.begin();i!=a1.end();i++)
        for(auto j=a2.begin();j!=a2.end();j++)
            if(*i==*j)
                st.insert(*i);

    for(auto val: st)
        cout<<val<<" ";
    cout<<endl;

    return 0;
}