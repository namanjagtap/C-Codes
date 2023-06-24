#include <iostream>
#include <stack>
using namespace std;

void reverseSentence(string s){
    // stack<string> st;
    stack<char> st;
    for(int i=0;i<s.length();i++){
        // string word="";
        // word += s[i];
        // st.push(word);
        st.push(s[i]);
    }

    while(!st.empty()){
        cout<<st.top();
        st.pop();
    }
    cout<<endl;
}

int main(){
    string s = "Naman";
    reverseSentence(s);

    return 0;
}