#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main(){
    vector<int> a1 = {1,2,3,4,5};
    vector<int> a2 = {1,2,3};

    set<int> st;
    for(auto i=a1.begin();i!=a1.end();i++)
        st.insert(*i);
    for(auto j=a2.begin();j!=a2.end();j++)
         st.insert(*j);

    cout<<st.size();

    return 0;
}