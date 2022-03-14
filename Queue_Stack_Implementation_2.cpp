#include <iostream>
#include <stack>
using namespace std;

class queue{
    stack<int> st;
    public:

    void push(int x){
        st.push(x);
        return;
    }

    int pop(){
        if(st.empty()){
            cout<<"Queue is empty."<<endl;
            return -1;
        }

        int x = st.top();
        st.pop();

        if(st.empty()){
            return x;
        }

        int item = pop();
        st.push(x);

        return item;
    }

    bool empty(){
        if(st.empty())
            return true;
        return false;
    }
};

int main(){
    queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    cout<<q.pop()<<endl;
    q.push(5);
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;

    return 0;
}