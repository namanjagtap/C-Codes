#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a;
    vector<int> v;
    for(int i=0;i<n;i++){
        cin>>a;
        v.push_back(a);
    }

    int min = INT_MAX;
    int max = INT_MIN;

    for(int i=0;i<n;i++){
        v[i]>max ? max = v[i] : max;
        v[i]<min ? min = v[i] : min;
    }
    cout<<"MAX:- "<<max<<"  MIN:- "<<min<<endl;
    return 0;
}